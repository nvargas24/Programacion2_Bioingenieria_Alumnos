#include "metodos_numericos/interpolacionLineal2.h"
#include <iostream>

using namespace std;

int main() {
    // Definición estricta de vectores de datos experimentales tabulados (Solo puntos)
    // NOTA: Deben estar ordenados de menor a mayor respecto a X
    const float puntos_x[] = {10.0f, 20.0f, 35.0f, 50.0f};
    const float puntos_y[] = {20.0f, 110.0f, 180.0f, 300.0f};
    
    int total_puntos = sizeof(puntos_x) / sizeof(puntos_x[0]);
    int total_tramos = total_puntos - 1;

    // Reservamos memoria para la tabla de tramos calculados
    TramoLineal tabla_tramos[total_tramos];

    cout << ">>> GENERANDO MODELO DE INTERPOLACION POR TRAMOS LINEALES <<<\n\n";
    
    int estado_modelo = calcular_tabla_tramos(puntos_x, puntos_y, total_puntos, tabla_tramos);

    if (estado_modelo != 0) {
        cout << "Error critico al procesar los puntos iniciales. Estado: " << estado_modelo << "\n";
        return -1;
    }

    // ------------------------------------------------------------------------
    // PRUEBA DE EVALUACIÓN DE IMÁGENES (Paso de valores X aleatorios)
    // ------------------------------------------------------------------------
    cout << "\n>>> EVALUANDO VALORES DE 'X' EN LAS RECTAS CALCULADAS <<<\n\n";

    float valores_evaluacion[] = {28.0f}; // El último forzará un error por fuera de rango
    float y_calculado = 0.0f;
    int estado_busqueda;

    for (float x_test : valores_evaluacion) {
        estado_busqueda = evaluar_x_en_tramos(tabla_tramos, total_tramos, x_test, &y_calculado);
        
        if (estado_busqueda == 0) {
            cout << " -> Resultado de la interpolacion: f(" << x_test << ") = " << y_calculado << "\n\n";
        } else {
            cout << " -> No se pudo interpolar el valor.\n\n";
        }
    }

    return 0;
}
