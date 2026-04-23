#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> cola;

    // carga elementos
    cola.push(10);
    cola.push(20);
    cola.push(30);

    cout << "Primer elemento: " << cola.front() << endl; // 10
    cout << "Ultimo elemento: " << cola.back() << endl; // 30
    cout << " ---------------"<< endl;
    
    // elimina primer elemento
    cola.pop(); // 10

    cout << "Nuevo Primer elemento: " << cola.front() << endl; // 20

    return 0;
}

