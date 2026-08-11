#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double interes_original;
    double interes_truncado;

    interes_original = 0.054391;
    interes_truncado = trunc(interes_original * 10000.0) / 10000.0;

    cout << fixed << setprecision(4); 
    cout << "Ganancia original de interés: $" << interes_original << endl;
    cout << "Interés retenido en cuenta (truncado): $" << interes_truncado << endl;

    return 0;
}
