#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "display.h"

Display * display_init(char *title, int screen_width, int screen_height)
{
    Display *display = NULL;
	display = malloc(sizeof(Display));

    if (display)
    {
    	// Methods

      // Attributes
    	display->window = NULL;

    	display->window = SDL_CreateWindow(title,
                                           SDL_WINDOWPOS_UNDEFINED,
                                           SDL_WINDOWPOS_UNDEFINED,
                                           screen_width,
                                           screen_height,
                                           SDL_WINDOW_OPENGL);

        display->gl_context = SDL_GL_CreateContext(display->window);
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
