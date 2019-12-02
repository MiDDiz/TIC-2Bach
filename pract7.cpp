#include <iostream>

void calculoDeArea(float a, float b){
  std::cout << "El area de tu triangulo es: " << (a*b)/2 << '\n';
}
int main() {

  float base;
  float altura;

  std::cout << "Introduce la base de tu triangulo:" << '\n';
  std::cin >> base;
  std::cout << "Introduce la altura:" << '\n';
  std::cin >>  altura;
  calculoDeArea(base, altura);

  return 0;
}
