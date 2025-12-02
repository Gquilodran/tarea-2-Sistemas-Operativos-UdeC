# 🐚 tarea-2-Sistemas-Operativos-UdeC

## 👤 Autores del Codigo
- José González Aguayo.
- Gonzalo Quilodrán Neira.
- Joaquín Sandoval Reyes.


## 📌 Descripción

Este proyecto fue desarrollado para la asignatura **501251-1 Sistemas Operativos**, impartida por el Departamento de Ingeniería Informática y Ciencias de la Computación (DIICC) de la Universidad de Concepción.

El trabajo aborda dos temáticas principales del área:

- **Sincronización de hebras mediante barreras reutilizables.**
- **Simulación de memoria virtual y manejo de fallos de página.**

Todo el código se encuentra escrito en **lenguaje C**, haciendo uso de `pthread` y distintas otras funcónes y bibliotecas.

En este repositorio se incluyen ambas partes de la tarea 2, cada una en su carpeta correspondiente y dividios en archivos distintos para facilitar su entendimiento y comprención.

---

## ⚙️ Funcionalidades

### 🧵 Parte I — Barrera de Sincronización

- Creación de N hebras (threads)
- Ejecución en E etapas
- Tipo de dato `barrera_t`
- Funciones implementadas:
  - `barrera_init()`
  - `barrera_wait()`
  - `barrera_destroy()`
- Control mediante:
  - `pthread_mutex_t`
  - `pthread_cond_t`
- Sincronización por etapas:
  - ninguna hebra avanza a la siguiente etapa hasta que todas hayan llegado a la barrera.

---

### 💾 Parte II — Simulación de Memoria Virtual

- Lectura de accesos de memoria desde archivo.
- Traducción de direcciones virtuales (página + offset).
- Manejo de fallos de página.
- Implementación de algoritmos de reemplazo de reloj.
- Estadísticas de ejecución:
  - número total de fallos.
  - estado de marcos en memoria.
  - trazado opcional de cada acceso.

---

## 📦 Requisitos

- **Sistema Operativo:** La tarea fue desarrollada en Windows y compilada con Mingw, pero se recomienda el uso de Linux/Unix y por ende de gcc para compilarlo.

## Compilación y ejecución:
  
```bash 
  ##Parte I:
    Compilar: gcc main.c barrera.c-lpthread-o programa
    Ejecutar: ./programa.exe
  ##Parte II:
    Compilar: gcc-o sim main.c sim.c funcion.c-lm
    Ejecutar:  Caso 1: ./sim 8 4096 trace1.txt  Caso 2:  ./sim 8 4096 -–verbose trace1.txt
 ```
## 📑 Licencia
Este codigo fue realizado con fines academicos por estudiantes de la universidad de Concepción, se prohíbe su distribución con otros fines.
