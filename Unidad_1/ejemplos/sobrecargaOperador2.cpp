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

    bool operator==(const Vector &otro){
        if((x == otro.x) && (y == otro.y)){
            return true;
        }
        else{
            return false;
        }
        
    }

};

void compareVector(Vector* a, Vector* b){
    cout <<"Los vectores: " << 
    " (" << a->x << ";" << a->y << ")"
    << " y "<< "(" << b->x << ";"<< b->y <<") -";
    
    if(*a == *b){
        cout << "son iguales" << endl;
    }
    else{
        cout << "son distintos" << endl;
    }
}

int main(){
    Vector a={7,5};
    Vector b={7,5};
    Vector c={1,2};
    Vector d={6,7};

    Vector e = a + b + c + d;
    cout <<"Resultado de suma: " << e.x << "; " << e.y << endl;

    // Determina si son iguales sus componentes
    compareVector(&a, &b);

    return 0;
}

