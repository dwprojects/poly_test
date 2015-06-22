#include "game.h"

static void start(Game *self)
{
	self->running = 1;
}

static void stop(Game *self)
{
	self->running = 0;
}

static void run(Game *self)
{
	self->start(self);
	self->fps->start_timer(self->fps);
}

static void set_cap_timer(Game *self, int frames)
{
	self->cap->start_timer(self->cap);
	float avg_fps = frames / ( self->fps->get_ticks(self->fps) / 1000.f );
	if( avg_fps > 2000000 )
	{ 
		avg_fps = 0;
	}
}

static int get_cap_ticks(Game *self)
{
	return(self->cap->get_ticks(self->cap));
}

static void render(Game *self)
{
	self->display->clear(self->display, 0.0f, 0.15f, 0.20f, 1.0f);
	self->display->update(self->display);
}

static void close(Game *self)
{
	destroy_display(self->display);
	destroy_timer(self->fps);
	destroy_timer(self->cap);
	destroy_transform(self->transform);
	destroy_camera(self->camera);
}

Game * game_init()
{
	Game *game = NULL;
	game = malloc(sizeof(Game));

	if (game)
	{
		// Methods
		game->start = start;
		game->stop = stop;
		game->run = run;
		game->set_cap_timer = set_cap_timer;
		game->get_cap_ticks = get_cap_ticks;
		game->render = render;
		game->close = close;

		// Attributes
		game->running = 0;
		game->display = NULL;
		game->fps = NULL;
		game->cap = NULL;
		game->transform = NULL;
		game->camera = NULL;

		// Display
		game->display = display_init("OpenGL Test", SCREEN_WIDTH, SCREEN_HEIGHT);
		if (!game->display)
		{
			printf("Error creating display: %s\n",
				   SDL_GetError());
		}

		// Timers
		game->fps = timer_init();
    	game->cap = timer_init();
    	if (!game->fps && game->cap)
    	{
    		printf("Error creating timers\n");
    	}

    	// Transform
    	game->transform = transform_init();
    	if (!game->transform)
    	{
    		printf("Error creating transform\n");
    	}

    	// Camera
    	game->camera = camera_init();
    	if (!game->camera)
    	{
    		printf("Error creating camera\n");
    	}

	}

	return(game);
}