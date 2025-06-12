#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <iostream>
#include "../P1/cadena.hpp"

class Clave{
    private: 
        Cadena clave_;
        static const char caracteres_validos[]; // caracteres válidos para la clave
    public:
        enum Razon {CORTA, ERROR_CRYPT};
        class Incorrecta {
            public:
                Incorrecta(Razon r) : razon_(r) {}
                Razon razon() const { return razon_; }
            private:
            Razon razon_;
            };
        explicit Clave(const char* contrasena);
        const Cadena& clave() const { return clave_; };
        bool verifica(const char* claro) const;
};  

#endif