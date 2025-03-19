#include "cadena.hpp"

//definicion del atributo static
char Cadena::vacia[1] = {'\0'};

Cadena::Cadena(size_t t, char c) : tam_(t), s_(vacia) {
    s_ = new char[tam_ + 1];
    std::memset(s_, c, tam_);
    s_[tam_] = '\0';
}

std::ostream& operator<<(std::ostream& os, const Cadena& cadena) {
    os << cadena.s_;
    return os;
}

// int main() {
//     Cadena a(3, 'A');
//     std::cout << a;
//     std::cin.get();
// }