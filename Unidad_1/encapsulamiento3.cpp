#include <iostream>
using namespace std;

class Animal {
private:
    int edad; // atributo privado 

public:
    // Setter - Modifica atributo privado
    int setEdad(int e){
        if(e>0 && e<50){
            edad = e;
            mostrarVal(true);
        }
        else{
            mostrarVal(false);
            return false;
        } 

        return true;
    }
    // Getter - Extrae valor de atributo privado
    int getEdad(){
        return edad;
    }

    // Muestra msj dependiendo validacion de dato
    void mostrarVal(bool flag_ok){
        if (flag_ok){
            cout<< "[INFO] Edad seteada valida" << endl;    
        }
        else{
            cout<< "[INFO] Edad seteada no valida" << endl;
        }
    }

};

int main() {
    Animal gato; // creo objeto

    if(gato.setEdad(5)){// acceso a atributo privado
        cout<< "Edad de gato: " << gato.getEdad() << " años"<<endl; 
    }

    return 0;
}

