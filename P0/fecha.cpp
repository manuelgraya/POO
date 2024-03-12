#include "fecha.hpp"
#include <iostream>

using namespace std;

void Fecha::verificardia(int d){

    if (d < 0 || d >31 ){
        throw Invalida("Día inválido");
    }

    if ((mes_ == 4 || mes_ == 6 || mes_ == 9 || mes_ == 11) && d > 30){// si el mes es abril, junio, septiembre o noviembre y el día es mayor a 30
        throw Invalida("Día inválido");
    }

    if ((mes_ == 2 && d > 29) || (mes_ == 2 && anio_%4!=0 && dia_ == 29 && (anio_%100 != 0 || anio_%400 == 0)) ){// si el mes es febrero y el año no es bisiesto y el día es 29
        throw Invalida("Día inválido");
    }

    if ((mes_ == 2 && d > 29) || (mes_ == 2 && anio_%4!=0 && dia_ == 29 && (anio_%100 != 0 || anio_%400 == 0)) ){// si el mes es febrero y el año no es bisiesto y el día es 29
        throw Invalida("Día inválido");
    }

}

void Fecha::verificarmes(int m){
    if (m < 0 || m > 12) {// si el mes es menor a 0 o mayor a 12
        throw Invalida("Mes inválido");// lanza excepción
    }
}

void Fecha::verificaranio(int a){
    if (a < AnnoMinimo || a > AnnoMaximo) {// si el año es menor a 1902 o mayor a 2037
        throw Invalida("Año inválido");    // lanza excepción
    }
}



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

Fecha::Fecha(int d, int m, int a): dia_(d), mes_(m), anio_(a){ // constructor de la clase Fecha con 3 parametros de entrada
    verificardia(d);
    verificarmes(m);
    verificaranio(a);
    dia_ = (d == 0) ? tiempo_descompuesto->tm_mday : d;
    mes_ = (m == 0) ? tiempo_descompuesto->tm_mon+1 : m; // si el mes es 0, asigna el mes actual del tiempo descompuesto al atributo mes_
    anio_ = (a == 0) ? tiempo_descompuesto->tm_year+1900 : a;
}

Fecha::Fecha(const char* s){ // constructor de la clase Fecha con un parametro de entrada de tipo char

    int d, m, a;
    if (sscanf(s, "%d/%d/%d" , &d, &m, &a)==3){ // sscanf devuelve el numero de items que lee
        verificardia(d);
        verificarmes(m);
        verificaranio(a);
        dia_ = (d == 0) ? tiempo_descompuesto->tm_mday : d;
        mes_ = (m == 0) ? tiempo_descompuesto->tm_mon+1 : m;
        anio_ = (a == 0) ? tiempo_descompuesto->tm_year+1900 : a;
    }else{
        throw Invalida("Formato inválido");
    }

}

/*------------------------------------------------------OPERADORES------------------------------------------------------------------------*/

Fecha& Fecha::operator +=(int n){
    tiempo_descompuesto->tm_mday += n; // suma n días al día actual del tiempo descompuesto 
    std::mktime(tiempo_descompuesto); // convierte el tiempo descompuesto a tiempo calendario 
    dia_ = tiempo_descompuesto->tm_mday; // asigna el día del tiempo descompuesto al atributo dia_
    mes_ = tiempo_descompuesto->tm_mon+1; // asigna el mes del tiempo descompuesto al atributo mes_
    anio_ = tiempo_descompuesto->tm_year+1900; // asigna el año del tiempo descompuesto al atributo anio_
    
    verificardia(dia_); // verifica que el día sea válido
    verificarmes(mes_); // verifica que el mes sea válido
    verificaranio(anio_); // verifica que el año sea válido
    
    return *this;
}

Fecha& Fecha::operator -=(int n){ // sobrecarga del operador -=

    return *this += -n; // llama al operador += con el valor negativo de n
}

Fecha Fecha::operator +(int n)const{ // sobrecarga del operador +
    Fecha f(*this); // crea un objeto de la clase Fecha con el valor de this
    return f += n; // llama al operador += con el valor de n
}

Fecha Fecha::operator -(int n)const{ // sobrecarga del operador -
    Fecha f(*this); // crea un objeto de la clase Fecha con el valor de this
    return f -= n; // llama al operador -= con el valor de n
}

Fecha& Fecha::operator ++(){ //(++f) sobrecarga del operador ++ 
    return *this += 1; // llama al operador += con el valor de 1
}

Fecha Fecha::operator ++(int){ //(f++) sobrecarga del operador ++
    Fecha f(*this); // crea un objeto de la clase Fecha con el valor de this
    *this += 1; // llama al operador += con el valor de 1
    return f; // retorna el objeto f
}

Fecha& Fecha::operator --(){
    return *this -= 1; // llama al operador -= con el valor de 1
}

Fecha Fecha::operator --(int){
    Fecha f(*this); // crea un objeto de la clase Fecha con el valor de this
    *this -= 1; // llama al operador -= con el valor de 1
    return f; // retorna el objeto f 
}

/*------------------------------------------------------OPERADORES LOGICOS------------------------------------------------------------*/