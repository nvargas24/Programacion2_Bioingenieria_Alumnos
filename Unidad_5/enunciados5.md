>Para los siguientes ejercicios realice un correspondiente esquema de conexión, teniendo en cuenta pines de microcontrolador, placa de desarrollo y el periférico correspondiente (utilice esquemático de LPC845BRK)

#### Problema 1
- Verificar funcionamiento de LEDs de forma física utilizando cables
- Realice los siguiente cambios de pines y verifique con ejemplo **led_blinky_lpc** 
  - LED ROJO a PIO0_00 
  - LED VERDE a PIO0_20
  - LED_AZUL a PIO1_2
- ¿Todos los casos pudieron realizarse?

#### Problema 2
Cambiar funcionamiento de ejemplo **led_blinky_lpc** a un LED externo conectado a PIO_08
Utilizando el ejemplo **led_blinky_lpc** , testear comportamiento del LED de LPC845BRK y de LED externo, al cambiar de resistores: 220Ω, 1𝑘Ω 𝑦 10𝑘Ω. ¿cambia comportamiento entre un LED y otro?

#### Problema 3
- Cambiar funcionamiento de ejemplo lpc_gpio_led_output a un pulsador externo conectado a PIO0_16 en configuración pull-up.
- Utilizando el ejemplo lpc_gpio_led_output, al pin anterior cambiar a pull-down.
- ¿qué cambio es necesario, en software, para que el cambio de configuración no afecte a la lógica del proyecto?

#### Problema 4
- Cambiar funcionamiento de ejemplo **led_blinky_5capas** para que parpadee cada 200ms un LED externo en PIO0_21.
- Realice los cambios necesarios para regular la intensidad de brillo del LED con un potenciómetro externo. 
- ¿es posible regular la intensidad de brillo del LED, por hardware, reemplazando el potenciómetro externo con RV1?
De no ser posible, hay otro tipo conexión con RV1 y el LED externo que permita regular su intensidad de brillo? 

#### Problema 5
Implementar un programa en la placa LPC845BRK que encienda el un LED externo en PIO0_16 cuando un pulsador externo en PIO0_17 configurado en pull-up es presionado. Y otro LED externo en PIO0_18 se encienda cuando otro pulsador  externo en PIO0_19 configurado en pull-up no este presionado. Si se presionan ambos pulsadores debe encenderse el LED azul disponible en la placa. Utilice como punto de partida el ejemplo **pulsador_simple_5capas**.

#### Problema 6
Implementar un programa en la placa LPC845BRK que encienda el LED azul (LED_BLUE) durante 500ms y este apagado durante 200ms en cada ciclo. Al llegar a la tercera vuelta, se debe encender el LED verde (LED_GREEN) (indicando el tercer ciclo), con el LED azul apagado. Si se presiona un pulsador externo en configuración pull-down, el LED verde se apaga, el contador se reinicia y el ciclo vuelve a comenzar. Utilice como punto de partida el ejemplo **pulsador_simple_5capas**.

#### Problema 7
Implementar un programa en la placa LPC845BRK que encienda el un LED externo en PIO0_16 con 3.3V cuando un pulsador externo en PIO0_18 configurado en pull-down es presionado. Y otro LED externo en PIO0_17 se encienda con 3.3V cuando otro pulsador externo en PIO0_19 configurado en pull-down no este presionado. Si se presionan ambos pulsadores debe encenderse el LED azul disponible en la placa. Utilice como punto de partida el ejemplo **pulsador_combinacion_5capas**.

#### Problema 8
Se requiere configurar el pin PIO0_4 como entrada digital para conectar un pulsador en pull-up, los pines PIO0_14 y PIO0_13 como salidas digitales, siendo su estado inicial en LOW y HIGH, respectivamente. Determine los registros modificados y el valor en hexadecimal de cada uno. 

#### Problema 9
Determine los registros DIR, SET y CLR, en su estado inicial, de **Problema 6** y **Problema 7**.

#### Problema 10
Para los siguientes registros proponga un esquema de conexión que permita testear su correcta configuración, como mínimo 4 GPIOs distintos.

```
DIR0: 0x00050000
SET0: 0x00010000
CLR0: 0x00040000
```

```
DIR0: 0x080C0000
SET0: 0x00040000
CLR0: 0x08080000
```

```
DIR0: 0x01F00000
SET0: 0x01100000
CLR0: 0x00E00000
```

#### Problema 11
Utilizando la LPC845BRK, implemente un proyecto con las funciones de **display_7seg_5capas** y **matriz_pulsadores_5capas** que considere necesarias, para que se prenda el número  correspondiente al teclado matricial, al ser presionado, en el display. 
