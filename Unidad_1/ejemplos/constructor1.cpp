#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;

public:
    // Constructor
    Persona(string n) {
        nombre = n;
    }

    void saludar() {
        cout << "Hola, soy " << nombre << endl;
    }
};

int main() {
    Persona p("Felipe"); // Se llama al constructor
    p.saludar();
    return 0;
}

