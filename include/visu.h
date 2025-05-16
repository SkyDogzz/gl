#ifndef VISU_H
#define VISU_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>

#include "keycode_i.h"

typedef struct s_wrapper
{
	Display	*display;
	Window	root;
	Window	window;
	XEvent	event;
	bool	quited;
}	t_wrapper;

#define	WINDOW_WIDTH	1280
#define WINDOW_HEIGHT	720
#define WINDOW_BACKGROUND	0x00000000

void	handle_events(t_wrapper *wrapper);
void	on_delete(t_wrapper *wrapper);
void	on_next(t_wrapper *wrapperi);
void	on_previous(t_wrapper *wrapper);

#endif
