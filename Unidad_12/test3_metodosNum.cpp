#include <stdio.h>
#include "metodos_numericos/interpolacionLineal.h"

#define N_MUESTRAS 4
#define CANTIDAD_PASOS 13
#define LIMIT 6.0f

const PuntoInterpolacion_t muestras_xy[N_MUESTRAS] = {
    {0.0f,  0.0f},  // {X, Y}
    {2.0f,  8.0f}, 
    {4.0f, 16.0f},
    {6.0f,  0.0f}  
};

// f(x)
float curva_real_sensor(float x) {
    return (-0.5f * x * x * x) + (3.0f * x * x);
}

FilaTablaAdquisicion_t mi_tabla[CANTIDAD_PASOS];

int main() {
    int8_t estado = generar_tabla_estimaciones(muestras_xy, N_MUESTRAS, mi_tabla, 
                                               CANTIDAD_PASOS, LIMIT, curva_real_sensor);

    if (estado == 0) {
        // Imprimir únicamente los encabezados solicitados
        printf("%-12s | %-15s | %-12s\n", "Entrada (v)", "Val. Estimado", "Error %");
        printf("-------------------------------------------------\n");

        // Recorrer el buffer e imprimir solo las tres variables deseadas
        for (uint16_t i = 0; i < CANTIDAD_PASOS; i++) {
            printf("%-12.2f | %-15.4f | %-11.2f%%\n",
                   mi_tabla[i].valor_entrada,
                   mi_tabla[i].valor_estimado,
                   mi_tabla[i].error_porcentual);
        }
    } else {
        printf("Error al procesar la tabla de estimaciones.\n");
    }

    return 0;
}
