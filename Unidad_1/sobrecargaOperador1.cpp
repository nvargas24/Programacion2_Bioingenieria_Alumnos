#include <iostream>

using namespace std;

struct Vector{
    int x, y;

    // Sobrecarga de operador
    Vector operator+(const Vector &otro){
        Vector resultado;

        resultado.x = x + otro.x;
        resultado.y = y + otro.y;
        return resultado;
    }
};

int main(){
    Vector a={2,3};
    Vector b={4,5};

    Vector c = a + b;
    cout <<"Resultado de suma: " << c.x << "; " << c.y << endl;

    return 0;
}

