#ifndef _CAMERA_H
#define _CAMERA_H
#include <d3d9.h>
#include <d3dx9.h>
//#include "CRect.h"

class CCamera
{
private:
	D3DXMATRIX m_transform;
	D3DXVECTOR2 m_position;
	//float m_zoom;
	//float m_rotate;
	//Rect m_viewport;
public:
	CCamera(void);
	~CCamera(void);
	void Update(D3DXVECTOR2 _pos, int mapWidth);
	D3DXMATRIX GetTransform();
	//Rect GetBound();
	D3DXVECTOR2 GetPosition();
};

#endif // !_CAMERA_H