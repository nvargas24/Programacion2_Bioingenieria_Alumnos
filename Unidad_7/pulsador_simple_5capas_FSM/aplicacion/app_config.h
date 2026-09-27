#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_
/* Maquina de estados de la aplicacion. Las lecturas de K3 no tienen antirrebote. */

typedef enum {
    STATE_LED_OFF,       // Apaga el LED y luego vuelve a leer K3.
    STATE_READ_BTN,      // Lee K3 y selecciona el siguiente estado.
    STATE_LED_ON,        // Enciende el LED y luego vuelve a leer K3.
} app_state_t;

#endif
