#include "trapecio.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// ============================================================================
// FUNCIONES AUXILIARES INTERNAS (Cálculos Puros)
// ============================================================================

/**
 * Ejecución matemática pura de la Regla del Trapecio Compuesta.
 */
static float ejecutar_calculo_trapecio(FuncionMatematica f, float a, float b, int n) {
    float h = (b - a) / n;
    float suma_intermedios = 0.0f;

    for (int i = 1; i < n; i++) {
        suma_intermedios += f(a + i * h);
    }

    // Fórmula del trapecio compuesta: (h / 2) * [f(a) + 2*Suma + f(b)]
    return (h / 2.0f) * (f(a) + (2.0f * suma_intermedios) + f(b));
}

// ============================================================================
// FUNCIONES PÚBLICAS
// ============================================================================

int calcular_trapecio(FuncionMatematica f, float lim_inf, float lim_sup, 
                      int segmentos, float valor_teorico, float* resultado_integral) 
{
    if (segmentos <= 0) {
        cout << "\n[ERROR]: El numero de segmentos debe ser mayor a 0.\n";
        return -1;
    }

    cout << string(65, '-') << "\n";
    cout << left << setw(12) << "Segmentos" 
         << setw(15) << "Ancho (h)" 
         << setw(20) << "Aprox. Integral" 
         << setw(15) << "e_v%" << "\n";
    cout << string(65, '-') << "\n";

    // Mostramos la evolución incremental para fines pedagógicos en la Prueba 1
    for (int i = 1; i <= segmentos; i++) {
        float h_actual = (lim_sup - lim_inf) / i;
        float aproximacion = ejecutar_calculo_trapecio(f, lim_inf, lim_sup, i);
        float error_porcentual = (fabs(aproximacion - valor_teorico) / valor_teorico) * 100.0f;

        cout << left << setw(12) << i 
             << fixed << setw(15) << setprecision(5) << h_actual
             << setw(20) << setprecision(6) << aproximacion
             << setw(15) << setprecision(4) << error_porcentual << "\n";
    }

    cout << string(65, '-') << "\n";
    *resultado_integral = ejecutar_calculo_trapecio(f, lim_inf, lim_sup, segmentos);
    return 0; 
}

int calcular_trapecio_por_error(FuncionMatematica f, float lim_inf, float lim_sup, 
                                float error_maximo, float valor_teorico, float* resultado_integral) 
{
    if (error_maximo <= 0.0f) {
        cout << "\n[ERROR]: La tolerancia de error debe ser mayor a 0.\n";
        return -1;
    }

    cout << string(65, '-') << "\n";
    cout << left << setw(12) << "Segmentos" 
         << setw(15) << "Ancho (h)" 
         << setw(20) << "Aprox. Integral" 
         << setw(15) << "e_v%" << "\n";
    cout << string(65, '-') << "\n";

    int n_segmentos = 1;
    float error_porcentual = 100.0f;
    float aproximacion = 0.0f;

    while (true) {
        float h_actual = (lim_sup - lim_inf) / n_segmentos;
        aproximacion = ejecutar_calculo_trapecio(f, lim_inf, lim_sup, n_segmentos);
        error_porcentual = (fabs(aproximacion - valor_teorico) / valor_teorico) * 100.0f;

        cout << left << setw(12) << n_segmentos 
             << fixed << setw(15) << setprecision(5) << h_actual
             << setw(20) << setprecision(6) << aproximacion
             << setw(15) << setprecision(4) << error_porcentual << "\n";

        if (error_porcentual <= error_maximo) {
            break;
        }

        n_segmentos++; // Aumentamos la resolución espacial de la grilla
    }

    cout << string(65, '-') << "\n";
    *resultado_integral = aproximacion;
    return 0; 
}
