#include <iostream>

using namespace std;

int main()
{
    int numeros[3] = {10,20,30};
    int* p = numeros;

    for(int i=0; i<3; i++){
        cout << "-----------" << endl;
        cout << "Elemento "<< i << endl; 
        cout << "Direccion de memoria que ocupa: " << (void *)(p+i) <<endl; 
        cout << "Memoria que ocupa : " << (char *)(p+i+1)-(char *)(p+i) << " bytes"<<endl; 
        cout << "Valor del elemento : "<< *(p+i)<<endl;
    }

    return 0;
}