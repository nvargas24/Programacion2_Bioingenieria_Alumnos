#ifndef METODOS_NUMERICOS_INTERPOLACION_TRAMOS_H
#define METODOS_NUMERICOS_INTERPOLACION_TRAMOS_H

// Estructura que almacena el modelo matemático de cada tramo (y = m*x + b)
struct TramoLineal {
    float x_inicial; // Límite inferior del tramo
    float x_final;   // Límite superior del tramo
    float m;         // Pendiente de la recta
    float b;         // Ordenada al origen
};

/**
 * Procesa la nube de puntos y calcula las ecuaciones de la recta (m y b) para cada tramo.
 * NOTA: Los arreglos de entrada 'arr_x' y 'arr_y' deben estar ordenados ascendentemente por X.
 */
int calcular_tabla_tramos(const float* arr_x, const float* arr_y, int cantidad_puntos, 
                          TramoLineal* tabla_tramos_destino);

/**
 * Busca el tramo correspondiente para un valor 'x_buscar' y calcula su imagen analítica 'y_resultado'.
 * Devuelve 0 si fue exitoso, o -1 si el valor está fuera del rango tabulado.
 */
int evaluar_x_en_tramos(const TramoLineal* tabla_tramos, int cantidad_tramos, 
                        float x_buscar, float* y_resultado);

#endif // METODOS_NUMERICOS_INTERPOLACION_TRAMOS_H
