#include "hal_gpio.h"
#include "fsl_gpio.h"

// Banderas estáticas para recordar si el puerto ya fue inicializado por el sistema
static bool gs_port_initialized[2] = {false, false};

void HAL_GPIO_InitPin(uint8_t port, uint8_t pin, hal_gpio_dir_t direction){

    // Solo inicializa el puerto si NO ha sido inicializado previamente
    if (port < 2 && !gs_port_initialized[port]) {
        GPIO_PortInit(GPIO, port); // por defecto  RESETEA el pin configurado - fabricante
        gs_port_initialized[port] = true; // Registra que el puerto ya está activo
    }

    gpio_pin_config_t gpio_config = {
        .pinDirection = (direction == HAL_GPIO_OUTPUT) ? kGPIO_DigitalOutput : kGPIO_DigitalInput,
        .outputLogic = 1u
    };

    GPIO_PinInit(GPIO, port, pin, &gpio_config);
}

void HAL_GPIO_WritePin(uint8_t port, uint8_t pin, hal_gpio_state_t state){
    GPIO_PinWrite(GPIO, port, pin, (uint8_t)state);
}

void HAL_GPIO_TogglePin(uint8_t port, uint8_t pin){
    GPIO_PortToggle(GPIO, port, (1u << pin));
}

hal_gpio_state_t HAL_GPIO_ReadPin(uint8_t port, uint8_t pin){
    uint32_t pin_val = GPIO_PinRead(GPIO, port, pin);
    return (pin_val == 0) ? HAL_GPIO_LOW : HAL_GPIO_HIGH;
}