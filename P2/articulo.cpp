 #include "articulo.hpp"

Articulo::Articulo(Cadena codigoRef, Cadena titulo, Fecha fechaPublic, double precio, unsigned numEjemplar)
    : codigoRef_(codigoRef), titulo_(titulo), fechaPublic_(fechaPublic), precio_(precio), numEjemplar_(numEjemplar) {}

 ostream& operator<<(ostream& os, const Articulo& art) {
    os << '[' << art.referencia() << "] "
       << '"' << art.titulo() << "\", "
       << art.f_publi().anno() << ". "
       << fixed << setprecision(2) << art.precio() << " €";
    return os;
}

