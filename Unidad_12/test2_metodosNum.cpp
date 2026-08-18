#include "metodos_numericos/biseccion.h"
#include <iostream>

using namespace std;

// ============================================================================
// CONFIGURACIÓN DE LOS MACROS DEL SENSOR (MODIFICABLE GLOBALMENTE)
// ============================================================================
// f(x) = x^3 - 6*x^2 + 11*x - 6
#define F_SENSOR(x)             (((x) * (x) * (x)) - (6.0f * (x) * (x)) + (11.0f * (x)) - 6.0f)

// Parámetros obligatorios pasados directamente en la llamada
#define RANGO_INICIAL_A         2.2f
#define RANGO_INICIAL_B         3.6f
#define ITERACIONES_SOLICITADAS 10
#define RAIZ_TEORICA            3.0f   // Parámetro dinámico de error analítico

// Envoltura limpia para pasar la función como puntero
float evaluar_sensor(float x) {
    return F_SENSOR(x);
}

int main() {
    float resultado_biseccion;
    int estado;

    resultado_biseccion = 0.0f;

    cout << "=== EJECUCION DE BISECCION CON PARAMETROS DE ERROR DINAMICOS ===\n";
    cout << "Intervalo inicial enviado: [" << RANGO_INICIAL_A << " a " << RANGO_INICIAL_B << "]\n";
    cout << "Raiz teorica configurada: " << RAIZ_TEORICA << "\n\n";

    estado= calcular_biseccion(evaluar_sensor, 
                                       RANGO_INICIAL_A, 
                                       RANGO_INICIAL_B, 
                                       ITERACIONES_SOLICITADAS, 
                                       RAIZ_TEORICA, 
                                       &resultado_biseccion);

    // Verificación final
    if (estado == 0) {
        cout << "[MAIN - BISECCIÓN]: Raiz final calculada con exito: " << resultado_biseccion << " unidades.\n";
    } else {
        cout << "[MAIN - SENSOR]: Operacion cancelada por el modulo. Codigo: " << estado << "\n";
    }

    return 0;
}
