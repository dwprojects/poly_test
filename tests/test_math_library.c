#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <assert.h>
#include "../util/util.h"

#include "../util/mathlib/vec3.h"
#include "../util/mathlib/vec4.h"
#include "../util/mathlib/vertex.h"
#include "../util/mathlib/mat4.h"
#include "../util/mathlib/quaternion.h"

#define DEBUG 1

int test_vec2(GLfloat _x, GLfloat _y);

GLfloat x = 1.0f;
GLfloat y = 1.0f;
GLfloat z = 1.0f;
GLfloat w = 1.0f;

void debug_log(char *test_name, char *msg)
{
	printf("%s: %s\n", test_name, msg);
}

int test_Vec4_values()
{
	static int result = 0;
	//char *test_name = "test_Vec4_values";

	Vec4 *v = vec4_init(x, y, z, w);

	if ((v->x == x)
		&& (v->y == y)
		&& (v->z == z)
		&& (v->w == w))
	{
		result = 1;
	}

	free(v);
	v = NULL;
	return(result);
}

int test_Vertex_values()
{
	static int result = 0;
	//char *test_name = "test_Vertex_values";

	Vec3 *v3 = vec3_init(x, y, z);
	Vertex *v = vertex_init(v3);

	if ((v->pos->x == x)
		&& (v->pos->y == y)
		&& (v->pos->z == z))
	{
		result = 1;
	}

	free(v3);
	free(v);
	v3 = NULL;
	v = NULL;
	return(result);
}

// TODO: add functions to array
int main(int argc, char *args[])
{
	int errors = 0;

	// Vec2 Tests
	errors += test_vec2(x, y);
	
	/*
	if (!test_Vec3_values())
	{
		printf("test_Vec3_values: failed\n");
		error++;
	}
	if (!test_Vec4_values())
	{
		printf("test_Vec4_values: failed\n");
		error++;
	}
	if (!test_Vertex_values())
	{
		printf("test_Vertex_values: failed\n");
		error++;
	}
	*/

	if (errors)
	{
		printf("Mathlib tests failed: %d\n", errors);
	}
	else
	{
		printf("Tests ran successfully\n");
	}
	return(0);
}