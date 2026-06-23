#### Problema 1
Diseñe e implemente una interfaz gráfica de usuario, considerando lo siguiente:

- Grupo de control N.º 1:
    * Incluir un **QSlider**, un **QDial** y un **QSpinBox**, donde su máximo valor es **127** y el minimo es **0**.
    * Los tres widgets deberán estar sincronizados entre sí, de modo que cualquier cambio realizado en uno de ellos actualice automáticamente el valor de los demás.
    * El valor actual deberá visualizarse mediante un **QLCDNumber**.
- Grupo de control N.º 2:
    * Implementar un segundo conjunto independiente compuesto por un **QSlider**, un **QDial**, un **QSpinBox** y un **QLCDNumber**.
    * Su funcionamiento deberá ser idéntico al del Grupo de control N.º 1, manteniendo la sincronización entre los widgets del grupo.
- Indicador de progreso
    * Incorporar un **QProgressBar** que represente un porcentaje entre **0 % y 100 %**.
        ```cpp
        /*--- cargar valor a QProgressBar ---*/
        // void QProgressBar::setValue(int );
        ui->miBarraProgreso->setValue(value);
        ```
    * El valor mostrado por este control deberá calcularse a partir de la combinación de los valores de ambos **Grupos de control**, de manera que represente el porcentaje alcanzado respecto del valor máximo posible.
    * Cualquier modificación en los controles de los grupos anteriores deberá actualizar automáticamente este indicador.

        - Ejemplo

            Suponga que ambos grupos de control poseen un rango de valores entre **0 y 100**.

            | LCD Grupo 1 | LCD Grupo 2 | Suma | Porcentaje |
            | ----------- | ----------- | ---- | ---------- |
            | 0           | 0           | 0    | 0 %        |
            | 50          | 50          | 100  | 50 %       |
            | 100         | 0           | 100  | 50 %       |
            | 75          | 25          | 100  | 50 %       |
            | 100         | 100         | 200  | 100 %      |

            El porcentaje se calcula mediante la siguiente expresión:

            ```text
            Porcentaje = ((LCD1 + LCD2) / 200) × 100
            ```

            donde **200** corresponde a la suma máxima posible cuando ambos grupos alcanzan su valor máximo (100).
        > **Advertencia**: **QprogressBar** solo acepta del tipo `int`, por lo tanto, se debera truncar el decimal. Para esto utilice `static_cast<int>(per)`, siendo `per` el valor decimal.  

> **UI base** :  UI_genericos -> ControlValue -> mainwindow.ui  
> **Respuesta** : Ejemplos -> ControlCarga

#### Problema 2
Partiendo de la GUI desarrollada en el **Problema 1**, incorpore las siguientes funcionalidades:
- Agregue un **QGroupBox** que contenga tres **QPushButton**.   
    * **Modo**: Configuración del modo de operación  
    Al presionarlo, deberá abrir una ventana secundaria que contenga tres **QRadioButton**, agrupados mediante un **QButtonGroup**, para seleccionar el modo de operación del **QProgressBar**.

        Los modos disponibles serán:   
        * **Ambos**: el QProgressBar se actualiza considerando los valores de los dos grupos de control, tal como se implementó en el Problema 1.
        * **Solo carga 1**: el QProgressBar se actualiza únicamente utilizando el valor del Grupo de Control N.º 1.
        * **Solo carga 2**: el QProgressBar se actualiza únicamente utilizando el valor del Grupo de Control N.º 2.

    * **Limite**: Configuración de rangos   
    Al presionarlo, deberá abrir una ventana secundaria que permita configurar los valores mínimos y máximos de ambos grupos de control.   
    Para ello, la ventana deberá disponer de los controles necesarios utilizando **QSpinBox**.  
    Las modificaciones realizadas deberán reflejarse automáticamente en los widgets correspondientes de la ventana principal, al clickear un **QPushButton** que confirme la configuración.

    * **Color**: Cambio de color   
    Mientras el botón permanezca presionado, el **QGroupBox** al que pertenece deberá cambiar su color de fondo al valor: #A89499
    Al liberar el botón, el color original deberá restaurarse #F3F3F3

- Agregue un segundo **QGroupBox** que contenga tres **QCheckBox**.  

    Cada uno de ellos permitirá habilitar o deshabilitar un tipo de widget en ambos grupos de control:
    * **QCheckBox Slider**: habilita/deshabilita todos los QSlider. 
    * **QCheckBox Dial**: habilita/deshabilita todos los QDial.
    * **QCheckBox SpinBox**: habilita/deshabilita todos los QSpinBox.

- Consideraciones
    * Las ventanas secundarias deberán permanecer abiertas independientemente de la ventana principal (no utilizar popups).
    * La sincronización entre los widgets de cada grupo de control implementada en el **Problema 1** deberá mantenerse en todo momento.

> **UI base** :  UI_genericos -> configValue2 -> mainwindow.ui   
> **UI secundaria base** :  UI_genericos -> selectRadioBtn -> modos.ui   
> **UI secundaria base 2** :  UI_genericos -> configLimites -> limites.ui   

> **Respuesta** : Ejemplos -> ControlCarga2

#### Problema 3
