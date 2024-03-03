#include "fecha.hpp"

Fecha::Fecha(int d, int m, int a) : dia_{d}, mes_{m}, anio_{a} { // constructor de la clase Fecha con 3 parametros de entrada
    if (a < AnnoMinimo || a > AnnoMaximo) {// si el año es menor a 1902 o mayor a 2037
        throw Invalida("Año inválido");    // lanza excepción
    }
    if (m < 0 || m > 12) { // si el mes es menor a 0 o mayor a 12
        throw Invalida("Mes inválido");// lanza excepción
    }
    if (d < 0 || d > 31) {// si el día es menor a 0 o mayor a 31
        throw Invalida("Día inválido");//lanza excepción
    }

}

Fecha::Fecha(const char* s) {
    int d, m, a;
    if (sscanf(s, "%d/%d/%d", &d, &m, &a) != 3) { // sscanf devuelve el numero de items que lee
        throw Invalida("Formato inválido"); // si no lee 3 items, el formato es inválido
    }
    *this = Fecha(d, m, a); // llama al constructor de la clase
}