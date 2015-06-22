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

	GLfloat (*length)(struct _Vec3 *);
	GLfloat (*dot)(struct _Vec3 *, struct _Vec3 *r);
	void (*normalize)(struct _Vec3 *);
	struct _Vec3 * (*add)(struct _Vec3 *, GLfloat r);
	struct _Vec3 * (*addv)(struct _Vec3 *, struct _Vec3 *r);
	struct _Vec3 * (*sub)(struct _Vec3 *, GLfloat r);
	struct _Vec3 * (*subv)(struct _Vec3 *, struct _Vec3 *r);
	struct _Vec3 * (*mul)(struct _Vec3 *, GLfloat r);
	struct _Vec3 * (*mulv)(struct _Vec3 *, struct _Vec3 *r);
	struct _Vec3 * (*dvd)(struct _Vec3 *, GLfloat r);
	struct _Vec3 * (*dvdv)(struct _Vec3 *, struct _Vec3 *r);
	struct _Vec3 * (*rotate)(struct _Vec3 *, GLfloat angle);
	struct _Vec3 * (*cross_product)(struct _Vec3 *, struct _Vec3 *r);
	char * (*to_string)(struct _Vec3 *);
} Vec3;

Vec3 * vec3_init(GLfloat x, GLfloat y, GLfloat z);
void destroy_vec3(Vec3 *);

#endif