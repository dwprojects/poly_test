#include "timer.h"

void start_timer(Timer *self)
{
	self->started = 1;
	self->paused = 0;
	self->start_ticks = SDL_GetTicks();
	self->pause_ticks = 0;
}

void stop_timer(Timer *self)
{
	self->started = 0;
	self->paused = 0;
	self->start_ticks = 0;
	self->pause_ticks = 0;
}

unsigned int get_ticks(Timer *self)
{
	unsigned int t = 0;
	if (self->started)
	{
		if (self->paused)
		{
			t = self->pause_ticks;
		}
		else
		{
			t = SDL_GetTicks() - self->start_ticks;
		}
	}
	return(t);
}

Timer * timer_init()
{
	Timer *timer = NULL;
	timer = malloc(sizeof(timer));

	if (timer)
	{
		// Methods
		timer->start_timer = start_timer;
		timer->stop_timer = stop_timer;
		timer->get_ticks = get_ticks;

		// Attributes
		timer->start_ticks = 0;
		timer->pause_ticks = 0;
		timer->started = 0;
		timer->paused = 0;

		return(timer);
	}
	else
	{
		return(NULL);
	}
}

void destroy_timer(Timer *timer)
{
	free(timer);
	timer = NULL;
}