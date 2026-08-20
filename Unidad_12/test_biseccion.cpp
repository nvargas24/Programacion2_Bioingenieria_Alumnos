#include "metodos_numericos/biseccion.h"
#include <iostream>

using namespace std;

#define RANGO_INICIAL_A         2.2f
#define RANGO_INICIAL_B         3.6f
#define RAIZ_TEORICA            3.0f   // Raíz exacta para evaluar el Error% Verdadero

#define ITERACIONES_SOLICITADAS 10     // Para la Prueba 1
#define ERROR_TOLERADO_OBJETIVO 0.05f  // Para la Prueba 2 (Detenerse al alcanzar <= 0.05% de error verdadero)

float funcion_test(float x) { 
    // f(x) = x^3 - 6*x^2 + 11*x - 6
    return (x * x * x) - (6.0f * x * x) + (11.0f * x) - 6.0f; 
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
    
    estado = calcular_biseccion(funcion_test, 
                                RANGO_INICIAL_A, 
                                RANGO_INICIAL_B, 
                                ITERACIONES_SOLICITADAS, 
                                RAIZ_TEORICA, 
                                &resultado_biseccion);

    // ------------------------------------------------------------------------
    // PRUEBA 2: Método de bisección por tolerancia de error verdadero
    // ------------------------------------------------------------------------
    resultado_biseccion = 0.0f; // Limpieza de variable para la siguiente prueba    
    cout << ">>> PRUEBA 2: Biseccion por Tolerancia de Error Verdadero (Detener en <= " << ERROR_TOLERADO_OBJETIVO << "%)" << endl;
    
    estado = calcular_biseccion_por_error(funcion_test, 
                                          RANGO_INICIAL_A, 
                                          RANGO_INICIAL_B, 
                                          ERROR_TOLERADO_OBJETIVO, 
                                          RAIZ_TEORICA, 
                                          &resultado_biseccion);

    return 0;
}
