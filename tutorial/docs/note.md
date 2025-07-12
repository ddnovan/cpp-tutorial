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

// Declaración de variable
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