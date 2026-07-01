#include <iostream>

using namespace std;

// Clase base
class Animal {
public:
    void hacerSonido() {
        cout << "El animal hace un sonido" << endl;
    }
};
// Clase derivada
class Perro : public Animal {
public:
    void hacerSonido() {
        cout << "El perro ladra: Guau!" << endl;
    }
};

int main() {
    Animal* a;
    Perro p;

    a = &p;
    a->hacerSonido();

    return 0;
}