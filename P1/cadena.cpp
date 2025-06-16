#include "cadena.hpp"

//definicion del atributo static
char Cadena::vacia[1] = {'\0'};

//constructor por defecto
Cadena::Cadena(size_t t, char c) : tam_(t), s_(vacia) {
    if (t == 0) {
        s_ = vacia;
    } else {
        s_ = new char[t + 1];
        for (size_t i = 0; i < t; ++i) {
            s_[i] = c;
        }
        s_[t] = '\0'; // Aseguramos que la cadena esté terminada en nulo
    }
}

//construcor const char*
Cadena::Cadena(const char* str){
    tam_ = std::strlen(str);
    s_ = new char[tam_ + 1];
    std::strcpy(s_, str);
    s_[tam_] = '\0'; // Aseguramos que la cadena esté terminada en nulo
}

//constructor de copia
Cadena::Cadena(const Cadena& c) : tam_(c.tam_) {
    if (tam_ == 0) {
        s_ = vacia;
    } else {
        s_ = new char[tam_ + 1];
        std::strcpy(s_, c.s_);
        s_[tam_] = '\0'; // Aseguramos que la cadena esté terminada en nulo
    }
}

//constructor de movimiento
Cadena::Cadena(Cadena&& otra) noexcept : tam_(otra.tam_), s_(otra.s_) {
    // Dejar 'otra' en estado válido
    otra.s_ = vacia;
    otra.tam_ = 0;
}

//operador ==
bool operator ==(const Cadena& cad1, const Cadena& cad2){
    if (cad1.tam_ != cad2.tam_) {
        return false;
    }else{
        for (size_t i = 0; i < cad1.tam_; ++i) {
            if (cad1.s_[i] != cad2.s_[i]) {
                return false;
            }
        }
        return true;
    } 
}

//operador menor que
bool operator <(const Cadena& Cad1, const Cadena& Cad2) {
    size_t minLength = std::min(Cad1.tam_, Cad2.tam_);
    for (size_t i = 0; i < minLength; ++i){
        if (Cad1.s_[i] < Cad2.s_[i]) {
            return true;
        } else if (Cad1.s_[i] > Cad2.s_[i]) {
            return false;
        }
    }
    return Cad1.tam_ < Cad2.tam_; // Si son iguales hasta el minLength, el menor es el más corto (que no debería ocurrir nunca)	
}

//funcion at [] controla el indice sea valido dentro de tam_
char& Cadena::at(size_t index) const {
    if (index >= tam_ || index < 0) {
        throw std::out_of_range("Indice fuera de limite");
    }
    return s_[index];
}
char& Cadena::at(size_t index) {
    if (index >= tam_ || index < 0) {
        throw std::out_of_range("Indice fuera de limite");
    }
    return s_[index];
}

//metodo substr devuelve una subCadena especificada
Cadena Cadena::substr(size_t index, size_t tama) const {
    if (index > tam_ || tama > tam_ || index + tama > tam_) {
        throw std::out_of_range("Indice fuera de limite");
    }
    Cadena subCadena(tama);
    for (size_t i = 0; i < tama; ++i) {
        subCadena[i] = s_[i + index];
    }
    // No necesitas añadir el terminador nulo aquí, ya se hace en el constructor
    return subCadena;
}

Cadena& Cadena::operator=(const Cadena& otra) {
if (this != &otra) { // (diferente localización en memoria) Evitar autoasignación
    // Guardar puntero y tamaño original por si falla la asignación
    char* s_temp = s_;
    size_t tam_temp = tam_;
    
    try {
        // Crear nuevo buffer si es necesario
        if (otra.tam_ > 0) {
            s_ = new char[otra.tam_ + 1];
            std::strcpy(s_, otra.s_);
            tam_ = otra.tam_;
            s_[tam_] = '\0';
        } else {
            s_ = vacia;
            tam_ = 0;
        }
        
        // Si llegamos aquí, la asignación fue exitosa, liberamos la memoria antigua
        if (s_temp != vacia) {
            delete[] s_temp;
        }
    } catch (...) {
        // En caso de error, restauramos el estado original
        s_ = s_temp;
        tam_ = tam_temp;
        // No hacer nada más, conservamos el contenido original
    }
}

return *this;
}

// Implementación del operador de asignación para cadenas de C
Cadena& Cadena::operator=(const char* str) {
    // Guardar puntero y tamaño original por si falla la asignación
    char* s_temp = s_;
    size_t tam_temp = tam_;
    
    try {
        // Obtener tamaño de la cadena C
        size_t nueva_tam = std::strlen(str);
        
        // Crear nuevo buffer si es necesario
        if (nueva_tam > 0) {
            s_ = new char[nueva_tam + 1];
            std::strcpy(s_, str);
            tam_ = nueva_tam;
            s_[tam_] = '\0';
        } else {
            s_ = vacia;
            tam_ = 0;
        }
        
        // Si llegamos aquí, la asignación fue exitosa, liberamos la memoria antigua
        if (s_temp != vacia) {
            delete[] s_temp;
        }
    } catch (...) {
        // En caso de error, restauramos el estado original
        s_ = s_temp;
        tam_ = tam_temp;
        // No hacer nada más, conservamos el contenido original
    }
    return *this;
}

// Operador += para concatenación
Cadena& Cadena::operator+=(const Cadena& otra) {
    if (otra.tam_ > 0) { // Solo proceder si la otra cadena no está vacía
        // Guardar estado original en caso de fallo
        char* s_temp = s_;
        size_t tam_temp = tam_;
        
        try {
            // Crear nuevo buffer con espacio para ambas cadenas
            size_t nueva_tam = tam_ + otra.tam_;
            char* nuevo = new char[nueva_tam + 1];
            
            // Copiar cadena original y concatenar la nueva
            if (tam_ > 0)
                std::strcpy(nuevo, s_);
            else
                nuevo[0] = '\0';
                
            std::strcat(nuevo, otra.s_);
            
            // Actualizar miembros
            s_ = nuevo;
            tam_ = nueva_tam;
            
            // Liberar memoria original si no es la cadena vacía
            if (s_temp != vacia) {
                delete[] s_temp;
            }
        } catch (...) {
            // En caso de error, restaurar estado original
            s_ = s_temp;
            tam_ = tam_temp;
            // No hacer nada más, conservar el contenido original
        }
    }
    
    return *this;
}

// Operador + para concatenar dos cadenas (no modifica las originales)
Cadena operator+(const Cadena& cad1, const Cadena& cad2) {
    Cadena resultado(cad1);  // Crear copia de la primera cadena
    resultado += cad2;       // Usar el operador += para añadir la segunda
    return resultado;
}

// Sobrecarga del operador de extracción >> para leer una cadena desde un flujo de entrada

std::ostream& operator<<(std::ostream& os, const Cadena& cadena) {
    os << cadena.s_;
    return os;
}

//operador de extracción de cadena
std::istream& operator>>(std::istream& is, Cadena& cadena) {
    char buffer[33]; // Buffer para almacenar 32 caracteres + '\0'
    char caracter;
    size_t i = 0;

    //saltar ' ' iniciales
    while (is.get(caracter) && std::isspace(caracter)) {
        // No hacer nada, solo saltar los espacios
    }

    if (is.eof()){ // si se llega al final del archivo sin encontrar palabra
        cadena = cadena.vacia; // Asignar cadena vacía si se llega al final del archivo
        return is;
    }

    // Primer carácter válido (no espacio), lo devolvemos al flujo
    is.unget(); // Devolver el último caracter leído al flujo
    
    //Leer la palabra carácter a carácter
    while (i < 32 && is.get(caracter) && !std::isspace(caracter)) {
        buffer[i++] = caracter; // Almacenar el caracter en el buffer
    }

    // Si salimos por espacio, lo devolvemos al flujo para no consumirlo
    if (!is.eof() && std::isspace(caracter)) {
        is.unget();
    }

    buffer[i] = '\0'; // Terminar la cadena con '\0'
    cadena = Cadena(buffer); // Asignar el buffer a la cadena

    return is; // Devolver el flujo de entrada
}   

// Operador de asignación por movimiento
Cadena& Cadena::operator=(Cadena&& otra) noexcept {
    if (this != &otra) {
        if (s_ != vacia) {
            delete[] s_;
        }
        tam_ = otra.tam_;
        s_ = otra.s_;

        // Dejar 'otra' en estado válido
        otra.s_ = vacia;
        otra.tam_ = 0;
    }
    return *this;
}