#include "usuario.hpp"

unordered_set<Cadena> Usuario::ids;

Clave::Clave(const char* s_) : contrasenna_{s_}
{
    if (contrasenna_.length() < 5)
    {
        throw Clave::Incorrecta(CORTA);
    }
    if (s_ != nullptr)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distrib(0, 63);
        char salt[3];
        char caracter[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789./";

        for (int i = 0; i < 2; i++)
        {
            int numCaracter = distrib(rd);
            salt[i] = caracter[numCaracter];
        }
        salt[2] = '\0';
        s_ = crypt(s_, salt);
        contrasenna_ = Cadena(s_);
    }
    else
    {
        throw Clave::Incorrecta(ERROR_CRYPT);
    }
    
}

bool Clave::verifica(const char* claro) const
{
    if (claro != nullptr)
    {
        const char* clave1 = crypt(claro, (const char*)contrasenna_);
        return clave1 == contrasenna_;
    }
    else
    {
        throw Clave::Incorrecta(ERROR_CRYPT);
    }
}

Usuario::Usuario(Cadena id, Cadena nombre, Cadena apellidos, Cadena direccion, Clave clave) : id_{id}, nombre_{nombre}, apellidos_{apellidos}, direccion_{direccion}, password_{clave}
{
    typedef unordered_set<Cadena>::iterator tipoIt;
    pair<tipoIt, bool> res = ids.insert(id_);
    if (!res.second)
    {
        throw Usuario::Id_duplicado(id_);
    }
}

void Usuario::es_titular_de(Tarjeta& tarj)
{
    if (tarj.titular() == this)
    {
        tarjeta_[tarj.numero()] = &tarj;
    }
}

void Usuario::no_es_titular_de(Tarjeta& tarj)
{
    tarjeta_.erase(tarj.numero());
}


//DUDA hay que iterar
Usuario::~Usuario()
{
    for(auto& it: tarjeta_)
    {
        it.second->anula_titular();
    }
    ids.erase(id_);
    
}
// MESAS --> FIND NO ENCUENTRA ESE ARTÍCULO --> ME DEVOLVERÍA LA ÚLTIMA POSICIÓN (yo quiero añadir entonces esas mesas --> NUEVO ARTÍCULO)
void Usuario::compra(Articulo& art, unsigned int cantidad)
{
    auto it = articulo_.find(&art);
    if (it == articulo_.end())
    {
        if (cantidad > 0)
        {
            articulo_.insert(make_pair(&art, cantidad));
        }
    }
    else if (cantidad > 0)
    {
        it->second = cantidad;
    }
    else if(cantidad == 0)
    {
        articulo_.erase(&art);
    }
}

void Usuario::vaciar_carro()
{
    articulo_.clear();
}

size_t Usuario::n_articulos() const 
{
    size_t cont = 0;
    for (Articulos::const_iterator it = articulo_.cbegin(); it!=articulo_.cend(); it++)
    {
        cont++;
    }
    return cont;
}

ostream& operator <<(ostream& os, const Usuario& u)
{
    os << u.id() << "   ["<<u.password_.clave()<<"]  "<<u.nombre()<< " "<<u.apellidos()<<endl;
    os << u.direccion()<<endl;
    os << "Tarjetas:" <<endl;
    if(!u.tarjetas().empty())
    {
        for (auto it : u.tarjetas())
        {
            os << *it.second<<endl;
        }
    }

    return os;
}

ostream& mostrar_carro(ostream& os, const Usuario& user)
{
    os << "Carrito de compra de "<< user.id()<< "  [Artículos: "<<user.n_articulos()<<"]"<<endl;
    os << "\tCant. Artículo" <<endl;
    os << "==========================================================="<<endl;
    if (!user.compra().empty())
    {
        for (auto it : user.compra())
        {
            os << it.second << "   " << *it.first<<endl;
        }
    }
    return os;
}

