#include <iostream>
using namespace std;

struct Vector{
    int x, y;
};
// Sobrecarga de operador con funcion externa
Vector operator*(int a, Vector &b){
    Vector resultado;
    resultado.x = a * b.x;
    resultado.y = a * b.y;
    return resultado;
}

Vector operator*(Vector &b, int a){
    return a * b;
}

int operator*(Vector &a, Vector &b){
    int resultado;
    resultado = a.x * b.x + a.y * b.y;
    return resultado;
}

int main(){
    Vector a={2,3};
    Vector b={4,5};
    Vector c = 2 * b;
    Vector d = b * 4;

    cout << "P. escalar con literal: " <<"(" << c.x << "; " << c.y << ")" << endl;
    cout << "P. escalar con literal inv.: " <<"(" << d.x << "; " << d.y << ")" << endl;
    cout << "P. escalar con vectores: " << a * b << endl;

    return 0;
}


