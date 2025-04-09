#ifndef CADENA_HPP_
#define CADENA_HPP_

#include <iostream>
#include <cstring>

using namespace std;

class Cadena {
    private:
        static char vacia[1]; // atributo estático para la cadena vacía
        size_t tam_; // tamaño de la cadena
        char* s_; // apuntará a la cadena de caracteres terminada en \0

    public:
        // funciones observadoras
        int length() const { return tam_; } // devuelve el tamaño de la cadena

        // Constructor por defecto
        explicit Cadena (size_t tamano = 0, char caracter = ' ');
        //constructor const char*
        Cadena (const char* str);
        // Constructor de copia
        Cadena (const Cadena& C);
        // Destructor
        ~Cadena() { delete[] s_; }

        // Sobrecarga del operador de inserción
        friend std::ostream& operator<<(std::ostream& os, const Cadena& cadena);
        //operadores "padre" '<' && '=='
        friend bool operator ==(const Cadena& Cad1, const Cadena& Cad2);
        friend bool operator <(const Cadena& Cad1, const Cadena& Cad2);
        //operadores inline de comparación
        friend inline bool operator !=(const Cadena& Cad1, const Cadena& Cad2){return !(Cad1 == Cad2);}
        friend inline bool operator >(const Cadena& Cad1, const Cadena& Cad2){ return (Cad2 < Cad1);}
        friend inline bool operator >=(const Cadena& Cad1, const Cadena& Cad2){return !(Cad1 < Cad2);}
        friend inline bool operator <=(const Cadena& Cad1, const Cadena& Cad2){return !(Cad2 < Cad1);}

        


};
#endif


/*------------------------------------ CADENA SERGIO -------------------------------------------------------*/

// #ifndef CADENA_HPP_
// #define CADENA_HPP_
// #include<cstring>
// #include<algorithm>
// #include<iostream>
// using namespace std;

// class Cadena{
//     public:
//         explicit Cadena(size_t tam = 0, char a = ' ');  //OK
//         Cadena(const Cadena& C);  //OK
//         Cadena(const char* cad);  //OK
//         Cadena& operator =(const Cadena& c);  //OK
//         size_t length() const;  //OK
//         explicit operator const char*() const;  //OK
//         Cadena& operator +=(const Cadena& c);  //OK
//         char& operator [](size_t index) const;  //OK
//         char& operator [](size_t index);  //OK
//         char& at(size_t index); //OK
//         char& at(size_t index) const;  //OK
//         Cadena substr(unsigned index, size_t tama) const;
//         friend bool operator ==(const Cadena& Cad1, const Cadena& Cad2);   //OK
//         friend bool operator !=(const Cadena& Cad1, const Cadena& Cad2);   //OK
//         friend bool operator >(const Cadena& Cad1, const Cadena& Cad2);    //OK
//         friend bool operator <(const Cadena& Cad1, const Cadena& Cad2);    //OK
//         friend bool operator >=(const Cadena& Cad1, const Cadena& Cad2);   //OK
//         friend bool operator <=(const Cadena& Cad1, const Cadena& Cad2);   //OK
//         ~Cadena();  //OK
//     private:
//         static char vacia[1];
//         size_t tam_;
//         char* s_;
// };

// Cadena operator +(const Cadena& c1, const Cadena& c2);  //OK


// #endif