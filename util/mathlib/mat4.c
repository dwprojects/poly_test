#include "mat4.h"

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

Mat4 * mat4_init_rotation(GLfloat x, GLfloat y,
						  GLfloat z)
{
	Mat4 *r = NULL;
	x = d2r(x);
	y = d2r(y);
	//z = d2r(z);
	z = (M_PI * z) / 180;

	Mat4 *rx = NULL;
	Mat4 *ry = NULL;
	Mat4 *rz = NULL;
	rx = malloc(sizeof(Mat4));
	ry = malloc(sizeof(Mat4));
	rz = malloc(sizeof(Mat4));;

	if(rz)
	{
		// Methods
		rz->init_identity = init_identity;
		rz->init_translation = init_translation;
		rz->mul = mul;

		// x
		rz->m[0][0] = cosf(z);
		rz->m[0][1] = -sinf(z);
		rz->m[0][2] = 0.0f;
		rz->m[0][3] = 0.0f;

		// y
		rz->m[1][0] = sinf(z);
		rz->m[1][1] = cosf(z);
		rz->m[1][2] = 0.0f;
		rz->m[1][3] = 0.0f;

		// z
		rz->m[2][0] = 0.0f;
		rz->m[2][1] = 0.0f;
		rz->m[2][2] = 1.0f;
		rz->m[2][3] = 0.0f;

		// w
		rz->m[3][0] = 0.0f;
		rz->m[3][1] = 0.0f;
		rz->m[3][2] = 0.0f;
		rz->m[3][3] = 1.0;
		/*
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				printf("m[%d][%d]: %f ", i, j, m->m[i][j]);
			}
		}
		*/
	}

	if(rx)
	{
		// Methods
		rx->init_identity = init_identity;
		rx->init_translation = init_translation;
		rx->mul = mul;

		// x
		rx->m[0][0] = 1.0f;
		rx->m[0][1] = 0.0f;
		rx->m[0][2] = 0.0f;
		rx->m[0][3] = 0.0f;

		// y
		rx->m[1][0] = 0.0f;
		rx->m[1][1] = cosf(x);
		rx->m[1][2] = -sin(x);
		rx->m[1][3] = 0.0f;

		// z
		rx->m[2][0] = 0.0f;
		rx->m[2][1] = sinf(x);
		rx->m[2][2] = cosf(x);
		rx->m[2][3] = 0.0f;

		// w
		rx->m[3][0] = 0.0f;
		rx->m[3][1] = 0.0f;
		rx->m[3][2] = 0.0f;
		rx->m[3][3] = 1.0;

	}


	if(ry)
	{
		// Methods
		ry->init_identity = init_identity;
		ry->init_translation = init_translation;
		ry->mul = mul;

		// x
		ry->m[0][0] = cosf(y);
		ry->m[0][1] = 0.0f;
		ry->m[0][2] = -sinf(y);
		ry->m[0][3] = 0.0f;

		// y
		ry->m[1][0] = 0.0f;
		ry->m[1][1] = 1.0f;
		ry->m[1][2] = 0.0f;
		ry->m[1][3] = 0.0f;

		// z
		ry->m[2][0] = sinf(y);
		ry->m[2][1] = 0.0f;
		ry->m[2][2] = cosf(y);
		ry->m[2][3] = 0.0f;

		// w
		ry->m[3][0] = 0.0f;
		ry->m[3][1] = 0.0f;
		ry->m[3][2] = 0.0f;
		ry->m[3][3] = 1.0;

	}

	//Mat4 *yx = ry->mul(ry, rx);
	//r = rz->mul(rz, yx);


	//r = rz->mul(rz, ry->mul(ry, rx));
	//return(r);
	return(rz);
}

Mat4 * mat4_init_translation(GLfloat x, GLfloat y,
							 GLfloat z)
{
	Mat4 *mat4 = NULL;
	mat4 = malloc(sizeof(Mat4));

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
		mat4->mul = mul;

		mat4->init_translation = init_translation;
		//mat4->init_rotation = init_rotation;

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