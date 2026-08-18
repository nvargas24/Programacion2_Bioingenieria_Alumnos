#ifndef NEWTON_RAPHSON_H
#define NEWTON_RAPHSON_H

#ifdef __cplusplus
extern "C" {
#endif

// Tipo de puntero para vincular dinámicamente la función matemática del sensor
typedef float (*FuncionMatematica)(float);

/**
 * Ejecuta el método de Newton-Raphson completo e imprime la tabla analítica.
 * 
 * @param f                Puntero a la función del sensor a evaluar.
 * @param valor_inicial    Semilla o estimación inicial (x0).
 * @param max_iteraciones  Límite estricto de ciclos para el bucle.
 * @param lim_inf          Límite físico inferior del sensor (Acotamiento).
 * @param lim_sup          Límite físico superior del sensor (Acotamiento).
 * @param raiz_teorica     Raíz exacta obtenida en GeoGebra para calcular el Error%.
 * @param valor_ajustado   Puntero donde se almacenará el resultado final.
 * @return                 0 si fue exitoso, -1 si hubo derivada nula, -2 si salió de límites.
 */
int calcular_newton_raphson(FuncionMatematica f, float valor_inicial, int max_iteraciones, 
                            float lim_inf, float lim_sup, float raiz_teorica, float* valor_ajustado);

#ifdef __cplusplus
}
#endif

#endif // NEWTON_RAPHSON_H
