#include "Camera.h"

Camera::Camera()
{
	D3DXMatrixIdentity(&m_Matrix);
	m_Matrix._22 = -1;
	m_Y = m_lastY = 600;
}

void Camera::UpdateCamera(D3DXVECTOR2 cameraLocation)
{
	m_X = cameraLocation.x - GL_scrWidth / 2;

	if (m_X < 0)
	{
		m_X = 0;
	}

	if (m_Y < 600)
	{
		m_Y = 600;
	}
	else if (cameraLocation.y > m_Y - 150)
	{
		m_Y += 2;
	}
	else if (cameraLocation.y < m_Y - 450)
	{
		m_Y -= 3;
	}


	m_Matrix._41 = -(m_X);
	m_Matrix._42 = m_Y;

	m_Rect.left = m_X;
	m_Rect.right = m_Rect.left + GL_scrWidth;
	m_Rect.top = m_Y;
	m_Rect.bottom = m_Rect.top - GL_scrHeight;
}
Camera::~Camera()
{
}
