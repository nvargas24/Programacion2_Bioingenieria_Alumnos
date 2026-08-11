// Ejemplo de truncamiento
#include <iostream>
#include <iomanip>
#include <cmath> 

using namespace std;

int main() {
    double real, truncado, suma, error;
    int i;

    real = 1.999;
    truncado = trunc(real); // Corta los decimales: da 1.0
    suma = 0.0;

    cout << fixed << setprecision(3); // Intruccion para formato de salida "x.yyy"
    cout << "Valor real: " << real << " -> Truncado: " << truncado << endl;

    // Acumulación de error (truncamos 1.999 a 1.0 diez veces)
    for (i = 0; i < 10; ++i) {
        suma += trunc(real); 
    }

    error = (real * 10) - suma; // (19.99) - 10.0

    cout << "Suma total truncada (10 veces): " << suma << endl;
    cout << "Error acumulado total: " << error << endl;

    return 0;
}
