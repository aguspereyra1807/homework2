bin:
	mkdir -p bin

run1: bin
	g++ Ejercicio\ 1/main.cpp Ejercicio\ 1/clock.cpp -Wall -o bin/main_ej_1
	./bin/main_ej_1

valgrind1: bin
	g++ Ejercicio\ 1/main.cpp Ejercicio\ 1/clock.cpp -Wall -o bin/main_ej_1
	valgrind ./bin/main_ej_1

run2: bin
	g++ Ejercicio\ 2/main.cpp Ejercicio\ 2/student.cpp Ejercicio\ 2/course.cpp -Wall -o bin/main_ej_2
	./bin/main_ej_2

valgrind2: bin
	g++ Ejercicio\ 2/main.cpp Ejercicio\ 2/student.cpp Ejercicio\ 2/course.cpp -Wall -o bin/main_ej_2
	valgrind ./bin/main_ej_2

run3: bin
	g++ Ejercicio\ 3/main.cpp Ejercicio\ 3/integer.cpp Ejercicio\ 3/real.cpp Ejercicio\ 3/complex.cpp -Wall -o bin/main_ej_3
	./bin/main_ej_3

valgrind3: bin
	g++ Ejercicio\ 3/main.cpp Ejercicio\ 3/integer.cpp Ejercicio\ 3/real.cpp Ejercicio\ 3/complex.cpp -Wall -o bin/main_ej_3
	valgrind ./bin/main_ej_3

run4: bin
	g++ Ejercicio\ 4/main.cpp Ejercicio\ 4/checkingAccount.cpp Ejercicio\ 4/savingsAccount.cpp -Wall -o bin/main_ej_4
	./bin/main_ej_4

valgrind4: bin
	g++ Ejercicio\ 4/main.cpp Ejercicio\ 4/checkingAccount.cpp Ejercicio\ 4/savingsAccount.cpp -Wall -o bin/main_ej_4
	valgrind ./bin/main_ej_4