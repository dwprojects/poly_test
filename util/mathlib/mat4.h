#ifndef MAT4_H
#define MAT4_H

#include <GL/glew.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "../util.h"

typedef struct _Mat4 {
	GLfloat m[4][4];

	void (*init_identity)(struct _Mat4 *);
	void (*init_translation)(struct _Mat4 *, GLfloat x,
									   GLfloat y, GLfloat z);
	void (*init_rotation)(struct _Mat4 *, GLfloat x,
									   GLfloat y, GLfloat z);
	struct _Mat4 * (*mul)(struct _Mat4 *, struct _Mat4 *r);
} Mat4;

Mat4 * mat4_init();
Mat4 * mat4_init_translation(GLfloat x, GLfloat y, GLfloat z);
Mat4 * mat4_init_rotation(GLfloat x, GLfloat y, GLfloat z);
void destroy_mat4(Mat4 *mat4);

#endif