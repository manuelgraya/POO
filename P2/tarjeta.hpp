#ifndef TARJETA_HPP__
#define TARJETA_HPP__
#include<iostream>
#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"
#include "articulo.hpp"
#include "usuario.hpp"
#include<map>
#include<unordered_map>
#include<set>
#include<cctype>

using namespace std;

class Usuario;

class Numero {
    public:
        Numero(Cadena num);
        enum Razon {LONGITUD, DIGITOS, NO_VALIDO};
        class Incorrecto {
            public:
                Incorrecto(Razon r) : r_{r} {};
                Razon razon() const { return r_;};
            private:
                Razon r_;
        };

        operator const char*() const;

    private:
        Cadena numTroquelado_;
};

bool operator <(const Numero& num1, const Numero& num2);


class Tarjeta {
    public:
        Tarjeta(Numero numTarjeta, Usuario& user, Fecha caducidad, bool activa = true);
        enum Tipo{Otro, VISA, Mastercard, Maestro, JCB, AmericanExpress};
        class Caducada {
            public:
                Caducada(const Fecha caducada) : caducada_{caducada} {};
                const Fecha cuando() const {return caducada_;};
            private:
                const Fecha caducada_;
        };
        class Num_duplicado {
            public:
                Num_duplicado(const Numero duplicado) : duplicado_{duplicado} {};
                const Numero que() const {return duplicado_;};
            private:
                const Numero duplicado_;
        }; 

        const Numero numero() const { return numTarjeta_;};
        const Usuario* titular() const { return user_;};
        const Fecha caducidad() const { return caducidad_;};
        bool activa() const {return activa_;};
        Tipo tipo() const;
        bool& activa(bool act) {activa_ = act; return activa_;};
        ~Tarjeta();
    private:
        const Numero numTarjeta_;
        const Usuario* user_;
        const Fecha caducidad_;
        bool activa_;
        static set<Numero> numeros;
        friend class Usuario;
        void anula_titular();
        Tarjeta(const Tarjeta& tarj)= delete;
        Tarjeta& operator =(const Tarjeta& tarj)= delete;
};

//Sobrecarga del operador de inserción de flujo de Tarjeta
ostream& operator <<(ostream& os, const Tarjeta& tarjeta);

//Sobrecarga del operador de inserción de flujo de Tarjeta::Tipo
ostream& operator <<(ostream& os, const Tarjeta::Tipo& tipo);

//Sobrecarga del operador menor que para comparar dos tarjetas
bool operator <(const Tarjeta& tarj1, const Tarjeta& tarj2);

#endif