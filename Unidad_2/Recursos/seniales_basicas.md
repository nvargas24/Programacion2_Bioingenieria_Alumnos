| Widget | Señal | Cuándo se emite | Uso habitual |
|---------|---------|---------|---------|
| **QPushButton** | `clicked()` | Al hacer clic sobre el botón. | Ejecutar una acción. |
|  | `pressed()` | Cuando se presiona el botón. | Detectar inicio de una acción. |
|  | `released()` | Cuando se libera el botón. | Detectar fin de una acción. |
|  | `toggled(bool)` | Si el botón es checkable y cambia de estado. | Activar o desactivar opciones. |
| **QLineEdit** | `textChanged(QString)` | Cuando cambia el texto. | Validación en tiempo real. |
|  | `textEdited(QString)` | Cuando el usuario modifica el texto. | Detectar cambios realizados manualmente. |
|  | `editingFinished()` | Al presionar Enter o perder el foco. | Procesar el dato ingresado. |
|  | `returnPressed()` | Al presionar Enter. | Confirmar una entrada. |
| **QDial** | `valueChanged(int)` | Cuando cambia el valor. | Actualizar indicadores o controles. |
|  | `sliderPressed()` | Al comenzar a mover el dial. | Iniciar una operación. |
|  | `sliderReleased()` | Al soltar el dial. | Finalizar una operación. |
| **QSlider** | `valueChanged(int)` | Cuando cambia el valor. | Actualizar variables y visualizaciones. |
|  | `sliderMoved(int)` | Mientras el usuario mueve el control. | Mostrar cambios en tiempo real. |
|  | `sliderPressed()` | Al comenzar el desplazamiento. | Detectar inicio de interacción. |
|  | `sliderReleased()` | Al finalizar el desplazamiento. | Aplicar cambios definitivos. |
| **QTextEdit** | `textChanged()` | Cuando cambia el contenido. | Contar caracteres, guardar cambios. |
|  | `copyAvailable(bool)` | Cuando existe texto seleccionado. | Habilitar botones Copiar/Cortar. |
| **QSpinBox** | `valueChanged(int)` | Cuando cambia el valor. | Actualizar parámetros numéricos. |
|  | `textChanged(QString)` | Cuando cambia el texto mostrado. | Mostrar unidades o validaciones. |
| **QComboBox** | `currentIndexChanged(int)` | Cuando cambia el elemento seleccionado. | Actualizar opciones dependientes. |
|  | `currentTextChanged(QString)` | Cuando cambia el texto seleccionado. | Mostrar información relacionada. |
|  | `activated(int)` | Cuando el usuario selecciona una opción. | Ejecutar acciones específicas. |
| **QGroupBox** | `toggled(bool)` | Cuando cambia su estado (checkable). | Habilitar o deshabilitar grupos de controles. |
| **QListWidget** | `itemClicked(QListWidgetItem*)` | Al hacer clic sobre un elemento. | Seleccionar elementos. |
|  | `itemDoubleClicked(QListWidgetItem*)` | Doble clic sobre un elemento. | Abrir o editar información. |
|  | `currentItemChanged(...)` | Cambia el elemento actual. | Actualizar vistas asociadas. |
| **QTableWidget** | `cellClicked(int, int)` | Al seleccionar una celda. | Mostrar detalles del dato. |
|  | `cellDoubleClicked(int, int)` | Doble clic en una celda. | Editar información. |
|  | `itemChanged(QTableWidgetItem*)` | Modificación de un dato. | Validar cambios. |
| **QListView** | `clicked(QModelIndex)` | Al seleccionar un elemento. | Navegación y selección. |
|  | `doubleClicked(QModelIndex)` | Doble clic sobre un elemento. | Abrir contenido. |
| **QTableView** | `clicked(QModelIndex)` | Selección de una celda. | Mostrar información relacionada. |
|  | `doubleClicked(QModelIndex)` | Doble clic en una celda. | Edición o apertura de datos. |
| **QRadioButton** | `clicked(bool)` | Al seleccionar la opción. | Cambiar modos de operación. |
|  | `toggled(bool)` | Cuando cambia el estado. | Activar configuraciones mutuamente excluyentes. |
| **QButtonGroup** | `buttonClicked(QAbstractButton*)` | Cuando se selecciona un botón del grupo. | Gestionar grupos de opciones. |
|  | `idClicked(int)` | Cuando se selecciona un botón asociado a un ID. | Simplificar la lógica de selección. |
| **QCheckBox** | `clicked(bool)` | Al hacer clic. | Activar o desactivar funciones. |
|  | `toggled(bool)` | Cuando cambia el estado. | Habilitar o deshabilitar widgets. |
|  | `stateChanged(int)` | Al cambiar entre marcado, desmarcado o estado parcial. | Configuraciones avanzadas. |