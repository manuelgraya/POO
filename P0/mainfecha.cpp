#include <iostream>
#include "Fecha.hpp"

int main() {
    // try {
    //     Fecha s("02/1/2000");
    // } catch (Fecha::Invalida& e) {
    //     std::cerr << e.por_que() << std::endl;
    // }
    // try
    // {
    //     Fecha a(6,12,2002);
    // }
    // catch(Fecha::Invalida& e){ //captura la excepción lanzada por el constructor de Fecha y la imprime.
    //     std::cerr << e.por_que() << std::endl;
    // }
    // Fecha s("02/1/2000");
    // Fecha a(6,12,2002);
    // if (s==a){
    //     std::cout << "Son iguales" << std::endl;
    // }else{
    //     std::cout << "No son iguales" << std::endl;
    // }
    // if (s<a){
    //     std::cout << "02/1/2000 es menor que 06/12/2002" << std::endl;
    // }else{
    //     std::cout << "s no es menor que 06/12/2002" << std::endl;
    // }

    // try {
    //     Fecha armagedon(31, 12, Fecha::AnnoMaximo),
    //     big_bang(1, 1, Fecha::AnnoMinimo);
    //     armagedon++; // Error, desbordamiento superior en armagedon
    //     big_bang-= 3; // Error, desbordamiento inferior en la Fecha devuelta
    // } catch(Fecha::Invalida& e) { std::cerr << e.por_que() << std::endl; }

    //     // Prueba del operador de conversión a const char*
    // Fecha fechaPrueba(15, 8, 2021);
    // const char* fechaComoCadena = fechaPrueba;
    // std::cout << "Fecha como cadena: " << fechaComoCadena << std::endl;
    Fecha a(1,0,0);
    a += 9;
    std::cout << a.dia() << "/" << a.mes() << "/" << a.anno() << std::endl;
    a -= 9;
    std::cout << a.dia() << "/" << a.mes() << "/" << a.anno() << std::endl;
    a = a + 5;
    std::cout << "a + 5:" << endl;
    std::cout << a.dia() << "/" << a.mes() << "/" << a.anno() << std::endl;
    a = a - 5;
    std::cout << "a - 5:" << endl;
    std::cout << a.dia() << "/" << a.mes() << "/" << a.anno() << std::endl;
    std::cout << "++a:" << endl;
    ++a;
    std::cout << a.dia() << "/" << a.mes() << "/" << a.anno() << std::endl;
    std::cout << "a++:" << endl;
    a++;
    std::cout << a.dia() << "/" << a.mes() << "/" << a.anno() << std::endl;
    --a;
    std::cout << a.dia() << "/" << a.mes() << "/" << a.anno() << std::endl;
    a--;
    std::cout << a.dia() << "/" << a.mes() << "/" << a.anno() << std::endl;

    

    return 0;
}