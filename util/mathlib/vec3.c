#include "vec3.h"

Vec3 * vec3_init(GLfloat x, GLfloat y, GLfloat z)
{
	Vec3 *v = NULL;
	v = malloc(sizeof(Vec3));
	if (v)
	{
		v->x = x;
		v->y = y;
		v->z = z;
	}

	return(v);
}