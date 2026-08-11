#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double tarifa_original;
    double tarifa_truncada;

    tarifa_original = 25.678;
    tarifa_truncada = trunc(tarifa_original * 10.0) / 10.0;

    cout << fixed << setprecision(1); 
    cout << "Tarifa real calculada: $" << tarifa_original << endl;
    cout << "Tarifa mostrada al cliente (truncada): $" << tarifa_truncada << endl;

    return 0;
}
