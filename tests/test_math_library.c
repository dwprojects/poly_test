#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <assert.h>
#include "../util/mathlib/vec2.h"
#include "../util/mathlib/vec3.h"
#include "../util/mathlib/vec4.h"
#include "../util/mathlib/vertex.h"
#include "../util/mathlib/mat4.h"
#include "../util/mathlib/quaternion.h"

#define DEBUG 1

GLfloat x = 1.0f;
GLfloat y = 1.0f;
GLfloat z = 1.0f;
GLfloat w = 1.0f;

void debug_log(char *test_name, char *msg)
{
	printf("%s: %s\n", test_name, msg);
}

int test_Vec2_values()
{
	static int result = 0;
	//char *test_name = "test_Vec2_values";

	Vec2 *v = vec2_init(x, y);

	if ((v->x == x)
		&& (v->y == y))
	{
		result = 1;
	}

	free(v);
	return(result);
}

int test_Vec3_values()
{
	static int result = 0;
	//char *test_name = "test_Vec3_values";

	Vec3 *v = vec3_init(x, y, z);

	if ((v->x == x)
		&& (v->y == y)
		&& (v->z == z))
	{
		result = 1;
	}

	free(v);
	return(result);
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

	return(result);
}

int main(int argc, char *args[])
{
	int error = 0;

	if (!test_Vec2_values())
	{
		printf("test_Vec2_values: failed\n");
	}
	/*
	if (!test_Vec3_values())
	{
		printf("test_Vec3_values: failed\n");
	}
	if (!test_Vec4_values())
	{
		printf("test_Vec4_values: failed\n");
	}
	if (!test_Vertex_values())
	{
		printf("test_Vertex_values: failed\n");
	}
	*/

	if (error)
	{
		printf("Mathlib tests failed");
	}
	else
	{
		printf("Tests ran successfully\n");
	}
	return(0);
}