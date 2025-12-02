# 🐚 tarea-2-Sistemas-Operativos-UdeC

## 👤 Autores del Codigo
- José González Aguayo.
- Gonzalo Quilodrán Neira.
- Joaquín Sandoval Reyes.

# 🧠 Proyecto — Sistemas Operativos (Tarea 2)

## 📌 Descripción

Este proyecto fue desarrollado para la asignatura **501251-1 Sistemas Operativos**, impartida por el Departamento de Ingeniería Informática y Ciencias de la Computación (DIICC) de la Universidad de Concepción.

El trabajo aborda dos temáticas principales del área:

- **Sincronización de hebras mediante barreras reutilizables.**
- **Simulación de memoria virtual y manejo de fallos de página.**

Todo el código se encuentra escrito en **lenguaje C**, haciendo uso de `pthread` y funciones POSIX.

En este repositorio se incluyen archivos fuente, cabeceras y archivos auxiliares necesarios para la correcta ejecución del proyecto.

---

## ⚙️ Funcionalidades

### 🧵 Parte I — Barrera de Sincronización

- Creación de N hebras (threads)
- Ejecución en E etapas
- Tipo de dato `barrera_t`
- Funciones implementadas:
  - `barrier_init()`
  - `barrier_wait()`
  - `barrier_destroy()`
- Control mediante:
  - `pthread_mutex_t`
  - `pthread_cond_t`
- Sincronización por etapas:
  - ninguna hebra avanza a la siguiente etapa hasta que todas hayan llegado a la barrera

---

### 💾 Parte II — Simulación de Memoria Virtual

- Lectura de accesos de memoria desde archivo
- Traducción de direcciones virtuales (página + offset)
- Manejo de fallos de página
- Implementación de algoritmos de reemplazo:
  - FIFO
  - LRU
  - LFU  
  *(dependiendo del enunciado)*
- Estadísticas de ejecución:
  - número total de fallos
  - estado de marcos en memoria
  - trazado opcional de cada acceso

---

## 📦 Requisitos

- **Sistema Operativo:** Linux/Unix recomendado  
  *(puede compilarse también en Windows con Mingw, Cygwin o WSL)*

- **Compilador:** `gcc` (recomendado)

- **Bibliotecas necesarias:**
  - `<pthread.h>`
  - `<stdio.h>`
  - `<stdlib.h>`
  - `<unistd.h>` *(Part I)*

---

## 🛠️ Compilación

### Parte I (barrera)
```bash
gcc main.c barrera.c -o barrera -lpthread
