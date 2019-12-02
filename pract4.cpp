#include <iostream>
using namespace std;
int main() {
  int num;
  cout << "Introduce un numero del 1 al 10\n";
  cin >> num;
  switch(num){
    case 3:
      cout << "El 3 es multiplo";
      return 0;
    case 6:
      cout << "El 6 es multiplo";
      return 0;
    case 9:
      cout << "El 9 es multiplo";
      return 0;
  }
  cout << num << " no es multiplo";
  return 0;
}
