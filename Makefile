engine: main.o \
	game.o \
	mathlib.o \
	util.o \
	display.o \
	render.o \
	timer.o \
	input.o \
	transform.o \
	camera.o \
	model.o \
	shader.o \

	gcc -Wall -g -o engine main.o \
	game.o \
	mathlib.o \
	util.o \
	display.o \
	render.o \
	timer.o \
	input.o \
	transform.o \
	camera.o \
	model.o \
	shader.o \
	-framework SDL2 -framework OpenGL -lGLEW

test_mathlib: mathlib.o util.o
	gcc -Wall -g -o test mathlib.o util.o ./tests/test_math_library.c \
	 ./tests/test_math_library_vec2.c \
	 ./tests/test_math_library_vec3.c \
	 ./tests/test_math_library_mat4.c \
	 ./tests/test_math_library_quaternion.c \
	 ./tests/test_math_library_vertex.c \
	 -framework SDL2 -framework OpenGL -lGLEW

main.o: main.c
	gcc -c -g main.c

game.o: game.c
	gcc -c -g game.c

display.o: display.c
	gcc -c -g display.c

render.o: render.c
	gcc -c -g render.c

camera.o: camera.c
	gcc -c -g camera.c

input.o: input.c
	gcc -c -g input.c

transform.o: transform.c
	gcc -c -g transform.c

model.o: model.c
	gcc -c -g model.c

shader.o: shader.c
	gcc -c -g shader.c

timer.o: ./util/timer/timer.c
	gcc -c -g ./util/timer/timer.c

util.o: ./util/util.c
	gcc -c -g ./util/util.c

mathlib.o: ./util/mathlib/vec2.c \
	./util/mathlib/vec3.c \
	./util/mathlib/vec4.c \
	./util/mathlib/mat4.c \
	./util/mathlib/quaternion.c \
	./util/mathlib/vertex.c \
	./util/mathlib/vertex_array.c

	gcc -c -g ./util/mathlib/vec2.c \
	 ./util/mathlib/vec3.c \
	 ./util/mathlib/vec4.c \
	 ./util/mathlib/vertex.c \
	 ./util/mathlib/mat4.c \
	 ./util/mathlib/quaternion.c \
	 ./util/mathlib/vertex.c \
	 ./util/mathlib/vertex_array.c

	ld -r vec2.o vec3.o vec4.o vertex.o vertex_array.o mat4.o quaternion.o -o mathlib.o

clean:
	rm engine *.o

clean_test:
	rm test *.o