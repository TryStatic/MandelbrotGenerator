/*
 * FractalCreator.cpp
 *
 *  Created on: Oct 13, 2017
 *      Author: static
 */

#include "FractalCreator.h"
#include "assert.h"
#include <iostream>

using namespace std;

namespace fract {

FractalCreator::FractalCreator(int width, int height) :
		m_width(width),
		m_height(height),
		m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}),
		m_fractal(new int[m_width * m_height]{0}),
		m_bitmap(m_width, m_height),
		m_zoomList(m_width, m_height),
		m_total(0)
{
}

FractalCreator::~FractalCreator() {
	// TODO Auto-generated destructor stub
}

void FractalCreator::run(string filename) {
	calculateIterations();
	calculateTotalIterations();
	calculateRangeTotals();
	drawFractal();
	writeBitmap(filename);
}

void FractalCreator::run(Screen &screen) {
	calculateIterations();
	cout << " calculateIterations done" << endl;
	calculateTotalIterations();
	cout << " calculateTotalIterations done" << endl;
	calculateRangeTotals();
	cout << "calculateRangeTotals done" << endl;
	drawFractalToScreen(screen);
	cout << "drawFractalToScreen done" << endl;

}

void FractalCreator::addZoom(const Zoom& zoom) {
	m_zoomList.add(zoom);
}

void FractalCreator::addRange(double rangeEnd, const RGB &rgb) {
	m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
	m_colors.push_back(rgb);

	if(m_bGotFirstRange)
		m_rangeTotals.push_back(0);

	m_bGotFirstRange = true;

}

int FractalCreator::getRange(int iterations) const {

	int range = 0;
	for(int i=1 ; i < m_ranges.size(); i++) {
		range = i;
		if(m_ranges[i] > iterations) {
			break;
		}
	}
	range--;
	assert(range > -1);
	assert(range < m_ranges.size());
	return range;
}


void FractalCreator::calculateIterations() {
	for(auto y=0;y<m_height;y++) {
		for(auto x=0;x<m_width;x++) {
			pair<double, double> coords = m_zoomList.doZoom(x, y);
			int iterations = Mandelbrot::getIterations(coords.first, coords.second);
			m_fractal[y*m_width + x] = iterations;
			if(iterations != Mandelbrot::MAX_ITERATIONS)
				m_histogram[iterations]++;
		}
	}
}

void FractalCreator::calculateRangeTotals() {

	int rangeIndex = 0;
	for(int i=0;i<Mandelbrot::MAX_ITERATIONS;i++) {
		int pixels = m_histogram[i];
		if(i >= m_ranges[rangeIndex+1])
			rangeIndex++;
		m_rangeTotals[rangeIndex] += pixels;
	}
}

void FractalCreator::calculateTotalIterations() {
	for(int i=0; i<Mandelbrot::MAX_ITERATIONS; i++)
		m_total += m_histogram[i];
}

void FractalCreator::drawFractal() {

	for(auto y=0;y<m_height;y++) {
		for(auto x=0;x<m_width;x++) {

			int iterations = m_fractal[y*m_width + x];
			int range = getRange(iterations);
			int rangeTotal = m_rangeTotals[range];
			int rangeStart = m_ranges[range];

			RGB& startColor = m_colors[range];
			RGB& endColor = m_colors[range+1];
			RGB colorDiff = endColor - startColor;

			uint8_t red=0;
			uint8_t green=0;
			uint8_t blue=0;

			if(iterations != Mandelbrot::MAX_ITERATIONS) {

				int totalPixels = 0;

				for(int i=rangeStart; i <= iterations; i++) {
					totalPixels += m_histogram[i];
				}

				red = startColor.R + colorDiff.R * (double) totalPixels / rangeTotal;
				green = startColor.G + colorDiff.G * (double) totalPixels / rangeTotal;
				blue = startColor.B + colorDiff.B * (double) totalPixels / rangeTotal;
			}
			m_bitmap.setPixel(x, y, red, green, blue);
		}
	}
}

void FractalCreator::drawFractalToScreen(Screen &screen) {

	for(auto y=0;y<m_height;y++) {
		for(auto x=0;x<m_width;x++) {

			int iterations = m_fractal[y*m_width + x];
			int range = getRange(iterations);
			int rangeTotal = m_rangeTotals[range];
			int rangeStart = m_ranges[range];

			RGB& startColor = m_colors[range];
			RGB& endColor = m_colors[range+1];
			RGB colorDiff = endColor - startColor;

			uint8_t red=0;
			uint8_t green=0;
			uint8_t blue=0;

			if(iterations != Mandelbrot::MAX_ITERATIONS) {

				int totalPixels = 0;

				for(int i=rangeStart; i <= iterations; i++) {
					totalPixels += m_histogram[i];
				}

				red = startColor.R + colorDiff.R * (double) totalPixels / rangeTotal;
				green = startColor.G + colorDiff.G * (double) totalPixels / rangeTotal;
				blue = startColor.B + colorDiff.B * (double) totalPixels / rangeTotal;
			}
			screen.setPixel(x, y, red, green, blue);
		}
	}
}


void FractalCreator::writeBitmap(string filename) {
	m_bitmap.write(filename);
}


} /* namespace fract */
