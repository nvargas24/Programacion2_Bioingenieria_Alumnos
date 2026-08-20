#include "newton_raphson.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// ============================================================================
// FUNCIONES AUXILIARES INTERNAS
// ============================================================================

/**
 * Calcula la pendiente de la recta tangente usando Diferencias Centrales.
 */
static float calcular_derivada_interna(FuncionMatematica f, float x) {
    float h;
    float numerador;
    float denominador;
    
    h = 1e-4f;
    numerador = f(x + h) - f(x - h);
    denominador = 2.0f * h;
    
    return (numerador / denominador);
}

/**
 * El Núcleo: Ejecución pura del método de Newton-Raphson con ciclo FOR.
 */
static float ejecutar_newton_raphson(FuncionMatematica f, float valor_inicial, int max_iteraciones) {
    float x_actual;
    int i;
    
    x_actual = valor_inicial;

    for (i = 0; i < max_iteraciones; i++) {
        x_actual = x_actual - (f(x_actual) / calcular_derivada_interna(f, x_actual));
    }
    
    return x_actual;
}

/**
 * Ejecución pura de Newton-Raphson deteniéndose por criterio de error verdadero.
 */
static float ejecutar_newton_raphson_por_error(FuncionMatematica f, float valor_inicial, 
                                                float error_objetivo, float raiz_teorica) 
{
    float x_actual = valor_inicial;
    float x_siguiente;
    float error_porcentual;

    while (true) {
        x_siguiente = x_actual - (f(x_actual) / calcular_derivada_interna(f, x_actual));
        error_porcentual = (fabs(x_siguiente - raiz_teorica) / raiz_teorica) * 100.0f;

        if (error_porcentual <= error_objetivo) {
            break;
        }
        x_actual = x_siguiente;
    }
    
    return x_siguiente;
}

// ============================================================================
// FUNCIONES PÚBLICAS
// ============================================================================

/**
 * Ejecuta el método de Newton-Raphson basándose en un número fijo de iteraciones máximas.
 */
int calcular_newton_raphson(FuncionMatematica f, float valor_inicial, int max_iteraciones, 
                            float lim_inf, float lim_sup, float raiz_teorica, float* valor_ajustado) 
{
    float epsilon_prot;
    float x_actual;
    float f_val;
    float df_val;
    float abs_df;
    float x_siguiente;
    float error_porcentual;
    int iteracion;
    
    epsilon_prot = 1e-7f;
    x_actual = valor_inicial;

    cout << string(75, '-') << "\n";
    cout << left << setw(12) << "Iteracion" 
         << setw(15) << "x_n" 
         << setw(15) << "f(x_n)" 
         << setw(15) << "x_{n+1}" 
         << setw(15) << "Error %" << "\n";
    cout << string(75, '-') << "\n";

    for (iteracion = 0; iteracion <= max_iteraciones; iteracion++) {
        f_val = f(x_actual);
        df_val = calcular_derivada_interna(f, x_actual);

        abs_df = (df_val < 0.0f) ? -df_val : df_val;
        if (abs_df < epsilon_prot) {
            cout << "\n[ERROR]: Derivada nula detectada.\n";
            return -1; 
        }

        x_siguiente = ejecutar_newton_raphson(f, valor_inicial, iteracion + 1);

        if (x_siguiente < lim_inf || x_siguiente > lim_sup) {
            cout << "\n[ERROR]: Fuera de los limites [" << lim_inf << ", " << lim_sup << "].\n";
            return -2; 
        }

        error_porcentual = (fabs(x_siguiente - raiz_teorica) / raiz_teorica) * 100.0f;

        // CORREGIDO: Se eliminó el bloque condicional para imprimir el Error % siempre
        cout << left << setw(12) << iteracion 
             << fixed << setw(15) << setprecision(4) << x_actual
             << setw(15) << f_val
             << setw(15) << x_siguiente
             << setw(15) << error_porcentual << "\n";

        x_actual = x_siguiente;
    }

    cout << string(75, '-') << "\n";
    
    *valor_ajustado = x_actual;
    return 0; 
}

/**
 * Ejecuta el método de Newton-Raphson hasta alcanzar el porcentaje de error verdadero solicitado.
 */
int calcular_newton_raphson_por_error(FuncionMatematica f, float valor_inicial, float error_maximo, 
                                      float lim_inf, float lim_sup, float raiz_teorica, float* valor_ajustado) 
{
    float epsilon_prot = 1e-7f;
    float x_actual = valor_inicial;
    float f_val;
    float df_val;
    float abs_df;
    float x_siguiente;
    float error_porcentual;
    int iteracion = 0;

    cout << string(75, '-') << "\n";
    cout << left << setw(12) << "Iteracion" 
         << setw(15) << "x_n" 
         << setw(15) << "f(x_n)" 
         << setw(15) << "x_{n+1}" 
         << setw(15) << "Error %" << "\n";
    cout << string(75, '-') << "\n";

    while (true) {
        f_val = f(x_actual);
        df_val = calcular_derivada_interna(f, x_actual);

        abs_df = (df_val < 0.0f) ? -df_val : df_val;
        if (abs_df < epsilon_prot) {
            cout << "\n[ERROR]: Derivada nula detectada.\n";
            return -1; 
        }

        x_siguiente = ejecutar_newton_raphson(f, valor_inicial, iteracion + 1);

        if (x_siguiente < lim_inf || x_siguiente > lim_sup) {
            cout << "\n[ERROR]: Fuera de los limites [" << lim_inf << ", " << lim_sup << "].\n";
            return -2; 
        }

        error_porcentual = (fabs(x_siguiente - raiz_teorica) / raiz_teorica) * 100.0f;

        // CORREGIDO: Se eliminó el bloque condicional para imprimir el Error % siempre
        cout << left << setw(12) << iteracion 
             << fixed << setw(15) << setprecision(4) << x_actual
             << setw(15) << f_val
             << setw(15) << x_siguiente
             << setw(15) << error_porcentual << "\n";

        if (error_porcentual <= error_maximo) {
            break;
        }

        x_actual = x_siguiente;
        iteracion++;
    }

    cout << string(75, '-') << "\n";
    
    *valor_ajustado = ejecutar_newton_raphson_por_error(f, valor_inicial, error_maximo, raiz_teorica);
    return 0; 
}
