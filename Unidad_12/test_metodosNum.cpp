#include "metodos_numericos/newton_raphson.h"
#include <iostream>

using namespace std;

// ============================================================================
// CONFIGURACIÓN DE LOS MACROS DEL SENSOR PARA EL EJERCICIO INTRODUCTORIO
// ============================================================================
// f(x) = 0.2*x^3 - 2*x + 2
#define F_SENSOR(x)             ((0.2f * (x) * (x) * (x)) - (2.0f * (x)) + 2.0f)

// Parámetros obligatorios solicitados para la llamada directa
#define VALOR_INICIAL           3.95f
#define ITERACIONES_SOLICITADAS 5
#define RANGO_INFERIOR          0.0f
#define RANGO_SUPERIOR          5.0f
#define RAIZ_TEORICA_SENSOR     1.133107f // Raíz real suave del polinomio introductorio

// Envoltura limpia para pasar la función matemática como puntero
float evaluar_sensor(float x) {
    return F_SENSOR(x);
}

int main() {
    // Declaración única de las variables de estado al principio del bloque
    float resultado_sensor;
    int estado_modulo;

    resultado_sensor = 0.0f;

    cout << "=== EJECUCION DE NEWTON-RAPHSON MEDIANTE MACROS DIRECTOS ===\n";
    cout << "Valor inicial enviado: " << VALOR_INICIAL << "\n";
    cout << "Limites operacionales: [" << RANGO_INFERIOR << " a " << RANGO_SUPERIOR << "]\n";
    cout << "Raiz teorica configurada: " << RAIZ_TEORICA_SENSOR << "\n\n";

    // INYECCIÓN DIRECTA DE MACROS EN LA FIRMA DE LA FUNCIÓN MODULAR
    estado_modulo = calcular_newton_raphson(evaluar_sensor, 
                                            VALOR_INICIAL, 
                                            ITERACIONES_SOLICITADAS, 
                                            RANGO_INFERIOR, 
                                            RANGO_SUPERIOR, 
                                            RAIZ_TEORICA_SENSOR, 
                                            &resultado_sensor);

    // Verificación final del estado del procesamiento autónomo
    if (estado_modulo == 0) {
        cout << "[MAIN - SENSOR]: Lectura final ajustada con exito: " << resultado_sensor << " unidades.\n";
    } else {
        cout << "[MAIN - SENSOR]: Operacion cancelada por el modulo. Codigo: " << estado_modulo << "\n";
    }

    return 0;
}
