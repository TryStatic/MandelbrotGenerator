/*
 * Screen.h
 *
 *  Created on: Oct 15, 2017
 *      Author: static
 */

#ifndef SDL2_SCREEN_H_
#define SDL2_SCREEN_H_

#include "../HandlerCodes.h"
#include "SDL2/SDL.h"

namespace fract {

class Screen {
private:
	int m_screenWidth;
	int m_screenHeight;
	SDL_Window *m_window { nullptr };
	SDL_Renderer *m_renderer{ nullptr };
	SDL_Texture *m_texture{ nullptr };
	Uint32 *m_buffer{ nullptr };
public:
	Screen(int width, int height);

public:
	bool init();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	int eventHandler(SDL_Event &e);
	void close();
};

} /* namespace fract */

#endif /* SDL2_SCREEN_H_ */
