#include "biseccion.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// ============================================================================
// FUNCIONES AUXILIARES INTERNAS
// ============================================================================

/**
 * Ejecución pura del método de Bisección con ciclo FOR (por iteraciones máximas).
 */
static float ejecutar_bucle_biseccion(FuncionMatematica f, float lim_inf, float lim_sup, int max_iteraciones) {
    float a = lim_inf;
    float b = lim_sup;
    float c;
    int i;

    for (i = 0; i < max_iteraciones; i++) {
        c = (a + b) / 2.0f;

        if ((f(a) * f(c)) < 0.0f) {
            b = c; 
        } else {
            a = c; 
        }
    }

    return (a + b) / 2.0f;
}

/**
 * Ejecución pura del método de Bisección deteniéndose por criterio de error verdadero.
 */
static float ejecutar_bucle_biseccion_por_error(FuncionMatematica f, float lim_inf, float lim_sup, 
                                                float raiz_teorica, float error_objetivo) {
    float a = lim_inf;
    float b = lim_sup;
    float c;
    float error_porcentual;

    while (true) {
        c = (a + b) / 2.0f;
        error_porcentual = (fabs(c - raiz_teorica) / raiz_teorica) * 100.0f;

        if (error_porcentual <= error_objetivo) {
            break;
        }

        if ((f(a) * f(c)) < 0.0f) {
            b = c;
        } else {
            a = c;
        }
    }

    return c;
}

// ============================================================================
// FUNCIONES PÚBLICAS
// ============================================================================

/**
 * Calcula la bisección basándose en un número fijo de iteraciones máximas utilizando Error Verdadero.
 */
int calcular_biseccion(FuncionMatematica f, float lim_inf, float lim_sup, 
                       int max_iteraciones, float raiz_teorica, float* valor_ajustado) 
{
    float x_actual_izq;
    float x_actual_der;
    float c_actual;
    float error_porcentual;
    int iteracion;

    if ((f(lim_inf) * f(lim_sup)) >= 0.0f) {
        cout << "\n[ERROR]: El intervalo inicial no encierra un cambio de signo.\n";
        return -1;
    }

    x_actual_izq = lim_inf;
    x_actual_der = lim_sup;

    cout << string(60, '-') << "\n";
    cout << left << setw(12) << "Iteracion" 
         << setw(15) << "a_n(izq)" 
         << setw(15) << "b_n(der)" 
         << setw(15) << "c_n(Medio)" 
         << setw(15) << "e_v%" << "\n";
    cout << string(60, '-') << "\n";

    for (iteracion = 0; iteracion <= max_iteraciones; iteracion++) {
        c_actual = (x_actual_izq + x_actual_der) / 2.0f;
        error_porcentual = (fabs(c_actual - raiz_teorica) / raiz_teorica) * 100.0f;

        cout << left << setw(12) << iteracion 
             << fixed << setw(15) << setprecision(4) << x_actual_izq
             << setw(15) << x_actual_der
             << setw(15) << c_actual
             << setw(15) << error_porcentual << "\n";

        if ((f(x_actual_izq) * f(c_actual)) < 0.0f) {
            x_actual_der = c_actual;
        } else {
            x_actual_izq = c_actual;
        }
    }

    cout << string(60, '-') << "\n";
    
    *valor_ajustado = ejecutar_bucle_biseccion(f, lim_inf, lim_sup, max_iteraciones);
    return 0; 
}

/**
 * Calcula la bisección deteniéndose exactamente cuando el Error Verdadero cumple la tolerancia de parada.
 */
int calcular_biseccion_por_error(FuncionMatematica f, float lim_inf, float lim_sup, 
                                 float error_maximo, float raiz_teorica, float* valor_ajustado) 
{
    float x_actual_izq;
    float x_actual_der;
    float c_actual;
    float error_porcentual;
    int iteracion = 0;

    if ((f(lim_inf) * f(lim_sup)) >= 0.0f) {
        cout << "\n[ERROR]: El intervalo inicial no encierra un cambio de signo.\n";
        return -1;
    }

    x_actual_izq = lim_inf;
    x_actual_der = lim_sup;

    cout << string(60, '-') << "\n";
    cout << left << setw(12) << "Iteracion" 
         << setw(15) << "a_n(izq)" 
         << setw(15) << "b_n(der)" 
         << setw(15) << "c_n(Medio)" 
         << setw(15) << "e_v%" << "\n";
    cout << string(60, '-') << "\n";

    while (true) {
        c_actual = (x_actual_izq + x_actual_der) / 2.0f;
        error_porcentual = (fabs(c_actual - raiz_teorica) / raiz_teorica) * 100.0f;

        cout << left << setw(12) << iteracion 
             << fixed << setw(15) << setprecision(4) << x_actual_izq
             << setw(15) << x_actual_der
             << setw(15) << c_actual
             << setw(15) << error_porcentual << "\n";

        if (error_porcentual <= error_maximo) {
            break;
        }

        if ((f(x_actual_izq) * f(c_actual)) < 0.0f) {
            x_actual_der = c_actual;
        } else {
            x_actual_izq = c_actual;
        }

        iteracion++;
    }

    cout << string(60, '-') << "\n";
    
    *valor_ajustado = ejecutar_bucle_biseccion_por_error(f, lim_inf, lim_sup, raiz_teorica, error_maximo);
    return 0; 
}
