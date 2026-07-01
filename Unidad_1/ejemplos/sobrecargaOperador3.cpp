#include <iostream>

using namespace std;

struct Vector{
    int x, y;
};

// Sobrecarga de operador con funcion externa
Vector operator+(Vector &a, Vector &b){
    Vector resultado;

    resultado.x = a.x + b.x;
    resultado.y = a.y + b.y;
    return resultado;
}

int main(){
    Vector a={2,3};
    Vector b={4,5};

    Vector c = a + b;
    cout <<"Resultado de suma: " << c.x << ", " << c.y << endl;

    return 0;
}

