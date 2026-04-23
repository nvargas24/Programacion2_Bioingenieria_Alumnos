#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> pila;

    // carga elementos
    pila.push(10);
    pila.push(20);
    pila.push(30);

    cout << "Ultimo elemento: " << pila.top() << endl; // 30
    cout << "Tamanio: " << pila.size() << endl;
    cout << " ---------------"<< endl;
    
    // elimino ultimo elemento
    pila.pop(); // elimina 30

    cout << "Nuevo ultimo elemento: " << pila.top() << endl; // 20
    cout << "Nuevo tamanio: " << pila.size() << endl;

    return 0;
}

