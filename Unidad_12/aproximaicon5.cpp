#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double sensor_calc, sensor_final;
    double actuador_calc, actuador_final;
    double transductor_calc, transductor_final;

    sensor_calc = 8.124;
    actuador_calc = 3.41;
    transductor_calc = 24.56;

    sensor_final = trunc(sensor_calc * 100.0) / 100.0;
    actuador_final = ceil(actuador_calc);
    transductor_final = round(transductor_calc);

    cout << fixed << setprecision(2);
    cout << "Sensor (trunc 2 dec): " << sensor_final << endl;
    cout << "Actuador (ceil): " << actuador_final << endl;
    cout << "Transductor (round entero): " << transductor_final << endl;

    return 0;
}
