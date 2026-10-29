# Componentes clave de fsl_mrt para LPC845

A continuación se detallan las funciones, macros y enums más importantes del driver `fsl_mrt` para su uso en producción, omitiendo las rutinas de inicialización gestionadas por **PeripheralsTool**.

| Elemento | Tipo | Nombre exacto | Descripción breve |
| :--- | :--- | :--- | :--- |
| **`mrt_chnl_t`** | `enum` | `kMRT_Channel_0` hasta `kMRT_Channel_3` | **Selector de canal**. El LPC845 tiene 4 canales MRT independientes; se usa para indicar a qué canal aplicar una función. |
| **`mrt_mode_t`** | `enum` | `kMRT_RepeatMode` o `kMRT_OneShotMode` | **Modo de operación**. Permite cambiar dinámicamente si el timer cuenta cíclicamente o se dispara una sola vez. |
| **`MRT_StartTimer()`** | Función | `MRT_StartTimer(MRT_Type *base, mrt_chnl_t channel, uint32_t ticks)` | **Dispara el temporizador**. Carga el valor en *ticks* en el canal seleccionado y arranca el conteo descendente de inmediato. |
| **`MRT_StopTimer()`** | Función | `MRT_StopTimer(MRT_Type *base, mrt_chnl_t channel)` | **Detiene el temporizador**. Frena el conteo en el canal indicado de manera explícita escribiendo un cero en su registro. |
| **`MRT_GetStatusFlags()`** | Función | `MRT_GetStatusFlags(MRT_Type *base, mrt_chnl_t channel)` | **Consulta de bandera de interrupción**. Devuelve si el canal llegó a cero. Ideal si haces *polling* (espera sin usar interrupciones). |
| **`MRT_ClearStatusFlags()`** | Función | `MRT_ClearStatusFlags(MRT_Type *base, mrt_chnl_t channel, uint32_t mask)` | **Limpia la bandera**. Es una macro/función crítica para limpiar el flag de interrupción (`kMRT_TimerInterruptFlag`) dentro de la ISR. |
| **`MRT_EnableInterrupts()`** | Función | `MRT_EnableInterrupts(MRT_Type *base, mrt_chnl_t channel, uint32_t mask)` | **Habilita la interrupción**. Permite activar el bit de interrupción (`kMRT_TimerInterruptEnable`) del canal en caliente. |
| **`kMRT_TimerInterruptFlag`** | Macro | `kMRT_TimerInterruptFlag` | **Máscara del Flag**. Constante que identifica el bit de estado de interrupción para pasárselo a las funciones de consulta/limpieza. |

# Componentes clave del driver fsl_pint (LPC845)

Al delegar la inicialización en el PeripheralsTool, las funciones principales a utilizar en el código de aplicación se centran en el control de estados de flanco, lectura de flags y callbacks.

| Elemento | Tipo | Nombre exacto | Descripción breve |
| :--- | :--- | :--- | :--- |
| **`pint_pin_int_t`** | `enum` | `kPINT_PinInt0` hasta `kPINT_PinInt7` | **Selector de canal PINT**. El LPC845 soporta hasta 8 interrupciones de pin independientes simultáneas. |
| **`pint_pin_enable_t`** | `enum` | `kPINT_PinEnableSettingEdgeHigh` / `kPINT_PinEnableSettingEdgeLow` / `kPINT_PinEnableSettingEdgeBoth` | **Configuración de disparo**. Define si el pin responde a flanco ascendente, descendente o ambos. (También existen variantes para nivel: `kPINT_PinEnableSettingLevelHigh` y `Low`). |
| **`pint_cb_t`** | `typedef` | `void (*pint_cb_t)(pint_pin_int_t pintr, uint32_t pmatch_status)` | **Prototipo de Callback**. Firma obligatoria que debe tener tu función de software si usás el despachador de callbacks del SDK. |
| **`PINT_PinInterruptConfig()`** | Función | `PINT_PinInterruptConfig(PINT_Type *base, pint_pin_int_t intr, pint_pin_enable_t enable, pint_cb_t callback)` | **Configura y reasigna en caliente**. Permite cambiar dinámicamente el tipo de flanco/detección de un canal y asignarle una función callback en ejecución. |
| **`PINT_GetStatusFlags()`** | Función | `PINT_GetStatusFlags(PINT_Type *base)` | **Lee las banderas pendientes**. Devuelve una máscara de bits con todos los canales PINT que se han disparado. Útil para hacer *polling* o validaciones específicas. |
| **`PINT_ClearStatusFlags()`** | Función | `PINT_ClearStatusFlags(PINT_Type *base, pint_pin_int_t聚集mask)` | **Limpia la interrupción**. Borra la condición de flag disparado para el canal especificado escribiendo en el registro `IST`. Indispensable si manejás la ISR de forma manual. |
| **`PINT_ClearStatusFlagsByPins()`**| Función | `PINT_ClearStatusFlagsByPins(PINT_Type *base, uint32_t mask)` | **Limpieza masiva**. Borra los flags de múltiples canales PINT de forma simultánea utilizando una máscara de bits completa. |


# Componentes clave del driver fsl_usart (LPC845)

Al usar PeripheralsTool para configurar el reloj, pines y baudios, estas son las macros, estructuras y funciones más importantes a usar en la lógica de aplicación.

## 1. Operaciones Bloqueantes / Polling (Control Directo)

| Elemento | Tipo | Nombre exacto | Descripción breve |
| :--- | :--- | :--- | :--- |
| **`USART_WriteByte()`** | Función | `USART_WriteByte(USART_Type *base, uint8_t data)` | **Escribe un byte**. Envía un único carácter de manera inmediata cargándolo directamente en el registro `TXDATA`. |
| **`USART_ReadByte()`** | Función | `uint8_t USART_ReadByte(USART_Type *base)` | **Lee un byte**. Retorna el carácter que se encuentra alojado de forma pendiente en el registro `RXDATA`. |
| **`USART_WriteBlocking()`**| Función | `USART_WriteBlocking(USART_Type *base, const uint8_t *data, size_t length)` | **Envío en cadena bloqueante**. Detiene la ejecución del hilo principal hasta que se hayan transmitido todos los bytes del buffer. |
| **`USART_ReadBlocking()`** | Función | `status_t USART_ReadBlocking(USART_Type *base, uint8_t *data, size_t length)` | **Recepción bloqueante**. Congela el código hasta recibir la cantidad exacta de bytes definidos en `length`. |
| **`USART_GetStatusFlags()`**| Función | `uint32_t USART_GetStatusFlags(USART_Type *base)` | **Consulta de estado**. Devuelve una máscara de bits con las banderas actuales del periférico. Vital si hacés polling manual. |
| **`kUSART_TxReady`** | Macro | `kUSART_TxReady` | **Flag TX**. Constante de máscara para verificar si el buffer de transmisión está libre y listo para recibir otro byte. |
| **`kUSART_RxReady`** | Macro | `kUSART_RxReady` | **Flag RX**. Constante de máscara para saber si ingresó un nuevo carácter al puerto y está listo para lectura. |

## 2. Operaciones Transaccionales (Asincrónicas por Interrupción)

| Elemento | Tipo | Nombre exacto | Descripción breve |
| :--- | :--- | :--- | :--- |
| **`usart_handle_t`** | `struct` | `usart_handle_t` | **Contexto de la transacción**. Estructura interna del SDK que guarda el estado de los buffers asincrónicos, el callback y contadores de bytes. |
| **`usart_transfer_t`** | `struct` | `usart_transfer_t` | **Paquete de datos**. Estructura temporal donde definís el puntero a la memoria (`data`) y la cantidad de bytes (`dataSize`) para enviar/recibir. |
| **`USART_TransferCreateHandle()`**| Función | `USART_TransferCreateHandle(USART_Type *base, usart_handle_t *handle, usart_transfer_cb_t callback, void *userData)` | **Vincula las interrupciones**. Conecta tu variable `handle` y tu función de callback con el canal USART del SDK para habilitar la lógica en background. |
| **`USART_TransferSendNonBlocking()`**| Función | `status_t USART_TransferSendNonBlocking(USART_Type *base, usart_handle_t *handle, usart_transfer_t *xfer)` | **Envío asincrónico**. Inicia la transmisión del paquete en background usando interrupciones y retorna el control a tu código inmediatamente. |
| **`USART_TransferReceiveNonBlocking()`**| Función | `status_t USART_TransferReceiveNonBlocking(USART_Type *base, usart_handle_t *handle, usart_transfer_t *xfer, size_t *receivedBytes)` | **Recepción asincrónica**. Configura al SDK para que reciba datos en background sin congelar el programa hasta que se complete la trama. |
| **`USART_TransferGetSendCount()`**| Función | `status_t USART_TransferGetSendCount(USART_Type *base, usart_handle_t *handle, size_t *count)` | **Progreso TX**. Devuelve cuántos bytes del buffer asincrónico ya han sido enviados con éxito hasta el momento. |
| **`USART_TransferGetReceiveCount()`**| Función | `status_t USART_TransferGetReceiveCount(USART_Type *base, usart_handle_t *handle, size_t *count)` | **Progreso RX**. Devuelve cuántos bytes han ingresado de forma efectiva al buffer asincrónico configurado. |

# Componentes clave del driver fsl_i2c (LPC845) 

Al usar PeripheralsTool para resolver la inicialización del hardware, estas son las estructuras, enums y funciones críticas para controlar la lógica transaccional de lectura y escritura en periféricos esclavos I2C (como sensores o memorias EEPROM).

## 1. Estructuras de Control Transaccional

| Elemento | Tipo | Nombre exacto | Descripción breve |
| :--- | :--- | :--- | :--- |
| **`i2c_master_transfer_t`** | `struct` | `i2c_master_transfer_t` | **Descriptor de la transacción**. Estructura central en la que se definen la dirección del esclavo, la dirección de lectura/escritura, la subdirección del registro interno y el buffer de datos a transferir. |
| **`i2c_master_handle_t`** | `struct` | `i2c_master_handle_t` | **Contexto de fondo**. Estructura interna del driver para mantener el estado de la comunicación cuando se trabaja con interrupciones asincrónicas. |

## 2. Direccionalidad y Banderas (Enums y Macros)

| Elemento | Tipo | Nombre exacto | Descripción breve |
| :--- | :--- | :--- | :--- |
| **`i2c_direction_t`** | `enum` | `kI2C_Write` / `kI2C_Read` | **Selector de operación**. Define si la transacción va a enviar datos hacia el esclavo o a solicitar una lectura desde él. |
| **`_i2c_master_transfer_flags`** | `enum` | `kI2C_TransferDefaultFlag` / `kI2C_TransferRepeatedStartFlag` | **Control de Bus**. Permite modificar el comportamiento por defecto de la transacción (ejemplo: forzar un *Repeated Start* en lugar de emitir un STOP intermedio). |

## 3. Funciones de Transferencia

| Elemento | Tipo | Nombre exacto | Descripción breve |
| :--- | :--- | :--- | :--- |
| **`I2C_MasterTransferBlocking()`** | Función | `I2C_MasterTransferBlocking(I2C_Type *base, i2c_master_transfer_t *xfer)` | **Transferencia bloqueante**. Ejecuta toda la transacción de I2C (START, Direccionamiento, Envío/Lectura y STOP) mediante *polling*. No retorna hasta que se completa o se detecta un error de NACK o pérdida de arbitraje. |
| **`I2C_MasterTransferCreateHandle()`**| Función | `I2C_MasterTransferCreateHandle(I2C_Type *base, i2c_master_handle_t *handle, i2c_master_transfer_cb_t callback, void *userData)` | **Asociación de Callbacks**. Vincula una variable de tipo `handle` y una rutina callback de software para operar el bus I2C mediante interrupciones asincrónicas. |
| **`I2C_MasterTransferNonBlocking()`** | Función | `I2C_MasterTransferNonBlocking(I2C_Type *base, i2c_master_handle_t *handle, i2c_master_transfer_t *xfer)` | **Transferencia asincrónica**. Inicia la máquina de estados de I2C por interrupción en background y devuelve el control al programa principal de forma inmediata. |
| **`I2C_MasterTransferGetCount()`** | Función | `I2C_MasterTransferGetCount(I2C_Type *base, i2c_master_handle_t *handle, size_t *count)` | **Progreso de bytes**. Consulta la cantidad de bytes que han sido transferidos efectivamente hasta el momento en una transacción no bloqueante activa. |
| **`I2C_MasterTransferAbort()`** | Función | `I2C_MasterTransferAbort(I2C_Type *base, i2c_master_handle_t *handle)` | **Abortar comunicación**. Cancela inmediatamente una transferencia asincrónica en curso y fuerza un estado seguro en el bus. |

# Componentes clave del driver fsl_spi (LPC845)

Al usar PeripheralsTool para resolver la configuración del hardware de reloj y pines, estas son las estructuras, macros y funciones esenciales para controlar la comunicación SPI con tus periféricos esclavos.

## 1. Estructuras de Control Transaccional

| Elemento | Tipo | Nombre exacto | Descripción breve |
| :--- | :--- | :--- | :--- |
| **`spi_transfer_t`** | `struct` | `spi_transfer_t` | **Descriptor de la transferencia**. Estructura donde se asignan los buffers de transmisión (`txData`), recepción (`rxData`), el tamaño de la trama en bytes y banderas especiales de control. |
| **`spi_master_handle_t`** | `struct` | `spi_master_handle_t` / `spi_slave_handle_t` | **Contexto de fondo**. Estructura interna encargada de almacenar y vigilar los estados de transferencia asincrónica por interrupción en background. |

## 2. Configuración Dinámica de Trama (Macros y Enums)

| Elemento | Tipo | Nombre exacto | Descripción breve |
| :--- | :--- | :--- | :--- |
| **`_spi_descriptor_config_flags`** | `enum` | `kSPI_FrameAssertCs` / `kSPI_FrameDeassertCs` | **Control de SSEL (Chip Select)**. Permite indicar si el pin de selección de chip debe mantenerse abajo (activo) o levantarse inmediatamente después de terminar de transmitir el byte actual. |
| **`kSPI_TxReady`** | Macro | `kSPI_TxReady` | **Flag TX**. Constante de máscara utilizada para verificar si el buffer/registro de transmisión por hardware está libre antes de escribir. |
| **`kSPI_RxReady`** | Macro | `kSPI_RxReady` | **Flag RX**. Constante de máscara utilizada para verificar si ha ingresado un byte completo desde el bus y está listo para lectura. |

## 3. Funciones de Transferencia

| Elemento | Tipo | Nombre exacto | Descripción breve |
| :--- | :--- | :--- | :--- |
| **`SPI_MasterTransferBlocking()`** | Función | `SPI_MasterTransferBlocking(SPI_Type *base, spi_transfer_t *xfer)` | **Transferencia bloqueante (Master)**. Envía y recibe simultáneamente la cantidad de bytes indicada utilizando *polling*. El hilo principal se detiene hasta finalizar la operación. |
| **`SPI_MasterTransferCreateHandle()`**| Función | `SPI_MasterTransferCreateHandle(SPI_Type *base, spi_master_handle_t *handle, spi_master_transfer_cb_t callback, void *userData)` | **Asociación de Callbacks**. Conecta la estructura `handle` y la rutina de callback del software para habilitar transferencias asincrónicas controladas por interrupción. |
| **`SPI_MasterTransferNonBlocking()`** | Función | `SPI_MasterTransferNonBlocking(SPI_Type *base, spi_master_handle_t *handle, spi_transfer_t *xfer)` | **Transferencia asincrónica**. Inicia la transmisión/recepción en background mediante la máquina de estados por interrupción del SDK, retornando inmediatamente al lazo principal. |

# Componentes clave del driver fsl_adc (LPC845)

Al usar PeripheralsTool para resolver la inicialización, calibración y asignación de canales, estas son las estructuras, macros y funciones críticas que vas a utilizar en tu código para leer señales analógicas (como el potenciómetro de la placa).

## 1. Estructuras de Conversión y Datos

| Elemento | Tipo | Nombre exacto | Descripción breve |
| :--- | :--- | :--- | :--- |
| **`adc_result_info_t`** | `struct` | `adc_result_info_t` | **Contenedor del resultado**. Estructura donde el SDK vuelca la información leída: el valor digitalizado (`result`), el canal al que pertenece (`channelNumber`) y si hubo sobreescritura (`overrunFlag`). |
| **`adc_seq_config_t`** | `struct` | `adc_seq_config_t` | **Configuración de secuencia**. Estructura para alterar dinámicamente qué canales se van a convertir en ráfaga dentro de la Secuencia A o B. |

## 2. Definiciones de Control (Enums y Macros)

| Elemento | Tipo | Nombre exacto | Descripción breve |
| :--- | :--- | :--- | :--- |
| **`kADC_ConvSeqA`** / **`kADC_ConvSeqB`** | `enum` | `kADC_ConvSeqA` / `kADC_ConvSeqB` | **Selectores de secuencia**. Especifican si querés operar sobre la Secuencia de Conversión A o la B. |
| **`kADC_SequenceConversionDoneFlag`** | Macro | `kADC_SequenceConversionDoneFlag` | **Flag de fin de secuencia**. Máscara de bit que indica que todos los canales activos en la secuencia elegida terminaron de convertirse. |

## 3. Funciones de Disparo y Lectura

| Elemento | Tipo | Nombre exacto | Descripción breve |
| :--- | :--- | :--- | :--- |
| **`ADC_DoSoftwareTriggerConvSeq()`** | Función | `ADC_DoSoftwareTriggerConvSeq(ADC_Type *base, adc_conv_seq_index_t seqIndex)` | **Disparo por software**. Ordena inmediatamente al ADC que empiece a digitalizar los canales asignados a la secuencia indicada (`kADC_ConvSeqA` o B). |
| **`ADC_GetSequenceStatusFlags()`** | Función | `uint32_t ADC_GetSequenceStatusFlags(ADC_Type *base, adc_conv_seq_index_t seqIndex)` | **Chequeo de estado**. Devuelve los flags de la secuencia. Se usa para verificar mediante polling si ya terminó la conversión usando `kADC_SequenceConversionDoneFlag`. |
| **`ADC_ClearSequenceStatusFlags()`** | Función | `ADC_ClearSequenceStatusFlags(ADC_Type *base, adc_conv_seq_index_t seqIndex, uint32_t mask)` | **Limpieza de banderas**. Borra el flag de finalización de secuencia. Obligatorio hacerlo antes de lanzar una nueva conversión o dentro de la ISR. |
| **`ADC_GetChannelConversionValue()`** | Función | `bool ADC_GetChannelConversionValue(ADC_Type *base, uint32_t channelNumber, adc_result_info_t *resultInfoPointer)` | **Extracción de datos**. Busca el último valor convertido del pin analógico indicado por `channelNumber` y llena la estructura `adc_result_info_t`. Devuelve `true` si el dato es nuevo y válido. |

