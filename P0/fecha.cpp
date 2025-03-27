#include "fecha.hpp"
//constantes públicas
const int Fecha::AnnoMinimo = 1902;
const int Fecha::AnnoMaximo = 2037;

//Constructor
Fecha::Fecha(int d, int m, int a):dia_(d),mes_(m),anno_(a), actual(false) { //lista de inicialización
    

    std::time_t tiempo_calendario = std::time(nullptr); //time_t es un tipo de dato que representa el tiempo en segundos desde el 1 de enero de 1970
    std::tm* tiempo_descompuesto = std::localtime(&tiempo_calendario); //tm apunta a una estructura que contiene la fecha y hora actual
    if(d == 0) dia_ = tiempo_descompuesto->tm_mday; //tm_mday es el día del mes (1-31)
    if(m == 0) mes_ = tiempo_descompuesto->tm_mon + 1; //tm_mon es el mes del año (0-11)
    if(a == 0) anno_ = tiempo_descompuesto->tm_year + 1900; //tm_year es el año desde 1900 se le suma 1900 porque tm_year es el año desde 1900 y no desde 0        
    
    valida(dia_, mes_, anno_);
}
//Constructor de conversión
Fecha::Fecha(const char* cadena): actual(false){
    int d,m,a;
    sscanf(cadena,"%d/%d/%d", &d, &m, &a);
    dia_ = d;
    mes_ = m;
    anno_ = a;

    std::time_t tiempo_calendario = std::time(nullptr); //time_t es un tipo de dato que representa el tiempo en segundos desde el 1 de enero de 1970
    std::tm* tiempo_descompuesto = std::localtime(&tiempo_calendario); //tm apunta a una estructura que contiene la fecha y hora actual
    if(d == 0) dia_ = tiempo_descompuesto->tm_mday; //tm_mday es el día del mes (1-31)
    if(m == 0) mes_ = tiempo_descompuesto->tm_mon + 1; //tm_mon es el mes del año (0-11)
    if(a == 0) anno_ = tiempo_descompuesto->tm_year + 1900; //tm_year es el año desde 1900 se le suma 1900 porque tm_year es el año desde 1900 y no desde 0        
    valida(dia_, mes_, anno_);

}

bool es_bisiesto(int a){
    return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}

int dias_mes(int m, int a){
    int dias = 0;
    switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            dias = 31;
            break;
        case 4: case 6: case 9: case 11:
            dias = 30;
            break;
        case 2:
            if (es_bisiesto(a)) {
                dias = 29;
            }
            else {
                dias = 28;
            }
            break;
    }
    return dias;
}

bool valida(int d, int m, int a){
    if (m < 1 || m > 12) {
        throw Fecha::Invalida("Mes no válido");
    }
    if (d < 1  || d > dias_mes(m, a)) {
        throw Fecha::Invalida("Día no válido");
    }
    if (a!=0 && (a < Fecha::AnnoMinimo || a > Fecha::AnnoMaximo)) {
        throw Fecha::Invalida("Año no válido");
    }
    

    return true;

}

Fecha& Fecha::operator+=(int n){
    std::time_t tiempo_calendario = std::time(nullptr); //time_t es un tipo de dato que representa el tiempo en segundos desde el 1 de enero de 1970
    std::tm* tiempo_descompuesto = std::localtime(&tiempo_calendario); //tm apunta a una estructura que contiene la fecha y hora actual
    tiempo_descompuesto->tm_mday = dia_;
    tiempo_descompuesto->tm_mon = mes_ - 1;
    tiempo_descompuesto->tm_year = anno_ - 1900;
    tiempo_descompuesto->tm_mday += n;
    std::mktime(tiempo_descompuesto);
    dia_ = tiempo_descompuesto->tm_mday;
    mes_ = tiempo_descompuesto->tm_mon + 1;
    anno_ = tiempo_descompuesto->tm_year + 1900;
    actual=false;
    valida(dia_, mes_, anno_);
    return *this;
}

#include <locale>

Fecha::operator const char*() const{
    if (!actual){
        std::locale::global(std::locale("es_ES.UTF-8"));
        std::tm tiempo_descompuesto = {0};
        tiempo_descompuesto.tm_mday = dia_;
        tiempo_descompuesto.tm_mon = mes_ - 1;
        tiempo_descompuesto.tm_year = anno_ - 1900;
        std::mktime(&tiempo_descompuesto);
        std::strftime(cadena, 40, "%A %d de %B de %Y", &tiempo_descompuesto);
        actual = true;
    }
    return cadena;
}