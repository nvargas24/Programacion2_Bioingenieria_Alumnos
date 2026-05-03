#include <iostream>
using namespace std;

class Animal {
public:
    void hacerSonido() {
        cout << "El animal hace un sonido" << endl;
    }
};

class Perro : public Animal {
public:
    void hacerSonido() {
        cout << "El perro ladra" << endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() {
        cout << "El gato maulla" << endl;
    }
};

int main() {
    Animal a;
    Perro p;
    Gato g;

    a.hacerSonido();
    p.hacerSonido();
    g.hacerSonido();

    return 0;
}

