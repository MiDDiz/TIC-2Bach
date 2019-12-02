#include <iostream>
using namespace std;
void mayor(float n1, float n2){
  if (n1>n2)
    cout << n1 << " es mayor"<< "\n";
  else if (n2>n1)
    cout << n2 << " es mayor"<< "\n";
       else
        cout << "son iguales" << "\n";

}
int main() {
  float num1, num2;
  std::cout << "Dime un numero:" << '\n';
  std::cin >> num1;
  std::cout << "Dame otro:" << '\n';
  std::cin >> num2;
  mayor(num1, num2);

  return 0;
}
