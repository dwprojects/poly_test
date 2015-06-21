#include "vertex.h"

Vertex * vertex_init(Vec3 *v)
{
	Vertex *vertex = NULL;
	vertex = malloc(sizeof(Vertex));
	if (vertex)
	{
		vertex->pos = v;
	}

	return(vertex);
}