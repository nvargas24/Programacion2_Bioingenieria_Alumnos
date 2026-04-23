#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> d;

    // carga elementos  5 10 20
    d.push_back(10);   // al final
    d.push_back(20);
    d.push_front(5);   // al inicio

    cout << "Primer elemento: " << d.front() << endl; // 5
    cout << "Ultimo elemento: " << d.back() << endl;   // 20
    cout << "Tamanio: " << d.size() << endl;

    cout << " ---------------"<< endl;
    // elimina elementos
    d.pop_front(); // elimina 5
    d.pop_back();  // elimina 20

    cout << "Nuevo primer elemento: " << d.front() << endl; // 10

    // por índice
    cout << "Elemento en posicion 0: " << d[0] << endl;

    // Tamaño
    cout << "Tamanio: " << d.size() << endl;

    return 0;
}

