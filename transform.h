#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <stdlib.h>
#include <stdio.h>
#include "./util/mathlib/mathlib.h"

typedef struct _Transform {
	Vec3 *translation;
	Vec3 *rotation;
	Vec3 *scaling;

	void (*set_scaling)(struct _Transform *, GLfloat x,
						 GLfloat y, GLfloat z);
	void (*set_scaling_vec3)(struct _Transform *, Vec3 *r);

	void (*set_rotation)(struct _Transform *, GLfloat x,
						 GLfloat y, GLfloat z);
	void (*set_rotation_vec3)(struct _Transform *, Vec3 *r);

	void (*set_translation)(struct _Transform *, GLfloat x,
							GLfloat y, GLfloat z);
	void (*set_translation_vec3)(struct _Transform *, Vec3 *r);
	Mat4 * (*get_transformation)(struct _Transform *);

} Transform;

Transform * transform_init();
void destroy_transform(Transform *);

#endif