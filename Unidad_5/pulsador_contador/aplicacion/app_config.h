#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

#define ANTIREBOTE

typedef enum {
    READ_BTN, // Estado de lectura del pulsador
    LED_OFF,        // Todo apagado (Estado inicial)
    LED_RED,        // Color Rojo
    LED_GREEN,      // Color Verde
    LED_BLUE,       // Color Azul
    LED_WHITE       // Color Blanco
} app_state_t;

#endif