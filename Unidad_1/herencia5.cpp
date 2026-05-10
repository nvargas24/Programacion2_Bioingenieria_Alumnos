#include <iostream>
using namespace std;

// Clase base
class Animal {
protected:
    string raza;   // Accessible desde clases derivadas
private:
    int edad;      // Solo accesible dentro de Animal
public:
    Animal(string r, int e) {
        raza = r;
        edad = e;
    }
    int getEdad() {
        return edad;
    }
};

// Clase derivada
class Perro : public Animal {
private:
    string nombre;
public:
    Perro(string n, string r, int e) : Animal(r, e) {
        nombre = n;
    }
    void mostrar() {
        // Acceso permitido porque raza es protected
        cout << "Raza: " << raza << endl;
        // Acceso permitido mediante metodo publico
        cout << "Edad: " << getEdad() << endl;
        cout << "Nombre: " << nombre << endl;

        /*ERROR:
        edad es private en Animal
        cout << edad << endl;
        */
    }
};

int main() {
    Perro p("Firulais", "Labrador", 5);
    p.mostrar();
    return 0;
}

