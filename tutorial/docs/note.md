---
id: "custom"
---

<!-- @import "note-style.less" -->

<!-- https://detexify.kirelabs.org/classify.html -->
<!-- https://shd101wyy.github.io/markdown-preview-enhanced/#/ -->

<link href="https://fonts.googleapis.com/css2?family=Handlee&display=swap" rel="stylesheet">

# Chapter 1.1

## Statements / sentencias

Tipo de instrucciones que  terminan en ';' (semicolon).

## Función: main

Debe estar presente siempre en lowercase y ser de tipo a devolver **Int**eger (entero).

El nombre main o de cualquier función, objeto se le denomina **identificador**.

```javascript {.line-numbers}
#include <iostream> // Librería para usar std::cout p.ej.
int main() 
{ 
   std::cout << "Hello world!";
   return 0;
}
```
Las sentencias se ejecutan secuencialmente, muestra "Hello world!" por pantalla y devuelve valor '0' al sistema significa que "todo fue okay".

# Chapter 1.2

## Comentarios

Comentarios de **una línea** con '//' (double slash).

Recomendación: escribir comentario encima del trozo de código.

Comentarios de **más de una línea** con '/* */'.

Al nivel de un statement, los comentarios deberían de describir *por qué* el código está haciendo algo.
(Ahora sabemos *por qué* la visión del jugador de ha puesto a 0.)
```javascript {.line-numbers}
// The player just drank a potion of blindness and can not see anything
sight = 0;
```

Nunca escribir *qué* hace el código:

```javascript {.line-numbers}
// Set sight range to 0
sight = 0;
```

Buena práctica: escribir comentarios cómo si estuviésemos explicando a alguien que no tiene ni idea de lo que hace el código.

- Nivel de librería, programa o función, usar comentarios para describir **qué**.

- Dentro de librería, programa o función, usar comentarios para describir **cómo**.

- Nivel de sentencia, usar comentarios para describir **por qué**.

# Chapter 1.3

## Data

Programas están compuestos por instrucciones que manipulan datos para producir un resultado deseado.

Los datos pueden adquirirse desde **fichero**, **base de datos**, **red**, **user input** (entrada de usuario), **source code** (en código fuente).

### Values

Sean números: 1, caracteres 'a', texto "hola".

Se denominan **literals** sí están escritos directamente en código fuente.

### Objects and variables

En C++ el acceso directo a memoria está desaprobado, por tanto accedemos a memoria indirectamente con un **objeto**. Éste representa una región del almacenamiento que puede contener un valor (value).
Un objeto con un nombre representa una **variable**.

Asignación o **allocation**, es la reserva de almacenamiento de un objeto, en runtime (ejecución de un programa cargado en memoria).

```javascript {.line-numbers}
// Definición de variable
int x;

// Declaración o asignación de variable
x = 2;
```

Definiendo múltiples variables:

```javascript {.line-numbers}
int a, int b; // wrong (compiler error)

int a, b; // correct

// Buena práctica: definir cada variable en una sentencia diferente, con comentarios.
```

Resumen:
- Usar objetos para acceder a memoria.
- Objeto con nombre es una variable.
- Cada variable tiene **identificador** (nombre), **tipo** (determinar cómo el valor en memoria debe interpretarse) y **valor**.

# Chapter 1.4

## Asignación 

Cambia el valor de una variable, con operador de asignación '=' (de derecha a izq.).

## Inicialización

Dar valor inicial al objeto, su sintaxis es llamada **initializer**.

Recomendación: Inicializar variables al crearlas.

### Formas de inicialización en C++

```javascript {.line-numbers}
int a;         // default-initialization (no initializer)

// Traditional initialization forms:
int b = 5;     // copy-initialization (initial value after equals sign)
int c(6);   // direct-initialization (initial value in parenthesis)

// Modern initialization forms (preferred):
int d{7};   // direct-list-initialization (initial value in braces)
int e{};      // value-initialization (empty braces)
```

**Copy-initialization**: no se recomienda en C++ moderno. Usado cuando los valores son copiados implícitamente (pasar argumentos a una función por valor, devolver de una función por valor u atrapar excepciones por valor).

**Direct-initialization**: tampoco en C++ moderno. Usado para castings de valores explícitos a otro tipo, por ejemplo *static_cast*.

**List-initialization**: forma moderna de inicializar objetos en C++. List-initialization disallows "narrowing conversions", el compilador produce diagnóstico si intentas list-inicializar una variable con valor que no puede almacenar de forma segura.

**Value-initialization**: con llaves '{}' vacías, en la mayoría de casos inicializará la variable a 0 o cercano a él (se llama zero-initialization cuando esto ocurre también).
Para tipos de clase, se inicializa el objeto a un valor por defecto predefinido por la clase.

## Instanciación

Variable que ha sido creada e inicializada define una **instancia**.

Atributo \[[maybe_unused]] permite establecer variables que no se usen en el programa, evita que el compilador no se 'queje' con errores o warnings debido a esto.

```javascript {.line-numbers}
[[maybe_unused]] double pi { 3.14159 };  // Don't complain if pi is unused
```

# Chapter 1.5

## Librería input/output

Incluir el encabezado *iostream* en la parte superior de cada fichero de código donde se utiliza.

```javascript {.line-numbers}
#include <iostream>
```

### std::cout

Variable predefinida en la librería, enviar datos a la consola para mostrar como texto.

Usar con operador de inserción '<<'.

### std::endl

Usar siempre al terminar un std::cout, incluso al final.

Es a veces poco eficiente, pues muestra un newline y vacía el buffer.

Para no tener que vaciar el buffer, usar **\n** .

Si se usa sólo, indicar que es un caracter con comillas simples: **'\n'**.

### std::cin

Variable predefinida en la librería *iostream*, lee desde teclado, con operador de extracción '>>' nos permite poner en una variable el valor de entrada.

Concatenar operadores de extracción de la siguiente forma, permite realizar más de un input de una sola línea:

```javascript {.line-numbers}
std::cin >> x >> y;
```

Separar sí o sí en la entrada por espacios, tabs o newlines.

Y como std::endl, std::cin usa el buffer.

Por tanto, por cada extracción realizada de caracteres del buffer, se comprueba si es del tipo de la variable dónde se va a almacenar:

- **Si lo es**, entonces la variable almacena el valor. También se aplica si empieza por números y luego hay letras (dejando estas últimas).
- **Si no lo es**, el valor almacenado es distinto, sea 0 para caracteres (por int), número redondeado (para fraccionarios).

# Chapter 1.6

## Uninitialized variables

Variable sin valor conocido asignado (a partir de inicialización o asignación). Puede contener cualquier valor (basura) en la dirección de memoria especificada.

## Undefined behavior

Resultado de ejecutar código cuyo comportamiento no está bien definido por C++.

- Un caso (entre otros) en el que se produce: usar el valor de una variable no inicializada.

## Implementation-defined behavior

Una **implementación** es un compilador específico y su librería estándar asociada, que definen el *comportamiento* eficiente a una plataforma dada, por ejemplo:

```javascript {.line-numbers}
// print how many bytes of memory an int value takes
std::cout << sizeof(int) << '\n';
```

Produce valor *4* y en otras produce *2*.

Este comportamiento debe ser documentado y consistente para una implementación dada.

## Unspecified behavior

Similar al *Implementation-defined behavior* en dónde el comportamiento es definido por la *implementación*, pero la implementación hace que el comportamiento se vuelva inpredecible y variable en base a ejecuciones.

# Chapter 1.7

## Keywords o palabras clave

Palabras reservadas con significado especial en el lenguaje.

## Reglas para nombrar identifiers

- No puede ser una keyword, están reservadas.
- Sólo componerse con **letras** (minúsculas o mayúsculas), **números**, y el guión bajo '**_**'.
- No puede empezar por números.
- C++ es case sensitive, distingue entre variables, ej: *nvalue* y *nValue*.

### Buenas prácticas:

1. Empezar con letra minúscula, para acrónimos o única palabra.

```javascript {.line-numbers}
int value; // conventional
```

2. Usar snake_case o camelCase (intercapped), para variables de más de una palabra.

```javascript {.line-numbers}
int my_variable_name;   // conventional (separated by underscores/snake_case)
int my_function_name(); // conventional (separated by underscores/snake_case)

int myVariableName;     // conventional (intercapped/camelCase)
int myFunctionName();   // conventional (intercapped/camelCase)
```

3. Al trabajar en un programa que ya existe, usar las convenciones de ese programa (aunque no apliquen las buenas prácticas anteriores).

4. La longitud del identificador debe ser proporcional a cómo de específico y accesible es:
4.1 Nombre corto para identifier que exista para pocas sentencias.
4.2 Nombre largo para identifier accesible desde cualquier parte (se puede beneficiar).
4.3 Nombre largo para identifier que represente un valor específico. (tamaño en milímetros, tiempo en segundos, tipo de data, etc).

5. Introducir un comentario para describir para qué la variable va a ser usada (ahorrar nombre largo).

# Chapter 1.8

Whitespace se refiere a caracteres usados para formatear, sean **espacios**, **tabs** o **newlines**.

Elementos como variables, funciones, etc, deben contener whitespaces para que el compilador pueda determinarlos.

## Quoted text

Se concatena el texto separado por sólo whitespaces.

```javascript {.line-numbers}
std::cout << "Hello
     world!"; // Not allowed!
std::cout << "Hello "
     "world!"; //prints "Hello world"
```

Identar el código dentro de dos llaves **{ }**.

Las líneas deben tener como máximo **80 caracteres**.

Por cada línea de continuación (cuando una línea es muy larga y se debe separar), se debe identar una vez más.

Operadores como '**<<**' ó '**+**' deben escribirse al principio de la siguiente línea, no al final.

Alinear código usando whitespace, sean variables o comentarios para mejor lectura.

```javascript {.line-numbers}
cost         = 57;
pricePerItem = 24;

std::cout << "Hello world!\n";                  // cout lives in the iostream library
std::cout << "It is very nice to meet you!\n";  // these comments are easier to read
```

## Guías de estilo

Documentos con convenciones para programar, formateo y mejores prácticas. Por ejemplo:

- [C++ Core Guidelines](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
- [Google](https://google.github.io/styleguide/cppguide.html)
- [LLVM](https://llvm.org/docs/CodingStandards.html)
- [GCC/GNU](https://gcc.gnu.org/codingconventions.html)