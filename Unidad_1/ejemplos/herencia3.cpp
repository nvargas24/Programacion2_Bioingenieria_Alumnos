#include <iostream>
using namespace std;

// Clase base
class Empleado {
public:
    void trabajar() {
        cout << "El empleado trabaja aqui" << endl;
    }
};

// Clase derivada
class Programador : public Empleado {
public:
    void programar() {
        cout << "El programador escribe codigo" << endl;
    }
};

int main() {
    Programador p;
    p.trabajar();
    p.programar();
    return 0;
}

