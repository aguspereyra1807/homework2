# Homework 2

---

Agustín Pereyra

## Aclaraciones

- Para el ejercicio 3 tuve la propuesta de realizar las operaciones como sobrecarga de operadores, y todas las operaciones dan como resultado un objeto de la clase del objeto de la izquierda de la operación. Es decir que si hago `x = <Integer> + <Complex>`, x será de la clase `<Integer>`, y en el caso de hacer `y = <Complex> + <Integer>`, y será de la clase `<Complex>`

## Respuestas de los ejercicios

***2b v.*** Lo que se realiza es un *deep copy* del vector, es decir se crea un nuevo vector para el nuevo curso con los mismos estudiantes. Pero a la vez se realiza un *shallow copy* de cada estudiantes. De forma que el objeto estudinate sea único y si modifico un estudiante dentro de un curso, se modifica para los demás también. Pero que pueda manejar el vector de estudiantes de cada curso independientemente.

***2c.*** La relación entre las clases "Course" y "Student" es de **Agregación**:
Ya que al curso se lo puede ver como ese "todo", mientras que los estudiantes son sus partes. Pero el estudiante puede seguir existiendo fuera del curso, es decir, el curso no tiene el ownership completo sobre el estudiante, ni mucho menos el estudiante es dependiente de la otra clase.

***4a.*** Los atributos `protected` de `BankAccount` son *balance* y *owner* ya que son atributos que deben tener las clases derivadas, pero que solo sean accesibles desde dentro de las mismas.
Luego dentro de las derivadas tenemos diferentes atributos privados según la clase.

- ``SavingsAccount`` tiene *showCounter*, que no es nada más que el contador de las veces que el método público `info()` fue usado, para implementar el descuento de $20 cada 2 llamadas al método.
- ``CheckingAccount`` tiene puntero a un objeto *SavingsAccount*, la cual es la caja de ahorros asociada a la cuenta corriente. Debe ser privada ya que debe ser solo accedida dentro de `withdraw()` a la hora de necesitar retirar dinero adicional de la misma en caso de no tener fondos suficientes en la cuenta corriente. 

Luego en atributos públicos tenemos simplemente a los métodos de acceso público como depositar, retirar y mostrar info como también a los constructores y destructores.

## Compilación y ejecución

Se puede compilar y ejecutar cada ejercicio a través del makefile del repositorio. Desde la consola (parado sobre la carpeta donde esté clonado el repo) escribir *make run* junto al número del ejercicio( `make run<nº ej>`), el cual compilará los archivos .cpp necesarios para luego ejecutarlos.
Se creará una carpeta *bin* donde se guardarán todos los ejecutables.
Para ver el registro de ***valgrind*** y verificar la memoria alocada esta el comando `make valgrind<nº ej>`.

> Modo de compilación: ``g++ main.cpp <.cpp necesarios> -Wall -o bin/main``.
>
> Modo ejecución:
>
> - Sin Valgrind -> ``./bin/main``
> - Con Valgrind -> ``valgrind ./bin/main``
