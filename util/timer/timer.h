#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>

typedef struct _Timer {
	unsigned int start_ticks;
	unsigned int pause_ticks;
	int paused;
	int started;

	void (*start_timer)(struct _Timer *);
	void (*stop_timer)(struct _Timer *);
	unsigned int (*get_ticks)(struct _Timer *);
} Timer;

Timer * timer_init();
void destroy_timer(Timer *);

#endif