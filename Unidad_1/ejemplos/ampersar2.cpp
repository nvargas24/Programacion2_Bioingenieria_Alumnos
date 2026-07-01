#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 87;

    int &ref = a;
    int &otro = b;

    // Direcciones
    cout << "Direcciones" << endl;
    cout << "Direccion 'ref': " << &ref << endl;
    cout << "Direccion de 'a': " << &a << endl;
    cout << "Direccion 'otro': " << &otro << endl;
    cout << "Direccion de 'b': " << &b << endl;

    // Antes de modificar
    cout << "-----------------" << endl;
    cout << "Valores antes de modificar" << endl;
    cout << "Valor de 'a': " << a << endl;
    cout << "Valor de 'b': " << b << endl;

    // Modifico atra vez del alias
    ref = 64;
    otro = 12;

    // Despues
    cout << "-----------------" << endl;
    cout << "Valores despues de modificar" << endl;
    cout << "Nuevo valor de 'a': " << a << endl;
    cout << "Nuevo valor de 'b': " << b << endl;

    return 0;
}

