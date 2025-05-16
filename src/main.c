#include "../include/visu.h"

int main(void) 
{
	t_wrapper	*wrapper;

	wrapper = (t_wrapper *)malloc(sizeof(t_wrapper));
	if (!wrapper)
		return (0);
	wrapper->quited = 0;
	wrapper->display = XOpenDisplay(NULL);
	if (NULL == wrapper->display) {
		fprintf(stderr, "Failed to initialize display");
		return EXIT_FAILURE;
	}

	wrapper->root = DefaultRootWindow(wrapper->display);
	if (None == wrapper->root) {
		fprintf(stderr, "No root window found");
		XCloseDisplay(wrapper->display);
		return EXIT_FAILURE;
	}

	wrapper->window = XCreateSimpleWindow(wrapper->display, wrapper->root, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0, WINDOW_BACKGROUND);
	if (None == wrapper->window) {
		fprintf(stderr, "Failed to create window");
		XCloseDisplay(wrapper->display);
		return EXIT_FAILURE;
	}
	XMapWindow(wrapper->display, wrapper->window);

	Atom wm_delete_window = XInternAtom(wrapper->display, "WM_DELETE_WINDOW", False);
	XSetWMProtocols(wrapper->display, wrapper->window, & wm_delete_window, 1);

	XSelectInput(wrapper->display, wrapper->window, KeyPressMask | StructureNotifyMask);
	while (!wrapper->quited) {
		XNextEvent(wrapper->display, &wrapper->event);
		switch(wrapper->event.type) {
			case ClientMessage:
				if(wrapper->event.xclient.data.l[0] == (long) wm_delete_window) {
					on_delete(wrapper);
				}
				break;
			case KeyPress:
				if (wrapper->event.xkey.keycode == KEYCODE_ESC || wrapper->event.xkey.keycode == KEYCODE_Q)
					on_delete(wrapper);
				break;
		}
	}
	XCloseDisplay(wrapper->display);
	free(wrapper);
	return 0;
}
