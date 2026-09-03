#ifndef METODOS_NUMERICOS_TRAPECIO_H
#define METODOS_NUMERICOS_TRAPECIO_H

// Definición del tipo de función matemática a integrar
typedef float (*FuncionMatematica)(float);

/**
 * Calcula la integral mediante la regla del trapecio basándose en un número fijo de segmentos.
 * Muestra una tabla detallada de la evolución del cálculo y evalúa el Error Verdadero porcentual.
 */
int calcular_trapecio(FuncionMatematica f, float lim_inf, float lim_sup, 
                      int segmentos, float valor_teorico, float* resultado_integral);

/**
 * Calcula la integral aumentando dinámicamente los segmentos hasta cumplir con la tolerancia de error dada.
 */
int calcular_trapecio_por_error(FuncionMatematica f, float lim_inf, float lim_sup, 
                                float error_maximo, float valor_teorico, float* resultado_integral);

#endif // METODOS_NUMERICOS_TRAPECIO_H
