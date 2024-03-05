#include <iostream>
#include "holamundo.hpp"

// Remove the existing definition of the function
// void HolaMundo::imprimir() {
//     std::cout << "Hola, mundo!" << std::endl;
// }

// Add the corrected definition of the function
HolaMundo::HolaMundo() {
    // Empty
}
void HolaMundo::imprimir() {
    std::cout << "Hola, mundo!" << std::endl;
}


