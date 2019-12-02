#include <iostream>
int main() {
  int n;
  int var1=0;
  int var2=1;
  std::cout << "Hasta que numero quieres realizar la sucesion?" << '\n';
  std::cin >> n;

  for(int i; i<n ; i++){
    std::cout << var1 << '\n';
    var2 = var2 + var1;
    var1 = var2 - var1;
  }

  return 0;
}
