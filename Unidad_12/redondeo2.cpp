#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double peso_real;
    double peso_facturado;

    peso_real = 4.12;
    peso_facturado = ceil(peso_real);

    cout << fixed << setprecision(2);
    cout << "Peso real del paquete: " << peso_real << " kg" << endl;
    cout << "Kilogramos a facturar (ceil): " << peso_facturado << " kg" << endl;

    return 0;
}

