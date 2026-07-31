#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

typedef enum {
    STATE_LED_OFF,       // LED apagado, esperando que se presione K3
    STATE_DEBOUNCE,      // Botón detectado, esperando tiempo de estabilización mecánica
    STATE_LED_ON,        // LED encendido, esperando que se suelte K3
} app_state_t;

#endif