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

