#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    string nombre;
    int edad;
public:
    Animal(string n, int e) {
        nombre = n;
        edad = e;
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
    Perro(string n, int e, string r) : Animal(n, e) {
        raza = r;
    }
    void mostrarInfo() {
        cout << "--- PERRO ---" << endl;
        Animal::mostrarInfo();
        cout << "Raza: " << raza << endl;
    }
    void hacerSonido() {
        cout << "El perro ladra: Guau Guau!" << endl;
    }
};

class Gato : public Animal {
private:
    int vidas;
public:
    Gato(string n, int e, int v) : Animal(n, e) {
        vidas = v;
    }
    void mostrarInfo() {
        cout << "--- GATO ---" << endl;
        Animal::mostrarInfo();
        cout << "Vidas: " << vidas << endl;
    }
    void hacerSonido() {
        cout << "El gato maulla: Miau!" << endl;
    }
};

class Pajaro : public Animal {
private:
    bool vuela;
public:
    Pajaro(string n, int e, bool v) : Animal(n, e) {
        vuela = v;
    }
    void mostrarInfo() {
        cout << "--- PAJARO ---" << endl;
        Animal::mostrarInfo();
        cout << "Puede volar: ";
        if(vuela)
            cout << "Si" << endl;
        else
            cout << "No" << endl;
    }
    void hacerSonido() {
        cout << "El pajaro canta: Pio Pio!" << endl;
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
void presentar(Pajaro p) {
    p.mostrarInfo();
    p.hacerSonido();
    cout << endl;
}
int main() {
    Perro perro1("Toby", 5, "Labrador");
    Gato gato1("Michi", 3, 7);
    Pajaro pajaro1("Piolin", 1, true);

    presentar(perro1);
    presentar(gato1);
    presentar(pajaro1);

    return 0;
}