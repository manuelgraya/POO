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
        mutable bool actual;
        mutable char cadena_[40]; // Cadena de representación de la fecha
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

    //operadores de comparación == Y <
    // a != b => !(a == b)
    // a > b => b < a
    // a <= b => !(b < a)
    // a >= b => !(a < b)
    
    inline bool operator==(const Fecha& f) const { return dia_ == f.dia_ && mes_ == f.mes_ && anno_ == f.anno_; }
    inline bool operator<(const Fecha& f) const { return (anno_ < f.anno_) || (anno_ == f.anno_ && mes_ < f.mes_) || (anno_ == f.anno_ && mes_ == f.mes_ && dia_ < f.dia_); }
    inline bool operator>(const Fecha& f) const { return f < *this; }
    inline bool operator<=(const Fecha& f) const { return !(f < *this); }
    inline bool operator>=(const Fecha& f) const { return !(*this < f); }
    inline bool operator!=(const Fecha& f) const { return !(*this == f); }

    //operadores aritméticos
    // f -=n => f += -n
    // f + n => t = f, t += n
    // f - n => t = f, t += -n
    // ++f => f += 1
    // f++ => t = f, f += 1, t
    // --f => f += -1
    // f-- => t = f, f += -1, t
    Fecha& operator+=(int n); //se pone & para que se pueda hacer f += 5 debido a que se modifica el objeto f y no se crea uno nuevo
    inline Fecha& operator-=(int n) { return *this += -n; }
    inline Fecha operator+(int n) const { Fecha t = *this; return t += n; }
    inline Fecha operator-(int n) const { Fecha t = *this; return t+= -n; }
    inline Fecha& operator++() { return *this += 1; } // preincremento es decir primero se incrementa y luego se devuelve el valor
    inline Fecha operator++(int) { Fecha t = *this; *this += 1; return t; } // postincremento es decir primero se devuelve el valor y luego se incrementa
    inline Fecha& operator--() { return *this += -1; } // predecremento es decir primero se decrementa y luego se devuelve el valor
    inline Fecha operator--(int) { Fecha t = *this; *this += -1; return t; } // postdecremento es decir primero se devuelve el valor y luego se decrementa

    //operador de conversión a const char* 
    // operator const char*() const;
    //P1: ESTE OPERADOR PASA A SER UN MÉTODO OBSERVADOR DE LA CLASE FECHA, NO UN OPERADOR DE CONVERSIÓN. 
    const char* cadena() const;



    //operador de extracción e insercción
    friend std::istream& operator>>(std::istream&, Fecha&);
    friend std::ostream& operator<<(std::ostream&, const Fecha&); //se pone const porque no se modifica el objeto

};  

bool valida(int d, int m, int a);
int dias_mes(int m, int a);
bool es_bisiesto(int a);
// Operadores globales para comparar const char* con Fecha
bool operator==(const char* cad, const Fecha& f) noexcept;
bool operator!=(const char* cad, const Fecha& f) noexcept;
bool operator< (const char* cad, const Fecha& f) noexcept;
bool operator> (const char* cad, const Fecha& f) noexcept;
bool operator<=(const char* cad, const Fecha& f) noexcept;
bool operator>=(const char* cad, const Fecha& f) noexcept;


#endif