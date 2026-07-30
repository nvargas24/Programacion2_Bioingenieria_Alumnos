#include "driver_led.h"
#include "hal_gpio.h"

void Driver_LED_Init(uint8_t port, uint8_t pin){
    HAL_GPIO_InitPin(port, pin, HAL_GPIO_OUTPUT);
}

void Driver_LED_On(uint8_t port, uint8_t pin){
    HAL_GPIO_WritePin(port, pin, HAL_GPIO_LOW);
}

void Driver_LED_Off(uint8_t port, uint8_t pin){
    HAL_GPIO_WritePin(port, pin, HAL_GPIO_HIGH);
}

void Driver_LED_Toggle(uint8_t port, uint8_t pin){
    HAL_GPIO_TogglePin(port, pin); 
}
