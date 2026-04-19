#include <iostream>

using namespace std;

int main()
{
    int numeros[5]={14, 25 ,47 ,58, 17};

    // Mostrar primer y ultimo elemento
    cout<< "Primer numero: "<< numeros[0]<<endl;
    cout<< "Ultimo numero: "<< numeros[4]<<endl;

    cout<< "------------" << endl;
    // Mostrar por terminal orden descendente
    for(int i=4; i>-1; i--){
        cout<< "Numero " << i <<": "<<numeros[i] << endl;
    }

    return 0;
}