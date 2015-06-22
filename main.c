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

    	game->run(game);

		while(game->running)
		{
			// Timer
			game->set_cap_timer(game, frames);
			int frame_ticks = game->get_cap_ticks(game);

			// Rendering
			game->render(game);
			SDL_Delay(1000);
			game->stop(game);

			// Timer
			if( frame_ticks < TIME_PER_FRAME )
			{
				SDL_Delay( TIME_PER_FRAME - frame_ticks );
			}
			frames++;
		}

		game->close(game);
	}
	else
	{
		printf("Failed to start: %s",
			   SDL_GetError());
	}

	return(0);
}

