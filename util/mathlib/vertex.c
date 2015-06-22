#include "vertex.h"

Vertex * vertex_init(Vec3 *v)
{
	Vertex *vertex = NULL;
	vertex = malloc(sizeof(Vertex));
	if (vertex)
	{
		vertex->size = 3;
		vertex->pos = v;
	}

	return(vertex);
}

Vertex * vertex_init_float(GLfloat x, GLfloat y,
						   GLfloat z)
{
	Vertex *vertex = NULL;
	vertex = malloc(sizeof(Vertex));
	if (vertex)
	{
		vertex->size = 3;
		vertex->pos = vec3_init(x, y, z);
	}

	return(vertex);
}

void destroy_vertex(Vertex *v)
{
	destroy_vec3(v->pos);
	free(v);
	v = NULL;
}