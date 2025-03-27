#include "cadena.hpp"

int main() {
    Cadena a(3, 'A');
    std::cout <<"Constructor predeterminado, entrada  Cadena a(3, 'A'); \n Salida:" << a;
    std::cin.get();

    Cadena b("Hola");
    std::cout << "Constructor predeterminado, entrada  Cadena b(\"Hola\"); \n Salida:" << b;
    std::cin.get();

    return 0;
}