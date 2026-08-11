#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double transductor_calc;
    int transductor_final;
    double sensor_calc, sensor_final;
    double actuador_calc, actuador_final;

    transductor_calc = 14.89;
    sensor_calc = 5.672;
    actuador_calc = 0.12;

    transductor_final = (int)transductor_calc;
    sensor_final = round(sensor_calc * 100.0) / 100.0;
    actuador_final = ceil(actuador_calc);

    cout << fixed << setprecision(2);
    cout << "Transductor (trunc entero): " << transductor_final << endl;
    cout << "Sensor (round 2 dec): " << sensor_final << endl;
    cout << "Actuador (ceil): " << actuador_final << endl;

    return 0;
}
