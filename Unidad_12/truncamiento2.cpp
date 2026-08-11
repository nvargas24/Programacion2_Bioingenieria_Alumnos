#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double consumo_original;
    double consumo_truncado;

    consumo_original = 4.12395;
    consumo_truncado = trunc(consumo_original * 1000.0) / 1000.0;

    cout << fixed << setprecision(3); 
    cout << "Consumo del sensor: " << consumo_original << " litros" << endl;
    cout << "Consumo procesado (truncado): " << consumo_truncado << " litros" << endl;

    return 0;
}
