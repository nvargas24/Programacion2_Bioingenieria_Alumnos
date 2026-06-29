#include <iostream>

using namespace std;

int main()
{
    int v=20;
    int* p;

    p = &v;

    // Muestra por terminal el valor de 'v' antes y despues
    // de cambiar por referencia
    cout<< "Valor de 'v' antes: " <<v << endl;
    *p = 25;
    cout<< "Valor de 'v' despues: " <<v << endl;

    return 0;
}