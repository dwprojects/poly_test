#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "display.h"

static void clear(Display *self, float r, float g,
				  float b, float a)
{
	glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

static void update(Display *self)
{
    SDL_GL_SwapWindow(self->window);
}

Display * display_init(char *title, int screen_width, int screen_height)
{
    Display *display = NULL;
	display = malloc(sizeof(Display));

    if (display)
    {
    	// Methods
    	display->clear = clear;
        display->update = update;

        // Attributes
    	display->window = NULL;
    	display->i = 3;

    	display->window = SDL_CreateWindow(title,
                                           SDL_WINDOWPOS_UNDEFINED,
                                           SDL_WINDOWPOS_UNDEFINED,
                                           screen_width,
                                           screen_height,
                                           SDL_WINDOW_OPENGL);

    	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,32);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

        display->gl_context = SDL_GL_CreateContext(display->window);

        glewExperimental = GL_TRUE;
        glewInit();
    	glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
    }

	return(display);
}

void destroy_display(Display *display)
{
    SDL_GL_DeleteContext(display->gl_context);
    SDL_DestroyWindow(display->window);
    SDL_Quit();
    free(display);
    display = NULL;
}
