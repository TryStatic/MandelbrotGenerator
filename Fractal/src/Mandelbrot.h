/*
 * Mandelbrot.h
 *
 *  Created on: Oct 13, 2017
 *      Author: static
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace fract {

class Mandelbrot {
public:
	static const int MAX_ITERATIONS = 1000;

public:
	Mandelbrot();
	virtual ~Mandelbrot();
	static int getIterations(double x, double y);
};

} /* namespace fract */

#endif /* MANDELBROT_H_ */
