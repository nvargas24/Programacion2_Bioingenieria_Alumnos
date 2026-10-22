#ifndef SYS_TIMER_H_
#define SYS_TIMER_H_

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Estructura de un temporizador por software periódico.
 *
 * Permite gestionar intervalos de tiempo no bloqueantes basados en los ticks
 * globales provistos por el módulo sys_time.
 */
typedef struct {
    uint32_t start_tick; /**< Tick de referencia inicial. Se actualiza automáticamente al vencer el intervalo. */
    uint32_t period_ms;  /**< Duración de cada intervalo expresada en milisegundos. */
    bool is_running;     /**< Estado de actividad. Indica si el temporizador está activo (true) o detenido (false). */
} sw_timer_t;

/**
 * @brief Inicia o reinicia el intervalo del temporizador software.
 *
 * Configura el período deseado y activa el temporizador tomando el tiempo actual.
 *
 * @note Requiere obligatoriamente que el contador de ticks de sys_time esté activo y actualizándose.
 * @warning Si el puntero @p timer es NULL, la función no realizará ninguna acción.
 *
 * @param timer     Puntero a la estructura del temporizador a inicializar.
 * @param period_ms Duración del intervalo en milisegundos.
 */
void timerStart(sw_timer_t* timer, uint32_t period_ms);

/**
 * @brief Detiene el funcionamiento del temporizador software.
 *
 * Desactiva la bandera de ejecución para que las verificaciones de vencimiento
 * comiencen a retornar falso.
 *
 * @param timer Puntero a la estructura del temporizador a detener. Si es NULL, no hace nada.
 */
void timerStop(sw_timer_t* timer);

/**
 * @brief Verifica si el intervalo de tiempo del temporizador ha expirado.
 *
 * Si el tiempo se ha cumplido, la función recarga automáticamente el tiempo de
 * referencia (@p start_tick) para iniciar el siguiente ciclo periódico.
 *
 * @param timer Puntero a la estructura del temporizador a verificar.
 *
 * @return true  Si el temporizador está activo y el intervalo de tiempo ya venció.
 * @return false Si el intervalo no ha vencido, si el temporizador está detenido o si el puntero es NULL.
 */
bool timer_isExpired(sw_timer_t* timer);
#endif
