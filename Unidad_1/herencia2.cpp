#include <iostream>
using namespace std;

// Clase base
class Animal {
private:
    string raza;

public:
    Animal(string r) {
        raza = r;
    }

    string getRaza() {
        return raza;
    }

    void comer() {
        cout << "El animal come" << endl;
    }
};

// Clase derivada
class Perro : public Animal {
private:
    string nombre;

public:
    Perro(string n, string r) : Animal(r) {
        nombre = n;
    }
    void ladrar(){
        cout << "El perro ladra" << endl;
    }

    void mostrar() {
        cout << "Nombre: " << getRaza() << endl;
        cout << "Raza: " << nombre << endl;
    }
};

int main() {
    Perro p("Firulais", "Labrador");
    p.mostrar();
    return 0;
}
