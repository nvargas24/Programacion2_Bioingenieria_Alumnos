#include "driver_display.h"
#include "../hal/hal_gpio.h"

static const uint8_t digit_patterns[10] = {
    0x3FU, 0x06U, 0x5BU, 0x4FU, 0x66U,
    0x6DU, 0x7DU, 0x07U, 0x7FU, 0x6FU
};

static display_config_t display_config;
static uint8_t displayed_digits[2] = {0U, 0U};
static uint8_t active_digit = 0U;

static hal_gpio_state_t Driver_Display_ActiveLevel(void)
{
    return (display_config.type == DISPLAY_COMMON_CATHODE) ? HAL_GPIO_HIGH : HAL_GPIO_LOW;
}

static hal_gpio_state_t Driver_Display_InactiveLevel(void)
{
    return (display_config.type == DISPLAY_COMMON_CATHODE) ? HAL_GPIO_LOW : HAL_GPIO_HIGH;
}

static hal_gpio_state_t Driver_Display_DigitActiveLevel(void)
{
    if (display_config.digit_select == DISPLAY_DIGIT_SELECT_LOW) {
        return HAL_GPIO_LOW;
    }
    if (display_config.digit_select == DISPLAY_DIGIT_SELECT_HIGH) {
        return HAL_GPIO_HIGH;
    }
    return Driver_Display_ActiveLevel();
}

static hal_gpio_state_t Driver_Display_DigitInactiveLevel(void)
{
    return (Driver_Display_DigitActiveLevel() == HAL_GPIO_HIGH) ? HAL_GPIO_LOW : HAL_GPIO_HIGH;
}

static bool Driver_Display_PinIsValid(display_gpio_t pin)
{
    return ((pin.port == 0U) && (pin.pin < 32U)) ||
           ((pin.port == 1U) && (pin.pin <= 10U));
}

static bool Driver_Display_ConfigIsValid(const display_config_t *config)
{
    if ((config == 0) || ((config->digit_count != 1U) && (config->digit_count != 2U)) ||
        ((config->type != DISPLAY_COMMON_CATHODE) && (config->type != DISPLAY_COMMON_ANODE)) ||
        ((config->digit_select != DISPLAY_DIGIT_SELECT_DEFAULT) &&
         (config->digit_select != DISPLAY_DIGIT_SELECT_LOW) &&
         (config->digit_select != DISPLAY_DIGIT_SELECT_HIGH))) {
        return false;
    }

    for (uint8_t segment = 0U; segment < 7U; segment++) {
        if (!Driver_Display_PinIsValid(config->segment_pins[segment])) {
            return false;
        }
        for (uint8_t previous = 0U; previous < segment; previous++) {
            if ((config->segment_pins[segment].port == config->segment_pins[previous].port) &&
                (config->segment_pins[segment].pin == config->segment_pins[previous].pin)) {
                return false;
            }
        }
    }

    if (config->digit_count == 2U) {
        for (uint8_t digit = 0U; digit < 2U; digit++) {
            if (!Driver_Display_PinIsValid(config->digit_pins[digit])) {
                return false;
            }
            for (uint8_t segment = 0U; segment < 7U; segment++) {
                if ((config->digit_pins[digit].port == config->segment_pins[segment].port) &&
                    (config->digit_pins[digit].pin == config->segment_pins[segment].pin)) {
                    return false;
                }
            }
        }
        if ((config->digit_pins[0].port == config->digit_pins[1].port) &&
            (config->digit_pins[0].pin == config->digit_pins[1].pin)) {
            return false;
        }
    }

    return true;
}

bool Driver_Display_Init(const display_config_t *config)
{
    if (!Driver_Display_ConfigIsValid(config)) {
        return false;
    }

    display_config = *config;
    active_digit = 0U;
    displayed_digits[0] = 0U;
    displayed_digits[1] = 0U;

    hal_gpio_state_t segment_off = (display_config.type == DISPLAY_COMMON_CATHODE) ? HAL_GPIO_LOW : HAL_GPIO_HIGH;
    hal_gpio_state_t digit_off = Driver_Display_DigitInactiveLevel();

    for (uint8_t segment = 0U; segment < 7U; segment++) {
        display_gpio_t pin = display_config.segment_pins[segment];
        HAL_GPIO_InitPinWithState(pin.port, pin.pin, HAL_GPIO_OUTPUT, segment_off);
    }

    if (display_config.digit_count == 2U) {
        for (uint8_t digit = 0U; digit < 2U; digit++) {
            display_gpio_t pin = display_config.digit_pins[digit];
            HAL_GPIO_InitPinWithState(pin.port, pin.pin, HAL_GPIO_OUTPUT, digit_off);
        }
    }

    return true;
}

void Driver_Display_SetValue(uint8_t value)
{
    if (display_config.digit_count == 2U) {
        value %= 100U;
        displayed_digits[0] = value % 10U;
        displayed_digits[1] = value / 10U;
    } else {
        displayed_digits[0] = value % 10U;
    }
}

void Driver_Display_Refresh(void)
{
    uint8_t pattern = digit_patterns[displayed_digits[active_digit]];
    hal_gpio_state_t active_level = Driver_Display_ActiveLevel();
    hal_gpio_state_t inactive_level = Driver_Display_InactiveLevel();
    hal_gpio_state_t digit_active_level = Driver_Display_DigitActiveLevel();
    hal_gpio_state_t digit_inactive_level = Driver_Display_DigitInactiveLevel();

    if (display_config.digit_count == 2U) {
        for (uint8_t digit = 0U; digit < 2U; digit++) {
            display_gpio_t pin = display_config.digit_pins[digit];
            HAL_GPIO_WritePin(pin.port, pin.pin, digit_inactive_level);
        }
    }

    for (uint8_t segment = 0U; segment < 7U; segment++) {
        display_gpio_t pin = display_config.segment_pins[segment];
        hal_gpio_state_t state = (pattern & (1U << segment)) ? active_level : inactive_level;
        HAL_GPIO_WritePin(pin.port, pin.pin, state);
    }

    if (display_config.digit_count == 2U) {
        display_gpio_t pin = display_config.digit_pins[active_digit];
        HAL_GPIO_WritePin(pin.port, pin.pin, digit_active_level);
        active_digit ^= 1U;
    }
}