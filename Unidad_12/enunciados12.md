# Sistemas númericos
## Ejercicio 1 
Convierte el número decimal 45 a binario.
> **Solución**: 101101₂ (45 en binario)

## Ejercicio 2
Convierte el número binario 101101 a decimal.
> **Solución**: 45₁₀ (101101 en decimal)

## Ejercicio 3
Convierte el número decimal 255 a hexadecimal.
> **Solución**: FF₁₆ (255 en hexadecimal)

## Ejercicio 4
Convierte el número hexadecimal 3A a decimal.
> **Solución**: 58₁₀ (3A en hexadecimal)

## Ejercicio 5
Convierte el número binario 1101101 a hexadecimal.
> **Solución**: 6D₁₆ (1101101 en binario agrupado de 4 en 4)

## Ejercicio 6
Convierte el número hexadecimal B5 a binario.
> **Solución**: 10110101₂ (B5 en binario)

## Ejercicio 7
Convierte el número decimal 128 a binario.
> **Solución**: 10000000₂ (128 en binario)

## Ejercicio 8
Convierte el número binario 1001111 a hexadecimal.
> **Solución**: 4F₁₆ (1001111 en binario)

## Ejercicio 9
Convierte el número hexadecimal CF a decimal.
> **Solución**: 207₁₀ (CF en hexadecimal)

## Ejercicio 10
Convierte el número decimal 98 a hexadecimal.
> **Solución**: 62₁₆ (98 en hexadecimal)

# Aritmetica binaria
## Ejercicio 1
Realiza la suma binaria de los números enteros `00101000` (40) y `00010100` (20).
> **Solución**: `00111100` (60 en decimal).

## Ejercicio 2
Calcula la resta binaria de los números enteros `01011000` (88) menos `00110100` (52).
> **Solución**: `00100100` (36 en decimal).

## Ejercicio 3
Aplica un desplazamiento lógico a la izquierda de 2 bits (<< 2) al registro entero `00010100` (20).
> **Solución**: `01010000` (80 en decimal).

## Ejercicio 4
Aplica un desplazamiento lógico a la derecha de 1 bit (>> 1) al registro entero `01101100` (108).
> **Solución**: `00110110` (54 en decimal).

## Ejercicio 5
Realiza la operación lógica AND (&) bit a bit entre los valores enteros `01011100` y `00111010`.
> **Solución**: `00011000` (24 en decimal).

## Ejercicio 6
Realiza la operación lógica OR (|) bit a bit entre los valores enteros `01000010` y `00111000`.
> **Solución**: `01111010` (122 en decimal).

## Ejercicio 7
Efectúa la suma de enteros con signo utilizando complemento a 2 entre los números `00011000` (24) y `11110100` (-12).
> **Solución**: `00001100` (12 en decimal).

## Ejercicio 8
Efectúa la resta de enteros con signo utilizando complemento a 2 de `00010000` (16) menos `11111000` (-8).
> **Solución**: `00011000` (24 en decimal).

## Ejercicio 9
Determina el resultado de aplicar la operación AND (&) seguida de un desplazamiento a la derecha de 2 bits (>> 2) a los números enteros `11001100` y `11110000`.
> **Solución**: `00110000` (48 en decimal; operación intermedia AND: `11000000`).

## Ejercicio 10
Determina el resultado de aplicar la operación OR (|) seguida de un desplazamiento a la izquierda de 1 bit (<< 1) a los números enteros `00100100` y `00010010`.
> **Solución**: `01101100` (108 en decimal; operación intermedia OR: `00110116` o `00110110` binario).



# Punto flotante
## Ejercicio 1
Convierte el número decimal `3.5` a binario de 32 bits (1 bit signo, 8 bits exponente con sesgo de 127, 23 bits mantisa).
> **Solución**: `0 10000000 11000000000000000000000` (Hexadecimal: `0x40600000`).

## Ejercicio 2
Convierte el número decimal `-8.25` al formato binario de 32 bits.
> **Solución**: `1 10000010 00010000000000000000000` (Hexadecimal: `0xC1040000`).

## Ejercicio 3
Pasa el código hexadecimal `0x40400000` a su representación decimal original.
> **Solución**: `3.0` (Signo: `+`, Exponente: `1`, Mantisa: `1.1₂` en binario = `1.5` decimal).

## Ejercicio 4
Pasa el código hexadecimal `0xC1200000` a su representación decimal original.
> **Solución**: `-10.0` (Signo: `-`, Exponente: `3`, Mantisa: `1.01₂` en binario = `1.25` decimal).

## Ejercicio 5
Convierte el número decimal `0.5` a binario de 32 bits.
> **Solución**: `0 01111110 00000000000000000000000` (Hexadecimal: `0x3F000000`).

## Ejercicio 6
Representa el número decimal `-12.0` en formato binario de 32 bits y luego exprésalo en hexadecimal.
> **Solución**: `0xC1400000` (Binario: `1 10000010 10000000000000000000000`).

## Ejercicio 7
Determina el valor decimal que corresponde a la secuencia binaria `0 10000010 01100000000000000000000`.
> **Solución**: `6.75` (Signo: `+`, Exponente: `3`, Mantisa: `1.011₂` en binario = `1.375` decimal).

## Ejercicio 8
Convierte el número decimal `0.375` a la estructura binaria de 32 bits.
> **Solución**: `0 01111101 10000000000000000000000` (Hexadecimal: `0x3EEC0000`).

## Ejercicio 9
Representa el número decimal `18.5` directamente en formato hexadecimal de 32 bits.
> **Solución**: `0x41940000` (Binario: `0 10000011 00101000000000000000000`).


# Aproximaciones
## Problema 1
Desarrolla un programa que calcule el costo real de un viaje que dio como resultado $25.678 pesos. Utiliza truncamiento numérico para forzar al sistema a quedarse únicamente con un dígito decimal (el resultado final en pantalla debe ser $25.6).

> **Ejemplo base**: aproximaciones2.cpp
> **Respuesta**: truncamiento1.cpp

## Problema 2
Un vehiculo consume un promedio exacto de 4.12395 litros por vuelta. Escribe un algoritmo que procese este valor y, mediante truncamiento matemático, lo reduzca a exactamente tres dígitos decimales (4.123)

> **Ejemplo base**: aproximaciones2.cpp
> **Respuesta**: truncamiento2.cpp

## Problema 3
La tasa de interés diaria de un cliente genera un saldo de ganancia de $0.054391 dólares. Crea un programa que procese dicho monto y aplique el truncamiento necesario para conservar únicamente cuatro dígitos decimales (0.0543).

> **Ejemplo base**: aproximaciones2.cpp
> **Respuesta**: truncamiento3.cpp

## Problema 4
Un cliente compra un artículo cuyo total con impuestos da $18.3461 dólares. Si se trunca a 18.34, la tienda pierde dinero; si se aproxima correctamente al centavo más cercano, debe cobrarse $18.35. Diseña el programa que realice este redondeo estándar a dos decimales.

> **Ejemplo base**: aproximaciones3.cpp
> **Respuesta**: redondeo1.cpp

## Problema 5
Un paquete de libros pesa exactamente 4.12 kg. Aunque el decimal .12 es muy bajo, las reglas de la aerolínea exigen redondear hacia arriba para cobrar por 5 kg enteros. Desarrolla el algoritmo utilizando la función de techo (ceil) para calcular los kilogramos a facturar.

> **Ejemplo base**: aproximaciones3.cpp
> **Respuesta**: redondeo2.cpp

## Problema 6
Un cliente realiza una compra de $87.90 dólares. Al dividir entre 10, el resultado es 8.79 puntos. A pesar de estar muy cerca de los 9 puntos, el cliente no ha gastado los $90.0 requeridos, por lo que el sistema debe redondear hacia abajo de forma matemática utilizando la función de piso (floor) para otorgar únicamente 8 puntos.

> **Ejemplo base**: aproximaciones3.cpp
> **Respuesta**: redondeo3.cpp

## Problema 7
Un módulo de automatización lee tres señales físicas consecutivas: primero, un actuador calcula 1.43 bares y requiere aproximar hacia arriba para garantizar la presión mínima de apertura; segundo, un sensor mide 4.5678 voltios y debe fijarse a dos decimales sin aumentar el valor por seguridad; y tercero, un transductor registra 11.77 pulsos, necesitando extraer únicamente la cantidad entera de ciclos completos realizados.

> **Respuesta**: aproximacion4.cpp

## Problema 8
Un PLC procesa tres señales de una línea de ensamblaje: primero, un sensor de peso mide 8.124 kg y debe fijarse a dos decimales truncando el valor para no sobreestimar la carga real; segundo, un actuador neumático calcula 3.41 bares y requiere aproximar hacia arriba (techo) para asegurar la fuerza mínima de prensado; y tercero, un transductor de velocidad registra 24.56 Hz y debe redondearse al entero más cercano para sincronizar los motores de forma equitativa.

> **Respuesta**: aproximacion5.cpp

## Problema 9
El firmware de un robot calibra sus subcomponentes: primero, un transductor de nivel calcula que un tanque tiene 14.89 litros y extrae la cantidad entera máxima de ciclos completos (truncando a entero) para evitar succionar aire; segundo, un sensor óptico registra 5.672 lúmenes y debe aproximarse al valor más cercano con dos decimales usando redondeo estándar; y tercero, un actuador lineal calcula que debe desplazarse 0.12 mm y requiere redondear hacia arriba para garantizar que venza la fricción estática del riel.

> **Respuesta**: aproximacion6.cpp