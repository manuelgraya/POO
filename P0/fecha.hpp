#ifndef FECHA_HPP
#define FECHA_HPP

#include <iostream>
#include <stdlib.h>

using namespace std;    

class Fecha {

    private:
        int dia_;
        int mes_; //atributos
        int anio_;
        
    public:

    static const int AnnoMinimo = 1902;
    static const int AnnoMaximo = 2037;
    explicit Fecha(int dia=0, int mes=0, int anio=0); // Constructor
    Fecha (const char* s); // Constructor

    class Invalida {
        private:
            const char* s_;

        public:
            inline Invalida(const char* s) : s_{s} {} // Constructor
    };
};

#endif