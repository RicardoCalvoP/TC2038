
# Proyecto: Análisis de Archivos de Transmisión y Códigos Maliciosos

**Nombre del Estudiante:** Ricardo Alfredo Calvo Pérez
**Matrícula:** A01028889
**Fecha:** 28/10/2024

## Descripción del Problema

Este proyecto tiene como objetivo desarrollar un programa en C++ que lea cinco archivos de texto fijos, los cuales contienen datos de transmisiones y códigos maliciosos, y determine si los códigos maliciosos están contenidos en las transmisiones. Además, el programa debe identificar patrones espejeados (palíndromos) y calcular la subsecuencia común más larga entre dos transmisiones.

### Archivos involucrados:

1. **Archivos de Transmisión:**
   - `transmission1.txt`
   - `transmission2.txt`

2. **Archivos de Códigos Maliciosos:**
   - `mcode1.txt`
   - `mcode2.txt`
   - `mcode3.txt`

### Descripción de los Archivos:

- Los archivos **transmissionX.txt** contienen secuencias de caracteres que representan datos de transmisiones de un dispositivo a otro.
- Los archivos **mcodeX.txt** contienen secuencias de códigos maliciosos que deben ser buscados dentro de las transmisiones.

## Objetivos del Programa

### Parte 1: Detección de Códigos Maliciosos

El programa debe analizar si el contenido de los archivos `mcode1.txt`, `mcode2.txt`, y `mcode3.txt` está contenido en los archivos `transmission1.txt` y `transmission2.txt`. El resultado debe ser `true` o `false` si la secuencia de caracteres de los archivos `mcodeX.txt` está contenida en las transmisiones, seguido de la posición en la que empieza.

**Formato de salida:**

```
(true | false) posición_inicial
```

Ejemplo:

```
true 4
false
```

### Parte 2: Detección de Palíndromos

El programa debe buscar si hay códigos espejeados (palíndromos) dentro de los archivos de transmisión. Para cada archivo de transmisión, el programa debe mostrar la posición inicial y final (iniciando desde 1) donde se encuentra el palíndromo más largo.

**Formato de salida:**

```
posición_inicial posición_final
```

Ejemplo:

```
4 9
```

### Parte 3: Substring Común Más Largo

El programa debe analizar cuán similares son los archivos de transmisión `transmission1.txt` y `transmission2.txt`. Se debe mostrar la posición inicial y final (iniciando desde 1) de la subsecuencia común más larga entre ambos archivos de transmisión.

**Formato de salida:**

```
posición_inicial posición_final
```

Ejemplo:

```
3 8
```

## Input

- No hay input por parte del usuario. Los archivos deben existir en la misma carpeta donde se ejecuta el programa.

## Output

### Parte 1:
Debe mostrar si los archivos `transmission1.txt` y `transmission2.txt` contienen los códigos de `mcode1.txt`, `mcode2.txt`, y `mcode3.txt`, junto con la posición inicial de cada código en la transmisión.

### Parte 2:
Debe mostrar la posición inicial y final del código espejeado (palíndromo) más largo dentro de los archivos de transmisión.

### Parte 3:
Debe mostrar la posición inicial y final de la subsecuencia común más larga entre los dos archivos de transmisión.

## Ejemplos

### Ejemplo 1 - Parte 1

**Archivos:**

- `mcode1.txt`: `A12B34`
- `transmission1.txt`: `123A12B34C567`

**Salida:**

```
true 4
```

### Ejemplo 2 - Parte 2

**Archivo:**

- `transmission1.txt`: `123ABCCBA456`

**Salida:**

```
4 9
```

### Ejemplo 3 - Parte 3

**Archivos:**

- `transmission1.txt`: `ABCDEF123`
- `transmission2.txt`: `XYZDEF123`

**Salida:**

```
4 9
```

---

## Notas:

- Asegúrate de que los archivos de texto estén en la misma carpeta donde se ejecuta el programa.
- Los índices deben comenzar en 1, no en 0.
- Usa este template para completar con tus propios datos.

---
