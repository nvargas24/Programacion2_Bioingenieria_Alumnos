#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    string nombre;
    int edad;
public:
    Animal(string n, int e): nombre(n), edad(e) {
    }
    void mostrarInfo() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }
    void hacerSonido() {
        cout << "El animal hace un sonido" << endl;
    }
};

class Perro : public Animal {
private:
    string raza;
public:
    Perro(string n, int e, string r) : Animal(n, e), raza(r) {
    }
    void mostrarInfo() {
        cout << "--- PERRO ---" << endl;
        Animal::mostrarInfo();
        cout << "Raza: " << raza << endl;
    }
    void hacerSonido() {
        cout << "El perro ladra" << endl;
    }
};

class Gato : public Animal {
private:
    string color;
public:
    Gato(string n, int e, string c) : Animal(n, e), color(c) {
    }
    void mostrarInfo() {
        cout << "--- GATO ---" << endl;
        Animal::mostrarInfo();
        cout << "Color: " << color << endl;
    }
    void hacerSonido() {
        cout << "El gato maulla" << endl;
    }
};

void presentar(Perro p) {
    p.mostrarInfo();
    p.hacerSonido();
    cout << endl;
}
void presentar(Gato g) {
    g.mostrarInfo();
    g.hacerSonido();
    cout << endl;
}

int main() {
    Perro perro1("Toby", 5, "Labrador");
    Gato gato1("Michi", 3, "Gris");

    presentar(perro1);
    presentar(gato1);

    return 0;
}