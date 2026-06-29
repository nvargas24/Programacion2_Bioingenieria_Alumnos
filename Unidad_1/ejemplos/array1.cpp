#include <iostream>

using namespace std;

int main()
{
    int numeros[5];

    // Solicita datos a usuario
    for(int i=0; i<5; i++){
        cout<< "Ingrese un numero: ";
        cin >> numeros[i];
    }

    // Mostrar por terminal orden ascendente
    for(int i=0; i<5; i++){
        cout<< numeros[i] << endl;
    }

    return 0;
}