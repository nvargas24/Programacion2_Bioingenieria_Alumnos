# Matriz de pulsadores en 5 capas

Proyecto para leer una matriz de membrana con la LPC845. El driver soporta hasta 4 filas por 4 columnas y el ejemplo incluye mapas para matrices 3x3, 4x3 y 4x4.

## Configuracion

En `aplicacion/app_config.h`, selecciona la dimension:

```c
#define MATRIX_ROW_COUNT 4U
#define MATRIX_COLUMN_COUNT 4U
```

Dimensiones incluidas:

- `3U` filas y `3U` columnas: teclas `1` a `9`.
- `4U` filas y `3U` columnas: teclado telefonico `1` a `9`, `*`, `0`, `#`.
- `4U` filas y `4U` columnas: teclas `1` a `9`, `A` a `D`, `*`, `0`, `#`.

El mapa se recorre por filas. Para usar otra distribucion, cambia `MATRIX_KEYMAP` manteniendo un caracter por tecla y el mismo orden fila-columna. La ultima tecla estable se guarda en `g_ultima_tecla`; el LED azul cambia de estado una vez por pulsacion despues de 20 ms de antirrebote.

## Cableado

Las filas se asignan en `registros/pin_mux.h` y `registros/pin_mux.c`:

| Linea | GPIO | Conector LPC845 |
| --- | --- | --- |
| Fila 0 | P0_16 | CN1[1] |
| Fila 1 | P0_17 | CN1[2] |
| Fila 2 | P0_18 | CN1[3] |
| Fila 3 | P0_19 | CN1[4] |
| Columna 0 | P0_20 | CN1[5] |
| Columna 1 | P0_21 | CN1[6] |
| Columna 2 | P0_22 | CN1[7] |
| Columna 3 | P0_23 | CN1[8] |

Las columnas usan pull-up interno y se leen activas en bajo. En una matriz 3x3 se usan las primeras tres filas y columnas; en una 4x3 se usan cuatro filas y tres columnas. El orden electrico de los ocho contactos del flex varia entre modelos: consulta el datasheet o identifica filas y columnas midiendo continuidad antes de conectarlo. Si el orden del flex difiere, intercambia los pines en `pin_mux.h` y conserva el orden del mapa de teclas.

Las matrices sin diodos se recomiendan para una tecla pulsada a la vez; varias teclas simultaneas pueden producir teclas fantasma. El LED azul confirma la deteccion y `g_ultima_tecla` permite ver el caracter detectado desde el depurador.
