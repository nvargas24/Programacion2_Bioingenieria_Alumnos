| Widget | Propiedad | ¿Para qué sirve? |
|----------|----------|----------|
| **QPushButton** | `text` | Texto del botón. |
|  | `enabled` | Habilitar/deshabilitar. |
|  | `icon` | Insertar icono. |
|  | `toolTip` | Ayuda visual al acercar el cursor. |
|  | `styleSheet` | Aplicar estilos visuales. |
| **QLineEdit** | `text` | Entrada de texto. |
|  | `placeholderText` | Texto guía. |
|  | `readOnly` | Solo lectura. |
|  | `maxLength` | Límite de caracteres. |
|  | `alignment` | Alineación del texto. |
| **QDial** | `minimum`, `maximum` | Configuración del rango. |
|  | `notchesVisible`, `wrapping` | Visualización de graduación y comportamiento circular de la perilla. |
| **QSlider** | `orientation` | Define si el slider es horizontal o vertical. |
|  | `minimum`, `maximum` | Establecen el rango mínimo y máximo permitido. |
|  | `value` | Valor actual del control deslizante. |
|  | `tickPosition` | Posición de las marcas visuales de referencia. |
|  | `tickInterval` | Separación entre divisiones o marcas del slider. |
| **QScrollBar** | `orientation` | Define si la barra es horizontal o vertical. |
|  | `minimum`, `maximum` | Límites mínimo y máximo del desplazamiento. |
|  | `value` | Posición actual de la barra de scroll. |
|  | `pageStep` | Cantidad desplazada al hacer clic en la barra. |
|  | `singleStep` | Incremento pequeño al usar las flechas del scroll. |
| **QTextEdit** | `markdown` | Texto inicial en formato Markdown. |
|  | `html` | Permite mostrar contenido HTML enriquecido. |
|  | `placeholderText` | Texto guía cuando el campo está vacío. |
|  | `readOnly` | Permite bloquear la edición del contenido. |
|  | `lineWrapMode` | Configura el ajuste automático de líneas. |
| **QSpinBox** | `minimum`, `maximum` | Definen el rango numérico permitido. |
|  | `value` | Valor numérico actual. |
|  | `singleStep` | Incremento o decremento aplicado por cada paso. |
|  | `suffix` | Texto agregado al final del valor mostrado. |
|  | `prefix` | Texto agregado al inicio del valor mostrado. |
| **QComboBox** | `items` | Lista de opciones disponibles. |
|  | `currentIndex` | Índice actualmente seleccionado. |
|  | `currentText` | Texto actualmente seleccionado. |
|  | `editable` | Permite escribir texto manualmente. |
|  | `maxVisibleItems` | Cantidad máxima de elementos visibles al desplegar. |
| **QLabel** | `text` | Texto mostrado por el label. |
|  | `pixmap` | Imagen mostrada en el widget. |
|  | `alignment` | Alineación horizontal y vertical del contenido. |
|  | `wordWrap` | Permite salto automático de línea. |
|  | `scaledContents` | Escala automáticamente imágenes al tamaño del widget. |
| **QLCDNumber** | `digitCount` | Cantidad de dígitos visibles. |
|  | `segmentStyle` | Estilo visual de segmentos digitales. |
|  | `value` | Valor numérico mostrado. |
|  | `mode` | Sistema numérico utilizado (decimal, hexadecimal, etc.). |
|  | `smallDecimalPoint` | Ajusta el tamaño visual del punto decimal. |
| **QGroupBox** | `title` | Texto del título del grupo. |
|  | `checkable` | Permite habilitar/deshabilitar el grupo mediante checkbox. |
|  | `checked` | Estado actual del checkbox del grupo. |
|  | `alignment` | Alineación del título del grupo. |
|  | `flat` | Reduce el borde visual del GroupBox. |
| **QListWidget** | `sortingEnabled` | Habilita el ordenamiento automático de elementos. |
|  | `viewMode` | Configura modo lista o íconos. |
|  | `selectionMode` | Tipo de selección permitida. |
|  | `spacing` | Espaciado entre elementos de la lista. |
|  | `alternatingRowColors` | Alterna colores entre filas para mejorar la legibilidad. |
| **QTableWidget** | `rowCount` | Cantidad de filas de la tabla. |
|  | `columnCount` | Cantidad de columnas de la tabla. |
|  | `sortingEnabled` | Permite ordenar contenido automáticamente. |
|  | `editTriggers` | Configura cuándo pueden editarse las celdas. |
|  | `selectionBehavior` | Define si se seleccionan filas, columnas o celdas. |
| **QListView** | `model` | Modelo de datos asociado a la vista. |
|  | `viewMode` | Modo de visualización de elementos. |
|  | `selectionMode` | Tipo de selección permitida. |
|  | `uniformItemSizes` | Optimiza el rendimiento usando tamaños uniformes. |
|  | `spacing` | Espaciado visual entre elementos. |
| **QTableView** | `model` | Modelo de datos asociado a la tabla. |
|  | `sortingEnabled` | Permite ordenar filas automáticamente. |
|  | `selectionBehavior` | Configura el comportamiento de selección. |
|  | `showGrid` | Muestra u oculta las líneas divisorias de la tabla. |
|  | `alternatingRowColors` | Alterna colores entre filas para mejorar la lectura. |
| **QRadioButton** | `text` | Texto descriptivo del botón. |
|  | `checked` | Estado seleccionado actual. |
|  | `autoExclusive` | Hace que solo una opción pueda seleccionarse. |
|  | `icon` | Ícono mostrado junto al texto. |
|  | `shortcut` | Tecla rápida asociada al control. |
| **QCheckBox** | `text` | Texto descriptivo asociado. |
|  | `checked` | Estado marcado/desmarcado. |
|  | `tristate` | Permite un estado intermedio además de activo/inactivo. |
|  | `icon` | Ícono mostrado junto al checkbox. |
|  | `shortcut` | Tecla rápida asociada al control. |