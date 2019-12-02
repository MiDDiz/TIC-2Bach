#include <iostream>
using namespace std;
string user;
string password;
string inputUser;
string inputPassword;
int registro(){
  cout << "Introduce tu usuario: " << '\n';
  cin >> inputUser;
  cout << "Introduce tu contraseña: " << '\n';
  cin >> inputPassword;
  if (user == inputUser  && password == inputPassword){
      cout << "Usuario y contraseña correctos." << '\n';
      cout << "Bienvenido." << '\n';
      return 0;
    }else{
    cout << "Combinacion usuario y contraseña incorrectos..." << '\n';
    cout << "Revisa los credenciales y vuelve a intentarlo." << '\n';
      return 1;
  }
}

int main() {
  user = "7253";
  password = "1024";
  int loggueado = 1;
  cout << "Accediendo..." << '\n';

  while (loggueado) {
    loggueado = registro();
  }
  return 0;
}
