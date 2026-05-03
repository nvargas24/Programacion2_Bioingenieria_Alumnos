#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    Persona(string nombre, int edad) {
        this->nombre = nombre;
        this->edad = edad;
    }

    // Compara edades con otra persona
    void compareEdad(Persona& otro) {
        if (this->edad > otro.edad) {
            cout << this->nombre << " es mayor que " << otro.nombre << endl;
        } else {
            cout << this->nombre << " no es mayor que " << otro.nombre << endl;
        }
    }
};

int main() {
    Persona p1("Felipe", 30);
    Persona p2("Eduardo", 82);

    p1.compareEdad(p2);             // p1 es "this", p2 es "otro"
    p2.compareEdad(p1);              // p2 es "this", p1 es "otro"

    return 0;
}



