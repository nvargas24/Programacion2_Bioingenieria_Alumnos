#ifndef BISECCION_H
#define BISECCION_H

#ifdef __cplusplus
extern "C" {
#endif

// Tipo de puntero para vincular dinámicamente la función matemática del sensor
typedef float (*FuncionMatematica)(float);

/**
 * Ejecuta el método de Bisección completo e imprime la tabla analítica basándose en iteraciones fijas.
 * 
 * @param f                Puntero a la función del sensor a evaluar.
 * @param lim_inf          Límite inferior inicial del intervalo (a0).
 * @param lim_sup          Límite superior inicial del intervalo (b0).
 * @param max_iteraciones  Límite estricto de ciclos para el bucle.
 * @param raiz_teorica     Raíz exacta obtenida en GeoGebra para calcular el Error% Verdadero.
 * @param valor_ajustado   Puntero donde se almacenará el resultado final.
 * @return                 0 si fue exitoso, -1 si el intervalo inicial no encierra una raíz.
 */
int calcular_biseccion(FuncionMatematica f, float lim_inf, float lim_sup, 
                       int max_iteraciones, float raiz_teorica, float* valor_ajustado);

/**
 * Ejecuta el método de Bisección completo e imprime la tabla analítica hasta alcanzar un error verdadero objetivo.
 * 
 * @param f                Puntero a la función del sensor a evaluar.
 * @param lim_inf          Límite inferior inicial del intervalo (a0).
 * @param lim_sup          Límite superior inicial del intervalo (b0).
 * @param error_maximo     Porcentaje de error verdadero máximo permitido para detenerse (ej. 0.05f).
 * @param raiz_teorica     Raíz exacta obtenida en GeoGebra para calcular el Error% Verdadero y controlar la parada.
 * @param valor_ajustado   Puntero donde se almacenará el resultado final.
 * @return                 0 si fue exitoso, -1 si el intervalo inicial no encierra una raíz.
 */
int calcular_biseccion_por_error(FuncionMatematica f, float lim_inf, float lim_sup, 
                                 float error_maximo, float raiz_teorica, float* valor_ajustado);

#ifdef __cplusplus
}
#endif

#endif // BISECCION_H
