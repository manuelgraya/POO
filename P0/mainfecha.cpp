#include <iostream>
#include "Fecha.hpp"

int main() {
    Fecha f1;           // Fecha del sistema
    std::cout << "Fecha 1: " << f1.dia() << "/" << f1.mes() << "/" << f1.anno() << "\n";

    // Fecha f2(15);       // Día 15, mes y año del sistema
    // std::cout << "Fecha 2: " << f2.dia() << "/" << f2.mes() << "/" << f2.anno() << "\n";

    // Fecha f3(15, 7);    // 15 de julio, año del sistema
    // std::cout << "Fecha 3: " << f3.dia() << "/" << f3.mes() << "/" << f3.anno() << "\n";

    // Fecha f4(15, 7, 1990); // 15 de julio de 1990
    // std::cout << "Fecha 4: " << f4.dia() << "/" << f4.mes() << "/" << f4.anno() << "\n";

    // Fecha f5(29, 2, 2025); // Fecha errónea, bisiesto equivoco
    
    // Fecha f6(55, 7, 1990); // Fecha errónea,
    
    Fecha f2(f1);
    std::cout << "Fecha 2: " << f2.dia() << "/" << f2.mes() << "/" << f2.anno() << "\n";

    Fecha f3 = f2;
    std::cout << "Fecha 3: " << f3.dia() << "/" << f3.mes() << "/" << f3.anno() << "\n";

    Fecha f4("01/01/2000");
    std::cout << "Fecha 4: " << f4.dia() << "/" << f4.mes() << "/" << f4.anno() << "\n";

    Fecha f5("0/0/0");
    std::cout << "Fecha 5: " << f5.dia() << "/" << f5.mes() << "/" << f5.anno() << "\n";

    Fecha f6(0, 12, 0);
    std::cout << "Fecha 6: " << f6.dia() << "/" << f6.mes() << "/" << f6.anno() << "\n";

    std::cin.get();

    return 0;
}

