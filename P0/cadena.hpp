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

        // Constructores
        explicit Cadena (size_t tamano = 0, char caracter = ' ');

        // Destructor
        ~Cadena() { delete[] s_; }

        // Sobrecarga del operador de inserción
        friend std::ostream& operator<<(std::ostream& os, const Cadena& cadena);
};

#endif