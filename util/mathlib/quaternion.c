#include "quaternion.h"
#include "../util.h"

static GLfloat length(Quaternion *self)
{
	return(sqrt((self->x * self->x) +
				(self->y * self->y) +
				(self->z * self->z) +
				(self->w * self->w)));
}

Quaternion * quaternion_init(GLfloat x, GLfloat y,
							 GLfloat z, GLfloat w)
{
	Quaternion *quaternion = NULL;
	quaternion = malloc(sizeof(Quaternion));

	if (quaternion)
	{
		// Methods
		quaternion->length = length;

		// Attributes
		quaternion->x = x;
		quaternion->y = y;
		quaternion->z = z;
		quaternion->w = w;
	}

	return(quaternion);
}