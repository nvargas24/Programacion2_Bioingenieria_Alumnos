#include "metodos_numericos/biseccion.h"
#include <iostream>

using namespace std;

// f(x) = x^3 - 6*x^2 + 11*x - 6
#define F_SENSOR(x)             (((x) * (x) * (x)) - (6.0f * (x) * (x)) + (11.0f * (x)) - 6.0f)

#define RANGO_INICIAL_A         2.2f
#define RANGO_INICIAL_B         3.6f
#define RAIZ_TEORICA            3.0f   // Raíz exacta para evaluar el Error% Verdadero

#define ITERACIONES_SOLICITADAS 10     // Para la Prueba 1
#define ERROR_TOLERADO_OBJETIVO 0.05f  // Para la Prueba 2 (Detenerse al alcanzar <= 0.05% de error verdadero)

float evaluar_sensor(float x) {
    return F_SENSOR(x);
}

int main() {
    float resultado_biseccion = 0.0f;
    int estado;

    // ------------------------------------------------------------------------
    // PRUEBA 1: Método de bisección cantidad de iteraciones
    // ------------------------------------------------------------------------
    cout << "Intervalo: [" << RANGO_INICIAL_A << " a " << RANGO_INICIAL_B << "]\n";
    cout << "Raiz teorica: " << RAIZ_TEORICA << "\n\n";

    cout << ">>> PRUEBA 1: Biseccion por Iteraciones Fijas :" << ITERACIONES_SOLICITADAS << endl;
    
    estado = calcular_biseccion(evaluar_sensor, 
                                RANGO_INICIAL_A, 
                                RANGO_INICIAL_B, 
                                ITERACIONES_SOLICITADAS, 
                                RAIZ_TEORICA, 
                                &resultado_biseccion);

    if (estado == 0) {
        cout << "[MAIN - ITERACIONES]: Raiz final calculada: " << resultado_biseccion << endl << endl;
    } else {
        cout << "[MAIN - SENSOR]: Operacion cancelada en Prueba 1. Codigo: " << estado << endl << endl;
    }

    resultado_biseccion = 0.0f; // Limpieza de variable para la siguiente prueba

    // ------------------------------------------------------------------------
    // PRUEBA 2: Método de bisección por tolerancia de error verdadero
    // ------------------------------------------------------------------------
    cout << ">>> PRUEBA 2: Biseccion por Tolerancia de Error Verdadero (Detener en <= " << ERROR_TOLERADO_OBJETIVO << "%) <<<\n";
    
    estado = calcular_biseccion_por_error(evaluar_sensor, 
                                          RANGO_INICIAL_A, 
                                          RANGO_INICIAL_B, 
                                          ERROR_TOLERADO_OBJETIVO, 
                                          RAIZ_TEORICA, 
                                          &resultado_biseccion);

    if (estado == 0) {
        cout << "[MAIN - ERROR]: Raiz final calculada: " << resultado_biseccion << " unidades.\n";
    } else {
        cout << "[MAIN - SENSOR]: Operacion cancelada en Prueba 2. Codigo: " << estado << "\n";
    }

    return 0;
}
