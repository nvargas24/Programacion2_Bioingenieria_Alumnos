#ifndef INTERPOLACION_TRAMOS_H
#define INTERPOLACION_TRAMOS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief Estructura que representa un punto o nodo conocido (X, Y).
 */
typedef struct {
    float x;
    float y;
} PuntoInterpolacion_t;

/**
 * @brief Estructura que almacena una fila de la tabla de adquisición de datos.
 */
typedef struct {
    uint16_t n_muestra;       // Número de muestra secuencial (NMuestra)
    float valor_entrada;      // Variable de entrada evaluada (x)
    float valor_estimado;     // Resultado obtenido por el método (g(x))
    float error_porcentual;   // Error porcentual dinámico adaptativo (%)
} FilaTablaAdquisicion_t;

/**
 * @brief Estima un valor intermedio utilizando interpolación lineal por tramos.
 */
float interpolar_por_tramos(const PuntoInterpolacion_t* tabla, uint16_t tamano_tabla, float x_objetivo);

/**
 * @brief Genera una tabla de análisis de estimaciones para un rango específico.
 * 
 * @param tabla_nodos Arreglo de nodos conocidos cargados en memoria.
 * @param tamano_nodos Cantidad de nodos en la tabla de calibración.
 * @param buffer_salida Arreglo de estructuras donde se guardará la tabla generada.
 * @param max_pasos Cantidad de muestras a calcular en total (puntos de prueba).
 * @param limite_superior El valor máximo de la variable de entrada para el barrido (ej. 6.0).
 * @param func_real_sensor Puntero a la función física f(x) real (para calcular el error en base a ella).
 * @return int8_t Retorna 0 si la ejecución fue exitosa, -1 si hay error de parámetros.
 */
int8_t generar_tabla_estimaciones(const PuntoInterpolacion_t* tabla_nodos, uint16_t tamano_nodos,
                                  FilaTablaAdquisicion_t* buffer_salida, uint16_t max_pasos, 
                                  float limite_superior, float (*func_real_sensor)(float));

#ifdef __cplusplus
}
#endif

#endif // INTERPOLACION_TRAMOS_H
