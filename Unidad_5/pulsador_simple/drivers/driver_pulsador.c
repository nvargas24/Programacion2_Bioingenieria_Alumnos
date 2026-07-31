#include "driver_led.h"
#include "hal_gpio.h"

void Driver_Pulsador_Init(uint8_t port, uint8_t pin){
    HAL_GPIO_InitPin(port, pin, HAL_GPIO_INPUT);
}

hal_gpio_state_t Driver_Pulsador_Read(uint8_t port, uint8_t pin){
    return HAL_GPIO_ReadPin(port, pin);
}