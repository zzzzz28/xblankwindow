#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

int main(int argc, char *argv[])
{
    Display* display = XOpenDisplay(NULL);

	XVisualInfo vinfo;

	XMatchVisualInfo(display, DefaultScreen(display), 32, TrueColor, &vinfo);
	XSetWindowAttributes attr;
	attr.colormap = XCreateColormap(display, DefaultRootWindow(display), vinfo.visual, AllocNone);
	attr.border_pixel = 0; 
	// AARRGGBB
	unsigned long color = 0xFF000000;

	char* windowTitle = "Blank Window";

	int options;
	while ((options = getopt(argc, argv, "t:c:")) != -1) { 
		switch (options) {
			case 't':
				windowTitle = optarg;
				break;
			case 'c':
				color = strtoul(optarg, NULL, 16);
				break;
			default:
				perror("Incorrect usage, Usage: xblankwindow -t \"Window Title\" -c 0xFF112233\n");
				return 1;
		}
	}

	attr.background_pixel = color;

	Window window = XCreateWindow(display, DefaultRootWindow(display), 0, 0, 250, 250, 0, vinfo.depth, InputOutput, vinfo.visual, CWColormap | CWBorderPixel | CWBackPixel, &attr);
    XEvent event;

    XMapWindow(display, window);
    XSelectInput(display, window, ExposureMask | StructureNotifyMask);
	XStoreName(display, window, windowTitle);

	bool running = true;
	Atom wmDeleteMessage = XInternAtom(display, "WM_DELETE_WINDOW", False);
	XSetWMProtocols(display, window, &wmDeleteMessage, 1);
    while (running) {
		
      XNextEvent(display, &event);
      // printf("%d\n", event.type);
	  switch (event.type)
		{
	    	case ClientMessage:
            	if (event.xclient.data.l[0] == wmDeleteMessage)
                	running = false;
            	break;

        	default:
            	break;

		}
    }
    return 0;
}

