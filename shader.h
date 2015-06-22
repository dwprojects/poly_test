#ifndef SHADER_H
#define SHADER_H
#define NUM_SHADERS 2

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "transform.h"

enum {
	TRANSFORM_U,
	NUM_UNIFORMS
};

typedef struct _Shader {
	GLuint program;
	GLuint shaders[NUM_SHADERS];
	GLuint uniforms[NUM_UNIFORMS];

	char * (*load_shader)(struct _Shader *self, char *str, char *ext);
	void (*check_shader_error)(struct _Shader *self, GLuint shader, GLuint flag,
							   int is_program, char *error_msg);
	GLuint (*create_shader)(struct _Shader *self, char *buffer, GLenum shader_type);
	void (*bind)(struct _Shader *);
	void (*update)(struct _Shader *, Transform *transform);
} Shader;

Shader * shader_init(char *str);
void destroy_shader(Shader *);

#endif