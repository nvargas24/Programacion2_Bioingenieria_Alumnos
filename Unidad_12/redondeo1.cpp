#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double monto_exacto;
    double monto_redondeado;

    monto_exacto = 18.3461;
    monto_redondeado = round(monto_exacto * 100.0) / 100.0;

    cout << fixed << setprecision(2);
    cout << "Monto exacto calculado: $" << monto_exacto << endl;
    cout << "Monto final cobrado (round): $" << monto_redondeado << endl;

    return 0;
}

