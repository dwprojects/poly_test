#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>

typedef struct _Display {
	SDL_Window *window;
	SDL_GLContext gl_context;
	int i;

	void (*clear)(struct _Display *, float r, float g,
				  float b, float a);
	void (*update)(struct _Display *);

} Display;

Display * display_init(char *title, int screen_width, int screen_height);
void destroy_display(Display *);

#endif