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
> Estructura de ostream:
`ostream& operator<<(ostream &, Vector &)`

> **Ejemplos base** : sobrecargaOperador4.cpp    
> **Respuesta**: sobrecargaOperador7.cpp


#### Problema 5
En base al ejemplo de operador <<, sobre cargue operador >> para que al utilizar cin>> se solicite al usuario  componentes en x e y de Vector a y Vector b

> Estructura de istream:
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

## Clase 5
####  Problema 1
Validar la `edad` seteada. Considere valida:  **0< edad < 20**. Y que se muestre por terminal, según corresponda:
```text
--- salida esperada ---
> Edad seteada valida
> Edad del gato 35 anios
```

```text
--- salida esperada ---
> Edad seteada no valida 
```

> **Ejemplos base** : encapsulamiento2.cpp    
> **Respuesta**: encapsulamiento3.cpp

####  Problema 2
Modifique el código para que se incremente 3 años mas el valor de edad seteada. Muestre el incremento de edad **uno por uno**
```cpp 
// Ejemplo  
 Ingresar edad: 25
```
```text
 --- salida esperada ---
 > Edad ingresada: 25
 > Edad +1: 26
 > Edad +2: 27
 > Edad +3: 28 
```

> **Ejemplos base** : encapsulamiento2.cpp    
> **Respuesta**: encapsulamiento4.cpp

#### Problema 3
Modificar el código para que no se permitan depósitos negativos. Debe mostrar los siguientes mjs, segun corresponda:
```text
--- salida esperada ---
 > [INFO] Deposito valido
 > [ERROR] Deposito no valido
```
> **Ejemplos base** : encapsulamiento5.cpp     
> **Respuesta**: encapsulamiento6.cpp

#### Problema 4
- Sobrecargar el constructor de la `clase Sensor`: 
Un constructor debe recibir `nombre` y `valor`. 
Otro constructor debe recibir únicamente nombre . 

- Mostrar un mensaje distinto según el constructor utilizado. 

- Crear un objeto (‘humedad’) dinámico utilizando new. 

- Utilizar el método `mostrar()` para visualizar sus datos. 

- Liberar correctamente la memoria utilizando delete . 

- Verificar mediante los mensajes del destructor cuándo se destruyen los objetos.

```text
 --- salida esperada  ---
> [Constructor 1] Sensor inicializado: Temperatura -> 24.5
> [Constructor 2] Sensor inicializado: Presion
> [Constructor 1] Sensor inicializado: Humedad -> 40
> Sensor: Temperatura| Valor: 24.5
> Sensor: Presion
> Sensor: Humedad| Valor: 40
> [Destructor] Liberando sensor: Humedad
> [Destructor] Liberando sensor: Presion
> [Destructor] Liberando sensor: Temperatura 
```

> **Ejemplos base** : constdest1.cpp    
> **Respuesta**: constdest2.cpp

## Clase 6

#### Problema 1
Modificar la `clase Animal` para que el atributo `String raza` sea privado, se inicialice mediante un **constructor** y se acceda con un **getter**.

```cpp
//ejemplo de getter
public:
    ...
    string getRaza() {
        ...
    }
};
```

Modificar la `clase Perro` para agregar un atributo privado `String nombre`, definir un constructor que reciba `String raza` y `String nombre` utilizando el constructor de la **clase base**, y mostrar los datos usando el getter.

Adaptar el `main()` para crear un objeto Perro y utilizar una funcion `mostrar()` de la `clase Perro`, que muestre su nombre y raza.

```cpp
public:
    ...
    void mostrar() {
        ...
    }
};
```
Por ejemplo, considere:    
raza="labrador"    
nombre="Firulais"
```text
--- salida esperada ---
> Nombre: Firulais
> Raza: labrador
```

> **Ejemplos base** : herencia1.cpp    
> **Respuesta**: herencia2.cpp

#### Problema 2
Modificar la `clase Empleado` para que incluya un atributo `nombre` como privado, inicializado mediante un constructor y accesible a través de un getter.

```cpp
// ejemplo de getter
public:
    ...
    string getNombre() {
        ...
    }
```

Adaptar la `clase Programador` agregando un atributo privado `lenguaje`, definiendo un constructor que reciba ambos datos y utilice el constructor de la `clase base`.

Agregar un método que muestre la información del programador utilizando el getter, y actualizar el `main()` para crear un objeto y mostrar sus datos.

```cpp
public:
    ...
    void mostrar() {
        ...
    }
```

Por ejemplo considere:     
nombre="Ana"    
lenguaje="C++"

```text
--- salida esperada ---
> Nombre: Ana
> Lenguaje: C++
```

> **Ejemplos base** : herencia3.cpp    
> **Respuesta**: herencia4.cpp

#### Problema 3            
Considere el ejemplo `herencia4.cpp`.
Se solicita que:      
- Incorpore en `class Empleado` el atributo `empresa` como miembro protected.
- Modifique el constructor de `Empleado` para inicializar los atributos `nombre` y `empresa`.
- Modifique el constructor de `Programador` para que reciba los parámetros:
`string nombre`, `string empresa` y `string lenguaje` El constructor deberá inicializar correctamente el constructor de `Empleado`.
- Modifique el método `mostrar()` para visualizar los atributos `nombre`, `empresa` y `lenguaje` del objeto.
- Implemente el método `bool compareLenguaje(Programador&)` que permita determinar si dos objetos `Programador` utilizan el mismo lenguaje de programación.
- Utilize el método `compareLenguaje()` dentro de `main()` para comparar dos objetos `Programador`.

```cpp
// codigo obligatorio a utilizar en main()
int main() {
    Programador p1("Ana", "TechSoft", "C++");
    Programador p2("Luis", "CodeSystems", "C++");

    p1.mostrar();
    p2.mostrar();
    
    cout << p1.getNombre()<<" y "<< p2.getNombre();
    if (p1.compareLenguaje(p2))
        cout <<" usan el mismo lenguaje" << endl;
    else
        cout << " usan lenguajes distintos" << endl;

    return 0;
}
```

```
--- salida esperada ---
> Nombre: Ana
> Empresa: TechSoft
> Lenguaje: C++
>
> Nombre: Luis
> Empresa: CodeSystems
> Lenguaje: C++
> 
> Ana y Luis usan el mismo lenguaje
```

> **Ejemplos base** : herencia4.cpp    
> **Respuesta**: this5.cpp

## Clase 7

#### Problema 1
Se solicita que:
- `class Animal` se incorporen los atributos protegidos `nombre` y `edad`
- `class Perro` se incorpore atributo privado `raza`.
- `class Gato` se incorpore atributo privado `color`
- Genere los constructores para inicializar los objetos.
- Un método `mostrarInfo()` que muestre la información de cada animal.
- Funciones que permitan presentar cada objeto mostrando sus datos correspondiente.

```
 Al crear un objeto tenga en cuenta que los parametros son:   
    Perro perro1([Nombre], [edad], [raza])  
    Gato gato1([Nombre], [edad], [color])
```

```cpp
// codigo obligatorio a utilizar en main()
int main() {
    Perro perro1("Toby", 5, "Labrador");
    Gato gato1("Michi", 3, "Gris");

    presentar(perro1);
    presentar(gato1);

    return 0;
}
```
```text
--- salida esperada ---
> --- PERRO ---
> Nombre: Toby
> Edad: 5
> Raza: Labrador
> El perro ladra
> 
> --- GATO ---
> Nombre: Michi
> Edad: 3
> Color: Gris
> El gato maulla
```

> **Ejemplos base** : polimorfismo1.cpp    
> **Respuesta**: polimorfismo2.cpp

#### Problema 2
Considere el ejemplo `polimorfismo2.cpp`.    
Se solicita que:"
- Redefina las funciones `void presentar()` como una única función `void presentarAnimal(Animal*)`.
- La función `presentarAnimal(Animal*)` debe ejecutar los métodos `hacerSonido()` y `mostrarinfo()` de las `clases hija` correspondientes del objeto recibido como parametro.
- Realice las modificaciones necesarias en los métodos `mostrarInfo()` y `hacerSonido()` de cada clase para que funcione correctamente la función `presentarAnimal()`.,

```cpp
// codigo obligatorio a utilizar en main()
int main() {
    Perro perro1("Toby", 5, "Labrador");
    Gato gato1("Michi", 3, 7);

    presentarAnimal(&perro1);
    presentarAnimal(&gato1);

    return 0;
}
```
```text
--- Salida esperada ---
> --- PERRO ---
> Nombre: Toby
> Edad: 5
> Raza: Labrador
> El perro ladra: Guau Guau!
> 
> --- GATO ---
> Nombre: Michi
> Edad: 3
> Vidas: 7
> El gato maulla: Miau!
```

> **Ejemplos base** : polimorfismo4.cpp    
> **Respuesta**: polimorfismo3.cpp
