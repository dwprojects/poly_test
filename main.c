#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int main(int args, char *argv[])
{
	Game *game = NULL;
	SDL_Init(SDL_INIT_EVERYTHING);
    
    game = game_init();

    if (game)
    {
    	int frames = 0;
    	SDL_Event event;

    	game->run(game);

		while(game->running)
		{
			// Timer
			game->set_cap_timer(game, frames);
			int frame_ticks = game->get_cap_ticks(game);
			float avg_fps = frames / (game->fps->get_ticks(game->fps) / 1000.f);
			if( avg_fps > 2000000 )
			{ 
				avg_fps = 0;
			}

			// Rendering
			game->render(game);
			//printf("%f\n", avg_fps);

			// Event handling
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					game->stop(game);
				}
			}

			// Timer
			if( frame_ticks < TIME_PER_FRAME )
			{
				SDL_Delay(TIME_PER_FRAME - frame_ticks);
			}
			frames++;

			//game->stop(game);

		}

		game->close(game);
		destroy_display(game->display);
		free(game);
		game = NULL;
	}
	else
	{
		printf("Failed to start: %s",
			   SDL_GetError());
	}


	SDL_Quit();
	return(0);
}

