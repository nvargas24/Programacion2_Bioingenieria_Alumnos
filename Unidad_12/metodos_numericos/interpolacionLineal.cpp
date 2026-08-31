#include "interpolacionLineal.h"
#include <math.h>

float interpolar_por_tramos(const PuntoInterpolacion_t* tabla, uint16_t tamano_tabla, float x_objetivo) {
    if (tabla == 0 || tamano_tabla < 2) return 0.0f;
    
    // Extrapolación por saturación (Protección de límites)
    if (x_objetivo <= tabla[0].x) return tabla[0].y;
    if (x_objetivo >= tabla[tamano_tabla - 1].x) return tabla[tamano_tabla - 1].y;

    for (uint16_t i = 0; i < tamano_tabla - 1; i++) {
        if (x_objetivo >= tabla[i].x && x_objetivo <= tabla[i + 1].x) {
            float x0 = tabla[i].x;
            float y0 = tabla[i].y;
            float x1 = tabla[i + 1].x;
            float y1 = tabla[i + 1].y;

            if (x1 - x0 == 0.0f) return y0; // Evitar división por cero si los nodos se superponen
            
            float pendiente = (y1 - y0) / (x1 - x0);
            return y0 + pendiente * (x_objetivo - x0);
        }
    }
    return 0.0f;
}

int8_t generar_tabla_estimaciones(const PuntoInterpolacion_t* tabla_nodos, uint16_t tamano_nodos, FilaTablaAdquisicion_t* buffer_salida, uint16_t max_pasos, float limite_superior, float (*func_real_sensor)(float)) {
    // Validaciones de seguridad para el microcontrolador
    if (tabla_nodos == 0 || buffer_salida == 0 || max_pasos < 2 || func_real_sensor == 0) {
        return -1;
    }

    float limite_inferior = tabla_nodos[0].x;
    float delta_paso = (limite_superior - limite_inferior) / (float)(max_pasos - 1);

    for (uint16_t i = 0; i < max_pasos; i++) {
        buffer_salida[i].n_muestra = i + 1;
        
        // Mitigación de error de redondeo acumulado
        float x_actual = (i == max_pasos - 1) ? limite_superior : limite_inferior + ((float)i * delta_paso);
        buffer_salida[i].valor_entrada = x_actual;

        float real = func_real_sensor(x_actual);
        float estimado = interpolar_por_tramos(tabla_nodos, tamano_nodos, x_actual);
        buffer_salida[i].valor_estimado = estimado;

        // Cálculo del error absoluto
        float error_abs = fabsf(estimado - real);

        // Blindaje estándar de división por cero basado estrictamente en el valor REAL
        if (real == 0.0f) {
            // Si ambos son cero, el error es cero. Si no, tiende a infinito (se satura al 100% o indicador máximo)
            buffer_salida[i].error_porcentual = (estimado == 0.0f) ? 0.0f : 100.0f; 
        } else {
            // Fórmula estándar universal: (Error Absoluto / Valor Real) * 100
            buffer_salida[i].error_porcentual = (error_abs / fabsf(real)) * 100.0f;
        }
    }
    return 0; // Tabla generada correctamente
}
