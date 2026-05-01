# Ejercicios realizados en clases

## Clase 1

#### Problema 1
- Mostrar primer y ultimo elemento
- Mostrar orden inverso 

> **Ejemplos base** : array1.cpp

> **Respuesta**: array2.cpp

#### Problema 2
- Mostrar valor de v antes y después de ser modificado por ‘p’

- Agregar una variable ‘w’ =12. Realizar cambio de valores entre ‘v’ y ‘w’ utilizando puntero ‘p’ y una variable auxiliar de ser necesario. Mostrar sus valores antes y después del intercambio

> **Ejemplos base** : punteros1.cpp

> **Respuesta1**: punteros2.cpp 

> **Respuesta2**: punteros3.cpp 

## Clase 2

#### Problema 1
Modifique el código para poder cambiar como mínimo 2 campos de la estructura utilizando punteros

> **Ejemplos base** : estructuras3.cpp

> **Respuesta**: estructuras4.cpp 


#### Problema 2
Cree una variable ‘b=87’, asigne un alias para modificar su valor y el de ‘a’ a b=12 y a=64.
Muestre los valores de ‘a’ y ‘b’, antes y después de cambiar su valores, a su vez las direcciones de memoria. 

> **Ejemplos base** : ampersar1.cpp

> **Respuesta**: ampersar2.cpp 

#### Problema 3
- Cree un namespace ‘Operacion’ que realice ambas operaciones sumar, identificado si es para suma de elementos en orden ‘Par’ o ‘Impar’.

- Agregar la función resta en los namespace Impar y Par, siguiendo el mismo criterio que en suma (operar con posiciones impares o pares).

> **Ejemplos base** : namespace1.cpp

> **Respuesta1**: namespace2.cpp 

> **Respuesta2**: namespace3.cpp 

#### Problema 4
Genere una función multiplicar con 4 parámetros Calcular el producto de los 4 valores y validar que sean todos positivos sino mostrar msj :
```text
> [ERROR] Valor no valido
``` 
Calcule el producto de al menos 2 funciones sobrecargadas (incluya el de 4 parámetros).

> **Ejemplos base** : sobrecargaFunciones1.cpp

> **Respuesta**: sobrecargaFunciones2.cpp 

## Clase 3
#### Problema 1
- Sobrecargar la función suma para que acepte tipo (float, float), donde se realiza la operación (a*b+b).
-Muestre por terminal cual suma() utilizo, para cada caso, por ejemplo 
```text
> [INFO] suma de (int, int)
> [INFO] suma de (float, float)
```

> **Ejemplos base** : sobrecargaFunciones3.cpp

> **Respuesta1**: sobrecargaFunciones4.cpp 

> **Respuesta2**: sobrecargaFunciones5.cpp 

#### Problema 2
- Cree una función que sobrecargue un operador, el cual pueda determinar si dos estructuras ‘Vector’ son iguales.
- Cree una función externa `void compareVector(Vector*, Vector*)`que reciba parámetros por referencia para realizar la comparación. A su vez, que muestre por terminal los vectores que se comparan y el resultado.

> **Ejemplos base** : sobrecargaOperador1.cpp

> **Respuesta1 y 2**: sobrecargaOperador2.cpp

#### Problema 3
Agregar sobrecarga de operador para multiplicar un vector por un escalar (un literal), sin importar el orden. A su vez, el producto escalar entre vectores

Sea: **[escalar]*[vector]** o **[vector]*[escalar]** o **[vector]*[vector]**

> **Ejemplos base** : sobrecargaOperador3.cpp

> **Respuesta**: sobrecargaOperador6.cpp

#### Problema 4
Modifique el ejemplo para poder mostrar un vector con versores fundamentales.
Tenga en cuenta todos los casos para poder mostrar adecuadamente, de ser nulo indíquelo textual, solo utilizando `cout << v << endl;`
```text
V=( 2; 4)  --> V=2i+4j
V=( -2; 4)  --> V=-2i+4j
V=( 0; -4)  --> V=-4j
V=( 0; 0)  --> V= vector nulo
```
> Estrucutra de ostream:
`ostream& operator<<(ostream &, Vector &)`

> **Ejemplos base** : sobrecargaOperador4.cpp

> **Respuesta**: sobrecargaOperador7.cpp


#### Problema 5
En base al ejemplo de operador <<, sobre cargue operador >> para que al utilizar cin>> se solicite al usuario  componentes en x e y de Vector a y Vector b

> Estrucutra de istream:
`istream& operator>>(istream &, Vector &)`

> **Ejemplos base** : sobrecargaOperador4.cpp

> **Respuesta**: sobrecargaOperador5.cpp

#### Problema 6
Defina la estructura `Paciente` con los campos: `char nombre[50]`, `int edad`, `float altura`
Cree un menú para cargar estos datos de ‘n’ pacientes. ‘n’ es un entero que debe ingresar por terminal.
Muestre todos los Pacientes y libere la memoria adecuadamente.

> **Ejemplos base** : memDinamic2.cpp

> **Respuesta**: memDinamic3.cpp

#### Problema 7
Modifique el campo nombre de `estructuras4.cpp` utilizando operador `->` 

```cpp
// ejemplo
"Carlos" --> "Felipe"
```

> **Ejemplos base** : string1.cpp

> **Respuesta**: string2.cpp

## Clase 4
####  Problema 1
Implementa un sistema básico de atención de pacientes utilizando una `queue`, se solicita:
Reorganizar la lógica utilizando funciones para: 
- Registrar un paciente 
- Atender un paciente 
- Mostrar el estado actual del registro

Mantener el comportamiento FIFO propio de la estructura `queue`

``` cpp
// Codigo obligatorio a utilizar en main()
int main() {
    queue<string> pacientes;

    cargaPaciente(pacientes, "Juan");
    cargaPaciente(pacientes, "Maria");
    cargaPaciente(pacientes, "Carlos");
    cargaPaciente(pacientes, "Felipe");
    mostrarEstado(pacientes);
    
    atenderPaciente(pacientes);
    mostrarEstado(pacientes);

    cargaPaciente(pacientes, "Patricio");
    mostrarEstado(pacientes);

    atenderPaciente(pacientes);
    mostrarEstado(pacientes);

    return 0;
}
```
> **Ejemplos base** : queue2.cpp

> **Respuesta**: queue3.cpp

#### Problema 2
- Implemente la función `deshacer()` con el ejemplo anterior, utilizando punteros

- Implemente función `rehacer()`, utilizando alias. 

> **Ejemplos base** : stack2.cpp

> **Respuesta**: stack4.cpp