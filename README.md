# Homework 2

---

Agustín Pereyra

## Respuestas de los ejercicios

***2c.*** La relación entre las clases "Course" y "Student" es de **Agregación**:
Ya que al curso se lo puede ver como ese "todo", mientras que los estudiantes son sus partes. Pero el estudiante puede seguir existiendo fuera del curso, es decir, el curso no tiene el ownership completo sobre el estudiante, ni mucho menos el estudiante es dependiente de la otra clase.

## Compilación y ejecución

Se puede compilar y ejecutar cada ejercicio a través del makefile del repositorio. Desde la consola (parado sobre la carpeta donde esté clonado el repo) escribir *make run* junto al número del ejercicio( `make run<nº ej>`), el cual compilará los archivos .cpp necesarios para luego ejecutarlos.
Se creará una carpeta *bin* donde se guardarán todos los ejecutables.
Para ver el registro de ***valgrind*** y verificar la memoria alocada esta el comando `make valgrind<nº ej>`.

> A la hora de compilar se usa la flag -Wall.
