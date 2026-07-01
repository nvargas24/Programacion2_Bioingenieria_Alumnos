#include <iostream>

using namespace std;

int main()
{
    int numeros[3] = {10,20,30};
    int* p = numeros;

    for(int i=0; i<3; i++){
        cout<< "Valor en posicion "<< i << ": "<< *(p+i)<<endl;
    }

    return 0;
}