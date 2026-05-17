#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
    string nombre;
public:
    Persona(string nombre): nombre(nombre){
        cout << "[CONSTRUCTOR Clase Persona] Inicializa nombre: "<< this->nombre<< endl;
    }
    string getNombre() {
        return this->nombre;
    }
    ~Persona(){
    cout << "[DESTRUCTOR Clase Persona]" << endl;
    }
};

class Alumno : public Persona {
private:
    int edad;
    int legajo;
public:
    Alumno(string nombre, int edad, int legajo): Persona(nombre), legajo(legajo){
        cout << "[CONSTRUCTOR Clase Alumno] Parametros recibidos: "
        << nombre <<", "<< edad <<", "<< legajo << endl;
        cout << "[CONSTRUCTOR Clase Alumno] Inicializa legajo: "<< this->legajo <<endl;
        validacionEdad(edad);
    }
    void validacionEdad(int edad){
        if (edad >= 0 && edad <= 120) {
            this->edad = edad;
            cout << "[VALIDACION] Edad valida. Se asigna "<< this->edad << endl;
        }
        else {
            this->edad = 0;
            cout << "[VALIDACION] Edad invalida. Se asigna 0" << endl;
        }     
    }
    void mostrarDatos() {
        cout << "--- Atributos de objeto --- "<< endl;
        cout << "Nombre: " << getNombre() << endl; 
        cout << "Edad: " << this->edad << endl;
        cout << "Legajo " << this->legajo << endl;
        cout << "--------------------------- "<< endl;
    }
    ~Alumno(){
        cout << "[DESTRUCTOR Clase Alumno]" << endl;
    }
};

int main() {
    Alumno a1("Juan", 5, 23117);
    a1.mostrarDatos();

    return 0;
}