#include <iostream>
using namespace std;

class Animal {
private:
    int edad; // atributo privado 

public:
    // Setter - Modifica atributo privado
    void setEdad(int e){
        edad = e;
    }
    // Getter - Extrae valor de atributo privado
    int getEdad(){
        return edad;
    }
};

int main() {
    Animal gato; // creo objeto

    gato.setEdad(35); // acceso a atributo privado

    cout<< "Edad de gato: " << gato.getEdad() << " años"<<endl; 
    
    return 0;
}

