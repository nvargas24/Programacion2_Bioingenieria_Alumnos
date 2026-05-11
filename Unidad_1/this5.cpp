#include <iostream>
using namespace std;

// Clase base
class Empleado {
protected:
    string empresa; // atributo protected
private:
    string nombre;
public:
    Empleado(string nombre, string empresa) {
        this->nombre = nombre;
        this->empresa = empresa;
    }
    string getNombre() {
        return nombre;
    }
    void trabajar() {
        cout << "El empleado trabaja en la empresa" << endl;
        cout << endl;
    }
};

// Clase derivada
class Programador : public Empleado {
private:
    string lenguaje;
public:
    Programador(string nombre, string empresa, string lenguaje): Empleado(nombre, empresa) {
        this->lenguaje = lenguaje;
    }
    void mostrar() {
        cout << "Nombre: " << getNombre() << endl;
        // Acceso permitido porque empresa es protected
        cout << "Empresa: " << empresa << endl;
        cout << "Lenguaje: " << lenguaje << endl;
        cout << endl;
    }
    // Metodo para comparar lenguajes
    bool compareLenguaje(Programador& otro) {
        if (this->lenguaje == otro.lenguaje) {
            return true;
        }
        return false;
    }
};

int main() {
    Programador p1("Ana", "TechSoft", "C++");
    Programador p2("Luis", "CodeSystems", "C++");

    p1.mostrar();
    p2.mostrar();
    
    cout << p1.getNombre()<<" y "<< p2.getNombre();
    if (p1.compareLenguaje(p2))
        cout <<" usan el mismo lenguaje" << endl;
    else
        cout << " usan lenguajes distintos" << endl;

    return 0;
}