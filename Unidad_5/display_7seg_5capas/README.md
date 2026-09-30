# Display de 7 segmentos en 5 capas

Proyecto de ejemplo para LPC845 con una capa de aplicacion, un driver de display, HAL GPIO y los servicios/archivos de placa reutilizados del proyecto original.

## Configuracion

En `aplicacion/app_config.h` se seleccionan el tipo electrico y la cantidad de digitos:

```c
#define DISPLAY_TYPE DISPLAY_COMMON_CATHODE
#define DISPLAY_DIGIT_COUNT 2U
#define DISPLAY_DIGIT_SELECT DISPLAY_DIGIT_SELECT_DEFAULT
```

Use `DISPLAY_COMMON_ANODE` para un display de anodo comun y `DISPLAY_DIGIT_COUNT 1U` para un solo digito. El mapeo de pines esta centralizado en `registros/pin_mux.h`, en orden `a, b, c, d, e, f, g`; el digito `UNITS` es unidades/derecha y `TENS` decenas/izquierda. `registros/pin_mux.c` inicializa esos GPIO. Al cambiar el cableado, actualice las macros `BOARD_DISPLAY_*` y la configuracion de pines de MCUXpresso si corresponde.

El ejemplo cuenta automaticamente de 0 a 9 o de 0 a 99. En una aplicacion propia se puede reemplazar ese contador y usar `Driver_Display_SetValue()`; para dos digitos, llamar a `Driver_Display_Refresh()` cada 1-2 ms mantiene el multiplexado.

## Conexion

Conecte cada salida `a`-`g` al segmento correspondiente mediante una resistencia limitadora de corriente. En dos digitos, conecte cada comun a su pin de seleccion. Verifique el orden de pines y la polaridad del display antes de alimentar. Para corrientes que excedan lo permitido por el microcontrolador, use transistores o un driver externo; no conecte los comunes directamente sin dimensionar la etapa de potencia.

Por defecto, la seleccion del comun usa el nivel habitual de una etapa con transistor: alto para catodo comun y bajo para anodo comun. Si el comun se controla directamente, seleccione nivel bajo para catodo comun o alto para anodo comun. Cambie `DISPLAY_DIGIT_SELECT` a `DISPLAY_DIGIT_SELECT_LOW` o `DISPLAY_DIGIT_SELECT_HIGH` segun su circuito. La seleccion de digitos se multiplexa; un digito individual no requiere pines de seleccion.