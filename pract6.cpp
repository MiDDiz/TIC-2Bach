#include <iostream>
using namespace std;
int main() {
  int num1, num2;
  std::cout << "Introduce el primer numero: " << '\n';
  std::cin >> num1;
  std::cout << "Introduce el segundo numero" << '\n';
  std::cin >> num2;
  for (num1; num1<num2+1; num1++){
    for (int i = 1; i<11; i++){
      std::cout << num1 << " por " << i << " da " << num1 * i << '\n';
    }
  }
  return 0;
}
