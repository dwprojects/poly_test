#ifndef VERTEX_H
#define VERTEX_H

#include <GL/glew.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "vec3.h"

typedef struct _Vertex {
	Vec3 *pos;
} Vertex;

Vertex * vertex_init(Vec3 *v);

#endif