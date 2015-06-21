#ifndef QUATERNION_H
#define QUATERNION_H

#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _Quaternion {
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat w;
} Quaternion;

#endif