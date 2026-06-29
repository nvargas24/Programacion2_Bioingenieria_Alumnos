#include <iostream>
using namespace std;

class Animal {
private:
    int edad; // atributo privado 

public:
    // Setter - Modifica atributo privado
    bool setEdad(int e){
        if(e>0 && e<20){
            edad = e;
            cout<< "Edad seteada valida" << endl;
        }
        else{
            cout<< "Edad seteada no valida" << endl;
            return false;
        } 
        return true;
    }
    // Getter - Extrae valor de atributo privado
    int getEdad(){
        return edad;
    }
};

int main() {
    Animal gato; // creo objeto

    if(gato.setEdad(35)){// acceso a atributo privado
        cout<< "Edad de gato: " << gato.getEdad() << " anios"<<endl; 
    }

    return 0;
}

