#include "cadena.hpp"

//definicion del atributo static
char Cadena::vacia[1] = {'\0'};

//constructor por defecto
Cadena::Cadena(size_t t, char c) : tam_(t), s_(vacia) {
    if (t == 0) {
        s_ = vacia;
    } else {
        s_ = new char[t + 1];
        for (size_t i = 0; i < t; ++i) {
            s_[i] = c;
        }
        s_[t] = '\0'; // Aseguramos que la cadena esté terminada en nulo
    }
}

//construcor const char*
Cadena::Cadena(const char* str){
    tam_ = std::strlen(str);
    s_ = new char[tam_ + 1];
    std::strcpy(s_, str);
    s_[tam_] = '\0'; // Aseguramos que la cadena esté terminada en nulo
}

//constructor de copia
Cadena::Cadena(const Cadena& c) : tam_(c.tam_) {
    if (tam_ == 0) {
        s_ = vacia;
    } else {
        s_ = new char[tam_ + 1];
        std::strcpy(s_, c.s_);
        s_[tam_] = '\0'; // Aseguramos que la cadena esté terminada en nulo
    }
}

//operador ==
bool operator ==(const Cadena& cad1, const Cadena& cad2){
    if (cad1.tam_ != cad2.tam_) {
        return false;
    }else{
        for (size_t i = 0; i < cad1.tam_; ++i) {
            if (cad1.s_[i] != cad2.s_[i]) {
                return false;
            }
        }
        return true;
    } 
}

//operador menor que
bool operator <(const Cadena& Cad1, const Cadena& Cad2) {
    if(Cad1.tam_ == 0 && Cad2.tam_ == 0) {
        return false;
    }
    if (Cad1.tam_ < Cad2.tam_) {
        return true;
    } else if (Cad1.tam_ > Cad2.tam_) {
        return false;
    } else {
        // Si las longitudes son iguales, comparamos carácter por carácter
        for (size_t i = 0; i < Cad1.tam_; ++i) {
            if (Cad1.s_[i] < Cad2.s_[i]) {
                return true;
            } else if (Cad1.s_[i] > Cad2.s_[i]) {
                return false;
            }
        }
        // Si todos los caracteres son iguales, las cadenas son iguales
        return false;
    }
    }

std::ostream& operator<<(std::ostream& os, const Cadena& cadena) {
    os << cadena.s_;
    return os;
}


/*-------------------------------- SERGIO CADENA --------------------------------------------------*/


// #include "cadena.hpp"

// //Inicializar la variable vacia[1] en el cpp de Cadena
// char Cadena::vacia[1] = {'\0'};

// //Constructor general
// Cadena::Cadena(size_t tam, char a) : tam_(tam)
// {
//     if (tam == 0)
//     {
//         s_ = vacia;
//     }
//     else
//     {
//         s_ = new char[tam + 1];
//         for (size_t i = 0; i < tam; i++)
//         {
//             s_[i] = a;
//         }
//         s_[tam_] = vacia[0];
//     }
    

// }

// //Constructor de copia
// Cadena::Cadena(const Cadena& cad) : tam_(cad.tam_)
// {
//     if(tam_ == 0)
//     {
//         s_ = vacia;
//     }
//     else
//     {
//         s_ = new char[tam_ + 1];
//         strcpy(s_, cad.s_);
//         s_[tam_ + 1] = vacia[0];
//     }

// }


// //Constructor de const char* a Cadena (conversión)
// Cadena::Cadena(const char* cad)
// {
//     tam_ = strlen(cad);
//     s_ = new char[tam_ + 1];
//     strcpy(s_, cad);
//     s_[tam_ + 1] = vacia[0];
// }


// //Sobrecarga del operador de asignación de copia
// Cadena& Cadena::operator =(const Cadena& otra)
// {
//     if (this != &otra)
//     {

//         if (tam_ > 0)
//         {
//             delete[] s_;
//         }

//         tam_ = otra.tam_;
//         if (otra.tam_ > 0)
//         {
            
//             s_ = new char[tam_ + 1];
//             strcpy(s_, otra.s_);
//             s_[tam_ + 1] = vacia[0];
//         }
//         else{

//             s_ = vacia;
//         }
       
//     }
//     return *this;
// }


// //Sobrecarga del operador const char* () (parece método observador)
// Cadena::operator const char *() const
// {
//     return s_;
// }

// //Método observador del tamanno de la cadena
// size_t Cadena::length() const
// {
//     return tam_;
// }


// Cadena& Cadena::operator +=(const Cadena& c)
// {
//     char* nuevo = new char[tam_ + c.length() + 1];
    
//     if (nuevo != nullptr)
//     {
//         strcpy(nuevo, s_);
//         strcat(nuevo, c.s_);
//         delete [] s_;

//         s_ = nuevo;

//         tam_ += c.tam_;
//     }

//     return *this;
// }

// Cadena operator +(const Cadena& c1, const Cadena& c2)
// {
//     Cadena c(c1);
//     c += c2;
//     return c;
// }

// //Operadores de comparación lógico
// //Operador de igualdad
// bool operator ==(const Cadena& Cad1, const Cadena& Cad2)
// {
//     return (strcmp(Cad1.s_, Cad2.s_) == 0);
// }

// //Operador de desigualdad
// bool operator !=(const Cadena& Cad1, const Cadena& Cad2)
// {
//     return !(Cad1 == Cad2);
// }

// //Operador de mayor que
// bool operator >(const Cadena& Cad1, const Cadena& Cad2)
// {
//     return (strcmp(Cad1.s_, Cad2.s_) > 0);
// }

// //Operador de menor que
// bool operator <(const Cadena& Cad1, const Cadena& Cad2)
// {
//     return (strcmp(Cad1.s_, Cad2.s_) < 0);
// }

// //Operador de mayor o igual que
// bool operator >=(const Cadena& Cad1, const Cadena& Cad2)
// {
//     return !(Cad1 < Cad2);
// }

// //Operador de menor o igual que
// bool operator <=(const Cadena& Cad1, const Cadena& Cad2)
// {
//     return !(Cad1 > Cad2);
// }

// //Sobrecarga del operador [] para const
// char& Cadena::operator [](size_t index) const
// {
//     return s_[index];
// }

// //Sobrecarga del operador [] para no const (modificables)
// char& Cadena::operator [](size_t index)
// {
//     return s_[index];
// }

// //Método que controla las excepciones para const
// char& Cadena::at(size_t index) const
// {
//     if (index >= tam_ || index < 0)
//     {
//         throw out_of_range("Indice fuera de limite");
//     }

//     return s_[index];
// }

// //Método que controla las excepciones para no const (modificables)
// char& Cadena::at(size_t index)
// {
//     if (index >= tam_ || index < 0)
//     {
//         throw out_of_range("Indice fuera de limite");
//     }
    
//     return s_[index];
// }

// //Método substr para devolver una subCadena especificado
// Cadena Cadena::substr(unsigned index, size_t tama) const
// {
//     if (index > tam_  || tama > tam_ || index + tama > tam_)
//     {
//         throw out_of_range("Indice fuera de limite");
//     }
//     Cadena subCadena(tama);
//     for (size_t i = 0; i < tama; ++i)
//     {
//         subCadena[i] = s_[i + index];
//     }
//     subCadena[tama] = vacia[0];
//     return subCadena;
// }

// //Destructor de Cadena (utiliza memoria dinámica)
// Cadena::~Cadena()
// {
//     if (tam_ > 0)
//     {
//         delete [] s_;
//     }
// }