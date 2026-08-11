#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double total_compra;
    double puntos_calculados;
    double puntos_otorgados;

    total_compra = 87.90;

    puntos_calculados = total_compra / 10.0;
    puntos_otorgados = floor(puntos_calculados);

    cout << fixed << setprecision(2);
    cout << "Total de compra: $" << total_compra << endl;
    cout << "Puntos exactos calculados: " << puntos_calculados << endl;
    cout << "Puntos finales otorgados (floor): " << puntos_otorgados << endl;

    return 0;
}

