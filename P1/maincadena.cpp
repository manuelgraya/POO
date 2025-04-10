#include <iostream>
#include <utility>      // std::move
#include "cadena.hpp"

int main() {
    // 1. Lectura e impresión con operadores >> y <<
    std::cout << "Introduce una palabra (máx 32 caracteres): ";
    Cadena c;
    std::cin >> c;
    std::cout << "\n✅ Palabra leída: " << c << "\n";

    // 2. Iteradores normales: modificación
    for (auto it = c.begin(); it != c.end(); ++it) {
        *it = std::toupper(*it);
    }
    std::cout << "🔁 Convertida a mayúsculas: " << c << "\n";

    // 3. Iteradores constantes
    std::cout << "🔍 Lectura constante con cbegin(): ";
    for (auto it = c.cbegin(); it != c.cend(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << "\n";

    // 4. Iteradores inversos
    std::cout << "🔁 Inverso con rbegin(): ";
    for (auto rit = c.rbegin(); rit != c.rend(); ++rit) {
        std::cout << *rit << ' ';
    }
    std::cout << "\n";

    std::cout << "🔍 Inverso constante con crbegin(): ";
    for (auto rit = c.crbegin(); rit != c.crend(); ++rit) {
        std::cout << *rit << ' ';
    }
    std::cout << "\n";

    // 5. Semántica de movimiento
    std::cout << "\n🚀 Movimiento:\n";
    Cadena origen("Temporal");
    Cadena movida = std::move(origen);
    std::cout << "Cadena movida: " << movida << "\n";
    std::cout << "Cadena original (vacía): " << origen << "\n";

    Cadena otra("Asignación");
    otra = std::move(movida);
    std::cout << "Tras asignación por movimiento: " << otra << "\n";
    std::cout << "Destino original tras mover (vacío): " << movida << "\n";

    return 0;
}
