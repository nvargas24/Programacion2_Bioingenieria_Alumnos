# Unidad 10: Comunicación Serie

## Descripción

En esta unidad se introduce la **comunicación serie**, utilizada para intercambiar información entre dispositivos electrónicos.

## Objetivos

- Comprender el funcionamiento de UART
- Transmitir y recibir datos
- Interactuar con una PC mediante puerto serie

## Contenidos

- Comunicación UART
- Transmisión de datos
- Recepción de datos
- Protocolos básicos

## Estructura de los ejemplos

Los ejemplos incluyen:

- Envío de datos por puerto serie
- Recepción de comandos

## Ejemplo `comm_serial`

El proyecto `comm_serial` implementa una consola interactiva para la LPC845BRK.
La USART0 recibe cada tecla mediante interrupciones; el programa principal
procesa el carácter y ejecuta la acción. La ISR no interpreta comandos ni
controla el LED.

Configura la terminal serial a **115200 baudios, 8 bits, sin paridad, 1 stop
bit y sin control de flujo**. Desactiva el eco local para ver el eco que genera
el firmware. Envía una tecla por vez y espera la respuesta antes de enviar otra.

Comandos disponibles:

| Comando | Acción |
| --- | --- |
| `?` | Muestra la ayuda. |
| `1` | Enciende el LED azul. |
| `0` | Apaga el LED azul. |
| `t` | Invierte el estado del LED azul. |
| `s` | Informa el estado del LED azul. |
| `p` | Prueba la comunicación y responde `pong`. |

Los comandos se ejecutan al presionar la tecla; no es necesario pulsar Enter.
