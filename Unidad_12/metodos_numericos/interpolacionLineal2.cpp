#include "interpolacionLineal2.h"
#include <iostream>
#include <iomanip>
#include <sstream> // Necesario para formatear el string del intervalo limpiamente

using namespace std;

int calcular_tabla_tramos(const float* arr_x, const float* arr_y, int cantidad_puntos, 
                          TramoLineal* tabla_tramos_destino)
{
    // Se necesitan al menos 2 puntos para definir un tramo lineal
    if (cantidad_puntos < 2 || arr_x == nullptr || arr_y == nullptr || tabla_tramos_destino == nullptr) {
        cout << "\n[ERROR]: Datos invalidos o cantidad de puntos insuficiente.\n";
        return -1;
    }

    int cantidad_tramos = cantidad_puntos - 1;

    // Aumentamos el ancho de la línea de 70 a 85 para acomodar números grandes
    cout << string(85, '-') << "\n";
    cout << left << setw(8)  << "Tramo" 
         << setw(26) << "Intervalo [X_i, X_f]"  // Más espacio explícito para el intervalo
         << setw(16) << "Pendiente (m)" 
         << setw(16) << "Ordenada (b)" 
         << setw(19) << "Ecuacion de la Recta" << "\n";
    cout << string(85, '-') << "\n";

    for (int i = 0; i < cantidad_tramos; i++) {
        float x0 = arr_x[i];
        float x1 = arr_x[i + 1];
        float y0 = arr_y[i];
        float y1 = arr_y[i + 1];

        // Validación para evitar división por cero en puntos con misma coordenada X
        if (x1 == x0) {
            cout << "\n[ERROR]: Coordenadas X consecutivas identicas en el indice " << i << ".\n";
            return -2;
        }

        // Cálculo de parámetros de la recta: y = mx + b
        float m = (y1 - y0) / (x1 - x0);
        float b = y0 - (m * x0);

        // Guardado de la estructura de datos para su posterior evaluación rápida
        tabla_tramos_destino[i].x_inicial = x0;
        tabla_tramos_destino[i].x_final   = x1;
        tabla_tramos_destino[i].m         = m;
        tabla_tramos_destino[i].b         = b;

        // Formateo dinámico del intervalo en un string para que setw(26) funcione perfectamente
        stringstream ss_intervalo;
        ss_intervalo << fixed << setprecision(2) << "[" << x0 << ", " << x1 << "]";
        string string_intervalo = ss_intervalo.str();

        // Visualización del tramo formateado en consola
        char string_ecuacion[40]; // Aumentado a 40 por seguridad con floats muy largos
        sprintf(string_ecuacion, "y = %.2fx + (%.2f)", m, b);

        cout << left << setw(8)  << (i + 1)
             << setw(26) << string_intervalo // Justifica perfectamente el intervalo completo de números grandes
             << fixed << setprecision(4)
             << setw(16) << m
             << setw(16) << b
             << setw(19) << string_ecuacion << "\n";
    }

    cout << string(85, '-') << "\n";
    return 0;
}

int evaluar_x_en_tramos(const TramoLineal* tabla_tramos, int cantidad_tramos, 
                        float x_buscar, float* y_resultado)
{
    if (tabla_tramos == nullptr || y_resultado == nullptr || cantidad_tramos <= 0) {
        return -1;
    }

    // Buscamos a qué tramo pertenece el valor X solicitado
    for (int i = 0; i < cantidad_tramos; i++) {
        // Validación con tolerancia en extremos inclusivos
        if (x_buscar >= tabla_tramos[i].x_inicial && x_buscar <= tabla_tramos[i].x_final) {
            
            // Evaluamos la ecuación lineal almacenada para ese tramo específico
            *y_resultado = (tabla_tramos[i].m * x_buscar) + tabla_tramos[i].b;
            
            cout << "[INFO]: Valor X = " << x_buscar << " encontrado en el Tramo " << (i + 1) << "\n";
            return 0; // Éxito
        }
    }

    // Si sale del bucle, el valor X está fuera del dominio de la tabla de puntos
    cout << "[ERROR]: El valor X = " << x_buscar << " se encuentra fuera del rango interpolable.\n";
    return -1; 
}
