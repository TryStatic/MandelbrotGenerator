//============================================================================
// Name        : Fractal.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "FractalCreator.h"
#include "RGB.h"
#include "Zoom.h"
#include "SDL2/Screen.h"
#include "HandlerCodes.h"

using namespace std;
using namespace fract;

int main(int argc, char ** argv) {

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	// Initializations
	FractalCreator fractalCreator(SCREEN_WIDTH, SCREEN_HEIGHT);
	fractalCreator.addRange(0.0, RGB(0, 0, 0));
	fractalCreator.addRange(0.3, RGB(0, 44, 152));
	fractalCreator.addRange(0.5, RGB(23, 132, 173));
	fractalCreator.addRange(1.0, RGB(132, 22, 255));
	Screen screen(SCREEN_WIDTH, SCREEN_HEIGHT);
	//fractalCreator.run("test23.bmp");

	// Screen Init
	if(!screen.init())
		return -1;

	// Screen Loop
	bool redraw = true;
	Zoom z = Zoom(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 4.0/SCREEN_WIDTH);
	while(true) {
		if(redraw) {
			fractalCreator.addZoom(z);
			fractalCreator.run(screen);
			screen.update();
			redraw = false;
			cout << "Finished" << endl;
		}
		SDL_Event event;
		if(screen.eventHandler(event) == QUIT_PROGRAM)
			break;
		else if(screen.eventHandler(event) == REDRAW){
			z._x = event.button.x;
			z._y = SCREEN_HEIGHT - event.button.y;
			z._scale = 0.1;
			redraw = true;
			cout << "Redrawing" << endl;
		}
	}

	screen.close();
	return 0;
}
