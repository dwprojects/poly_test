#ifndef VEC2_H
#define VEC2_H

#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _Vec2 {
	GLfloat x;
	GLfloat y;
} Vec2;

Vec2 * vec2_init(GLfloat x, GLfloat y);

#endif