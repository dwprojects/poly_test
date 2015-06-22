#ifndef MAT4_H
#define MAT4_H

#include <GL/glew.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _Mat4 {
	GLfloat m[4][4];

	struct _Mat4 * (*init_identity)(struct _Mat4 *);
	struct _Mat4 * (*init_translation)(struct _Mat4 *, GLfloat x,
									   GLfloat y, GLfloat z);
	struct _Mat4 * (*mul)(struct _Mat4 *, struct _Mat4 *r);
} Mat4;

Mat4 * mat4_init();
void destroy_mat4(Mat4 *mat4);

#endif