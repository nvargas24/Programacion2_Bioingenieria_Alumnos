#include <iostream>
using namespace std;

// Clase base
class Animal {
public:
    void comer() {
        cout << "El animal come" << endl;
    }
};

// Clase derivada
class Perro : public Animal {
public:
    void ladrar() {
        cout << "El perro ladra" << endl;
    }
};

int main() {
    Perro p;
    p.comer();   // heredado
    p.ladrar();  // propio
}

