#ifndef QUATERNION_H
#define QUATERNION_H

#include <GL/glew.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _Quaternion {
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat w;

	GLfloat (*length)(struct _Quaternion *);
	void (*normalize)(struct _Quaternion *);
	struct _Quaternion * (*conjugate)(struct _Quaternion *);
} Quaternion;

Quaternion * quaternion_init(GLfloat x, GLfloat y,
							 GLfloat z, GLfloat w);

#endif