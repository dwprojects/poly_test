#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int main(int args, char *argv[])
{
	Display *display;

	SDL_Init(SDL_INIT_EVERYTHING);
    display = display_init("OpenGL Test", SCREEN_WIDTH, SCREEN_HEIGHT);

    Timer *fps = timer_init();
    Timer *cap = timer_init();

    if (display)
    {
		int running = 1;
    	int frames = 0;

    	fps->start_timer(fps);

		while(running)
		{
			// Timer
			cap->start_timer(cap);
			float avg_fps = frames / ( fps->get_ticks(fps) / 1000.f );
			if( avg_fps > 2000000 )
			{ 
				avg_fps = 0;
			}
			int frame_ticks = cap->get_ticks(cap);

			// Rendering
			display->clear(display, 0.0f, 0.15f, 0.20f, 1.0f);
			display->update(display);
			SDL_Delay(1000);
			running = 0;

			// Timer
			if( frame_ticks < TIME_PER_FRAME )
			{
				SDL_Delay( TIME_PER_FRAME - frame_ticks );
			}
			frames++;
		}
		destroy_display(display);
	}
	else
	{
		printf("Failed to start: %s",
			   SDL_GetError());
	}

	return(0);
}

