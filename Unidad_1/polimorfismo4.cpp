#include <iostream>

using namespace std;

// Clase base
class Animal {
public:
    // Metodo virtual
    virtual void hacerSonido() {
        cout << "El animal hace un sonido" << endl;
    }
};
// Clase derivada
class Perro : public Animal {
public:
    // Sobrescribe el metodo de Animal
    void hacerSonido() override {
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