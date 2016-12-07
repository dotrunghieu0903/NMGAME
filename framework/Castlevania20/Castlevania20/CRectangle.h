#ifndef _CRECTANGLE_H_
#define _CRECTANGLE_H_

#pragma once
class CRectangle {
public:
	float X, Y, Width, Height;
	CRectangle() {
		X = 0; Y = 0; Width = 0; Height = 0;
	}

	CRectangle(float x, float y, float width, float height) {
		X = x; Y = y; Width = width; Height = height;
	}
};

#endif