#include <iostream>
using namespace std;

// Prototipo de funciones
int multiplicar(int, int);
int multiplicar(int, int, int);

int main() {
    cout << multiplicar(10, 2) <<endl;
    cout << multiplicar(5, 6, 4) <<endl;
    
    return 0;
}

// Funciones sobrecargadas por num parametros
int multiplicar(int a, int b){
    return a*b;
}
int multiplicar(int a, int b, int c){
    return a*b*c;
}
