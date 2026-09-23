#include "driver_pulsador.h"
#include "hal_gpio.h"

void Driver_Pulsador_Init(uint8_t port, uint8_t pin){
    HAL_GPIO_InitPin(port, pin, HAL_GPIO_INPUT);
}

pulsador_state_t Driver_Pulsador_Read(uint8_t port, uint8_t pin){
	hal_gpio_state_t gpio_state = HAL_GPIO_ReadPin(port, pin);

	if(gpio_state == HAL_GPIO_LOW){
		return BTN_PRESSED;
	}
	else if(gpio_state == HAL_GPIO_HIGH){
		return BTN_RELEASED;
	}
	return 0;
}
