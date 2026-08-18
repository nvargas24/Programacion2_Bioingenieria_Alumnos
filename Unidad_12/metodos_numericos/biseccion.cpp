#include "biseccion.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// ============================================================================
// FUNCIONES AUXILIARES INTERNAS
// ============================================================================

/**
 * Ejecución pura del método de Bisección con ciclo FOR.
 */
static float ejecutar_bucle_biseccion(FuncionMatematica f, float lim_inf, float lim_sup, int max_iteraciones) {
    float a;
    float b;
    float c;
    float resultado;
    int i;

    a = lim_inf;
    b = lim_sup;
    c = (a + b) / 2.0f;
    resultado = c;

    for (i = 0; i < max_iteraciones; i++) {
        c = (a + b) / 2.0f;

        if ((f(a) * f(c)) < 0.0f) {
            b = c; 
        } else {
            a = c; 
        }
    }

    resultado = (a + b) / 2.0f;
    return resultado;
}


int calcular_biseccion(FuncionMatematica f, float lim_inf, float lim_sup, 
                       int max_iteraciones, float raiz_teorica, float* valor_ajustado) 
{
    float x_actual_izq;
    float x_actual_der;
    float c_actual;
    float f_val;
    float error_porcentual;
    int iteracion;

    // Control de seguridad inicial: Verificar cambio de signo (Teorema de Bolzano)
    if ((f(lim_inf) * f(lim_sup)) >= 0.0f) {
        cout << "\n[ERROR]: El intervalo inicial no encierra un cambio de signo.\n";
        return -1;
    }

    x_actual_izq = lim_inf;
    x_actual_der = lim_sup;

    // Encabezado formateado de forma idéntica a la tabla de GeoGebra
    cout << string(75, '-') << "\n";
    cout << left << setw(12) << "Iteracion" 
         << setw(15) << "a_n(izq)" 
         << setw(15) << "b_n(der)" 
         << setw(15) << "c_n(Medio)" 
         << setw(15) << "f(c_n)" 
         << setw(15) << "Error%" << "\n";
    cout << string(75, '-') << "\n";

    // Bucle para volcar las filas solicitadas
    for (iteracion = 0; iteracion <= max_iteraciones; iteracion++) {
        c_actual = (x_actual_izq + x_actual_der) / 2.0f;
        f_val = f(c_actual);

        // CÁLCULO DINÁMICO: Utiliza el parámetro de la raíz teórica pasada por el main
        error_porcentual = (fabs(c_actual - raiz_teorica) / raiz_teorica) * 100.0f;

        // Impresión formateada con 4 decimales
        cout << left << setw(12) << iteracion 
             << fixed << setw(15) << setprecision(4) << x_actual_izq
             << setw(15) << x_actual_der
             << setw(15) << c_actual
             << setw(15) << f_val
             << setw(15) << error_porcentual << "\n";

        // Lógica de actualización de límites para la siguiente fila
        if ((f(x_actual_izq) * f(c_actual)) < 0.0f) {
            x_actual_der = c_actual;
        } else {
            x_actual_izq = c_actual;
        }
    }

    cout << string(75, '-') << "\n";
    
    // Retorno del valor numérico limpio invocando al núcleo matemático
    *valor_ajustado = ejecutar_bucle_biseccion(f, lim_inf, lim_sup, max_iteraciones);
    return 0; 
}
