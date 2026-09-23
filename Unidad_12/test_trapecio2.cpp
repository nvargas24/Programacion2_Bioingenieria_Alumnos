#include "metodos_numericos/trapecio2.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Ejemplo: Movimiento Circular Uniformemente Variado (MCUV)
    // Eje X: Tiempo (t) en segundos.
    // Eje Y: Velocidad angular (w) en rad/s.
    // El motor va aumentando su velocidad de 2 en 2 cada segundo.
    int estado = 0;
    float resultado_final = 0.0f;

    vector<Punto2D> muestras_mcuv = {
        {0.0, 0.0}, // Muestra 0: t = 0s, w = 0 rad/s  (Reposo)
        {1.0, 2.0}, // Muestra 1: t = 1s, w = 2 rad/s
        {4.0, 4.0}, // Muestra 2: t = 2s, w = 4 rad/s
        {5.0, 6.0}, // Muestra 3: t = 3s, w = 6 rad/s
        {8.0, 8.0}  // Muestra 4: t = 4s, w = 8 rad/s
    };

    cout << "Integrando Muestras de un MCUV (Velocidad Variable):\n";
   estado = calcular_trapecio_muestras(muestras_mcuv, &resultado_final);

    if (estado == 0) {
        cout << "\n[RESULTADO]: Desplazamiento Angular Total: " << resultado_final << " rad\n";
    } else {
        cout << "\n[ERROR]: Falla en el procesamiento del modulo.\n";
    }

    return 0;
}
