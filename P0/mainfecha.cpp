#include <iostream>
#include "Fecha.hpp"

int main() {
    try {
        Fecha s("02/1/2000");
    } catch (Fecha::Invalida& e) {
        std::cerr << e.por_que() << std::endl;
    }
    try
    {
        Fecha a(6,12,2002);
    }
    catch(Fecha::Invalida& e){ //captura la excepción lanzada por el constructor de Fecha y la imprime.
        std::cerr << e.por_que() << std::endl;
    }
    Fecha s("02/1/2000");
    Fecha a(6,12,2002);
    if (s==a){
        std::cout << "Son iguales" << std::endl;
    }else{
        std::cout << "No son iguales" << std::endl;
    }
    if (s<a){
        std::cout << "02/1/2000 es menor que 06/12/2002" << std::endl;
    }else{
        std::cout << "s no es menor que 06/12/2002" << std::endl;
    }
    a += 30;
    std::cout << a.dia() << "/" << a.mes() << "/" << a.anno() << std::endl;
    a -= 30;
    std::cout << a.dia() << "/" << a.mes() << "/" << a.anno() << std::endl;
    a = a + 5;
    std::cout << "a + 5:" << endl;
    std::cout << a.dia() << "/" << a.mes() << "/" << a.anno() << std::endl;
    a = a - 5;
    std::cout << "a - 5:" << endl;
    std::cout << a.dia() << "/" << a.mes() << "/" << a.anno() << std::endl;
    ++a;
    std::cout << a.dia() << "/" << a.mes() << "/" << a.anno() << std::endl;
    a++;
    std::cout << a.dia() << "/" << a.mes() << "/" << a.anno() << std::endl;
    --a;
    std::cout << a.dia() << "/" << a.mes() << "/" << a.anno() << std::endl;
    a--;
    std::cout << a.dia() << "/" << a.mes() << "/" << a.anno() << std::endl;


    return 0;
}