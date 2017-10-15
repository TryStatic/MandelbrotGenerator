/*
 * Screen.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: static
 */

#include "Screen.h"

namespace fract {

Screen::Screen(int width, int height) : m_screenWidth(width), m_screenHeight(height) { }

bool Screen::init() {

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		return false;

	m_window = SDL_CreateWindow("Mandelbrot Fractal", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_screenWidth, m_screenHeight, SDL_WINDOW_SHOWN);
	if(m_window == nullptr) {
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	if(m_renderer == nullptr) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, m_screenWidth, m_screenHeight);
	if(m_texture == nullptr) {
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_buffer = new Uint32[m_screenWidth * m_screenHeight];

	memset(m_buffer, 0, m_screenWidth * m_screenHeight * sizeof(Uint32));

	return true;
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
	if(x < 0 || x > m_screenWidth || y < 0 || y > m_screenHeight) {
		return;
	}

	Uint32 color = 0;
	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;

	m_buffer[ (y * m_screenWidth) + x ] = color;

}

void Screen::update() {
	SDL_UpdateTexture(m_texture, nullptr, m_buffer, m_screenWidth * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, nullptr, nullptr);
	SDL_RenderPresent(m_renderer);
}


int Screen::eventHandler(SDL_Event &e) {
	SDL_Event event;

	while(SDL_PollEvent(&event)) {
		if(event.type == SDL_QUIT) {
			return QUIT_PROGRAM;
		}
		if(event.type == SDL_MOUSEBUTTONDOWN) {
			int x = event.button.x;
			int y = event.button.y;
			if(x < 0 || y < 0 || x > m_screenWidth || y > m_screenHeight)
				return DEFAULT;
			e = event;
			return REDRAW;
		}
	}
	return DEFAULT;
}

void Screen::close() {
	delete[] m_buffer;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}



} /* namespace fract */
