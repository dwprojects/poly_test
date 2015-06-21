#include "vec3.h"
#include "../util.h"

static GLfloat length(Vec3 *self)
{
	return(sqrt((self->x * self->x) +
				(self->y * self->y) + 
				(self->z * self->z)));
}

static GLfloat dot(Vec3 *self, Vec3 *r)
{
	GLfloat dot = 0.0f;
	return((self->x * r->x) +
		   (self->y * r->y) +
		   (self->z * r->z));
}

static void normalize(Vec3 *self)
{
	GLfloat length = self->length(self);

	self->x = self->x / length;
	self->y = self->y / length;
	self->z = self->z / length;
}

/*
static Vec3 * rotate(Vec3 *self, GLfloat angle)
{
	Vec3 *r = NULL;
	GLfloat rd = d2r(angle);
	GLfloat c = cosf(rd);
	GLfloat s = sinf(rd);

	r = vec3_init( ((self->x * c) - (self->y * s)), 
				    0.0f
				   ((self->x * s) + (self->y * c)) ); 

	return(r);
}
*/

/*
 * Add by float
 */
static Vec3 * add(Vec3 *self, GLfloat r)
{
	return(vec3_init((self->x + r), (self->y + r), (self->z + r)));
}

/*
 * Add by vector
 */
static Vec3 * addv(Vec3 *self, Vec3 *r)
{
	return(vec3_init((self->x + r->x), (self->y + r->y), (self->z + r->z)));
}

/*
 * Subtract by float
 */
static Vec3 * sub(Vec3 *self, GLfloat r)
{
	return(vec3_init((self->x - r), (self->y - r), (self->z - r)));
}

/*
 * Subtract by vector
 */
static Vec3 * subv(Vec3 *self, Vec3 *r)
{
	return(vec3_init((self->x - r->x), (self->y - r->y), (self->z - r->z)));
}

/*
 * Multiply by float
 */
static Vec3 * mul(Vec3 *self, GLfloat r)
{
	return(vec3_init((self->x * r), (self->y * r), (self->z * r)));
}

/*
 * Multiply by vector
 */
static Vec3 * mulv(Vec3 *self, Vec3 *r)
{
	return(vec3_init((self->x * r->x), (self->y * r->y), (self->z * r->z)));
}

/*
 * Divide by GLfloat
 */
static Vec3 * dvd(Vec3 *self, GLfloat r)
{
	return(vec3_init((self->x / r), (self->y / r), (self->z / r)));
}

/*
 * Divide by vector
 */
static Vec3 * dvdv(Vec3 *self, Vec3 *r)
{
	return(vec3_init((self->x / r->x), (self->y / r->y), (self->z / r->z)));
}

static Vec3 * cross_product(Vec3 *self, Vec3 *r)
{
	GLfloat _x = (self->y * r->z) - (self->z * r->y);
	GLfloat _y = (self->z * r->x) - (self->x * r->z);
	GLfloat _z = (self->x * r->y) - (self->y * r->x);
	return(vec3_init(_x, _y, _z));
}

static char * to_string(Vec3 *self)
{
	char *str = "pending\n";
	return(str);
}

Vec3 * vec3_init(GLfloat x, GLfloat y, GLfloat z)
{
	Vec3 *v = NULL;
	v = malloc(sizeof(Vec3));

	if (v)
	{
		// Methods
		v->length = length;
		v->dot = dot;
		v->normalize = normalize;
		v->add = add;
		v->addv = addv;
		v->sub = sub;
		v->subv = subv;
		v->mul = mul;
		v->mulv = mulv;
		v->dvd = dvd;
		v->dvdv = dvdv;
		//v->rotate = rotate;
		v->cross_product = cross_product;
		v->to_string = to_string;

		// Attributes
 		v->x = x;
		v->y = y;
		v->z = z;
	}

	return(v);
}