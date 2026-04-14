#include <iostream>

using namespace std;

struct Punto{
    int x, y;

    // Sobrecarga de operador
    Punto operator+(const Punto &otro){
        Punto resultado;

        resultado.x = x + otro.x;
        resultado.y = y + otro.y;
        return resultado;
    }
};

int main(){
    Punto a={2,3};
    Punto b={4,5};

    Punto c = a + b;
    cout <<"Resultado de suma: " << c.x << ", " << c.y << endl;

    return 0;
}

