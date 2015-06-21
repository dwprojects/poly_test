#ifndef VEC3_H
#define VEC3_H

#include <GL/glew.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _Vec3 {
	GLfloat x;
	GLfloat y;
	GLfloat z;
} Vec3;

Vec3 * vec3_init(GLfloat x, GLfloat y, GLfloat z);

#endif