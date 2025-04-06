# Homework 2

---

Agustín Pereyra

## Aclaraciones

- Para el ejercicio 3 tuve la propuesta de realizar las operaciones como sobrecarga de operadores, y todas las operaciones dan como resultado un objeto de la clase del objeto de la izquierda de la operación. Es decir que si hago `x = <Integer> + <Complex>`, x será de la clase `<Integer>`, y en el caso de hacer `y = <Complex> + <Integer>`, y será de la clase `<Complex>`

## Respuestas de los ejercicios

***2b v.*** Lo que se realiza es un *deep copy* del vector, es decir se crea un nuevo vector para el nuevo curso con los mismos estudiantes. Pero a la vez se realiza un *shallow copy* de cada estudiantes. De forma que el objeto estudinate sea único y si modifico un estudiante dentro de un curso, se modifica para los demás también. Pero que pueda manejar el vector de estudiantes de cada curso independientemente.

***2c.*** La relación entre las clases "Course" y "Student" es de **Agregación**:
Ya que al curso se lo puede ver como ese "todo", mientras que los estudiantes son sus partes. Pero el estudiante puede seguir existiendo fuera del curso, es decir, el curso no tiene el ownership completo sobre el estudiante, ni mucho menos el estudiante es dependiente de la otra clase.

## Compilación y ejecución

Se puede compilar y ejecutar cada ejercicio a través del makefile del repositorio. Desde la consola (parado sobre la carpeta donde esté clonado el repo) escribir *make run* junto al número del ejercicio( `make run<nº ej>`), el cual compilará los archivos .cpp necesarios para luego ejecutarlos.
Se creará una carpeta *bin* donde se guardarán todos los ejecutables.
Para ver el registro de ***valgrind*** y verificar la memoria alocada esta el comando `make valgrind<nº ej>`.

> Modo de compilación: ``g++ main.cpp <.cpp necesarios> -Wall -o bin/main``.
> Modo ejecución:
>
> - Sin Valgrind -> ./bin/main
> - Con Valgrind -> valgrind ./bin/main
