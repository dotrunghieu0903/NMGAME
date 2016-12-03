#include "Rect.h"

CRect::CRect() :_x(0), _y(0), _width(0), _height(0)
{
	origin = D3DXVECTOR2(_x, _y);
}
CRect::CRect(float x, float y, float w, float h) : _x(x), _y(y), _width(w), _height(h)
{
	origin = D3DXVECTOR2(_x, _y);
}

CRect::CRect(D3DXVECTOR2 pos, float w, float h) : _x(pos.x), _y(pos.y), _width(w), _height(h)
{
	origin = D3DXVECTOR2(_x, _y);
}

CRect::~CRect()
{}

CRect* CRect::create(float x, float y, float w, float h)
{
	CRect* temp = new CRect(x, y, w, h);
	return temp;
}

RECT CRect::getRECT()
{
	RECT temp;
	temp.top = (int)_y;
	temp.left = (int)_x;
	temp.bottom = temp.top + (int)_height;
	temp.right = temp.left + (int)_width;
	return temp;
}

void CRect::setRect(float x, float y, float w, float h)
{
	_x = x;
	_y = y;
	_width = w;
	_height = h;
}
float CRect::getMaxX() const
{
	return (float)(_x + _width);
}

float CRect::getMidX() const
{
	return (float)(_x + _width / 2.0);
}

float CRect::getMinX() const
{
	return _x;
}

float CRect::getMaxY() const
{
	return _y + _height;
}

float CRect::getMidY() const
{
	return (float)(_y + _height / 2.0);
}

float CRect::getMinY() const
{
	return _y;
}

bool CRect::containsPoint(D3DXVECTOR2 point)
{
	bool bRet = false;

	if (point.x >= getMinX() && point.x <= getMaxX()
		&& point.y >= getMinY() && point.y <= getMaxY())
	{
		bRet = true;
	}

	return bRet;
}

bool CRect::intersectsRect(const CRect& b2)
{
	//     return !(     getMaxX() < rect.getMinX() ||
	//              rect.getMaxX() <      getMinX() ||
	//                   getMaxY() < rect.getMinY() ||
	//              rect.getMaxY() <      getMinY());
	return !(_x + _width < b2._x || _x > b2._x + b2._width || _y + _height < b2._y || _y > b2._y + b2._height);
}

// new
CRect CRect::QuadTL()
{
	return CRect(_x, _y, _width / 2, _height / 2);
}

CRect CRect::QuadTR()
{
	return CRect(_x + _width / 2, _y, _width / 2, _height / 2);
}

CRect CRect::QuadBL()
{
	return CRect(_x, _y + _height / 2, _width / 2, _height / 2);
}

CRect CRect::QuadBR()
{
	return CRect(_x + _width / 2, _y + _height / 2, _width / 2, _height / 2);
}

bool CRect::containRect(const CRect &rect)
{
	if (_x <= rect._x &&
		_x + _width >= rect._x + rect._width &&
		_y <= rect._y &&
		_y + _height >= rect._y + rect._height)
		return true;
	return false;
}

CRect CRect::Overlap(const CRect &r1, const CRect &r2)
{
	CRect r;
	r._x = r1._x < r2._x ? r1._x : r2._x;
	r._y = r1._y < r2._y ? r1._y : r2._y;
	r._width = r1._x + r1._width > r2._x + r2._width ? r1._x + r1._width : r2._x + r2._width;
	r._height = r1._y + r1._height > r2._y + r2._height ? r1._y + r1._height : r2._y + r2._height;
	return r;
}