// Ejemplo con error aproposito para usar this
#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;
public:
    // Constructor SIN usar this
    Persona(string nombre, int edad) {
        nombre = nombre; // asigna parámetro a sí mismo
        edad = edad; // asigna parámetro a sí mismo
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }
};

int main() {
    Persona p("Carlos", 27);
    p.mostrar(); 
    return 0;
}

