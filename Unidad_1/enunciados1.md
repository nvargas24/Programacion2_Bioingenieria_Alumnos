# Ejercicios extra de lógica

### Ejercicio 1
Escriba un programa para comprobar si un numero es par o impar.

### Ejercicio 2
Escribe un programa para encontrar el mayor de tres numeros.

### Ejercicio 3
Escribe un programa para intercambiar dos numeros usando una funcion. Utiliza pasaje de parametros por referencia.

### Ejercicio 4
Escribe un programa en C++ que permita determinar si dos arreglos son iguales.

> **Condición:**  
Dos arreglos se consideran iguales si contienen los mismos elementos, sin importar el orden, y con la misma cantidad de ocurrencias.

#### Ejemplos:

```cpp
// Son iguales
array_1 = {1, 3, 5, 6, 2};
array_2 = {3, 5, 1, 2, 6};

// NO son iguales
array_1 = {1, 3, 5, 6, 2};
array_2 = {3, 15, 1, 2, 6};

// No son iguales
array_1 = {1, 3, 5, 6, 2};
array_2 = {3, 5, 1, 6};
```
### Ejercicio 5
Escribe un programa para calcular el promedio de todos los
elementos presentes en un arreglo.

### Ejercicio 6
Escribe un programa en C++ que calcule la calificación final de un estudiante a partir de tres notas:

- **Nota de prácticas** → representa el **30%** de la nota final.  
- **Nota teórica** → representa el **60%** de la nota final.  
- **Nota de participación** → representa el **10%** de la nota final.  

El programa debe:
1. Leer las tres notas ingresadas por el usuario.
2. Calcular la nota final aplicando los porcentajes correspondientes.
3. Mostrar el resultado por pantalla.

#### Ejemplo:
```text
Nota de prácticas: 8
Nota teórica: 7
Nota de participación: 9
```

### Ejercicio 7
Escriba un programa que convierta una temperatura ingresada en grados Celsius a Fahrenheit y Kelvin.

### Ejercicio 8
Pida al usuario que ingrese n valores numéricos representando medidas de presión arterial en pacientes. Calcula la media y la desviación estándar de los datos ingresados.

### Ejercicio 9
Escriba un programa que determine si un número ingresado por el usuario es primo o no.

### Ejercicio 10
Escriba un programa en el que el usuario ingrese la velocidad de inicial y ángulo de una masa m de 1Kg y obtenga la altura máxima y el alcance.

### Ejercicio 11
Escriba un programa que genere los primeros n términos de la serie de Fibonacci.

### Ejercicio 12
Pida al usuario que elija entre un cubo o una esfera, luego solicite la dimensión correspondiente y proporcione el volumen del solido geométrico

# Ejercicios con nuevas funcionalidades en C++
### Ejercicio 1
En un sistema de asistencia médica, se requiere implementar una clase `CalculadoraDosis` que permita calcular la dosis de un medicamento en función de distintos parámetros clínicos del paciente.

La clase deberá implementar métodos sobrecargados llamados `calcularDosis`, contemplando los siguientes casos:

- Cálculo en función del peso (`double peso`)
- Cálculo en función de la edad (`int edad`)
- Cálculo en función del peso y un factor adicional (`float peso, float factor`)

Se espera que el diseño permita reutilizar el mismo nombre de función, diferenciando su comportamiento según los parámetros recibidos.

```cpp
// Ejemplo de uso
CalculadoraDosis calc;

calc.calcularDosis(70.0);
calc.calcularDosis(30);
calc.calcularDosis(70.0, 1.2);
```
```text
--- salida esperada ---
[INFO] Dosis calculada: 140 mg
[INFO] Dosis calculada: 80 mg
[INFO] Dosis ajustada: 168 mg
```
**Consideraciones**: 
- Se debe utilizar sobrecarga de funciones.
- No se permite usar nombres distintos para cada método.
- Puede definirse una lógica simple para el cálculo (no se evalúa exactitud clínica).

### Ejercicio 2
En el análisis de señales biomédicas discretas, se requiere modelar una clase `Senial` que permita representar un conjunto de muestras.

La clase deberá contener como atributo:
- `vector<float> muestras`

Se deberá implementar la sobrecarga del operador `+` para permitir la suma de dos señales, generando una nueva señal como resultado.

Asimismo, se deberá sobrecargar el operador `<<` para permitir la visualización de la señal por consola.

Antes de realizar la suma, se deberá validar que ambas señales posean la misma cantidad de muestras.

```cpp
// Ejemplo de uso
Senial s1({1.0, 2.0, 3.0});
Senial s2({4.0, 5.0, 6.0});

Senial s3 = s1 + s2;

cout << s3;
```
```text
--- salida esperada ---
[5.0, 7.0, 9.0]
```
**Consideraciones:**
- Validar dimensiones antes de operar.
- La suma debe ser elemento a elemento.
- El operador << debe facilitar la lectura de los datos.


### Ejercicio 3

En un sistema de monitoreo clínico, se requiere implementar una función que permita calcular la frecuencia cardíaca en función de distintos parámetros disponibles.

Se deberán implementar funciones sobrecargadas llamadas calcularFrecuencia, contemplando los siguientes casos:

- Cálculo a partir de la cantidad de latidos en un intervalo de tiempo (int latidos, float tiempoSeg)
- Cálculo directo si ya se conoce la frecuencia (float frecuencia)
- Cálculo a partir de un vector de intervalos RR (vector<float> rr)

``` cpp
// Ejemplo de uso
calcularFrecuencia(75, 60.0);
calcularFrecuencia(72.5);
calcularFrecuencia({0.8, 0.82, 0.78});
```
```text
--- salida esperada ---
[INFO] Frecuencia: 75 bpm
[INFO] Frecuencia: 72.5 bpm
[INFO] Frecuencia promedio: 75 bpm
```
**Consideraciones:**

- Utilizar sobrecarga de funciones.
- No utilizar nombres distintos.
- Puede definirse una lógica simplificada (caculo no preciso en cada funcion).

### Ejercicio 4

En un sistema de análisis de señales fisiológicas, se requiere modelar una estructura Muestra que represente un valor con su instante de tiempo.

``` cpp
struct Muestra {
    float valor;
    float tiempo;
};
```

Se deberá implementar la sobrecarga del operador + para permitir sumar dos muestras (sumando únicamente sus valores y manteniendo el tiempo de la primera).

Además, se deberá sobrecargar el operador << para mostrar la muestra en formato:

>   **(tiempo: X s, valor: Y)**

```cpp
// Ejemplo de uso
Muestra m1{2.0, 0.1};
Muestra m2{3.5, 0.2};

Muestra m3 = m1 + m2;

cout << m3;
```
```text
--- salida esperada ---
(tiempo: 0.1 s, valor: 5.5)
```
**Consideraciones:**

- Implementar operadores como funciones externas.

### Ejercicio 5

En un sistema hospitalario, se requiere calcular la dosis de un fármaco según distintos criterios clínicos.

Implemente funciones sobrecargadas llamadas **calcularDosis**, contemplando:

- Según peso (float peso)
- Según peso y concentración (float peso, float concentracion)
- Según edad y peso (int edad, float peso)

```cpp
// Ejemplo de uso
calcularDosis(70.0f);
calcularDosis(70.0f, 2.0f);
calcularDosis(30, 70.0f);
```
```text
--- salida esperada ---
[INFO] Dosis: 140 mg
[INFO] Dosis ajustada: 280 mg
[INFO] Dosis pediátrica: 105 mg
```
**Consideraciones:**

- Diferenciar por tipo y cantidad de parámetros.

### Ejercicio 6

En el procesamiento de señales biomédicas, se requiere representar una señal discreta mediante una estructura.

```cpp
struct Senial {
    vector<float> datos;
};
```

Se deberá:

- Sobrecargar el operador + para sumar dos señales.
- Sobrecargar el operador * para escalar (ampliar/ disminuir) una señal por un valor.
- Sobrecargar el operador << para mostrar la señal.

```cpp
// Ejemplo de uso
Senial s1{{1.0, 2.0, 3.0}};
Senial s2{{4.0, 5.0, 6.0}};

Senial suma = s1 + s2;
Senial escalada = s1 * 2.0;

cout << suma;
cout << escala;
```
```text
--- salida esperada ---
[5.0, 7.0, 9.0]
[2.0, 4.0, 6.0]
```

**Consideraciones:**

- Validar dimensiones en la suma.
- Operadores como funciones externas.

### Ejercicio 7

En un sistema hospitalario, se requiere registrar los nombres de pacientes atendidos durante el día.

El programa deberá permitir almacenar múltiples nombres utilizando un `vector<string>`.

Se deberá implementar una función que:

- Permita agregar pacientes
- Permita buscar un paciente por nombre
- Informe si el paciente fue atendido o no

```cpp
// Ejemplo de uso
agregarPaciente("Juan");
agregarPaciente("Maria");

buscarPaciente("Juan");
buscarPaciente("Pedro");
```
```text
--- salida esperada ---
[INFO] Paciente Juan encontrado
[INFO] Paciente Pedro no encontrado
```
**Consideraciones:**

- Usar `vector<string>`
- Recorrer el vector para la búsqueda
- Comparación de strings

### Ejercicio 8

En un sistema de análisis biomédico, se requiere implementar funciones dentro de un namespace anidado.

```cpp
namespace Sistema {
    namespace Analisis {
        // funciones aquí
    }
}
```

Se deberán implementar funciones para:

- Calcular máximo de un vector<float>
- Calcular mínimo de un vector<float>

```cpp
// Ejemplo de uso
Sistema::Analisis::maximo({1.0, 5.0, 3.0});
Sistema::Analisis::minimo({1.0, 5.0, 3.0});
```
```text
--- salida esperada ---
Max: 5
Min: 1
```
**Consideraciones:**

- Namespace anidado
- Uso de vector

### Ejercicio 9

En un sistema de procesamiento de señales, se requiere definir una estructura dentro de un grupo de namespaces.

```cpp
namespace Sistema {
    namespace Datos {
        struct Senial {
            vector<float> datos;
        };
    }
    namespace Operaciones {
    }
}
```
Se deberá implementar en `Operaciones`:

- Operador + para sumar señales
- Función `filtrar(Senial s, float umbral)`
- Operador << para mostrar la señal

```cpp
// Ejemplo de uso
Sistema::Datos::Senial s1{{1,2,3}};
Sistema::Datos::Senial s2{{4,5,6}};

Sistema::Datos::Senial s3 = s1 + s2;

Sistema::Datos::Senial s4 = Sistema::Operaciones::filtrar(s3, 4.0f);

cout << s4;
```

```text
--- salida esperada ---
[5, 7, 9]
[5, 7, 9]
```
**Consideraciones:**

- Operadores definidos fuera del struct
- Uso de múltiples namespaces

### Ejercicio 10

En un sistema de monitoreo de temperatura, se requiere organizar estructuras y operaciones.
```cpp
namespace Sistema {
    namespace Mediciones {
        struct Temperatura {
            float valor;
        };
    }
    namespace Analisis {
    }
}
```
Se deberá implementar:

En `Analisis`:

- Operador > para comparar
- Operador + para promedio
- Función `esCritica(Temperatura t)`

```cpp
// Ejemplo de uso (main)
Sistema::Mediciones::Temperatura t1{36.0};
Sistema::Mediciones::Temperatura t2{39.0};

Sistema::Mediciones::Temperatura t3 = t1 + t2;

if (Sistema::Analisis::esCritica(t2)) {
    cout << "Alerta\n";
}

cout << t3.valor;
```
```cpp
--- salida esperada ---
Alerta
37.5
```

**Consideraciones:**

- Uso de struct
- Operadores en namespace distinto


# Ejercicios extras de POO
### Ejercicio 1
Escriba un programa en C++ que implemente una clase llamada `Circulo`, la cual deberá contener una variable miembro privada correspondiente al radio, e incluir funciones miembro que permitan calcular el área y la circunferencia.

Además, implemente una clase llamada `Rectangulo`, que contenga variables miembro privadas para el largo y el ancho, junto con funciones miembro que permitan calcular el área y el perímetro.

Por último, implemente una clase llamada `Triangulo`, que contenga variables miembro privadas para las longitudes de sus tres lados, e incluya funciones miembro que permitan calcular el área y el perímetro.
Para el calculo del area utilice la formula de Heron, siendo a, b y c sus lados:

$$ s = \frac{a + b + c}{2} $$
$$\text{Área} = \sqrt{s \cdot (s-a) \cdot (s-b) \cdot (s-c)}$$

El programa deberá permitir al usuario seleccionar, mediante un menú de opciones, la figura sobre la cual desea operar. En función de la opción elegida, se deberán solicitar los datos necesarios, realizar los cálculos correspondientes y mostrar los resultados por pantalla. 

Se deberá contemplar además la validación de las entradas ingresadas por el usuario.
Para verificar conforman un triangulo utilice, la desigualdad triangular:
$$ a+b>c $$
$$ a+c>b $$
$$ b+c>a $$

#### Ejemplo de menú

```text
Seleccione una opción:
1. Círculo
2. Rectángulo
3. Triángulo
4. Salir
```

### Ejercicio 2
Escriba un programa para crear una clase llamada (Persona) con variables miembro privadas para nombre, edad y país. Implementa funciones miembros para establecer y obtener los valores de estas variables.
Permita al usuario seleccionar por un menú entre opciones, tenga en cuenta el chequeo de entradas.

### Ejercicio 3
Desarrolle un programa para implementar una clase llamada (Cuenta Bancaria) con variables miembro privadas para número de cuenta y saldo. Incluya funciones miembros para depositar y retirar dinero de la cuenta.
Permita al usuario seleccionar por un menú entre opciones, tenga en cuenta el chequeo de entradas.

### Ejercicio 4
Escriba un programa para crear una clase llamada (Triángulo) con variables miembro privadas para las longitudes de sus tres lados. Implementa funciones miembros para determinar si el triángulo es equilátero, isósceles o escaleno.

### Ejercicio 5
Escriba un programa en C++ para implementar una clase llamada (Fecha) con variables miembro privadas para día, mes y año. Incluye funciones miembros para establecer y obtener estos valores, así como para validar si la fecha es correcta.
Permita al usuario seleccionar por un menú entre opciones, tenga en cuenta el chequeo de entradas.

### Ejercicio 6
Escriba un programa en C++ para implementar una clase llamada Shape (Figura) con funciones virtuales para calcular área y perímetro. Derive clases como Circle (Círculo), Rectangle (Rectángulo) y Triangle (Triángulo) de la clase Shape y sobrescribe las funciones virtuales según corresponda.

### Ejercicio 7
Un sistema hospitalario necesita registrar información básica de pacientes durante su ingreso. Para ello, se solicita modelar una clase `Paciente` que incluya como atributos privados el nombre (`string nombre`), la edad (`int edad`) y la presión arterial (`float presionArterial`).

La inicialización de estos atributos deberá realizarse mediante un constructor que reciba los valores correspondientes. Además, con fines de auditoría del sistema, cada vez que se cree un objeto de esta clase deberá mostrarse un mensaje indicando la creación del paciente, y al destruirse el objeto, el destructor deberá emitir un mensaje informando su eliminación.

```cpp
// Ejemplo de uso:
Paciente p("Juan Perez", 45, 120.5);
```
```text
-- salida esperada --
[INFO] Paciente creado: Juan Perez
[INFO] Paciente eliminado: Juan Perez
```

### Ejercicio 8
En un entorno hospitalario, distintos dispositivos comparten características comunes. Se solicita modelar una clase base `DispositivoMedico`.

La clase deberá incluir:
- `int id`
- `bool encendido`

A partir de esta clase, se deberán implementar las clases derivadas:

- `Oximetro` (atributo adicional: `float saturacionOxigeno`)
- `Electrocardiografo` (atributo adicional: `int frecuenciaCardiaca`)

Cada clase deberá implementar un método `mostrarDatos()` que permita visualizar su estado.

```cpp
// Ejemplo de uso
Oximetro ox(1, true, 98.5);
ox.mostrarDatos();
```
```text
--- salida esperada
Dispositivo ID: 1 - Encendido
Saturacion de Oxigeno: 98.5%
```
**Consideraciones**:
- Utilizar herencia para evitar redundancia.
- Los atributos comunes deben estar en la clase base.

### Ejercicio 9
En un sistema de monitoreo clínico, las alarmas generadas por los dispositivos pueden ser de distinta naturaleza. Se requiere modelar una jerarquía de clases que permita representar este comportamiento de forma flexible.

Defina una clase base abstracta `Alarma` con los siguientes atributos protegidos:
- `int prioridad`
- `std::string mensaje`

La clase deberá declarar un método virtual puro:
- `virtual void activar() = 0;`

A partir de esta clase base, implemente las siguientes clases derivadas:
- `AlarmaVisual`
- `AlarmaSonora`
- `AlarmaCritica`

Cada una deberá redefinir el método `activar()` con un comportamiento específico:
- `AlarmaVisual`: muestra el mensaje en pantalla.
- `AlarmaSonora`: simula una alerta sonora.
- `AlarmaCritica`: combina alerta visual y sonora, destacando la prioridad.

El sistema deberá permitir almacenar objetos de tipo `Alarma` en una misma colección (por ejemplo, un `std::vector<Alarma*>`) y activar cada una de forma polimórfica.

```cpp
// ejemplo de uso
vector<Alarma*> alarmas;

alarmas.push_back(new AlarmaVisual(1, "Presión alta"));
alarmas.push_back(new AlarmaSonora(2, "Frecuencia cardíaca baja"));
alarmas.push_back(new AlarmaCritica(5, "Paro cardíaco"));

for (auto a : alarmas) {
    a->activar();
}
```
```text
--- salida esperada ---
[VISUAL] Presión alta
[SONORA] Frecuencia cardíaca baja
[CRITICA] Paro cardíaco - PRIORIDAD 5
```
**Consideraciones:**
- Uso obligatorio de polimorfismo.
- La clase base debe ser abstracta.
- Gestionar correctamente la memoria dinámica.

### Ejercicio 10
Un sistema de adquisición de datos biomédicos debe soportar distintos modos de funcionamiento según el dispositivo conectado.

Defina una clase base abstracta `DispositivoAdquisicion` con:
- `string id`

Y un método virtual:
- `virtual void adquirir() = 0;`

Implemente las siguientes clases derivadas:
- `AdquisicionContinua`
- `AdquisicionPorEvento`
- `AdquisicionPeriodica`

Cada clase deberá redefinir el método `adquirir()`:
- Continua: simula adquisición constante.
- Por evento: adquiere solo ante una condición.
- Periódica: adquiere en intervalos.

El sistema deberá demostrar el cambio dinámico de comportamiento mediante polimorfismo.

```cpp
// Ejemplo de uso
DispositivoAdquisicion* d;

d = new AdquisicionContinua("DEV001");
d->adquirir();

d = new AdquisicionPorEvento("DEV002");
d->adquirir();
```
```text
--- salida esperada ---
[DEV001] Adquisición continua en curso...
[DEV002] Esperando evento para adquirir datos...
```
**Consideraciones:**
- Uso de punteros a clase base.
- Implementación de métodos virtuales.
- Simulación clara de cada modo de adquisición.

### Ejercicio 11
Un sistema de monitoreo clínico debe permitir visualizar información del paciente mediante distintos tipos de interfaz.

Defina una clase base abstracta `InterfazUsuario` con el método:
- `virtual void mostrar(const string& dato) = 0;`

Implemente las siguientes clases derivadas:
- `InterfazConsola`
- `InterfazGrafica`
- `InterfazArchivo`

Cada una deberá redefinir el método `mostrar()`:
- Consola: imprime por `cout`.
- Gráfica: simula visualización en pantalla.
- Archivo: simula escritura en archivo.

```cpp
// Ejemplo de uso
InterfazUsuario* ui;

ui = new InterfazConsola();
ui->mostrar("Paciente estable");

ui = new InterfazArchivo();
ui->mostrar("Registro guardado");
```
```text
--- salida esperada ---
[CONSOLA] Paciente estable
[ARCHIVO] Registro guardado en archivo
```
**Consideraciones:**
- Separación clara entre lógica y presentación.
- Uso de polimorfismo para intercambiar interfaces.

### Ejercicio 12
En un sistema de procesamiento biomédico, las señales atraviesan múltiples etapas.

Defina una clase base abstracta `EtapaProcesamiento` con:
- `virtual void procesar(vector<float>& señal) = 0;`

Implemente las siguientes clases derivadas:
- `Filtrado`
- `Normalizacion`
- `DeteccionEventos`

Cada una deberá modificar la señal según su propósito:
- Filtrado: suaviza valores.
- Normalización: escala los datos.
- Detección: identifica eventos relevantes.

El sistema deberá permitir encadenar múltiples etapas.

```cpp
// Ejemplo de uso
vector<float> señal = {1.0, 2.5, 3.0};

EtapaProcesamiento* etapa1 = new Filtrado();
EtapaProcesamiento* etapa2 = new Normalizacion();

etapa1->procesar(señal);
etapa2->procesar(señal);
```
```text
--- salida esperada ---
Señal filtrada...
Señal normalizada...
```
**Consideraciones:**
- Uso de referencias para modificar la señal.
- Diseño extensible (nuevas etapas).

### Ejercicio 13
En dispositivos médicos como bombas de infusión o estimuladores eléctricos, se requiere controlar distintos tipos de actuadores.

Defina una clase base abstracta `Actuador` con:
- `virtual void ejecutar() = 0;`

Implemente las siguientes clases derivadas:
- `ActuadorBomba`
- `ActuadorElectrico`
- `ActuadorNeumatico`

Cada clase deberá redefinir el método `ejecutar()` con su comportamiento específico.

El sistema deberá poder operar distintos actuadores a través de una única interfaz común.

```cpp
// Ejemplo de uso
vector<Actuador*> actuadores;

actuadores.push_back(new ActuadorBomba());
actuadores.push_back(new ActuadorElectrico());

for (auto a : actuadores) {
    a->ejecutar();
}
```
```text
--- salida esperada ---
[BOMBA] Infusión iniciada
[ELECTRICO] Estimulación aplicada
```

**Consideraciones:**
- Uso obligatorio de polimorfismo.
- Diseño orientado a extensibilidad.
- Simulación clara del comportamiento de cada actuador.

# Ejercicios extras preprocesador
### Ejercicio 1
Escribe un programa en C++ que permita realizar operaciones matemáticas básicas entre dos números.

El programa debe:
1. Leer dos números ingresados por el usuario.
2. Calcular las siguientes operaciones: Suma, resta, multiplicación y división
3. Mostrar los resultados por pantalla.

>**Condición adicional (uso de preprocesador)**:
>El programa debe permitir trabajar en dos modos
>- **Modo entero (`int`)** → cuando no se desean decimales.  
>- **Modo decimal (`float`)** → cuando se desean resultados con decimales.  

Para ello, utiliza una directiva del **preprocesador** (por ejemplo, `#define`) que permita cambiar el tipo de dato sin modificar el resto del código.

#### Ejemplo de idea:
```cpp
#define USAR_DECIMALES
```