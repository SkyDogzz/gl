#include "../../include/visu.h"

void	on_delete(t_wrapper *wrapper)
{
	XDestroyWindow(wrapper->display, wrapper->window);
	wrapper->quited = wrapper->quited = true;
}
