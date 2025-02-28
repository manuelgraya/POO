#include "cadena.hpp"

Cadena::Cadena(int t, char c) : tam_(t), s_(new char[t + 1]) {
    std::fill_n(s_, t, c);
    s_[t] = '\0';
}

std::ostream& operator<<(std::ostream& os, const Cadena& cadena) {
    os << cadena.s_;
    return os;
}

int main() {
    Cadena a(3, 'A');
    std::cout << a;
    std::cin.get();
}