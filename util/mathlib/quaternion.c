#include "quaternion.h"
#include "../util.h"

static GLfloat length(Quaternion *self)
{
	return(sqrt((self->x * self->x) +
				(self->y * self->y) +
				(self->z * self->z) +
				(self->w * self->w)));
}

static void normalize(Quaternion *self)
{
	GLfloat length = self->length(self);

	self->x = self->x / length;
	self->y = self->y / length;
	self->z = self->z / length;
	self->w = self->w / length;
}

static Quaternion * conjugate(Quaternion *self)
{
	return(quaternion_init(-(self->x),
						   -(self->y),
						   -(self->z),
						   -(self->w)));
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
		quaternion->normalize = normalize;
		quaternion->conjugate = conjugate;

		// Attributes
		quaternion->x = x;
		quaternion->y = y;
		quaternion->z = z;
		quaternion->w = w;
	}

	return(quaternion);
}