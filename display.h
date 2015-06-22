#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "render.h"

typedef struct _Display {
	SDL_Window *window;
	SDL_GLContext gl_context;
} Display;

Display * display_init(char *title, int screen_width, int screen_height);
void destroy_display(Display *);

#endif