#include "driver_matriz.h"
#include "../hal/hal_gpio.h"

static matriz_config_t matriz_config;
static bool matriz_inicializada = false;

static bool Driver_Matriz_PinValido(matriz_gpio_t pin)
{
    return ((pin.port == 0U) && (pin.pin < 32U)) ||
           ((pin.port == 1U) && (pin.pin <= 10U));
}

static bool Driver_Matriz_MismaPin(matriz_gpio_t primero, matriz_gpio_t segundo)
{
    return (primero.port == segundo.port) && (primero.pin == segundo.pin);
}

static bool Driver_Matriz_ConfigValida(const matriz_config_t *config)
{
    if ((config == 0) || (config->cantidad_filas == 0U) ||
        (config->cantidad_filas > MATRIZ_MAX_FILAS) ||
        (config->cantidad_columnas == 0U) ||
        (config->cantidad_columnas > MATRIZ_MAX_COLUMNAS) ||
        (config->mapa_teclas == 0)) {
        return false;
    }

    for (uint8_t fila = 0U; fila < config->cantidad_filas; fila++) {
        if (!Driver_Matriz_PinValido(config->filas[fila])) {
            return false;
        }
        for (uint8_t anterior = 0U; anterior < fila; anterior++) {
            if (Driver_Matriz_MismaPin(config->filas[fila], config->filas[anterior])) {
                return false;
            }
        }
        for (uint8_t columna = 0U; columna < config->cantidad_columnas; columna++) {
            if (Driver_Matriz_MismaPin(config->filas[fila], config->columnas[columna])) {
                return false;
            }
        }
    }

    for (uint8_t columna = 0U; columna < config->cantidad_columnas; columna++) {
        if (!Driver_Matriz_PinValido(config->columnas[columna])) {
            return false;
        }
        for (uint8_t anterior = 0U; anterior < columna; anterior++) {
            if (Driver_Matriz_MismaPin(config->columnas[columna], config->columnas[anterior])) {
                return false;
            }
        }
    }

    for (uint16_t indice = 0U; indice < ((uint16_t)config->cantidad_filas * config->cantidad_columnas); indice++) {
        if (config->mapa_teclas[indice] == MATRIZ_TECLA_NINGUNA) {
            return false;
        }
    }

    return true;
}

bool Driver_Matriz_Init(const matriz_config_t *config)
{
    matriz_inicializada = false;
    if (!Driver_Matriz_ConfigValida(config)) {
        return false;
    }

    matriz_config = *config;

    for (uint8_t fila = 0U; fila < matriz_config.cantidad_filas; fila++) {
        matriz_gpio_t pin = matriz_config.filas[fila];
        HAL_GPIO_InitPin(pin.port, pin.pin, HAL_GPIO_OUTPUT);
        HAL_GPIO_WritePin(pin.port, pin.pin, HAL_GPIO_HIGH);
    }

    for (uint8_t columna = 0U; columna < matriz_config.cantidad_columnas; columna++) {
        matriz_gpio_t pin = matriz_config.columnas[columna];
        HAL_GPIO_InitPin(pin.port, pin.pin, HAL_GPIO_INPUT);
    }

    matriz_inicializada = true;
    return true;
}

char Driver_Matriz_Scan(void)
{
    if (!matriz_inicializada) {
        return MATRIZ_TECLA_NINGUNA;
    }

    for (uint8_t fila = 0U; fila < matriz_config.cantidad_filas; fila++) {
        matriz_gpio_t pin = matriz_config.filas[fila];
        HAL_GPIO_WritePin(pin.port, pin.pin, HAL_GPIO_HIGH);
    }

    for (uint8_t fila = 0U; fila < matriz_config.cantidad_filas; fila++) {
        matriz_gpio_t fila_pin = matriz_config.filas[fila];
        HAL_GPIO_WritePin(fila_pin.port, fila_pin.pin, HAL_GPIO_LOW);

        for (uint8_t columna = 0U; columna < matriz_config.cantidad_columnas; columna++) {
            matriz_gpio_t columna_pin = matriz_config.columnas[columna];
            if (HAL_GPIO_ReadPin(columna_pin.port, columna_pin.pin) == HAL_GPIO_LOW) {
                char tecla = matriz_config.mapa_teclas[(fila * matriz_config.cantidad_columnas) + columna];
                HAL_GPIO_WritePin(fila_pin.port, fila_pin.pin, HAL_GPIO_HIGH);
                return tecla;
            }
        }

        HAL_GPIO_WritePin(fila_pin.port, fila_pin.pin, HAL_GPIO_HIGH);
    }

    return MATRIZ_TECLA_NINGUNA;
}