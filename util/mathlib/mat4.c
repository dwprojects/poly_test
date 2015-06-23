#include "mat4.h"
#include "../util.h"

void init_identity(Mat4 *self)
{
	// x
	self->m[0][0] = 1.0f;
	self->m[0][1] = 0.0f;
	self->m[0][2] = 0.0f;
	self->m[0][3] = 0.0f;

	// y
	self->m[1][0] = 0.0f;
	self->m[1][1] = 1.0f;
	self->m[1][2] = 0.0f;
	self->m[1][3] = 0.0f;

	// z
	self->m[2][0] = 0.0f;
	self->m[2][1] = 0.0f;
	self->m[2][2] = 1.0f;
	self->m[2][3] = 0.0f;

	// w
	self->m[3][0] = 0.0f;
	self->m[3][1] = 0.0f;
	self->m[3][2] = 0.0f;
	self->m[3][3] = 1.0f;
}

void init_translation(Mat4 *self, GLfloat x, GLfloat y,
							   GLfloat z)
{
	// x
	self->m[0][0] = 1.0f;
	self->m[0][1] = 0.0f;
	self->m[0][2] = 0.0f;
	self->m[0][3] = x;

	// y
	self->m[1][0] = 0.0f;
	self->m[1][1] = 1.0f;
	self->m[1][2] = 0.0f;
	self->m[1][3] = y;

	// z
	self->m[2][0] = 0.0f;
	self->m[2][1] = 0.0f;
	self->m[2][2] = 1.0f;
	self->m[2][3] = z;

	// w
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

Mat4 * mat4_init_translation(GLfloat x, GLfloat y,
							 GLfloat z)
{
	Mat4 *mat4 = NULL;
	mat4 = malloc(sizeof(Mat4));;

	if(mat4)
	{
		// Methods
		mat4->init_identity = init_identity;
		mat4->init_translation = init_translation;
		mat4->mul = mul;

		// x
		mat4->m[0][0] = 1.0f;
		mat4->m[0][1] = 0.0f;
		mat4->m[0][2] = 0.0f;
		mat4->m[0][3] = x;

		// y
		mat4->m[1][0] = 0.0f;
		mat4->m[1][1] = 1.0f;
		mat4->m[1][2] = 0.0f;
		mat4->m[1][3] = y;

		// z
		mat4->m[2][0] = 0.0f;
		mat4->m[2][1] = 0.0f;
		mat4->m[2][2] = 1.0f;
		mat4->m[2][3] = z;

		// w
		mat4->m[3][0] = 0.0f;
		mat4->m[3][1] = 0.0f;
		mat4->m[3][2] = 0.0f;
		mat4->m[3][3] = 1.0f;

		return(mat4);
	}
	else
	{
		return(NULL);
	}
}

Mat4 * mat4_init()
{
	Mat4 *mat4 = NULL;
	mat4 = malloc(sizeof(Mat4));

	if (mat4)
	{
		// Methods
		mat4->init_identity = init_identity;
		mat4->init_translation = init_translation;
		mat4->mul = mul;

		// Attributes

		return(mat4);
	}
	else
	{
		return(NULL);
	}
	
}

void destroy_mat4(Mat4 *mat4)
{
	free(mat4);
	mat4 = NULL;
}