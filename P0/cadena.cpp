#include <iostream>
 class C {
 public:
 C(int i = 0, bool al = false): n(i), hayAlerta(al) {}
 void mostrar()const{
 if(hayAlerta) alerta();
 std::cout << "i = " << n << std::endl;
 }
 private:
 int n;
 bool hayAlerta;
 void alerta() const { std::cout << "Alerta " << std::endl; }
 };
 int main() { const C c; c.mostrar(); system("pause"); return 0;}