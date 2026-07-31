#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

#define TIEMPO_PARPADEO_ALERTA_MS   150   // El ritmo rápido del LED Rojo
#define DURACION_TOTAL_ALERTA_MS    3000  // La alerta dura exactamente 3 segundos

typedef enum {
    ESTADO_NORMAL,
    ESTADO_ALERTA
} estado_sistema_t;

#endif