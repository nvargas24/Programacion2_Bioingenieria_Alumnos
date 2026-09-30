#ifndef DRIVER_DISPLAY_H_
#define DRIVER_DISPLAY_H_

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint8_t port;
    uint8_t pin;
} display_gpio_t;

typedef enum {
    DISPLAY_COMMON_CATHODE = 0,
    DISPLAY_COMMON_ANODE = 1
} display_type_t;

typedef enum {
    DISPLAY_DIGIT_SELECT_DEFAULT = 0,
    DISPLAY_DIGIT_SELECT_LOW,
    DISPLAY_DIGIT_SELECT_HIGH
} display_digit_select_t;

typedef struct {
    display_gpio_t segment_pins[7];
    display_gpio_t digit_pins[2];
    uint8_t digit_count;
    display_type_t type;
    display_digit_select_t digit_select;
} display_config_t;

bool Driver_Display_Init(const display_config_t *config);
void Driver_Display_SetValue(uint8_t value);
void Driver_Display_Refresh(void);

#endif