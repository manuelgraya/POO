#include "fecha.hpp"

// Función main para probar el operador >>
int main() {
    try {
        Fecha f(1, 1, 2000);  // Fecha inicial
        std::cout << "Fecha inicial: " << f << std::endl;
        
        std::cout << "Ingrese una fecha (formato dd/mm/aaaa): ";
        std::cin >> f;
        std::cout << "Fecha ingresada: " << f << std::endl;
        
        // Probar con otra fecha
        std::cout << "Ingrese otra fecha (formato dd/mm/aaaa): ";
        std::cin >> f;
        std::cout << "Nueva fecha ingresada: " << f << std::endl;
        
        // Probar con una fecha inválida
        std::cout << "Ingrese una fecha inválida (ej: 32/13/2050): ";
        std::cin >> f;
        std::cout << "Esta línea no debería mostrarse si la fecha es inválida" << std::endl;
    }
    catch (const Fecha::Invalida& e) {
        std::cerr << "Fecha inválida: " << e.por_que() << std::endl;
    }
    
    return 0;
}