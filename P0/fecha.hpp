#ifndef FECHA_HPP_
#define FECHA_HPP_

#include <iostream>
#include <ctime>

using namespace std;    

class Fecha {

    private:
        int dia_;
        int mes_; //atributos
        int anio_;
        std::time_t tiempo_calendario = std::time(nullptr);
        std::tm* tiempo_descompuesto = std::localtime(&tiempo_calendario);
        void verificardia(int d);
        void verificarmes(int m);
        void verificaranio(int a);
    
    public:

    static const int AnnoMinimo = 1902;
    static const int AnnoMaximo = 2037;

    //constructores
    Fecha(int d = 0, int m = 0, int a = 0);
    Fecha(const char* f);

    //operadores aritmeticos
    Fecha& operator +=(int n);
    Fecha& operator -=(int n);
    Fecha operator +(int n)const;
    Fecha operator -(int n)const;
    Fecha& operator ++();
    Fecha operator ++(int);
    Fecha& operator --();
    Fecha operator --(int);

    class Invalida {
        private:
            const char* s_;

        public:
            inline Invalida(const char* s) : s_{s} {} // Constructor
    };
};

#endif