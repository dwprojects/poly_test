#include "transform.h"

static void set_rotation(Transform *self, GLfloat x,
							GLfloat y, GLfloat z)
{
	self->rotation->x = x;
	self->rotation->y = y;
	self->rotation->z = z;
}

static void set_rotation_vec3(Transform *self, Vec3 *r)
{
	self->rotation->x = r->x;
	self->rotation->y = r->y;
	self->rotation->z = r->z;
}

static void set_translation(Transform *self, GLfloat x,
							GLfloat y, GLfloat z)
{
	self->translation->x = x;
	self->translation->y = y;
	self->translation->z = z;
}

static void set_translation_vec3(Transform *self, Vec3 *r)
{
	self->translation->x = r->x;
	self->translation->y = r->y;
	self->translation->z = r->z;
}

Mat4 * get_transformation(Transform *self)
{
	Mat4 *t = NULL;
	Mat4 *r = NULL;

	t = mat4_init_translation(self->translation->x,
					        self->translation->y,
					  	    self->translation->z);
	r = mat4_init_rotation(self->rotation->x,
					        self->rotation->y,
					  	    self->rotation->z);

	if (t && r)
	{
		return(t->mul(t, r));
	}
	else
	{
		return(NULL);
	}
}

Transform * transform_init()
{
	Transform *transform = NULL;
	transform = malloc(sizeof(Transform));

	if (transform)
	{
		// Methods
		transform->get_transformation = get_transformation;

		transform->set_translation = set_translation;
		transform->set_translation_vec3 = set_translation_vec3;	

		transform->set_rotation = set_rotation;
		transform->set_rotation_vec3 = set_rotation_vec3;

		// Attributes
		transform->translation = NULL;
		transform->translation = vec3_init(0.0f,
										   0.0f,
										   0.0f);
		transform->rotation = NULL;
		transform->rotation = vec3_init(0.0f,
										0.0f,
										0.0f);
	}
	return(transform);
}

void destroy_transform(Transform *transform)
{
	free(transform);
	transform = NULL;
}