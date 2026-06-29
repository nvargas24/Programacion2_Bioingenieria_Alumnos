// correccion de this1.cpp con this
#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    // Constructor
    Persona(string nombre, int edad) {
        this->nombre = nombre; // diferencia atributo de parámetro
        this->edad = edad;
    }

    void mostrar() {
        cout << "Nombre: " << this->nombre << endl;
        cout << "Edad: " << this->edad << endl;
    }
};

int main() {
    Persona p("Carlos", 27);
    p.mostrar();
    return 0;
}

