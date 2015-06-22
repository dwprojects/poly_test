engine: main.o
	gcc -Wall -g -o engine main.o mathlib.o -framework SDL2 -lGLEW

test_mathlib: mathlib.o util.o
	gcc -Wall -g -o test mathlib.o util.o ./tests/test_math_library.c \
	 ./tests/test_math_library_vec2.c \
	 ./tests/test_math_library_vec3.c \
	 ./tests/test_math_library_mat4.c \
	 -framework SDL2 -lGLEW

main.o: main.c
	gcc -c main.c

util.o: ./util/util.c
	gcc -c ./util/util.c

mathlib.o: ./util/mathlib/vec2.c \
	./util/mathlib/vec3.c \
	./util/mathlib/vec4.c \
	./util/mathlib/vertex.c \
	./util/mathlib/mat4.c

	gcc -c ./util/mathlib/vec2.c \
	 ./util/mathlib/vec3.c \
	 ./util/mathlib/vec4.c \
	 ./util/mathlib/vertex.c \
	 ./util/mathlib/mat4.c
	ld -r vec2.o vec3.o vec4.o vertex.o mat4.o -o mathlib.o

clean:
	rm engine main.o mathlib.o

clean_test:
	rm test *.o