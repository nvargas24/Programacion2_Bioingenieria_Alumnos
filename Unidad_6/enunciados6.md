#### Problema 1
Hacer que un LED parpadee de forma continua:  
**LED ON $\rightarrow$ delay(2000) $\rightarrow$ LED OFF $\rightarrow$ delay(2000)**   
Mientras esto sucede, el programa debe leer un pulsador por polling para encender un segundo LED de alerta.
¿Es posible detectar el pulsador mientras parpadea el LED?

#### Problema 2
Implemente una FSM para el ***Problema 1***.
¿Es posible evitar usar el estado ***ST_READ_BTN***?

#### Problema 3
Modificar la FSM del ***Problema 2***. En lugar de que el estado base pregunte por polling si el pulsador cambió, el microcontrolador se configura en modo de bajo consumo (Sleep). El pulsador se conecta a una interrupción externa por flanco.

#### Problema 4
Diseñe una FSM que prenda un LED ROJO cuando se presione un pulsador, al soltar el pulsador se apague. Utilizando ISR PINT.

#### Problema 5
Se requiere que un LED RGB de placa cambie de color cada vez que se detecte flanco ascendente/subida al presionar el pulsador K3

> Solo utilizar estados: **ST_ROJO**, **ST_VERDE**, **ST_AZUL**
> siendo **ST_ROJO** su estado inicial.
> Utilizar ***Unidad6/pulsador_ISR_5capas***

#### Problema 6
Al ejercicio anterior, incorpore un pulsador externo. Al ser presionado, en cualquier momento y de detectarse flanco descendente/ bajada se apaga completamente el LED RGB hasta que se vuelva a presionar nuevamente y retoma en **ST_ROJO**.

> Incorporar estado: **ST_APAGADOS**
> Siendo este su estado inicial.
> Utilizar ***Unidad6/pulsador_RGB_ISR_FSM***

