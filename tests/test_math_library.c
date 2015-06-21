#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <assert.h>
#include "../util/util.h"
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
	v = NULL;
	return(result);
}

int test_Vec2_to_string()
{
	//static int result = 0;
	//char *test_name = "test_Vec2_to_string";

	Vec2 *v = vec2_init(x,y);

	printf("to_string: %s", v->to_string(v));

	return(1);
}

int test_Vec2_length()
{
	static int result = 0;
	//char *test_name = "test_Vec2_length";

	Vec2 *v = vec2_init(x, y);
	GLfloat length = sqrt((x*x) + (y*y));

	if (v->length(v) == length)
	{
		result = 1;
	}

	printf("length: %f\n", v->length(v));

	free(v);
	v = NULL;
	return(result);
}

int test_Vec2_dot()
{
	static int result = 0;
	//char *test_name = "test_Vec2_dot";

	Vec2 *v1 = vec2_init(x, y);
	Vec2 *v2 = vec2_init(x, y);

	if (v1->dot(v1, v2) == ((v1->x * v2->x) + (v1->y * v2->y)))
	{
		result = 1;
	}

	printf("dot: %f\n", v1->dot(v1, v2));

	free(v1);
	free(v2);
	v1 = NULL;
	v2 = NULL;
	return(result);
}

int test_Vec2_normalize()
{
	static int result = 0;
	//char *test_name = "test_Vec2_normalize";

	Vec2 *v = vec2_init(x, y);
	GLfloat l = v->length(v);
	
	v->normalize(v);

	if ((v->x == x/l)
		&& (v->y == y/l))
	{
		result = 1;
	}

	printf("normalize: %f, %f\n", v->x, v->y);

	free(v);
	v = NULL;
	return(result);
}

int test_Vec2_rotate()
{
	static int result = 0;
	//char *test_name = "test_Vec2_rotate";

	Vec2 *v = vec2_init(x, y);
	GLfloat angle = 90.0f;
	Vec2 *r = v->rotate(v, angle);
	
	GLfloat rd = d2r(angle);
	GLfloat c = cosf(rd);
	GLfloat s = sinf(rd);

	if ((r->x == ((x * c) - (y * s)))
		&& (r->y == ((x * s) + (y *c))))
	{
		result = 1;
	}

	printf("rotate: %f, %f\n", r->x, r->y);

	free(v);
	free(r);
	v = NULL;
	r = NULL;
	return(result);
}

int test_Vec2_add()
{
	static int result = 0;
	//char *test_name = "test_Vec2_add";

	Vec2 *v = vec2_init(x, y);
	GLfloat f = 2.0f;
	Vec2 *r = v->add(v, f);

	if ((r->x == x+f)
		&& (r->y == y+f))
	{
		result = 1;
	}

	printf("add: %f, %f\n", r->x, r->y);

	free(v);
	free(r);
	v = NULL;
	r = NULL;
	return(result);
}

int test_Vec2_addv()
{
	static int result = 0;
	//char *test_name = "test_Vec2_addv";

	Vec2 *v1 = vec2_init(x, y);
	Vec2 *v2 = vec2_init(x, y);
	Vec2 *r = NULL;

	r = v1->addv(v1, v2);

	if ((r->x == (v1->x + v2->x))
		&& (r->y == (v1->y + v2->y)))
	{
		result = 1;
	}

	printf("addv: %f, %f\n", r->x, r->y);

	free(v1);
	free(v2);
	free(r);
	v1 = NULL;
	v2 = NULL;
	r = NULL;
	return(result);
}

int test_Vec2_sub()
{
	static int result = 0;
	//char *test_name = "test_Vec2_sub";

	Vec2 *v = vec2_init(x, y);
	GLfloat f = 2.0f;
	Vec2 *r = v->sub(v, f);

	if ((r->x == x-f)
		&& (r->y == y-f))
	{
		result = 1;
	}

	printf("sub: %f, %f\n", r->x, r->y);

	free(v);
	free(r);
	v = NULL;
	r = NULL;
	return(result);
}

int test_Vec2_subv()
{
	static int result = 0;
	//char *test_name = "test_Vec2_addv";

	Vec2 *v1 = vec2_init(x, y);
	Vec2 *v2 = vec2_init(x, y);
	Vec2 *r = NULL;

	r = v1->subv(v1, v2);

	if ((r->x == (v1->x - v2->x))
		&& (r->y == (v1->y - v2->y)))
	{
		result = 1;
	}

	printf("subv: %f, %f\n", r->x, r->y);

	free(v1);
	free(v2);
	free(r);
	v1 = NULL;
	v2 = NULL;
	r = NULL;
	return(result);
}

int test_Vec2_mul()
{
	static int result = 0;
	//char *test_name = "test_Vec2_mul";

	Vec2 *v = vec2_init(x, y);
	GLfloat f = 2.0f;
	Vec2 *r = v->mul(v, f);

	if ((r->x == x*f)
		&& (r->y == y*f))
	{
		result = 1;
	}

	printf("mul: %f, %f\n", r->x, r->y);

	free(v);
	free(r);
	v = NULL;
	r = NULL;
	return(result);
}

int test_Vec2_mulv()
{
	static int result = 0;
	//char *test_name = "test_Vec2_mulv";

	Vec2 *v1 = vec2_init(x, y);
	Vec2 *v2 = vec2_init(x, y);
	Vec2 *r = NULL;

	r = v1->mulv(v1, v2);

	if ((r->x == (v1->x * v2->x))
		&& (r->y == (v1->y * v2->y)))
	{
		result = 1;
	}

	printf("mulv: %f, %f\n", r->x, r->y);

	free(v1);
	free(v2);
	free(r);
	v1 = NULL;
	v2 = NULL;
	r = NULL;
	return(result);
}

int test_Vec2_dvd()
{
	static int result = 0;
	//char *test_name = "test_Vec2_dvd";

	Vec2 *v = vec2_init(x, y);
	GLfloat f = 2.0f;
	Vec2 *r = v->dvd(v, f);

	if ((r->x == x/f)
		&& (r->y == y/f))
	{
		result = 1;
	}

	printf("dvd: %f, %f\n", r->x, r->y);

	free(v);
	free(r);
	v = NULL;
	r = NULL;
	return(result);
}

int test_Vec2_dvdv()
{
	static int result = 0;
	//char *test_name = "test_Vec2_dvdv";

	Vec2 *v1 = vec2_init(x, y);
	Vec2 *v2 = vec2_init(x, y);
	Vec2 *r = NULL;

	r = v1->dvdv(v1, v2);

	if ((r->x == (v1->x / v2->x))
		&& (r->y == (v1->y / v2->y)))
	{
		result = 1;
	}

	printf("dvdv: %f, %f\n", r->x, r->y);

	free(v1);
	free(v2);
	free(r);
	v1 = NULL;
	v2 = NULL;
	r = NULL;
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
	v = NULL;
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
	int error = 0;

	// Vec2 Tests
	if (!test_Vec2_values())
	{
		printf("test_Vec2_values: failed\n");
		error++;
	}
	if (!test_Vec2_to_string())
	{
		printf("test_Vec2_to_string: failed\n");
		error++;
	}
	if (!test_Vec2_length())
	{
		printf("test_Vec2_length: failed\n");
		error++;
	}
	if (!test_Vec2_dot())
	{
		printf("test_Vec2_dot: failed\n");
		error++;
	}
	if (!test_Vec2_normalize())
	{
		printf("test_Vec2_normalize: failed\n");
		error++;
	}
	if (!test_Vec2_rotate())
	{
		printf("test_Vec2_rotate: failed\n");
		error++;
	}
	if (!test_Vec2_add())
	{
		printf("test_Vec2_add: failed\n");
		error++;
	}
	if (!test_Vec2_addv())
	{
		printf("test_Vec2_addv: failed\n");
		error++;
	}
	if (!test_Vec2_sub())
	{
		printf("test_Vec2_sub: failed\n");
		error++;
	}
	if (!test_Vec2_subv())
	{
		printf("test_Vec2_subv: failed\n");
		error++;
	}
	if (!test_Vec2_mul())
	{
		printf("test_Vec2_mul: failed\n");
		error++;
	}
	if (!test_Vec2_mulv())
	{
		printf("test_Vec2_mulv: failed\n");
		error++;
	}
	if (!test_Vec2_dvd())
	{
		printf("test_Vec2_dvd: failed\n");
		error++;
	}
	if (!test_Vec2_dvdv())
	{
		printf("test_Vec2_dvdv: failed\n");
		error++;
	}
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

	if (error)
	{
		printf("Mathlib tests failed: %d\n", error);
	}
	else
	{
		printf("Tests ran successfully\n");
	}
	return(0);
}