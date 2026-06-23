## Clase 8

#### Problema 1
Diseñe una UX para el ejemplo `estructuras3.cpp`, incluya 1 validacion y 1 mensaje de informacion como minimo.

> **Ejemplos base** : estructuras3.cpp

#### Problema 2
Diseñe una UX para el ejemplo `namespace4.cpp`, incluya validaciones para lo datos ingresados por el usuario y 1 mensaje como minimo.

> **Ejemplos base** : namespace4.cpp

#### Problema 3
Diseñe una UX para el ejemplo `this5.cpp`, incluya una validación donde se verifique que sea un lenguaje valido y otra que el nombre sea texto valido. E incluya 2 mensaje de error, uno para cada caso.
```text
Lenguajes validos:
- C++ 
- Python 
- Java
- Ruby
- Swift
```
> **Ejemplos base** : this5.cpp

## Clase 9

#### Problema 1
Diseñe una GUI para carga de datos basico donde se ingresa `Nombre` y `Edad` del usuario. Estos se cargan con un `QPushButton` indentificado  como `btnIngresar`. Debe limitar la cantidad de caracteres y el tipo que puede ingresar en los `QLineEdit`.

> **UI base** :  UI_genericos -> FormularioBasico -> mainwindow.ui     

> **Respuesta** : Ejemplos -> FormularioBasico

#### Problema 2
Diseñe una GUI para el ejemplo `stack3.cpp` que sea responsive. Recuerde implementar correctamente la UX planteada.

> **UI base** :  UI_genericos -> RegistroAcciones -> mainwindow.ui   
> **UX base** :  UX_genericos -> RegistroAcciones.drawio  
> **Logica base** : Unidad_1 -> stack3.cpp   

> **Respuesta** : Ejemplos -> RegistroAcciones

## Clase 11
#### Problema 1
Partiendo de la plantilla `configGerador.pro` y todos sus archivos (`.ui`, `.h`, `.cpp`), se solicita:

- Las ventanas secundarias se deben mantener independientes de la ventana `MainWindow`, pero deben cerrarse al instante en que se cierre la ventana principal.
- Codificar el getter y setter de la ventana secundaria `modelos` para que la ventana `MainWindow` realice:
    - Carga de elementos del `QComboBox`.
    - Lectura de fecha del `QDateEdit`.
- Personalizar la ventana secundaria `Login`:
    - Cambiar el fondo utilizando un archivo de recursos `.qrc`. Asegurar que la imagen se asigne únicamente al fondo de la ventana y que no afecte a los demás widgets.
    - Cambiar la imagen del widget que representa la foto del usuario.
- Modificar el proyecto para que al iniciar no se abra la ventana `MainWindow`, sino la ventana `Login`.
- Implementar la validación de usuarios en `Login`. Utilizar `QHash` para cargar los usuarios válidos y verificar sus contraseñas:
    ```cpp
    // login.h
    #include <QHash>
    ...

    private:
        QHash<QString, QString> users;
    ```
    ```cpp
    // login.cpp
    /*--- Cargar usuarios válidos ---*/
    // void QHash::insert(const Key &key, const Value &value);
    users.insert("utn", "haedo");   // Usuario y contraseña

    /*--- Verificar usuarios existentes ---*/
    // bool QHash::contains(const Key &key) const;
    users.contains("Felipe"); // Verifica si la CLAVE existe (falso en este ejemplo)

    /*--- Si existe el usuario, se valida la contraseña ---*/
    users.contains("utn");
    ...
    // const QString QHash::value(const Key &key) const;
    if(users.value("utn") == pswLogin){}; // Obtiene el VALOR de la clave "utn" para compararlo
    ```

> **GUI base**: Plantillas -> configGenerador

#### Problema 2
Partiendo del `Problema 1`, se solicita:

- Implementar el getter de la ventana secundaria `Parametros` para que la ventana `MainWindow` muestre en los `QLabel` `labelDatosG` y `labelParametrosG` la información obtenida de la ventana `Parametros`, con el siguiente formato:
    ```cpp
    // Por ejemplo:
    Fuente: Tektronik 2020
    Parametros: 12V - 1A
    ```
- Utilizar el `QPushButton` `btnStatusG` para cambiar el color del `QLabel` `ledStatusG` teniendo en cuenta lo siguiente:
    - Utilizar la señal `toggled(bool)` para poder operar el `QPushButton` como se solicita. Asegurar que la propiedad `checkable` esté habilitada en Qt Designer para dicho widget.
    - Color `rojo`: salida deshabilitada --> al presionar el `QPushButton`.
    - Color `verde`: salida habilitada --> al presionar otra vez el `QPushButton`.
    Para el cambio de color del `QLabel`, utilizar el método `ui->ledStatusG->setStyleSheet(QString);`:
    ```cpp
    // Ejemplo color rojo
    ui->ledStatusG->setStyleSheet(
        "#ledStatusG{ "
        "background-color: rgb(255, 0, 0); "
        "border-radius: 19px; "
        "border: 2px solid black;}"
    );
    // Ejemplo color verde
    ui->ledStatusG->setStyleSheet(
        "#ledStatusG{ "
        "background-color: rgb(0, 255, 0); "
        "border-radius: 19px; "
        "border: 2px solid black;}"
    );
    ```
    >**Importante**: Tener en cuenta que, dependiendo de la resolución de la pantalla, los valores en `px` de los parámetros `border-radius` y `border` deben modificarse para poder visualizar correctamente los bordes.

- Utilizando el mismo `QPushButton` `btnStatusG`, modificar su texto para que cambie a la par del `QLabel` `ledStatusG`:
    - Color `rojo`: cambia el texto a `Habilitar salida` --> al presionar el `QPushButton`.
    - Color `verde`: cambia el texto a `Deshabilitar salida` --> al presionar otra vez el `QPushButton`.

- Registrar cada movimiento o acción realizada en la GUI dentro del `QListWidget` `listMovimientos`:
    ```cpp
    // Ejemplo
    "[INFO] Abre ventana 'Parametros'"
    "[INFO] Cierra ventana 'Parametros'"
    "[INFO] Actualiza datos de fuente"
    "[INFO] Actualiza parametros de fuente"
    "[ADVERTENCIA] Habilita salida"
    "[ADVERTENCIA] Deshabilita salida"
    ...
    ```
 
> **GUI base** :  Plantillas -> configGenerador  
> **Respuesta** : Ejemplos -> configGenerador

