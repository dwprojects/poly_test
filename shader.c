#include <stdio.h>
#include <stdlib.h>
#include "shader.h"

char * load_shader(Shader *self, char *str, char *ext)
{
	/*
	FILE *fp;
	long i = 0;
	char ch;
	char file_name[1024];
	char *buffer;
	strcpy(file_name, str);
	strcat(file_name, ext);

	fp = fopen(file_name, "r");
	fseek(fp, 0, SEEK_END);
	i = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	buffer = malloc(sizeof(i));
	fread(buffer, i, 1, fp);
	fclose(fp);

	//printf("%s-----\n", buffer);
	free(buffer);
	*/
	char *buffer;
	if (strncmp(ext, ".vs", 3))
	{
		// fs
		buffer = "#version 120\nvoid main()\n{\ngl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);\n}";
	}
	else
	{
		// vs
		//buffer = "#version 120\nattribute vec3 position;\nvoid main()\n{\ngl_Position = vec4(position, 1.0);\n}";
		buffer = "#version 120\nattribute vec3 position;\nuniform mat4 transform;\nvoid main()\n{\ngl_Position = transform * vec4(position, 1.0);\n}";
	}
	return(buffer);
}

void check_shader_error(Shader *self, GLuint shader, GLuint flag,
						int is_program, char *error_msg)
{
	GLint success = 0;
	GLchar error[1024] = {0};

	if (is_program)
	{
		glGetProgramiv(shader, flag, &success);
	}
	else
	{
		glGetShaderiv(shader, flag, &success);
	}

	if (success == GL_FALSE)
	{
		if (is_program)
		{
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		}
		else
		{
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);
		}
		printf("%s: %s\n\n", error_msg, error);
	}
}

GLuint create_shader(Shader *self, char *buffer, GLenum shader_type)
{
	GLuint shader = glCreateShader(shader_type);
	if (shader == 0)
	{
		printf("Error creating shader");
	}

	const GLchar *shader_source_string[1];
	GLint shader_source_string_length[1];

	shader_source_string[0] = buffer;
	shader_source_string_length[0] = strlen(buffer);

	glShaderSource(shader, 1, shader_source_string, shader_source_string_length);
	glCompileShader(shader);

	check_shader_error(self, shader, GL_COMPILE_STATUS, 0, "Compilation failed");

	return(shader);
}

void bind(Shader *self)
{
	glUseProgram(self->program);
}

/*
void shader_update(Shader *self, Transform *transform)
{
	Mat4 *model = NULL;
	
	model = transform->get_model(transform);
	printf("%f, %f, %f %f\n", model->m[0][0], model->m[0][1], model->m[0][2], model->m[0][3]);


	glUniformMatrix4fv(self->uniforms[TRANSFORM_U],
					   1,
					   GL_TRUE,
					   &(model->m[0][0]));
	free(model);
}
*/

Shader * shader_init(char *str)
{
	// Init
	Shader *shader = NULL;
	shader = malloc(sizeof(Shader));

	// Methods
	shader->load_shader = load_shader;
	shader->check_shader_error = check_shader_error;
	shader->create_shader = create_shader;
	shader->bind = bind;
	//shader->update = shader_update;

	// Attributes
	shader->program = glCreateProgram();

	shader->shaders[0] = create_shader(shader,
									   //load_shader(shader, str, ".vs"),
										//"#version 120\nattribute vec3 position;\nuniform mat4 transform;\nvoid main()\n{\ngl_Position = transform * vec4(position, 1.0);\n}",
										"#version 120\nattribute vec3 position;\nvoid main()\n{\ngl_Position = vec4(position, 1.0);\n}",
										//"#version 120\nattribute vec3 position;\nuniform mat4 transform;\nvoid main()\n{\ngl_Position = transform * vec4(position, 1.0);\n}",
									   GL_VERTEX_SHADER);
	shader->shaders[1] = create_shader(shader,
									   //load_shader(shader, str, ".fs"),
										"#version 120\nvoid main()\n{\ngl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);\n}",
									   GL_FRAGMENT_SHADER);


	for (int i = 0; i < NUM_SHADERS; i++)
	{
		glAttachShader(shader->program, shader->shaders[i]);
	}

	glBindAttribLocation(shader->program, 0, "position");

	glLinkProgram(shader->program);
	check_shader_error(shader, shader->program, GL_LINK_STATUS, 1, "shader program link failure");
	glValidateProgram(shader->program);
	check_shader_error(shader, shader->program, GL_VALIDATE_STATUS, 1, "invalid program");

	shader->uniforms[TRANSFORM_U] = glGetUniformLocation(shader->program, "transform");

	return(shader);
}

void destroy_shader(Shader *shader)
{
	for (int i = 0; i < NUM_SHADERS; i++)
	{
		glDetachShader(shader->program, shader->shaders[i]);
		glDeleteShader(shader->shaders[i]);
	}

	glDeleteProgram(shader->program);
	free(shader);
	shader = NULL;
}