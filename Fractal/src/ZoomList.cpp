/*
 * ZoomList.cpp
 *
 *  Created on: Oct 13, 2017
 *      Author: static
 */

#include "ZoomList.h"

using namespace std;

namespace fract {

ZoomList::ZoomList(int width, int height) : m_width(width), m_height(height) {}

void ZoomList::add(const Zoom& zoom) {

	zoomList.push_back(zoom);

	m_xCenter += (zoom._x - m_width / 2) * m_scale;
	m_yCenter += -(zoom._y - m_height / 2) * m_scale;

	m_scale *= zoom._scale;
}

pair<double, double> ZoomList::doZoom(int x, int y) {

	double xFractal = (x - m_width / 2) * m_scale + m_xCenter;
	double yFractal = (y - m_height / 2) * m_scale + m_yCenter;

	return pair<double, double>(xFractal,yFractal);
}


} /* namespace fract */
