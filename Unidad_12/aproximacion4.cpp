#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double actuador_calc, actuador_final;
    double sensor_exacto, sensor_seguro;
    double transductor_calc;
    int transductor_final;

    actuador_calc = 1.43;
    sensor_exacto = 4.5678;
    transductor_calc = 11.77;

    actuador_final = ceil(actuador_calc);
    sensor_seguro = trunc(sensor_exacto * 100.0) / 100.0;
    transductor_final = (int)transductor_calc;

    cout << fixed << setprecision(2);
    cout << "Actuador (redon.): " << actuador_final << endl;
    cout << "Sensor (trunc 2 dec): " << sensor_seguro << endl;
    cout << "Transductor (trunc entero): " << transductor_final << endl;

    return 0;
}
