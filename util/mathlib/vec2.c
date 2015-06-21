#include "vec2.h"

Vec2 * vec2_init(GLfloat x, GLfloat y)
{
	Vec2 *v = NULL;
	v = malloc(sizeof(Vec2));
	if (v)
	{
		v->x = x;
		v->y = y;
	}

	return(v);
}