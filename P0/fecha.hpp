#ifndef FECHA_HPP_
#define FECHA_HPP_

#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

class Fecha {
    private:
        int dia_;
        int mes_;
        int anno_;
    public:
    //constructores
    explicit Fecha (int dia = 0, int mes = 0, int anno = 0); //constructor con tres parametros, no permite conversion implicita Fecha f= 5; (Fecha (5,0,0))
    Fecha(const char* cadena); //constructor de conversion, permite conversion implicita Fecha f = "5/5/2020"; (Fecha (5,5,2020))
    // Métodos observadores
    int dia() const { return dia_; }
    int mes() const { return mes_; }
    int anno() const { return anno_; }

    //clase invalida
    class Invalida {
        private:
            const char* error_;
        public:
            Invalida(const char* error): error_(error) {}
            const char* por_que() const { return error_; } //devuelve el error
    };

    //constantes públicas
    static const int AnnoMinimo;
    static const int AnnoMaximo;
};

bool valida(int d, int m, int a);
int dias_mes(int m, int a);
bool es_bisiesto(int a);

#endif