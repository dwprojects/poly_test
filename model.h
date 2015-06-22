#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "./util/mathlib/vertex.h"

enum
{
	POSITION_VB,
	NUM_BUFFERS
};

typedef struct _Model {
	GLuint vertex_array_object;
	GLuint vertex_array_buffer[NUM_BUFFERS];
	unsigned int draw_count;

	void (*draw)(struct _Model *);
	
} Model;

//Model * model_init(Vertex **vertices, unsigned int vertex_count);
Model * model_init(GLfloat *vertices, unsigned int vertex_count);
void destroy_model(Model *);

#endif