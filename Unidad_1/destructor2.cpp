#include <iostream>
using namespace std;

class Persona {
public:
    string nombre;

    Persona(string n) {
        nombre = n;
        cout << "Objeto creado: " << nombre << endl;
    }
    ~Persona() {
        cout << "Objeto destruido: " << nombre << endl;
    }
};

int main() {
    // Reserva dinámica de un objeto
    Persona* p = new Persona("Felipe");

    cout << "Usando el objeto..." << endl;

    // Liberación de memoria
    delete p;
    p=nullptr;

    return 0;
}

