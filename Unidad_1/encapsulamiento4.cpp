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

    for(int i=0; i<4; i++){
        if(gato.setEdad(6+i)){// acceso a atributo privado
            if(i==0){
                cout<< "Edad ingresada de gato: "<< gato.getEdad() << " años"<<endl;
            }
            else{
                cout<< "Edad de gato +"<< i << ": "<< gato.getEdad() << " años"<<endl; 
            }
        }
    }

    return 0;
}

