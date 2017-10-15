/*
 * FractalCreator.h
 *
 *  Created on: Oct 13, 2017
 *      Author: static
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include <vector>
#include "Zoom.h"
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "RGB.h"
#include "SDL2/Screen.h"

using namespace std;

namespace fract {

class FractalCreator {
private:
	int m_width;
	int m_height;
	unique_ptr<int[]> m_histogram;
	unique_ptr<int[]> m_fractal;
	Bitmap m_bitmap;
	ZoomList m_zoomList;
	int m_total;

	vector<int> m_ranges;
	vector<RGB> m_colors;
	vector<int> m_rangeTotals;

	bool m_bGotFirstRange{false};
public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

private:
	void calculateIterations();
	void calculateTotalIterations();
	void calculateRangeTotals();
	void drawFractal();
	void drawFractalToScreen(Screen &screen);
	void writeBitmap(string fileame);
	int getRange(int iterations) const;


public:
	void addZoom(const Zoom& zoom);
	void addRange(double rangeEnd, const RGB &color);
	void run(string filename);
	void run(Screen &screen);
};

} /* namespace fract */

#endif /* FRACTALCREATOR_H_ */
