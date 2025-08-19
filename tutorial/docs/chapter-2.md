---
id: "custom"
---

<!-- @import "note-style.less" -->

<!-- https://detexify.kirelabs.org/classify.html -->
<!-- https://shd101wyy.github.io/markdown-preview-enhanced/#/ -->

<link href="https://fonts.googleapis.com/css2?family=Handlee&display=swap" rel="stylesheet">

# Chapter 2.1

## Funciones

Secuencia **reutilizable** de sentencias.

### User-defined functions

Su estructura se basa en encabezado de la función y cuerpo.

```javascript {.line-numbers}
returnType functionName() // This is the function header (tells the compiler about the existence of the function)
{
    // This is the function body (tells the compiler what the function does)
}
```

Llamar a una función con su nombre y paréntesis: functionName().

### Nested functions

Funciones definidas dentro de otras funciones, **NO están permitidas**.

*Placeholder names* como "foo", "bar", "baz", "goo" no tienen importancia para la demostración de un término.

# Chapter 2.2

## Return values

Especificar si la función va a devolver un valor a la función de llamada con: return type y statement.

- Tipo de return (especifica que valor se retorna a la función caller, void no retorna ningún valor): void, int, double...
- Sentencia de return.

Retornar un valor copiado al caller se denomina **return by value**.

Si el valor de retorno no se usa por el caller, el valor está discarded (sin uso).

## Status codes

Indicar que el programa fue exitoso, es decir se ejecutó y se comportó correctamente.

El estándar de C++ establece 3 status codes:

- 0, EXIT_SUCCESS.
- EXIT_FAILURE.

Son macros del preprocesador definidos en el header **\<cstdlib\>**.

## Value-returning functions

Funciones que retornan un valor, con cualquier tipo distinto de *void*.

(fallos al retornar o no retornar el valor de ese tipo en la sentencia de retorno produce *undefined behavior*)

Buena práctica: retornar un valor en tipos distintos de *void* siempre.

## Significado del valor de retorno

El autor de la función con valor de retorno establece su significado, documentando *qué significa el valor de retorno*.

Ciertas funciones pueden retornar *status codes*, para indicar fallos o no.

## Reusar funciones

Aplicar *DRY* o *Don't Repeat Yourself*, y programación modular: escribir función, testear, comprobar que funciona y reusar.

**Código no modular, redundante y con más riesgo a errores:**
```javascript {.line-numbers}
#include <iostream>

int main()
{
	int x{};
	std::cout << "Enter an integer: ";
	std::cin >> x;

	int y{};
	std::cout << "Enter an integer: ";
	std::cin >> y;

	std::cout << x << " + " << y << " = " << x + y << '\n';

	return 0;
}
```
**Código modular, legible**:
```javascript {.line-numbers}
#include <iostream>

int getValueFromUser()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}

int main()
{
    int x{ getValueFromUser() }; // first call to getValueFromUser
    int y{ getValueFromUser() }; // second call to getValueFromUser

    std::cout << x << " + " << y << " = " << x + y << '\n';

    return 0;
}
```
# Chapter 2.3

## Void functions

Funciones que no retornan ningún valor.

- Añadir: return; es redundante, pues la función *void* ya regresa de por si al *caller*.

- No se pueden usar en expresiones que requieran un valor, por ejemplo:  std::cout.

- Retornar un valor, produce un error de compilación:

```javascript {.line-numbers}
#include <iostream>

void printA()
{
    std::cout << "A\n";
}

int main()
{
    // Return void can't be sent to std::cout
    std::cout << printA() << '\n';

    return 0;
}
```

# Chapter 2.4

## Parámetros y argumentos

Adelantarnos al tiempo con inputs/outputs genéricos usamos parámetros, argumentos y returns.

Un **parámetro** es una variable usada en el header de la función, incializada con un valor dado por el caller de la función.

```javascript {.line-numbers}
// This function has two integer parameters, one named x, and one named y
// The caller will supply the value of both x and y
int add(int x, int y) {
    return x + y;
}
```

Un **argumento** es el valor pasado desde el caller a la función, cuando se realiza una llamada a función.

```javascript {.line-numbers}
add(2, 3); // 2 and 3 are the arguments passed to function add()
```

## Pass by value

La llamada a una función hace que todos los parámetros (*value parameters*) sean creados como variables, y el valor de los argumentos son copiados con copy-initialization a cada parámetro concreto.

## Return values como argumentos

```javascript {.line-numbers}
int main()
{
	int num { getValueFromUser() };
	printDouble(num);
	return 0;
}
```

Cómo *num* sólo se utiliza una vez, podemos directamente devolver el valor, aunque su lectura sea más difícil. También se puede realizar de la primera forma.

```javascript {.line-numbers}
int main() {
	printDouble(getValueFromUser());
	return 0;
}
```

## Unreferenced parameters

No usar parámetros en el cuerpo de la función establece **unreferenced parameters**.

## Unnamed parameters

En una función, el nombre de un parámetro es opcional.

Para casos en los que un parámetro deba existir pero no se use (ej: al quitar un parámetro para no tener que modificar cada llamada a la función), indicar con comentario el *unnamed parameter*.

```javascript {.line-numbers}
void doSomething(int /*count*/) {
}
```

# Chapter 2.5

## Local variables

Variables definidas en el cuerpo de una función son locales.

*Parámetros* de la función también son consideradas variables locales.

## Tiempo de vida de variables locales

Se define entre la creación y destrucción de un objeto.

```javascript {.line-numbers}
int add(int x, int y) // x and y created and initialized here
{
    int z{ x + y };   // z created and initialized here

    return z;
} // z, y, and x destroyed here
```
El objeto destruido se vuelve **inválido** y si se usa, se produce *undefined behavior*.
La memoria usada por el objeto será **deallocated** (liberada).

## Local scope

El *scope* de un identifier determina dónde puede verse y usarse.

Está fuera del scope si no se puede ver ni usar.

Un identifier de una variable local tiene un **scope local**. Usable desde su definición hasta el final de la función.

## Dónde definir variables locales

Buena práctica: definir variables locales lo más cercano a su primer uso, razonablemente.

```javascript {.line-numbers}
#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";
	int x{};       // x defined here
	std::cin >> x; // and used here

	std::cout << "Enter another integer: ";
	int y{};       // y defined here
	std::cin >> y; // and used here

	int sum{ x + y }; // sum can be initialized with intended value
	std::cout << "The sum is: " << sum << '\n';

	return 0;
}
```

## Uso de parámetros vs variables locales

Cuando una variable se necesita en una función:

- Usar un parámetro cuando el caller pasará como argumento un valor inicial para la variable.

- Usar variable local si no se cumple lo anterior.

Ejemplo:
```javascript {.line-numbers}
#include <iostream>

int getValueFromUser(int val) // val is a function parameter
{
    std::cout << "Enter a value: ";
    std::cin >> val;
    return val;
}

int main()
{
    int x {};
    int num { getValueFromUser(x) }; // main must pass x as an argument

    std::cout << "You entered " << num << '\n';

    return 0;
}
```

En este caso, esta forma es **correcta**:

```javascript {.line-numbers}
#include <iostream>

int getValueFromUser()
{
    int val {}; // val is a local variable
    std::cout << "Enter a value: ";
    std::cin >> val;
    return val;
}

int main()
{
    int num { getValueFromUser() }; // main does not need to pass anything

    std::cout << "You entered " << num << '\n';

    return 0;
}
```

# Chapter 2.6

## ¿Por qué usar funciones?

Beneficios:

- Organización: reducir complejidad, al separar funcionalidades del *main*.
- Reutilización: evitar código duplicado o repetido.
- Testeo: facilitar el testing por funciones.
- Extensibilidad: realizar cambios en una función produce efectos en cualquier llamada.
- Abstracción: Usar una función sólo se basa en conocer su nombre, entradas, salidas y dónde vive.

### Cuándo y cómo usar funciones

Deben ser funciones:

- Grupos de sentencias que aparezcan más de una vez en el programa (escribir numerosas veces de la misma forma).
- Código con entradas y salidas bien definidas, por ejemplo un listado de items a ordenar (código que ordena es el body, lista sin ordenar como entrada, lista ordenada como salida).
- Una función debe realizar una única tarea.
- Cuando una función se vuelve muy larga, complicada o difícil de entender hay que aplicar **refactoring**, dividiendo en sub-funciones.

# Chapter 2.7

Buena práctica: al resolver errores o warnings de compilación, resolver el primer problema y compilar de nuevo.

En el caso en que el compilador no encuentre una función:

## Reordenar las definiciones

Establecer más arriba las funciones de las que se realizan o no llamadas, por ejemplo *main* como último.

## Usar forward declaration

Afrontar el problema de funciones que se llamen a sí mismo y dónde ubicarlas.

**Forward declaration** indica al compilar la existencia de un *identifier* antes de definirlo.

Usar *function declaration statement* terminada en ';'.

```javascript {.line-numbers}
int add(int x, int y); // function declaration includes return type, name, parameters, and semicolon.  No function body!
int add(int, int); // valid function declaration too! but less readable.
```

Nos permite separar declaraciones en otro fichero.

No definir una función (su *body*) produce:

- Compilación y ejecución correcta, **si no hay llamada a la función**.
- Compilación correcta pero linking incorrecto, **si hay llamada a la función**.

## Declarations vs definitions

### Declaración
Existe un identifier con su tipo de información.

```javascript {.line-numbers}
int add(int x, int y); // tells the compiler about a function named "add" that takes two int parameters and returns an int.  No body!
int x;                 // tells the compiler about an integer variable named x
```

### Definición

Declaración que implementa o instancia el identifier.

```javascript {.line-numbers}
// because this function has a body, it is an implementation of function add()
int add(int x, int y)
{
    int z{ x + y };   // instantiates variable z
    return z;
}

int x;                // instantiates variable x
```

## One definition rule (ODR)

### Partes de la regla:

1. En un fichero, cada función, variable o tipo en un scope determinado sólo tiene una definición.
2. En un programa, cada función o variable en un scope determinado sólo tiene una definición.
3. Tipos, plantillas, funciones y variables inline pueden duplicar definiciones en diferentes ficheros, si la definición es idéntica.

# Chapter 2.8

## Multiple code files

Para programas grandes, se separan en ficheros para organización y reusabilidad.

Está permitido usar *forward declaration* de la siguiente forma:


**main.cpp:**
```javascript {.line-numbers}
#include <iostream>

int add(int x, int y); // needed so main.cpp knows that add() is a function defined elsewhere

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    return 0;
}
```
**add.cpp:**
```javascript {.line-numbers}
int add(int x, int y)
{
    return x + y;
}
```

Como el compilador compila cada fichero de código individualmente, en caso de usar std::cout o std::cin en add.cpp habría que incluir la cabecera.

# Chapter 2.9

## Naming collisions

C++ requiere que todos los *identifiers* no sean ambiguos.

Si el compilador o linkador encuentra dos identifiers idénticos producirá un error denominado **naming collision** o **naming conflict**.

### Scope regions

Área de código fuente dónde cada identifier es considerado distinto de nombres declarados en otros scopes.

El *body* de una función es un **scope region**.

### Namespaces

Otro tipo de *scope region* denominado **namespace scope** para desambiguar nombres definidos dentro con otros nombres idénticos de otros scopes.

Sólo deben contener declaraciones y definiciones (variables y funciones), **NO sentencias ejecutables** fuera de una definición de una función.

<u>**Global namespace or scope**</u>
Nombres no definidos dentro de una clase, función o namespace.
Ejemplo: **main()**.

Se recomienda:

- Identifiers declarados en *global scope* están en scope desde su declaración hasta *eof* (end of file).
- Evitar definir variables en el *global scope*.

## Explicit namespace qualifier std::

Al usar un identifier definido dentro de un namespace fuera del global, hay que indicar al compilador que ese identifier vive dentro del namespace.

De forma explícita: usar prefijo **std::**

### Scope resolution operator '::'

De la forma (::name -> se asume el *global namespace*): 
**Identifier::name**

Al incluir el prefijo, el identifier es una **qualified name**.

# Chapter 2.10

## Preprocessor

Modifica el código del programa, quitando comentarios, asegurando que cada fichero termine en un *newline* y procesa las **directivas #include**.

### Preprocessor directives

Instrucciones que indican al preprocesador ciertas tareas para manipular texto.

## Macro defines

La directiva **#define** se usa para crear una **macro**, que es una regla para definir como el texto de entrada es convertido en texto de salida reemplazado.

### Tipos de macros

<u>Function-like macros:</u> No se recomiendan usar (ya existen las funciones)
<u>Object-like macros:</u>
```javascript {.line-numbers}
#define IDENTIFIER
#define IDENTIFIER substitution_text
```
Buena práctica: Evitar usar macros con texto sustituido a menos que no haya alternativas viables.

## Conditional compilation

*Conditional compilation* preprocessor directives permite especificar bajo qué condiciones algo compila o no.

Directivas más comunes son: #ifdef, #ifndef y #endif.

<u>**#ifdef:**</u> Comprueba si un identifier fue definido anteriormente con *#define*.

<u>**#ifndef:**</u> Comprueba si un identifier NO fue definido anteriormente con *#define*.

Recomendación: Usar directiva **# if 0** para excluir un bloque de código de ser compilado.

```javascript {.line-numbers}
#include <iostream>

int main()
{
    std::cout << "Joe\n";

#if 0 // Don't compile anything starting here
    std::cout << "Bob\n";
    /* Some
     * multi-line
     * comment here
     */
    std::cout << "Steve\n";
#endif // until this point

    return 0;
}
```

## Scopes of #defines

Las directivas se resuelven antes de compilar, de arriba a abajo en todo el fichero.

Por tanto, aunque no se recomienda, no importa definir directivas dentro de funciones, funcionarán igual para identifiers en cualquier otro sitio.

# Chapter 2.11

## Header files

Con extensión **.h** propagan *forward declarations* hacia un fichero de código (.cpp).

### Partes de *header files*

1. **Header guard**.
2. Contenido, sean *forward declarations* para todos los identifiers que queremos que otros ficheros vean.

Si un *header file* se relaciona con un *code file*, deben usar el mismo nombre base (ej: add.cpp y add.h).

add.h:

```javascript {.line-numbers}
// Header guard here
// This is the content of the .h file, which is where the declarations go
int add(int x, int y); // function prototype for add.h -- don't forget the semicolon!
```
main.cpp:
```javascript {.line-numbers}
#include "add.h" // Insert contents of add.h at this point.  Note use of double quotes here.
#include <iostream>

int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
    return 0;
}
```
add.cpp:
```javascript {.line-numbers}
#include "add.h" // Insert contents of add.h at this point.  Note use of double quotes here.

int add(int x, int y)
{
    return x + y;
}
```

Buena práctica: evitar #include .cpp files.

<u>Regla:</u> Usar "" (double quotes) para incluir *header files* que hayamos escrito nosotros o que estén en el dir actual. Usar <> (angled brackets) para incluir headers procedentes del compilador, OS, o librerías de terceros instaladas en el sistema.

### Ruta del #include

NO usar rutas relativas en el #include.
```
For gcc users

Using g++, you can use the -I option to specify an alternate include directory:
g++ -o main -I./source/includes main.cpp

There is no space after the -I. For a full path (rather than a relative path), remove the . after -I.
```
```
For VS Code users

In your tasks.json configuration file, add a new line in the “Args” section:
"-I./source/includes",

There is no space after the -I. For a full path (rather than a relative path), remove the . after -I.
```

*Header files* pueden incluir otros headers, ej: #include <string_view>

**Transitive includes** se refieren a *header files* adicionales que se incluyen implícitamente a partir de incluirse por otros *header files*.
No se recomienda guiarnos por los *transitive includes*.

Buena práctica:

- Incluir el *header file* pareja del *code file* (ej: add.cpp con #include "add.h").
- Otros headers del mismo proyecto (ej: #include "mymath.h").
- Headers de librerías de terceros (ej: <boost/tuple/tuple.hpp>).
- Headers de librerías estándar (ej: #include <iostream>).

Si hay varios en el mismo nivel, se ordena alfabéticamente.