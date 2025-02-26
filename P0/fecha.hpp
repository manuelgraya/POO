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
    
    // Métodos observadores
    int dia() const { return dia_; }
    int mes() const { return mes_; }
    int anno() const { return anno_; }
};

bool valida(int d, int m, int a);
int dias_mes(int m, int a);
bool es_bisiesto(int a);

#endif