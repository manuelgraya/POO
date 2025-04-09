#include "cadena.hpp"
#include <iostream>
#include <stdexcept>

void mostrarInfo(const Cadena& cad, const char* nombre) {
    std::cout << "Cadena " << nombre << ": \"" << cad << "\", longitud: " << cad.length() << std::endl;
}

int main() {
    try {
        std::cout << "\n--- PRUEBA DE CONSTRUCTORES ---\n" << std::endl;
        
        // Constructor por defecto
        Cadena c1(5, 'a');
        mostrarInfo(c1, "c1");
        
        // Constructor a partir de const char*
        Cadena c2("Hola mundo");
        mostrarInfo(c2, "c2");
        
        // Constructor de copia
        Cadena c3(c2);
        mostrarInfo(c3, "c3 (copia de c2)");
        
        //constructor de copia implicita
        Cadena c3_2 = c2;
        mostrarInfo(c3_2, "c3_2 (copia de c2 implicita)");

        // Constructor con cadena vacía
        Cadena c4;
        mostrarInfo(c4, "c4 (vacía)");

        std::cout << "\n--- PRUEBA DE OPERADORES DE COMPARACIÓN ---\n" << std::endl;
        
        Cadena igual1("abc");
        Cadena igual2("abc");
        Cadena distinta1("abd");
        Cadena distinta2("ab");
        
        std::cout << "igual1: \"" << igual1 << "\"" << std::endl;
        std::cout << "igual2: \"" << igual2 << "\"" << std::endl;
        std::cout << "distinta1: \"" << distinta1 << "\"" << std::endl;
        std::cout << "distinta2: \"" << distinta2 << "\"" << std::endl;
        
        std::cout << "igual1 == igual2: " << (igual1 == igual2 ? "true" : "false") << std::endl;
        std::cout << "igual1 != distinta1: " << (igual1 != distinta1 ? "true" : "false") << std::endl;
        std::cout << "igual1 < distinta1: " << (igual1 < distinta1 ? "true" : "false") << std::endl;
        std::cout << "distinta1 > igual1: " << (distinta1 > igual1 ? "true" : "false") << std::endl;
        std::cout << "igual1 <= igual2: " << (igual1 <= igual2 ? "true" : "false") << std::endl;
        std::cout << "igual1 <= distinta1: " << (igual1 <= distinta1 ? "true" : "false") << std::endl;
        std::cout << "distinta1 >= igual1: " << (distinta1 >= igual1 ? "true" : "false") << std::endl;
        std::cout << "igual1 < distinta2: " << (igual1 < distinta2 ? "true" : "false") << std::endl;
        std::cout << "distinta2 < igual1: " << (distinta2 < igual1 ? "true" : "false") << std::endl;

        std::cout << "\n--- PRUEBA DE ACCESO A CARACTERES ---\n" << std::endl;
        
        Cadena palabra("Universidad");
        
        std::cout << "palabra: \"" << palabra << "\"" << std::endl;
        std::cout << "palabra[0]: " << palabra[0] << std::endl;
        std::cout << "palabra[5]: " << palabra[5] << std::endl;
        std::cout << "palabra[palabra.length() - 1]: " << palabra[palabra.length() - 1] << std::endl;
        
        // Modificar con operador []
        palabra[0] = 'u';
        palabra[5] = 'S';
        std::cout << "Después de modificar: \"" << palabra << "\"" << std::endl;
        
        // Prueba de método at()
        std::cout << "\nAcceso con at():" << std::endl;
        std::cout << "palabra.at(0): " << palabra.at(0) << std::endl;
        std::cout << "palabra.at(5): " << palabra.at(5) << std::endl;
        
        // Modificar con at()
        palabra.at(0) = 'U';
        palabra.at(5) = 's';
        std::cout << "Después de modificar con at(): \"" << palabra << "\"" << std::endl;
        
        std::cout << "\n--- PRUEBA DE EXCEPCIONES ---\n" << std::endl;
        
        try {
            std::cout << "Intentando acceder a palabra.at(" << palabra.length() << ")..." << std::endl;
            char c = palabra.at(palabra.length());
            std::cout << "¡Error! No se lanzó excepción." << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Excepción capturada correctamente: " << e.what() << std::endl;
        }
        
        try {
            std::cout << "Intentando acceder a palabra.at(-1)..." << std::endl;
            char c = palabra.at(-1);
            std::cout << "¡Error! No se lanzó excepción." << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Excepción capturada correctamente: " << e.what() << std::endl;
        }
        
        const Cadena constante("Constante");
        std::cout << "\nPrueba con objeto const:" << std::endl;
        std::cout << "constante: \"" << constante << "\"" << std::endl;
        std::cout << "constante[2]: " << constante[2] << std::endl;
        std::cout << "constante.at(3): " << constante.at(3) << std::endl;
        
        Cadena cad1("Hello World");
        std::cout << "Original: " << cad1 << std::endl;
        
        // Extract "Hello"
        Cadena sub1 = cad1.substr(0, 5);
        std::cout << "substr(0, 5): " << sub1 << std::endl;
        
        // Extract "World"
        Cadena sub2 = cad1.substr(6, 5);
        std::cout << "substr(6, 5): " << sub2 << std::endl;
        
        // Test error handling
        try {
            Cadena sub3 = cad1.substr(20, 5); // This should throw an exception
            std::cout << "This shouldn't print" << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Exception caught as expected: " << e.what() << std::endl;
        }

        Cadena cad2("Cadena de prueba");
        std::puts((const char*)cad2); // Imprime la cadena c1
        std::cout << "Cadena c1: " << cad2 << std::endl;
        std::cout << "\n--- TODAS LAS PRUEBAS COMPLETADAS CON ÉXITO ---\n" << std::endl;

        return 0;
        
    } catch (const std::exception& e) {
        std::cerr << "Error inesperado: " << e.what() << std::endl;
        return 1;
    }
}