#include "metodos_numericos/trapecio.h"
#include <iostream>

using namespace std;

#define LIMITE_INFERIOR         0.0f
#define LIMITE_SUPERIOR         2.0f
#define VALOR_TEORICO_INTEGRAL  2.666667f  // Integral exacta de x^2 en [0,2]

#define SEGMENTOS_SOLICITADOS   6          // Para la Prueba 1
#define ERROR_TOLERADO_OBJETIVO 0.5f       // Para la Prueba 2 (Detenerse al alcanzar <= 0.5% de error verdadero)

float funcion_test(float x) { 
    // f(x) = x^2
    return x * x; 
}

int main() {
    float resultado_integral = 0.0f;
    int estado;

    cout << "Intervalo de Integracion: [" << LIMITE_INFERIOR << " a " << LIMITE_SUPERIOR << "]\n";
    cout << "Valor Teorico Exacto: " << VALOR_TEORICO_INTEGRAL << "\n\n";

    // ------------------------------------------------------------------------
    // PRUEBA 1: Regla del Trapecio por Cantidad de Segmentos Fijos
    // ------------------------------------------------------------------------
    cout << ">>> PRUEBA 1: Trapecio por Segmentos Fijos: " << SEGMENTOS_SOLICITADOS << endl;
    
    estado = calcular_trapecio(funcion_test, 
                               LIMITE_INFERIOR, 
                               LIMITE_SUPERIOR, 
                               SEGMENTOS_SOLICITADOS, 
                               VALOR_TEORICO_INTEGRAL, 
                               &resultado_integral);
                               
    cout << "Resultado Final de la Integral (Prueba 1): " << resultado_integral << "\n\n";

    // ------------------------------------------------------------------------
    // PRUEBA 2: Regla del Trapecio por tolerancia de error verdadero
    // ------------------------------------------------------------------------
    resultado_integral = 0.0f; // Limpieza de variable
    cout << ">>> PRUEBA 2: Trapecio por Tolerancia de Error Verdadero (Detener en <= " << ERROR_TOLERADO_OBJETIVO << "%)\n";
    
    estado = calcular_trapecio_por_error(funcion_test, 
                                          LIMITE_INFERIOR, 
                                          LIMITE_SUPERIOR, 
                                          ERROR_TOLERADO_OBJETIVO, 
                                          VALOR_TEORICO_INTEGRAL, 
                                          &resultado_integral);

    cout << "Resultado Final de la Integral (Prueba 2): " << resultado_integral << "\n";
    cout << "Estado al utilizar metodo: " << estado << "\n";

    return 0;
}
