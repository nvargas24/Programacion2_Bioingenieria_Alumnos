#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int &ref = a;

    // Uso 1: obtener dirección de memoria
    cout << "Valor de 'a': " << a << endl;
    cout << "Direccion de 'a': " << &a << endl;

    // Uso 2: referencia (alias)
    ref = 20;  // modifica directamente 'a'

    cout << "Nuevo valor de 'a': " << a << endl;

    return 0;
}

