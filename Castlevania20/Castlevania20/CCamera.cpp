#include "CCamera.h"


CCamera::CCamera(void)
{
	//m_position.y = 0;
	m_position.y = 0;
	m_position.x = 0;
}


CCamera::~CCamera(void)
{

}

void CCamera::Update(D3DXVECTOR2 _pos, int mapWidth)
{

	if (m_position.x > _pos.x - 400 + 130)
		m_position.x = _pos.x - 400 + 130;
	//if(m_position.x < _pos.x -400 - 130)
	//	m_position.x = _pos.x -400 - 130;
	if (m_position.x < _pos.x - 400 + 100)
		m_position.x += 3.0f;
	if (m_position.x > _pos.x - 400 - 100)
		m_position.x -= 3.0f;

	//if(m_position.y > _pos.y + 520)
	//	m_position.y -= 3.5f;
	//if(m_position.y < _pos.y + 140)
	//	m_position.y += 2.5f;
	if (m_position.x < 0)
		m_position.x = 0;
	if (m_position.x + 800 >= mapWidth)
		m_position.x =(float)(mapWidth - 800);
	if (_pos.y < 0)
		m_position.y = 600;
}

D3DXMATRIX CCamera::GetTransform()
{
	D3DXMatrixIdentity(&m_transform);
	////D3DXMatrixAffineTransformation(&m_transform,m_zoom,&D3DXVECTOR3(0,0,0),&D3DXQUATERNION(0,0,0,0),&D3DXVECTOR3(-m_position.x,m_position.y,0));
	D3DXMATRIX mtScale;
	D3DXMatrixScaling(&mtScale, 1, 1, 0);
	D3DXMATRIX mtTrans;
	D3DXMatrixTranslation(&mtTrans, -m_position.x, m_position.y, 0);
	m_transform = mtScale*mtTrans;
	//m_transform._41 = -m_position.x;
	//m_transform._42 = m_position.y;
	m_transform._22 = -1;
	return m_transform;
}

//Rect CCamera::GetBound()
//{
//	return RectMake(m_position.x, 0, 800, 800);
//}

D3DXVECTOR2 CCamera::GetPosition()
{
	return m_position;
}

CCamera* CCamera::_camera = 0;
CCamera* CCamera::GetCamera() {
	if (!_camera)
		_camera = new CCamera();
	return _camera;
}

float CCamera::getViewPortX() {
	return m_position.x;
}

float CCamera::getViewPortY() {
	return m_position.y+GL_scrHeight;
}