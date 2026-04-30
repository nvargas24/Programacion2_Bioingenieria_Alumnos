#include <iostream>
using namespace std;

// Clase base
class Empleado {
private:
    string nombre;

public:
    Empleado(string n) {
        nombre = n;
    }

    string getNombre() {
        return nombre;
    }

    void trabajar() {
        cout << "El empleado trabaja aqui" << endl;
    }
};

// Clase derivada
class Programador : public Empleado {
private:
    string lenguaje;

public:
    Programador(string n, string l) : Empleado(n) {
        lenguaje = l;
    }

    void mostrar() {
        cout << "Nombre: " << getNombre() << endl;
        cout << "Lenguaje: " << lenguaje << endl;
    }
};

int main() {
    Programador p("Ana", "C++");
    p.trabajar();
    p.mostrar();
    return 0;
}