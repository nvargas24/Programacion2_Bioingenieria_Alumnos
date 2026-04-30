#include <iostream>
using namespace std;

// Clase base
class Animal {
private:
    string nombre;

public:
    Animal(string n) {
        nombre = n;
    }

    string getNombre() {
        return nombre;
    }
};

// Clase derivada
class Perro : public Animal {
private:
    string raza;

public:
    Perro(string n, string r) : Animal(n) {
        raza = r;
    }
    void mostrar() {
        cout << "Nombre: " << getNombre() << endl;
        cout << "Raza: " << raza << endl;
    }
};

int main() {
    Perro p("Firulais", "Labrador");
    p.mostrar();
    return 0;
}
