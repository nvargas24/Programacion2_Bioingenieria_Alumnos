#include <iostream>
#include <string>

using namespace std;

// Clase base
class Animal {
protected:
    string nombre;
    int edad;

public:
    Animal(string n, int e) {
        nombre = n;
        edad = e;
    }
    // Metodo virtual
    virtual void hacerSonido() {
        cout << "El animal hace un sonido" << endl;
    }
    // Metodo virtual
    virtual void mostrarInfo() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }
};

// Clase derivada Perro
class Perro : public Animal {
private:
    string raza;
public:
    Perro(string n, int e, string r) : Animal(n, e) {
        raza = r;
    }
    // override indica que se redefine el metodo virtual
    void hacerSonido() override {
        cout << "El perro ladra: Guau Guau!" << endl;
    }
    void mostrarInfo() override {
        cout << "--- PERRO ---" << endl;
        Animal::mostrarInfo();
        cout << "Raza: " << raza << endl;
    }
};

// Clase derivada Gato
class Gato : public Animal {
private:
    int vidas;
public:
    Gato(string n, int e, int v) : Animal(n, e) {
        vidas = v;
    }
    void hacerSonido() override {
        cout << "El gato maulla: Miau!" << endl;
    }
    void mostrarInfo() override {
        cout << "--- GATO ---" << endl;
        Animal::mostrarInfo();
        cout << "Vidas: " << vidas << endl;
    }
};

// Funcion polimorfica
void presentarAnimal(Animal* a) {
    a->mostrarInfo();
    a->hacerSonido();
    cout << endl;
}

int main() {
    Perro perro1("Toby", 5, "Labrador");
    Gato gato1("Michi", 3, 7);

    presentarAnimal(&perro1);
    presentarAnimal(&gato1);

    return 0;
}