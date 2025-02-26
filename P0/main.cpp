#include <iostream>
#include "Fecha.hpp"

int main() {
    Fecha f1;           // Fecha del sistema
    Fecha f2(15);       // Día 15, mes y año del sistema
    Fecha f3(15, 7);    // 15 de julio, año del sistema
    Fecha f4(15, 7, 1990); // 15 de julio de 1990

    std::cout << "Fecha 1: " << f1.dia() << "/" << f1.mes() << "/" << f1.anno() << "\n";
    std::cout << "Fecha 2: " << f2.dia() << "/" << f2.mes() << "/" << f2.anno() << "\n";
    std::cout << "Fecha 3: " << f3.dia() << "/" << f3.mes() << "/" << f3.anno() << "\n";
    std::cout << "Fecha 4: " << f4.dia() << "/" << f4.mes() << "/" << f4.anno() << "\n";
    std::cin.get();


    return 0;
}
