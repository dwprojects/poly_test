#include "mat4.h"
#include "../util.h"

void init_identity(Mat4 *self)
{
	self->m[0][0] = 1.0f;
	self->m[0][1] = 0.0f;
	self->m[0][2] = 0.0f;
	self->m[0][3] = 0.0f;

	self->m[1][0] = 0.0f;
	self->m[1][1] = 1.0f;
	self->m[1][2] = 0.0f;
	self->m[1][3] = 0.0f;

	self->m[2][0] = 0.0f;
	self->m[2][1] = 0.0f;
	self->m[2][2] = 1.0f;
	self->m[2][3] = 0.0f;

	self->m[3][0] = 0.0f;
	self->m[3][1] = 0.0f;
	self->m[3][2] = 0.0f;
	self->m[3][3] = 1.0f;
}

Mat4 * mul(Mat4 *self, Mat4 *r)
{
	Mat4 *mat4 = NULL;
	mat4 = mat4_init();

	if (mat4)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mat4->m[i][j] = ( (self->m[i][0] * r->m[0][j]) +
								  (self->m[i][1] * r->m[1][j]) +
								  (self->m[i][2] * r->m[2][j]) +
								  (self->m[i][3] * r->m[3][j]) );
			}
		}
	}

	return(mat4);
}

Mat4 * mat4_init()
{
	Mat4 *mat4 = NULL;
	mat4 = malloc(sizeof(Mat4));

	if (mat4)
	{
		// Methods
		mat4->init_identity = init_identity;
		mat4->mul = mul;

		// Attributes

	}

	return(mat4);
}