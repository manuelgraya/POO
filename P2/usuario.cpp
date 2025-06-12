#include "usuario.hpp"

#include "usuario.hpp"
#include <unistd.h>         // crypt()
#include <random>           // random_device, mt19937, uniform_int_distribution
#include <cstring>          // strcmp
#include <string>
#include <sstream>
#include <iomanip>

const char Clave::caracteres_validos[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";

  Clave::Clave (const char * contrasena) : clave_(contrasena) {
    if(std::strlen(contrasena) < 5) {
        throw Incorrecta(CORTA);
    }

    //GENERAR CLAVE CIFRADO
    static std::random_device rd; // Generador de números aleatorios
    static std::mt19937 gen(rd()); // Motor de generación
    static const std::size_t n = sizeof(caracteres_validos) - 1; // Tamaño del conjunto de caracteres válidos
    std::uniform_int_distribution<std::size_t> uniforme(0, n - 1);

    char salt[3] = {
        caracteres_validos[uniforme(gen)],
        caracteres_validos[uniforme(gen)],
        '\0' // Terminador de cadena
    };
    // char* cifrado = fake_crypt(contrasena, salt); //para windows se crea fake crypt, en el docker se puede usar crypt() directamente
    char* cifrado = crypt(contrasena, salt); //para docker
    if (cifrado == nullptr) {
        throw Incorrecta(ERROR_CRYPT);
    }
    clave_ = Cadena(cifrado);
  }

  char* fake_crypt(const char* password, const char* salt) {
  static std::string resultado;
  std::ostringstream oss;
  oss << salt << '_' << password << "_hashed"; // Simulación
  resultado = oss.str();
  return const_cast<char*>(resultado.c_str());
  }
  
  bool Clave::verifica(const char* claro) const
  {
    if (claro != nullptr)
    {
      const char* clave1 = crypt(claro, (const char*)clave_);
      return clave1 == clave_;
    }
    else
    {
      throw Clave::Incorrecta(ERROR_CRYPT);
    }
  }