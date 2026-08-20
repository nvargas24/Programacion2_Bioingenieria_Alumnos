#include "metodos_numericos/newton_raphson.h"
#include <iostream>

using namespace std;

#define VALOR_INICIAL           3.95f
#define ITERACIONES_SOLICITADAS 5
#define RANGO_INFERIOR          0.0f
#define RANGO_SUPERIOR          5.0f
#define RAIZ_TEORICA            2.4236f // Raíz real suave del polinomio introductorio

#define ERROR_TOLERADO 0.01f     // Detener cuando el Error % Verdadero sea <= 0.01%

float funcion_test(float x) {
    // f(x) = 0.2*x^3 - 2*x + 2
    return ((0.2f * (x) * (x) * (x)) - (2.0f * (x)) + 2.0f);  
}

int main() {
    float resultado;
    int estado_modulo;

    resultado = 0.0f;

    cout << "=== CONFIGURACION INICIAL DE NEWTON-RAPHSON ===\n";
    cout << "Valor inicial: " << VALOR_INICIAL << "\n";
    cout << "Limites operacionales: [" << RANGO_INFERIOR << " a " << RANGO_SUPERIOR << "]\n";
    cout << "Raiz teorica: " << RAIZ_TEORICA << endl << endl;

    // ------------------------------------------------------------------------
    // PRUEBA 1: Newton-Raphson por Iteraciones Fijas
    // ------------------------------------------------------------------------
    cout << ">>> PRUEBA 1: Newton-Raphson por Iteraciones Fijas (" << ITERACIONES_SOLICITADAS << endl;
    
    estado_modulo = calcular_newton_raphson(funcion_test, 
                                            VALOR_INICIAL, 
                                            ITERACIONES_SOLICITADAS, 
                                            RANGO_INFERIOR, 
                                            RANGO_SUPERIOR, 
                                            RAIZ_TEORICA, 
                                            &resultado);

    // ------------------------------------------------------------------------
    // PRUEBA 2: Newton-Raphson por Tolerancia de Error
    // ------------------------------------------------------------------------
    resultado = 0.0f; // Reinicio de variable para la siguiente prueba
    cout << ">>> PRUEBA 2: Newton-Raphson por Error Objetivo (Detener en <= " << ERROR_TOLERADO << "%) <<<\n";
    
    estado_modulo = calcular_newton_raphson_por_error(funcion_test, 
                                                      VALOR_INICIAL, 
                                                      ERROR_TOLERADO, 
                                                      RANGO_INFERIOR, 
                                                      RANGO_SUPERIOR, 
                                                      RAIZ_TEORICA, 
                                                      &resultado);

    return 0;
}
