#include "transform.h"

static void set_translation(Transform *self, GLfloat x,
							GLfloat y, GLfloat z)
{
	self->translation->x = x;
	self->translation->y = y;
	self->translation->z = z;
	//printf("%f, %f, %f\n", self->translation->x, self->translation->y, self->translation->z);
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
	t = mat4_init_translation(self->translation->x,
					        self->translation->y,
					  	    self->translation->z);
	
	if (t)
	{
		return(t);
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
		transform->set_translation = set_translation;
		transform->set_translation_vec3 = set_translation_vec3;
		transform->get_transformation = get_transformation;

		// Attributes
		transform->translation = NULL;
		transform->translation = vec3_init(0.0f,
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