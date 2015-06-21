#ifndef VEC4_H
#define VEC4_H

#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _Vec4 {
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat w;
} Vec4;

Vec4 * vec4_init(GLfloat x, GLfloat y, GLfloat z, GLfloat w);

#endif