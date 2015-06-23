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
}

static int get_cap_ticks(Game *self)
{
	return(self->cap->get_ticks(self->cap));
}

static void render(Game *self)
{
	Mat4 *model = NULL;

	render_clear_color(0.0f, 0.15f, 0.20f, 1.0f);
	self->shader->bind(self->shader);
	///*
	self->transform->set_rotation(self->transform, 
									 0.0f,
		//sinf(SDL_GetTicks() * 0.006f) / 2,
									 0.0f,
		//cosf(SDL_GetTicks() * 0.006f) / 2,
									 //0.0f);
		 sinf(self->counter) * 180);

	//*/
	/*
	self->transform->set_translation(self->transform, 
									 0.0f,
		//sinf(SDL_GetTicks() * 0.006f) / 2,
									 0.0f,
		//cosf(SDL_GetTicks() * 0.006f) / 2,
									 //0.0f);
		sinf(SDL_GetTicks()) / 2);
	*/
	self->shader->update(self->shader, self->transform);
	self->model->draw(self->model);
	render_update(self->display->window);
	self->counter += 0.1f;
}

static void close(Game *self)
{
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
		game->counter = 0.0f;
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
		game->display = display_init(TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);
		if (!game->display)
		{
			printf("Error creating display: %s\n",
				   SDL_GetError());
			exit(1);
		}
		render_init_graphics();

		// Timers
		game->fps = timer_init();
    	game->cap = timer_init();
    	if ((game->fps == NULL) && (game->cap == NULL))
    	{
    		printf("Error creating timers\n");
    		exit(1);
    	}

    	// Transform
    	game->transform = transform_init();
    	if (!game->transform)
    	{
    		printf("Error creating transform\n");
    		exit(1);
    	}

    	// Camera
    	game->camera = camera_init(NULL, NULL, NULL);
    	if (!game->camera)
    	{
    		printf("Error creating camera\n");
    		exit(1);
    	}

    	// Model
		Vertex *v1 = vertex_init_float(-0.5f, -0.5f, 0.0f);
	    Vertex *v2 = vertex_init_float(0.5f, -0.5f, 0.0f);
	    Vertex *v3 = vertex_init_float(0.0f, 0.5f, 0.0f);
	    VertexArray *vertices = NULL;
	    vertices = vertex_array_init(v1, v2, v3);

		game->model = model_init(vertices->a, (int)sizeof(vertices->a)/sizeof(vertices->a[0]));

		if (!game->model)
		{
			printf("Failed to create model\n");
			exit(1);
		}

		// Shader
		game->shader = shader_init("./res/basic_shader");

	    return(game);
	}
	return(NULL);
}