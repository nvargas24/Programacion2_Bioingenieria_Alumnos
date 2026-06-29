#include <iostream>

using namespace std;

int main()
{
    int v=20;
    int w=12;
    int* p;
    int n;

    p = &v;
    n = w;

    // Muestra por terminal el valor de 'v' y 'w' antes 
    // de cambiar por referencia
    cout<< "Valor de 'v' antes: " <<v << endl;
    cout<< "Valor de 'w' antes: " <<w << endl;

    w = *p; // Cambio de por referencia
    v = n;  // Cambio de por valor

    // Muestra por terminal el valor de 'v' y 'w' despues 
    // de cambiar por referencia
    cout<< "Valor de 'v' despues: " <<v << endl;
    cout<< "Valor de 'w' despues: " <<w << endl;

    return 0;
}