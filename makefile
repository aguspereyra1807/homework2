bin:
	mkdir -p bin

run1: bin
	g++ Ejercicio\ 1/main.cpp Ejercicio\ 1/clock.cpp -Wall -o bin/main_ej_1
	./bin/main_ej_1

valgrind1: bin
	g++ Ejercicio\ 1/main.cpp Ejercicio\ 1/clock.cpp -Wall -o bin/main_ej_1_v
	valgrind ./bin/main_ej_1_v

run2: bin
	g++ Ejercicio\ 2/main.cpp Ejercicio\ 2/student.cpp Ejercicio\ 2/course.cpp -Wall -o bin/main_ej_2
	./bin/main_ej_2

valgrind2: bin
	g++ Ejercicio\ 2/main.cpp Ejercicio\ 2/student.cpp Ejercicio\ 2/course.cpp -Wall -o bin/main_ej_2_v
	valgrind ./bin/main_ej_2_v