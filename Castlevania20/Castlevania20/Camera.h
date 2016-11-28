#ifndef _CAMERA_H_
#define _CAMERA_H_
#include "Globals.h"

class Camera
{
public:
	Camera();
	void UpdateCamera(D3DXVECTOR2 cameraLocation);
	~Camera();
private:
	float m_X;
	float m_Y;
	float m_lastY;
	D3DXMATRIX m_Matrix;
	RECT m_Rect;
};
#endif