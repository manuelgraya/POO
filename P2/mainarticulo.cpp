#include <iostream>
#include "articulo.hpp"

int main () {
    try {
        Articulo art(Cadena("ART123"), Cadena("C++ Programming"), Fecha(1, 1, 2023), 29.99, 100);
        cout << art << endl;
    } catch (const Fecha::Invalida& e) {
        cerr << "Fecha inválida: " << e.por_que() << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    system("pause"); // Pausa para ver la salida en consola
    return 0;

}