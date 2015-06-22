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
	render_clear_color(0.0f, 0.15f, 0.20f, 1.0f);
	self->shader->bind(self->shader);
	self->model->draw(self->model);
	render_update(self->display->window);
}

static void close(Game *self)
{
	destroy_display(self->display);
	destroy_timer(self->fps);
	destroy_timer(self->cap);
	destroy_transform(self->transform);
	destroy_camera(self->camera);
	destroy_model(self->model);
	destroy_shader(self->shader);
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
		game->model = NULL;
		game->shader = NULL;

		// Display
		game->display = display_init("OpenGL Test", SCREEN_WIDTH, SCREEN_HEIGHT);
		if (!game->display)
		{
			printf("Error creating display: %s\n",
				   SDL_GetError());
		}
		render_init_graphics();

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
    	game->camera = camera_init(NULL, NULL, NULL);
    	if (!game->camera)
    	{
    		printf("Error creating camera\n");
    	}

    	// Model
    	/*
		Vertex *v1 = vertex_init_float(-0.5f, -0.5f, 0.0f);
	    Vertex *v2 = vertex_init_float(0.5f, -0.5f, 0.0f);
	    Vertex *v3 = vertex_init_float(0.0f, 0.5f, 0.0f);
	    Vertex *vertices[] = {v1, v2, v3};
	    */
        GLfloat vertices[] = {-0.5f, -0.5f, 0.0f,
		 					   0.5f, -0.5f, 0.0f,
    	 					   0.0f, 0.5f, 0.0f};

		game->model = model_init(vertices, (int)sizeof(vertices)/sizeof(vertices[0]));

		// Shader
		game->shader = shader_init("./res/basic_shader");
	    
	}

	return(game);
}