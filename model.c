#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "model.h"

void draw(Model *self)
{
	glBindVertexArray(self->vertex_array_object);
	glDrawArrays(GL_TRIANGLES,
				 0,
				 self->draw_count);
	glBindVertexArray(0);
}

//Model * model_init(Vertex **vertices, unsigned int vertex_count)
Model * model_init(GLfloat *vertices, unsigned int vertex_count)
{
	// Init
	Model *model = NULL;
	model = malloc(sizeof(Model));

	// Methods
	model->draw = draw;

	// Attributes
	model->draw_count = vertex_count;
	
	glGenVertexArrays(1, &(model->vertex_array_object));
	glBindVertexArray(model->vertex_array_object);

	glGenBuffers(NUM_BUFFERS, model->vertex_array_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, model->vertex_array_buffer[POSITION_VB]);
	
	glBufferData(GL_ARRAY_BUFFER,			
				 3 * vertex_count * sizeof(vertices[0]),
				 vertices,
				 GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,
						  3,
						  GL_FLOAT,
						  GL_FALSE,
						  //GL_TRUE,
						  0,
						  0);

	glBindVertexArray(0);

	return(model);
}

void destroy_model(Model *model)
{
	glDeleteBuffers(NUM_BUFFERS, model->vertex_array_buffer);
	glDeleteVertexArrays(1, &(model->vertex_array_object));
	glDisableVertexAttribArray(0);
	free(model);
	model = NULL;
}