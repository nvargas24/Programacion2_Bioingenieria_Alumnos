#### Problema 1
Se requiere un temporizador con una base de tiempo 1 segundo, considere la frecuencia de reloj a 9MHz y determine los Ticks necesarios para configurar adecuadamente el temporizador.

#### Problema 2
Se requiere un temporizador con una base de tiempo 1 ms, considere la frecuencia de reloj a del microcontrolador LPC845 y determine los Ticks necesarios para configurar adecuadamente el temporizador.

#### Problema 3
Se requiere un temporizador con una base de tiempo 1 segundo, considere la frecuencia de reloj a del microcontrolador (30MHz) y determine los Ticks necesarios para configurar adecuadamente el temporizador.

#### Problema 4
Se requiere que un LED de la placa parpade cada 2 segundos. Tenga en cuenta limitaciones de reloj para el MRT, proponga una FSM con los estados: **ST_LED_OFF** (estado inicial) y **ST_LED_ON**.
El MTR debe activar la ISR cada 200ms

#### Problema 5
Utilizar un segundo canal (CH1) del MRT0 para que un LED VERDE externo parpadee cada 200ms. Sin interrumpir al parpadeo de otro LED VERDE que parpadea cada 500ms por ISR del CH0. Desarrolle la FSM para este caso.
Utilice el ejemplo: **led_blinky_MRT_FSM** 

> Solo utilizar estados: **ST_BLINKY** y **ST_OFF**,
siendo **ST_OFF** su estado inicial.

#### Problema 6
Modifique la FSM anterior para incorporar un tercer estado: **ST_SYNC**. Este se encara de activar el parpadeo del LED ROJO, incorporado en la placa. Este parpadea (ON->OFF->ON->…) cada vez, que los LEDs VERDES se sincronizan en tiempo, es decir, se enciende ambos al mismo tiempo.
Utilice el ejemplo: **led_duo_MRT_FSM**
