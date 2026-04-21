#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<float> temperaturas = {22.5, 23.0, 21.8, 24.1, 22.9};

    // agrego 3 mediciones
    temperaturas.push_back(25.3);
    temperaturas.push_back(20.7);
    temperaturas.push_back(23.8);

    // elimino el último elemento
    temperaturas.pop_back();

    // modifico el 2do elemento - posicion 1
    temperaturas[1] = 3.4;

    cout << "Cantidad de elementos: " << temperaturas.size() << endl;
    cout << "Temperaturas: ";
    for(int i = 0; i < temperaturas.size(); i++){
        cout << temperaturas[i] << "; ";
    }

    return 0;
}