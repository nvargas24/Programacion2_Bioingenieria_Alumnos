#include "hal_gpio.h"
#include "fsl_gpio.h"

/* Para LED */
void HAL_GPIO_WritePin(uint8_t port, uint8_t pin, hal_gpio_state_t state){
    GPIO_PinWrite(GPIO, port, pin, (uint8_t)state);
}

void HAL_GPIO_TogglePin(uint8_t port, uint8_t pin){
    GPIO_PortToggle(GPIO, port, (1u << pin));
}

/* Para pulsador */
hal_gpio_state_t HAL_GPIO_ReadPin(uint8_t port, uint8_t pin){
    uint32_t pin_val = GPIO_PinRead(GPIO, port, pin);
    return (pin_val) ? HAL_GPIO_HIGH : HAL_GPIO_LOW;
}
