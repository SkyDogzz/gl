#include "../../include/visu.h"

void	handle_events(t_wrapper *wrapper)
{
	if (wrapper->event.xkey.keycode == KEYCODE_ESC || wrapper->event.xkey.keycode == KEYCODE_Q)
		on_delete(wrapper);
	else if (wrapper->event.xkey.keycode == KEYCODE_LEFT_ARROW)
		on_previous(wrapper);
	else if (wrapper->event.xkey.keycode == KEYCODE_RIGHT_ARROW)
		on_next(wrapper);
}
