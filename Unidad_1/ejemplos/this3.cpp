#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    // Constructor
    Persona(string nombre, int edad) {
        this->nombre = nombre;
        this->edad = edad;
    }

    // Setter para cambiar el nombre
    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }
};

int main() {
    Persona p("Felipe", 27);

    p.mostrar();

    cout << "--- Modificando nombre ---" << endl;

    p.setNombre("Carlos"); // cambio del valor original

    p.mostrar();

    return 0;
}