/*  
    Queda cutre decirlo con un pequeño programa pero es buena practica xd:
    License CC-BY-SA for www.github.com/MiDDiz or Joan Carlos Naftanaila
    Last C++ excercise from my CS assignature.
    You can watch some others repos on https://www.github.com/MiDDiz or in https://middiz.github.io/main
*/
#include <iostream>
using namespace std;
double balance = 2000; //Balance es global para solucionar quebraderos de cabeza y tener que pasarlo de una funcion a otra :)
void opciones();
//La mayoria de esta funcion es simplemente 'decorativa'\
  Se usa para que el programa se pause y no escupa lineas de texto sin que se entere el usuario.\
  Esto tambien genera un bug ya que si podes un caracter que pueda valer en las opciones y acto despues otro igual lo tomara como\
  si fueran caracteres introducidos individualmente -> La estetica pesa mas que este bug asi que se queda :D
void volverAlMenu(){
    char foo;
    cout << "Pulsa enter para volver al menu..." << endl;
    foo = getchar();
    cin.ignore();
    opciones();
}
//Bastante autoexplicativo, aqui vemos la utilidad de volverAlMenu en accion
void verSaldo(){
    
    cout << "Ver saldo..." << endl;
    cout << "Tu saldo total es de: $" << balance << endl;
    volverAlMenu();
}
//Para comprobar si nuestro dinero es menor al que queremos sacar.\
Devuelve bool porque queria usarlo en el if statement de abajo
bool comprobarDinero(int dineroASacar, double balanceTotal){
    if(dineroASacar > balanceTotal) return true;
    else return false;
    return false; //Necesario por si acaso.
}
//Operaciones aritmeticas. Si el bloque if entra, el else no asi que no hay necesidad de returnear.
void billetes(int cantidad){
    if(cantidad % 20 != 0 && cantidad % 50 !=0 ) cout << "Este cajero solo dispone de billetes de 20 y de 50 por lo que no podemos continuar con la transaccion.\nDisculpe las molestias..." << endl;
    else {
        int billetesc = 0;
        int billetesv = 0;
        //La cantidad se sustraye al instante, lo de los billetes es solo algo que ocurre para el usuario.\
        Esto no da error porque se comprueba antes de que todo sea divisible por 20 minimo.
        balance-=cantidad; 
        while (cantidad != 0){
            if (cantidad % 50 == 0)
            {
                cantidad-=50;
                billetesc++;
            }else
            {
                cantidad-=20;
                billetesv++;
            }
        }
        cout << "Muchas gracias! Tome " << billetesc << " billetes de 50 y " << billetesv << " de 20" << endl;
    }
}  
void sacarDinero(){
    int cantidadASacar;
    cout << "Introduce la cantidad de dinero que quieres sacar: " <<endl;
    //Hay un bug aqui. Si introduces algo que no sea un numero el programa se vuelve loco en vez de caer asi que no puedo pillarlo con un try-catch :(
    cin >> cantidadASacar; 
    //Auto explicativo, si devuelve la funcion true es que el dinero a sacar es mayor.
    if (comprobarDinero(cantidadASacar, balance)) {
        cout << "La cantidad de dinero a sacar supera su saldo actual" << endl;
        volverAlMenu();
        return; //Para que no se ejecute el resto de codigo returneamos aqui.
    }
    cout << "Va a retirar $" << cantidadASacar << " dejando un balance total de $" 
        << balance-cantidadASacar << endl;
    //El bucle se usa para corregir errores de introduccion del teclado. Queremos que el usuario se asegure.
    while (1){ 
        cout << "Quiere continuar con la transaccion? Si (s) o No (n) ?" << endl;
        char option;
        cin >> option;
        if (option == 's'){
            cout << "Sacando $" << cantidadASacar << " ..." << endl;
            billetes(cantidadASacar);
            cout << "Transaccion finalizada." << endl;
            volverAlMenu();
            return; 
        }
        else if(option == 'n'){
            cout << "Cancelando transaccion..." << endl;
            volverAlMenu();
            return;
        }else cout << "No he entendido eso ultimo, porfavor repita..." << endl;
    }

}
void opciones(){
    char option;
    cout << "(v) - Ver saldo" << endl;
    cout << "(d) - Sacar dinero" << endl;
    cout << "(s) - Salir" << endl;
    cin >> option;
    switch (option)
    {
    case 'v':
        verSaldo();
        break;
    case 'd':
        sacarDinero();
        break;
    case 's':
        cout << "Vale, adios!" << endl;
        return;
    default:
        cout << "No he entendido eso, podrias repetirlo?" << endl;
        opciones(); //Uso de recursion para evitar loops infinitos innecesarios.
        break;
    }
 
}

int main(){
    //El bucle del programa lo maneja la recursion de opciones(). Al salir con 's' se cierran todos los switch abiertos y entra en el return 0 del main.
    
        cout << "Bienvenido a RoBankia" << endl; //Lo pillas? Roba-bankia jaja... un poco de humor no hace mal.
        cout << "Que es lo que quieres hacer hoy?\n" << endl;
        opciones();
        return 0;
}