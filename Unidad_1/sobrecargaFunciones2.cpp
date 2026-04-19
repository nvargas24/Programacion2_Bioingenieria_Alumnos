#include <iostream>
#define ERROR -1

using namespace std;

// Prototipo de funciones
int multiplicar(int, int);
int multiplicar(int, int, int);
int multiplicar(int, int, int, int);

int main() {
    int value = multiplicar(10,2,4,6);

    if(value == ERROR){
        return 0;
    }
    else{
        cout << multiplicar(value, 5, 7) << endl;
    }
    
    return 0;
}

// Funciones sobrecargadas por num parametros
int multiplicar(int a, int b){
    return a*b;
}
int multiplicar(int a, int b, int c){
    return a*b*c;
}
int multiplicar(int a, int b, int c, int d){
    // Validacion previa a realizar operacion
    if(a<0 || b<0 || c<0 || d<0){
        cout << "[ERROR] Valor no valido" << endl;
        return ERROR;
    }
    else{
        return a*b*c*d;  
    } 
}
