/*
 * BitmapFileHeader.h
 *
 *  Created on: Oct 13, 2017
 *      Author: static
 */

#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>
using namespace std;

#pragma pack(2)

namespace fract {

struct BitmapFileHeader {
	char header[2]{'B', 'M'};
	int32_t fileSize;
	int32_t reserved{0};
	int32_t dataOffset;
};

}

#endif /* BITMAPFILEHEADER_H_ */
