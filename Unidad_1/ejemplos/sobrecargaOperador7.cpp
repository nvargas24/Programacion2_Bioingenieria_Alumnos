#include <iostream>
using namespace std;

struct Vector{
    int x, y;
};
// Sobrecarga de operador con funcion externa
/*
1) x=0, y=0 → "nulo"
2) x≠0, y=0 → "xi"
3) x=0, y≠0 → "yj"  --considerar negativo
4) x≠0, y≠0:
   y > 0 → "xi + yj"
   y < 0 → "xi - yj"
*/

ostream& operator<<(ostream &miCout, const Vector &comp){
    if (comp.x == 0 && comp.y == 0) { // flujo  :    0 i + 0 j
        miCout << "vector nulo";
        return miCout;
    }

    // Componente en i  
    if (comp.x != 0) {     // flujo  :    x i + ...
        miCout << comp.x << "i";
    }

    // Si componente en i es nulo no se vera por terminal
    // Componente en j
    if (comp.y != 0) {    // flujo  :   ... +- y j
        if (comp.x != 0) {   // ... +- y j
            if (comp.y > 0) {   
                miCout << " + "; // ... + y j
            } else {
                miCout << " - ";  // ... - y j
            }
        } else if (comp.y < 0) {   // - y j
            miCout << "-";
        }

        miCout << abs(comp.y) << "j"; // y j
    }

    return miCout;
}

int main(){
    Vector a={0, 0}; 

    cout << "Vector a= " << a << endl;

    return 0;
}


