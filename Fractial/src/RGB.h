/*
 * RBG.h
 *
 *  Created on: Oct 13, 2017
 *      Author: static
 */

#ifndef RGB_
#define RGB_

namespace fract {

struct RGB {
	double R;
	double G;
	double B;

	RGB(double r, double g, double b);
};

RGB operator-(const RGB &first, const RGB &second);


} /* namespace fract */

#endif /* RGB_ */
