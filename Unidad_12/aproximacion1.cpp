// Ejemplo de error
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float suma = 0.0f;
    float incremento = 0.1f; // El valor real teórico
    float valor_verdadero = 1000.0f; // 0.1 * 10000 = 1000
    float error_absoluto = 0;

    // Sumamos 0.1 diez mil veces
    for (int i = 0; i < 10000; ++i) {
        suma += incremento;
    }

    error_absoluto= valor_verdadero - suma;

    cout << fixed << setprecision(6);
    cout << "Valor obtenido en C++: " << suma << endl;
    cout << "Error Absoluto acumulado: " << error_absoluto << endl;

    return 0;
}