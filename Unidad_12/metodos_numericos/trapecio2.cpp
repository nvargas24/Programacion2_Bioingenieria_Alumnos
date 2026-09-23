#include "trapecio2.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// ============================================================================
// FUNCIONES AUXILIARES INTERNAS (Cálculos Puros)
// ============================================================================

static double ejecutar_trapecio_puntos(const vector<Punto2D>& puntos) {
    double suma_integral = 0.0;
    size_t n = puntos.size();

    for (size_t i = 0; i < n - 1; i++) {
        double h = puntos[i+1].x - puntos[i].x;
        double area_trapecio = (h / 2.0) * (puntos[i].y + puntos[i+1].y);
        suma_integral += area_trapecio;
    }

    return suma_integral;
}

// ============================================================================
// FUNCIONES PÚBLICAS
// ============================================================================

int calcular_trapecio_muestras(const vector<Punto2D>& puntos, float* resultado_integral) {
    if (puntos.size() < 2) {
        cout << "\n[ERROR]: Se necesitan al menos 2 puntos para calcular un area.\n";
        return -1;
    }

    // Tabla ajustada a 61 caracteres de ancho al remover e_v%
    cout << string(61, '-') << "\n";
    cout << left << setw(10) << "Muestra" 
         << setw(15) << "Intervalo (h)" 
         << setw(18) << "Puntos (x_i, x_f)" 
         << setw(18) << "Area Acumulada" << "\n";
    cout << string(61, '-') << "\n";

    double aproximacion_acumulada = 0.0;
    size_t total_puntos = puntos.size();

    for (size_t i = 0; i < total_puntos - 1; i++) {
        double h_actual = puntos[i+1].x - puntos[i].x;
        double area_panel = (h_actual / 2.0) * (puntos[i].y + puntos[i+1].y);
        aproximacion_acumulada += area_panel;

        string rango_x = "[" + to_string(i) + "->" + to_string(i+1) + "]";

        cout << left << setw(10) << i + 1
             << fixed << setw(15) << setprecision(5) << h_actual
             << setw(18) << rango_x
             << setw(18) << setprecision(6) << aproximacion_acumulada << "\n";
    }

    cout << string(61, '-') << "\n";
    
    *resultado_integral = static_cast<float>(ejecutar_trapecio_puntos(puntos));
    return 0;
}
