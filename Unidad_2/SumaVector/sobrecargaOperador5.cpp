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
    miCout <<"(" << rta.x << "; " << rta.y << ")";
    return miCout;
}

istream& operator>>(istream &miCin, Vector &inVec){
    cout << "Ingrese componente 'x': ";
    miCin >> inVec.x;
    cout << "Ingrese componente 'y': ";
    miCin >> inVec.y;

    return miCin;
}

int main(){
    Vector a;
    Vector b;
    Vector c;

    cout << "Vector 'a':" <<endl;
    cin >> a;
    cout << "--------------"<<endl;

    cout << "Vector 'b':" <<endl;
    cin >> b;

    c= a + b;
    cout << "Operacion: " << a << " + "<< b << " = " << c << endl;

    return 0;
}

