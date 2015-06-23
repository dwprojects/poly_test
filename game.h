#ifndef GAME_H
#define GAME_H

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define FPS 60
#define TIME_PER_FRAME 1000 / FPS
#define TITLE "OpenGL Test"

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>
#include "model.h"
#include "shader.h"
#include "display.h"
#include "render.h"
#include "camera.h"
#include "input.h"
#include "transform.h"
#include "./util/mathlib/vertex_array.h"
#include "./util/timer/timer.h"

typedef struct _Game 
{
	GLfloat counter;
	int running;
	Display *display;
	Timer *fps;
	Timer *cap;

	Transform *transform;
	Camera *camera;

	Model *model;
	Model *model2;
	Shader *shader;

	void (*start)(struct _Game *);
	void (*stop)(struct _Game *);
	void (*run)(struct _Game *);
	void (*set_cap_timer)(struct _Game *, int frames);
	int (*get_cap_ticks)(struct _Game *);
	void (*render)(struct _Game *);
	void (*update)(struct _Game *);
	void (*close)(struct _Game *);
} Game;

Game * game_init();

#endif