#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

#define ANTIREBOTE

typedef enum {
    STATE_LED_OFF,    // Todo apagado (Estado inicial)
    STATE_LED_RED,    // Color Rojo
    STATE_LED_GREEN,  // Color Verde
    STATE_LED_BLUE,   // Color Azul
    STATE_LED_WHITE   // Color Blanco
} app_state_t;

#endif