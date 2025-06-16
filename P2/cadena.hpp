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
        // Tipos de iteradores
        using iterator = char*; // iterador para recorrer la cadena
        using const_iterator = const char*; // iterador constante para recorrer la cadena
        using reverse_iterator = std::reverse_iterator<iterator>; // iterador inverso
        using const_reverse_iterator = std::reverse_iterator<const_iterator>; // iterador inverso constante

        //iteradores directos
        inline iterator begin() noexcept { return s_; } // devuelve el puntero al primer elemento;
        inline iterator end() noexcept { return s_ + tam_; } // devuelve el puntero al final de la cadena
        inline const_iterator begin() const noexcept { return s_; } // devuelve el puntero al primer elemento constante
        inline const_iterator end() const noexcept { return s_ + tam_; } // devuelve el puntero al final de la cadena constante
        inline const_iterator cbegin() const noexcept { return s_; } // devuelve el puntero al primer elemento constante
        inline const_iterator cend() const noexcept { return s_ + tam_; } // devuelve el puntero al final de la cadena constante
        //iteradores inversos        
        inline reverse_iterator rbegin() noexcept { return reverse_iterator(end()); } // devuelve el puntero al final de la cadena
        inline reverse_iterator rend() noexcept { return reverse_iterator(begin()); } // devuelve el puntero al primer elemento
        inline const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(end()); } // devuelve el puntero al final de la cadena constante
        inline const_reverse_iterator rend() const noexcept { return const_reverse_iterator(begin()); } // devuelve el puntero al primer elemento constante
        inline const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator(cend()); } // devuelve el puntero al final de la cadena constante
        inline const_reverse_iterator crend() const noexcept { return const_reverse_iterator(cbegin()); } // devuelve el puntero al primer elemento constante

        // funciones observadoras
        size_t length() const { return tam_; } // devuelve el tamaño de la cadena
        char& at(size_t index) const; // devuelve el caracter en la posición index (controla excepciones) para constantes
        char& at(size_t index); // devuelve el caracter en la posición index (controla excepciones) para no constantes
        // Constructor por defecto
        explicit Cadena (size_t tamano = 0, char caracter = ' ');
        //constructor const char*
        Cadena (const char* str);
        // Constructor de copia
        Cadena (const Cadena& C);
        //Constructo de movimiento
        Cadena (Cadena&& C) noexcept;
        // Destructor
        ~Cadena() { 
            if (s_ != vacia)
                delete[] s_; 
        }
        //metodo substr para devolver una subCadena especificado
        Cadena substr(size_t index, size_t tama) const;

        //operadores "padre" '<' && '=='
        friend bool operator ==(const Cadena& Cad1, const Cadena& Cad2);
        friend bool operator <(const Cadena& Cad1, const Cadena& Cad2);
        //operadores inline de comparación
        friend inline bool operator !=(const Cadena& Cad1, const Cadena& Cad2){return !(Cad1 == Cad2);}
        friend inline bool operator >(const Cadena& Cad1, const Cadena& Cad2){ return (Cad2 < Cad1);}
        friend inline bool operator >=(const Cadena& Cad1, const Cadena& Cad2){return !(Cad1 < Cad2);}
        friend inline bool operator <=(const Cadena& Cad1, const Cadena& Cad2){return !(Cad2 < Cad1);}
        // Sobrecarga operador corchetes
        inline const char& operator[](size_t index) const { return s_[index]; } // para objetos const
        inline char& operator[](size_t index) { return s_[index]; }            // para objetos no const
        //operador de asignación
        Cadena& operator =(const Cadena& c); // asignación de cadena
        Cadena& operator =(const char* str); // asignación de const char*
        // Operador de asignación por movimiento
        Cadena& operator=(Cadena&& otra) noexcept;
        //operador const char* para convertir a cadena
        inline explicit operator const char*() const { return s_; } // conversión a const char*
        //operador de concatenación
        Cadena& operator+=(const Cadena& otra);
        friend Cadena operator+(const Cadena& c1, const Cadena& c2);
        //Operador de insercción y extracción
        friend std::istream& operator>>(std::istream& is, Cadena& cadena);
        friend std::ostream& operator<<(std::ostream& os, const Cadena& cadena);

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

// #endi