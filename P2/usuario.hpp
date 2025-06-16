#ifndef USUARIO_HPP__
#define USUARIO_HPP__
#include<iostream>
#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"
#include "articulo.hpp"
#include "tarjeta.hpp"
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<unistd.h>
#include<random>
using namespace std;

class Numero;
class Tarjeta;

class Clave {
    public:
        Clave(const char* s_);
        enum Razon {CORTA, ERROR_CRYPT};
        class Incorrecta{
            public:
                Incorrecta(Razon r) : r_{r} {};
                Razon razon() const { return r_;};
            private:
                Razon r_;
        };
        Cadena clave() const {return contrasenna_;};
        bool verifica(const char* claro) const;
    private:
        Cadena contrasenna_;
};

class Usuario{
    public:
        typedef std::map<Numero, Tarjeta*> Tarjetas;
        typedef std::unordered_map<Articulo*, unsigned int> Articulos;
        Usuario(Cadena id, Cadena nombre, Cadena apellidos, Cadena direccion, Clave clave);
        class Id_duplicado{
            public:
                Id_duplicado(Cadena idDuplicado) : idDuplicado_{idDuplicado} {};
                Cadena idd() const { return idDuplicado_;};
            private:
                Cadena idDuplicado_;
        };
        const Cadena id() const { return id_;};
        const Cadena nombre() const {return nombre_;};
        const Cadena apellidos() const {return apellidos_;};
        const Cadena direccion() const { return direccion_;};

        friend ostream& operator <<(ostream& os, const Usuario& u);

        const Tarjetas& tarjetas() const noexcept{ return tarjeta_;};
        Articulos compra() const { return articulo_;};
        void es_titular_de(Tarjeta& tarj);
        void no_es_titular_de(Tarjeta& tarj);
        void compra(Articulo& art, unsigned int cantidad = 1);
        //const Articulos& compra() const;
        void vaciar_carro();
        size_t n_articulos() const;
        ~Usuario();
    private:
        const Cadena id_;
        const Cadena nombre_;
        const Cadena apellidos_;
        const Cadena direccion_;
        Clave password_;
        Tarjetas tarjeta_;
        Articulos articulo_;
        static unordered_set<Cadena> ids;
        Usuario(const Usuario& user)= delete;
        Usuario& operator =(const Usuario& user)= delete;
        
};


ostream& mostrar_carro(ostream& os, const Usuario& user);


#endif