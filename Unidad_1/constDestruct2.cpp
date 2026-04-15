#include <iostream>
using namespace std;

int main(){
    // Memoria estática
    int a = 10;

    // Memoria dinámica
    int* ptr = new int;
    *ptr = 20;

    cout << "Valores:" << endl;
    cout << "a = " << a << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "-----------------------------" << endl;

    cout << "Direcciones de memoria" << endl;
    cout << "'a' (estatica): " << &a << endl;
    cout << "'ptr' (dinamica): " << ptr << endl;

    delete ptr;
    ptr = nullptr;

    return 0;
}

