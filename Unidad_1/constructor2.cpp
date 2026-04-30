#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    // Constructor sobrecargado
    Persona() {
        nombre = "Sin nombre";
        edad = 0;
    }
    Persona(string n) {
        nombre = n;
        edad = 0;
    }
    Persona(string n, int e) {
        nombre = n;
        edad = e;
    }

    void mostrar() {
        if (edad == 0)
            cout << nombre << endl;
        else
            cout << nombre << " - " << edad << endl;
    }
};

int main() {
    Persona p1;
    Persona p2("Felipe");
    Persona p3("Carlos", 27);

    p1.mostrar();
    p2.mostrar();
    p3.mostrar();
}

