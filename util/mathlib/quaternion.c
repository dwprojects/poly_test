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

static Quaternion * mul(Quaternion *self, Quaternion *r)
{
	GLfloat _w = (self->w * r->w) - (self->x * r->x) - (self->y * r->y) - (self->z * r->z);
	GLfloat _x = (self->x * r->w) + (self->w * r->x) + (self->y * r->z) - (self->z * r->y);
	GLfloat _y = (self->y * r->w) + (self->w * r->y) + (self->z * r->x) - (self->x * r->z);
	GLfloat _z = (self->z * r->w) + (self->w * r->z) + (self->x * r->y) - (self->y * r->x);

	return(quaternion_init(_x, _y, _z, _w));
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
		quaternion->mul = mul;

		// Attributes
		quaternion->x = x;
		quaternion->y = y;
		quaternion->z = z;
		quaternion->w = w;
	}

	return(quaternion);
}