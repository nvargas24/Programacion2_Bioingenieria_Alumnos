#ifndef DRIVER_MATRIZ_H_
#define DRIVER_MATRIZ_H_

#include <stdbool.h>
#include <stdint.h>

#define MATRIZ_MAX_FILAS 4U
#define MATRIZ_MAX_COLUMNAS 4U
#define MATRIZ_TECLA_NINGUNA '\0'

typedef struct {
    uint8_t port;
    uint8_t pin;
} matriz_gpio_t;

typedef struct {
    matriz_gpio_t filas[MATRIZ_MAX_FILAS];
    matriz_gpio_t columnas[MATRIZ_MAX_COLUMNAS];
    uint8_t cantidad_filas;
    uint8_t cantidad_columnas;
    const char *mapa_teclas;
} matriz_config_t;

bool Driver_Matriz_Init(const matriz_config_t *config);
char Driver_Matriz_Scan(void);

#endif