#include "cadena.hpp"

int main() {
    Cadena a(3, 'A');
    std::cout <<"Constructor predeterminado, entrada  Cadena a(3, 'A'); \n Salida:" << a;
    std::cin.get();

    Cadena b("Hola");
    std::cout << "Constructor predeterminado, entrada  Cadena b(\"Hola\"); \n Salida:" << b;
    std::cin.get();
    // b = a; //comprobar constructor de copia funciona, y sí.

    if (a == b) {
        std::cout << "a es igual a b" << std::endl;
    } else {
        std::cout << "a no es igual a b" << std::endl;
    }


    if (a != b) {
        std::cout << "a no es igual a b" << std::endl;
    } else {
        std::cout << "a es igual a b" << std::endl;
    }

    if (a < b) {
        std::cout << "a es menor que b" << std::endl;
    } else {
        std::cout << "a no es menor que b" << std::endl;
    }

    if (a > b) {
        std::cout << "a es mayor que b" << std::endl;
    } else {
        std::cout << "a no es mayor que b" << std::endl;
    }

    if (a <= b) {
        std::cout << "a es menor o igual que b" << std::endl;
    } else {
        std::cout << "a no es menor o igual que b" << std::endl;
    }

    if (a >= b) {
        std::cout << "a es mayor o igual que b" << std::endl;
    } else {
        std::cout << "a no es mayor o igual que b" << std::endl;
    }


    return 0;
}