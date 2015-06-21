#include "vec2.h"
#include "../util.h"

static GLfloat length(Vec2 *self)
{
	return(sqrt((self->x * self->x) + 
				(self->y * self->y)));
}

static GLfloat dot(Vec2 *self, Vec2 *r)
{
	GLfloat dot = 0.0f;
	return((self->x * r->x) + (self->y * r->y));
}

static void normalize(Vec2 *self)
{
	GLfloat length = self->length(self);

	self->x = self->x / length;
	self->y = self->y / length;
}

static Vec2 * rotate(Vec2 *self, GLfloat angle)
{
	Vec2 *r = NULL;
	GLfloat rd = d2r(angle);
	GLfloat c = cosf(rd);
	GLfloat s = sinf(rd);

	r = vec2_init( ((self->x * c) - (self->y * s)), 
				   ((self->x * s) + (self->y * c)) ); 

	return(r);
}

/*
 * Add by float
 */
static Vec2 * add(Vec2 *self, GLfloat r)
{
	return(vec2_init((self->x + r), (self->y + r)));
}

/*
 * Add by vector
 */
static Vec2 * addv(Vec2 *self, Vec2 *r)
{
	return(vec2_init((self->x + r->x), (self->y + r->y)));
}

/*
 * Subtract by float
 */
static Vec2 * sub(Vec2 *self, GLfloat r)
{
	return(vec2_init((self->x - r), (self->y - r)));
}

/*
 * Subtract by vector
 */
static Vec2 * subv(Vec2 *self, Vec2 *r)
{
	return(vec2_init((self->x - r->x), (self->y - r->y)));
}

/*
 * Multiply by float
 */
static Vec2 * mul(Vec2 *self, GLfloat r)
{
	return(vec2_init((self->x * r), (self->y * r)));
}

/*
 * Multiply by vector
 */
static Vec2 * mulv(Vec2 *self, Vec2 *r)
{
	return(vec2_init((self->x * r->x), (self->y * r->y)));
}

/*
 * Divide by GLfloat
 */
static Vec2 * dvd(Vec2 *self, GLfloat r)
{
	return(vec2_init((self->x / r), (self->y / r)));
}

/*
 * Divide by vector
 */
static Vec2 * dvdv(Vec2 *self, Vec2 *r)
{
	return(vec2_init((self->x / r->x), (self->y / r->y)));
}


static char * to_string(Vec2 *self)
{
	char *str = "pending\n";
	return(str);
}

Vec2 * vec2_init(GLfloat x, GLfloat y)
{
	Vec2 *v = NULL;
	v = malloc(sizeof(Vec2));

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
		v->rotate = rotate;
		v->to_string = to_string;

		// Attributes
 		v->x = x;
		v->y = y;
	}

	return(v);
}