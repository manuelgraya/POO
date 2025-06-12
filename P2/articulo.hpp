#ifndef ARTICULO_HPP
#define ARTICULO_HPP

#include <string>
#include<iomanip>
#include "../P1/fecha.hpp"
#include "../P1/cadena.hpp"

class Articulo {
    public:
        Articulo(Cadena codigoRef, Cadena titulo, Fecha fechaPublic, double precio, unsigned numEjemplar = 0);
        const Cadena referencia() const { return codigoRef_; }
        const Cadena titulo() const { return titulo_; }
        const Fecha f_publi() const { return fechaPublic_; }
        const double precio() const { return precio_; }
        const unsigned stock() const { return numEjemplar_; }
    private:
        const Cadena codigoRef_;
        const Cadena titulo_;
        const Fecha fechaPublic_;
        double precio_;
        unsigned numEjemplar_;
};

ostream& operator <<(ostream& os, const Articulo& art);

#endif