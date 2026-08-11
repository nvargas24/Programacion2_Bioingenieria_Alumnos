// Ejemplo de redondeo
#include <iostream>
#include <iomanip>
#include <cmath> 

using namespace std;

int main() {
    double real, redondeado, suma, error;
    int i;

    real = 1.999;
    redondeado = round(real); // Redondea al entero más cercano: da 2.0
    suma = 0.0;

    cout << fixed << setprecision(3);
    cout << "Valor real: " << real << " -> Redondeado: " << redondeado << endl;

    for (i = 0; i < 10; ++i) {
        suma += round(real); 
    }

    error = suma - (real * 10); // 20.0 - 19.990

    cout << "Suma total redondeada (10 veces): " << suma << endl;
    cout << "Diferencia acumulada por redondeo: " << error << endl;

    return 0;
}
