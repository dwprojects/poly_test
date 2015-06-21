#include "vec4.h"

Vec4 * vec4_init(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	Vec4 *v = NULL;
	v = malloc(sizeof(Vec4));
	if (v)
	{
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
	}

	return(v);
}