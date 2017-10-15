/*
 * RBG.cpp
 *
 *  Created on: Oct 13, 2017
 *      Author: static
 */

#include "RGB.h"

namespace fract {

RGB::RGB(double r, double g, double b) : R(r), G(g), B(b) {

}

RGB operator-(const RGB &first, const RGB &second) {
	return RGB(first.R - second.R, first.G - second.G, first.B - second.B);
}

} /* namespace fract */
