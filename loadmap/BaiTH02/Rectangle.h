#pragma once
class CRectangle {
	/*typedef struct RECTANGLE
	{
		Rectangle() {
			X = 0;
			Y = 0;
			Width = 0;
			Height = 0;
		}
		Rectangle(float _x, float _y, float _width, float _height) {
			X = _x;
			Y = _y;
			Width = _width;
			Height = _height;
		}
		float    X;
		float    Y;
		float    Width;
		float    Height;
	} Rectangle;*/
public:
	float X, Y, Width, Height;
	CRectangle() {
		X = 0; Y = 0; Width = 0; Height = 0;
	}

	CRectangle(float x, float y, float width,float height) {
		X = x; Y = y; Width = width; Height = height;
	}
};
