#include "tarjeta.hpp"

set<Numero> Tarjeta::numeros;

bool luhn(const Cadena& cad);

Numero::Numero(Cadena num) : numTroquelado_{num}
{
    Cadena aux;
    for (Cadena::iterator it = numTroquelado_.begin(); it != numTroquelado_.end(); it++)
    {
        if (!isspace(*it))
        {
            if (!isdigit(*it))
            {
                throw Numero::Incorrecto(DIGITOS);
            }
            else
            {
                aux+=Cadena(1, *it);
            }
        }
    }

    if (aux.length() < 13 || aux.length() > 19)
    {
        throw Numero::Incorrecto(LONGITUD);
    }

    if (!luhn(aux))
    {
        throw Numero::Incorrecto(NO_VALIDO);
    }
    numTroquelado_ = aux;
}

Numero::operator const char*() const
{
    return (const char*)numTroquelado_;
}


bool operator <(const Numero& num1, const Numero& num2)
{
    return (strcmp((const char*)num1, (const char*)num2) < 0);
}


Tarjeta::Tarjeta(Numero numTarjeta, Usuario& user, Fecha caducidad, bool activa) : numTarjeta_{numTarjeta}, user_{&user}, caducidad_{caducidad}, activa_{activa}
{
    if (caducidad_ < Fecha())
    {
        throw Tarjeta::Caducada(caducidad_);
    }
   
    typedef set<Numero>::iterator tipoIt;
    pair<tipoIt, bool> res = numeros.insert(numTarjeta_);
    if (!res.second)
    {
        throw Tarjeta::Num_duplicado(numTarjeta_);
    }
    user.es_titular_de(*this);
}

Tarjeta::Tipo Tarjeta::tipo() const 
{
    //Preguntar
    const char* num = (const char*)numTarjeta_;
    switch(num[0])
    {
        case '3':
            if (num[1] == '4' or num[1] == '7')
            {
                return AmericanExpress;
            }
            else
            {
                return JCB;
            }
            break;
        case '4':
            return VISA;
            break;
        case '5':
            return Mastercard;
            break;
        case '6':
            return Maestro;
            break;
        default:
            return Otro;
            break;
    }
}

void Tarjeta::anula_titular()
{
    activa_ = false;
    const_cast<Usuario*&>(user_) = nullptr;
}

Tarjeta::~Tarjeta()
{
    if (user_ != nullptr)
    {
        const_cast<Usuario*>(user_)->no_es_titular_de(*this);
        const_cast<Usuario*&>(user_) = nullptr;
    }
    numeros.erase(numero());
}

bool operator <(const Tarjeta& tarj1, const Tarjeta& tarj2)
{
    return tarj1.numero() < tarj2.numero();
}

ostream& operator <<(ostream& os, const Tarjeta::Tipo& tipo)
{
    switch(tipo)
    {
        case Tarjeta::Tipo::AmericanExpress:
            os << "American Express"<<endl;
            return os;
            break;
        case Tarjeta::Tipo::JCB:
            os << "JCB"<<endl;
            return os;
            break;
        case Tarjeta::Tipo::Maestro:
            os << "Maestro"<<endl;
            return os;
            break;
        case Tarjeta::Tipo::Mastercard:
            os << "Mastercard"<<endl;
            return os;
            break;
        case Tarjeta::Tipo::VISA:
            os << "VISA"<<endl;
            return os;
            break;
        case Tarjeta::Tipo::Otro:
            os << "Tipo indeterminado"<<endl;
            return os;
            break;
    }
}

ostream& operator <<(ostream& os, const Tarjeta& tarjeta)
{
    os << tarjeta.tipo() << tarjeta.numero() << endl;
    Cadena aux = tarjeta.titular()->nombre() + " " + tarjeta.titular()->apellidos();
    for (Cadena::iterator it = aux.begin(); it != aux.end(); it++)
    {
        *it = toupper(*it);
    }

    os << aux << endl;
    os << "Caduca:  " <<setfill('0')<<setw(2) <<tarjeta.caducidad().mes() << "/" << tarjeta.caducidad().anno()%100;
    return os;
}