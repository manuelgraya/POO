#include "usuario.hpp"
#include <iostream>

int main() {
  try {
    Clave c("segura");
    std::cout << "Clave cifrada: " << c.clave() << std::endl;
    std::cout << "¿Verifica 'segura'? " << c.verifica("segura") << std::endl;
    std::cout << "¿Verifica 'fallo'? " << c.verifica("fallo") << std::endl;
  } catch (const Clave::Incorrecta& e) {
    std::cout << "Clave incorrecta. Motivo: " << e.razon() << std::endl;
  }
}
