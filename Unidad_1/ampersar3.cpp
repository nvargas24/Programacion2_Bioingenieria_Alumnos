#include <iostream>
using namespace std;

// Función por referencia (NO copia)
void actualizar(int &valor) {
    cout << "[actualizar] Direccion recibida: " << &valor << endl;
    valor += 10;
}

// Función por valor (SI copia)
void copiar(int valor) {
    cout << "[copiar] Direccion recibida: " << &valor << endl;
    valor += 10;
}

int main() {
    int a = 10;
    int b = 87;

    cout << "Direcciones en main" << endl;
    cout << "Direccion de a: " << &a << endl;
    cout << "Direccion de b: " << &b << endl;
    cout << "-----------------" << endl;

    actualizar(a);
    copiar(b);

    cout << "-----------------" << endl;
    cout << "Valores despues" << endl;
    cout << "a (referencia): " << a << endl;
    cout << "b (copia): " << b << endl;

    return 0;
}