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
Utilice el proyecto de ***\Unidad_9\ ...\Problema1*** y elimine la verificación manual del pin en el flujo principal y delegue la detección del sensor al módulo de interrupciones externas por hardware de la placa LPC845BRK. El mecanismo de detección por flancos asíncronos debe responder de manera inmediata ante dos eventos opuestos: el momento exacto en que la fuerza supera el umbral y el instante en que el usuario relaja el músculo.    
El bucle principal deja de mirar el hardware y simplemente reacciona a los cambios lógicos globales que la rutina de servicio de interrupción (ISR) registra en memoria, alternando de manera inmediata entre la activación del motor y el reposo.

#### Problema 5
Utilice el proyecto de ***\Unidad_9\ ...\Problema2*** y modifique el sistema para liberar el uso de la CPU mientras la habitación se encuentra estable, delegando la detección del pulsador de llamada al módulo de interrupciones externas por hardware de la placa LPC845BRK.    
Configure el periférico para operar mediante flancos asíncronos de modo que el microcontrolador pueda permanecer en modo de bajo consumo hasta que el paciente requiera asistencia. La rutina de servicio de interrupción (ISR) debe actuar como el evento disparador que altere la secuencia de la máquina, permitiendo que la FSM reestructure su flujo lógico en el bucle principal una vez que el hardware valide la conclusión del evento.