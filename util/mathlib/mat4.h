#ifndef MAT4_H
#define MAT4_H

#include <GL/glew.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _Mat4 {
	GLfloat m[4][4];
} Mat4;

#endif