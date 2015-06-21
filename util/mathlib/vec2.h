#ifndef VEC2_H
#define VEC2_H

#include <GL/glew.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _Vec2 {
	GLfloat x;
	GLfloat y;

	GLfloat (*length)(struct _Vec2 *);
	GLfloat (*dot)(struct _Vec2 *, struct _Vec2 *r);
	void (*normalize)(struct _Vec2 *);
	struct _Vec2 * (*add)(struct _Vec2 *, GLfloat r);
	struct _Vec2 * (*addv)(struct _Vec2 *, struct _Vec2 *r);
	struct _Vec2 * (*sub)(struct _Vec2 *, GLfloat r);
	struct _Vec2 * (*subv)(struct _Vec2 *, struct _Vec2 *r);
	struct _Vec2 * (*mul)(struct _Vec2 *, GLfloat r);
	struct _Vec2 * (*mulv)(struct _Vec2 *, struct _Vec2 *r);
	struct _Vec2 * (*dvd)(struct _Vec2 *, GLfloat r);
	struct _Vec2 * (*dvdv)(struct _Vec2 *, struct _Vec2 *r);
	struct _Vec2 * (*rotate)(struct _Vec2 *, GLfloat angle);
	char * (*to_string)(struct _Vec2 *);
} Vec2;

Vec2 * vec2_init(GLfloat x, GLfloat y);

#endif