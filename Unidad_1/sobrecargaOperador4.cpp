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
ostream& operator<<(ostream &miCout, const Vector &rta){
    miCout <<"(" << rta.x << ", " << rta.y << ")"<< endl;
    return miCout;
}
int main(){
    Vector a={2,3};
    Vector b={4,5};

    Vector c = a + b;
    cout << "Resultado de suma: " << c << endl;

    return 0;
}


