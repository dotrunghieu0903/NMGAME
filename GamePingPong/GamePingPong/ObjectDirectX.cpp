#include "ObjectDirectX.h"
#include <cmath>
#include <algorithm>
#include <limits>
ObjectDirectX::ObjectDirectX()
{}

ObjectDirectX::ObjectDirectX(LPDIRECT3DDEVICE9 device, LPCSTR path)
{
	_texture->LoadTextureFromFile(
		device,
		path,
		D3DCOLOR_ARGB(100, 255, 255, 255));
}

void ObjectDirectX::init(float x, float y, float w, float h, float vX, float vY)
{
	_width = w;
	_height = h;
	_velocX = vX;
	_velocY = vY;
	position.x = x;
	position.y = y;
}

void ObjectDirectX::render(LPD3DXSPRITE sprireHanlde) {
	
}

float ObjectDirectX::get_width() {
	return _width;
}

float ObjectDirectX::get_height() {
	return _height;
}

float ObjectDirectX::getX() {
	return position.x;
}

float ObjectDirectX::getY() {
	return position.y;
}

void ObjectDirectX::setY(float y) {
	position.y = y;
}

void ObjectDirectX::move() {
	position.x += _velocX;
	position.y += _velocY;
}

void ObjectDirectX::setVeloc(float x, float y)
{
	_velocX = x;
	_velocY = y;
}

float ObjectDirectX::get_velocX() 
{
	return _velocX;
}

float ObjectDirectX::get_velocY()
{
	return _velocY;
}


Box ObjectDirectX::getBox() 
{
	return Box(position.x - _width /2, position.y - _height /2, _width, _height, _velocX, _velocY);
}

float ObjectDirectX::sweptAABB(Box b1, Box b2, float& normalx, float& normaly)
{
	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	// find the distance between the objects on the near and far sides for both x and y
	if (b1.vx > 0.0f)
	{
		xInvEntry = b2.x - (b1.x + b1.w);
		xInvExit = (b2.x + b2.w) - b1.x;
	}
	else
	{
		xInvEntry = (b2.x + b2.w) - b1.x;
		xInvExit = b2.x - (b1.x + b1.w);
	}

	if (b1.vy > 0.0f)
	{
		yInvEntry = b2.y - (b1.y + b1.h);
		yInvExit = (b2.y + b2.h) - b1.y;
	}
	else
	{
		yInvEntry = (b2.y + b2.h) - b1.y;
		yInvExit = b2.y - (b1.y + b1.h);
	}

	// find time of collision and time of leaving for each axis (if statement is to prevent divide by zero)
	float xEntry, yEntry;
	float xExit, yExit;

	if (b1.vx == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		xEntry = xInvEntry / b1.vx;
		xExit = xInvExit / b1.vx;
	}

	if (b1.vy == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / b1.vy;
		yExit = yInvExit / b1.vy;
	}

	// find the earliest/latest times of collision
	float entryTime = xEntry > yEntry ? xEntry : yEntry;
	float exitTime = xExit < yExit ? xExit : yExit;

	// if there was no collision
	if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
	{
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0f;
	}
	else // if there was a collision
	{
		// calculate normal of collided surface
		if (xEntry > yEntry)
		{
			if (xInvEntry < 0.0f)
			{
				normalx = 1.0f;
				normaly = 0.0f;
			}
			else
			{
				normalx = -1.0f;
				normaly = 0.0f;
			}
		}
		else
		{
			if (yInvEntry < 0.0f)
			{
				normalx = 0.0f;
				normaly = 1.0f;
			}
			else
			{
				normalx = 0.0f;
				normaly = -1.0f;
			}
		}

		// return the time of collision
		return entryTime;
	}
}

bool ObjectDirectX::AABB(Box b1, Box b2, float& moveX, float& moveY) {
	moveX = moveY = 0.0f;

	float l = b2.x - (b1.x + b1.w);
	float r = (b2.x + b2.w) - b1.x;
	float t = b2.y - (b1.y + b1.h);
	float b = (b2.y + b2.h) - b1.y;

	// check that there was a collision
	if (l > 0 || r < 0 || t > 0 || b < 0)
		return false;

	// find the offset of both sides
	moveX = abs(l) < r ? l : r;
	moveY = abs(t) < b ? t : b;

	// only use whichever offset is the smallest
	if (abs(moveX) < abs(moveY))
		moveY = 0.0f;
	else
		moveX = 0.0f;

	return true;
}

bool ObjectDirectX::checkCollisionWith(Box box2)
{
	if (AABB(this->getBox(), box2, moveX, moveY))
	{
		return true;
	}
	float result = sweptAABB(this->getBox(), box2, normalx, normaly);
	if (result > 0 && result < 1)
	{
		return true;
	}
	return false;
}

ObjectDirectX::~ObjectDirectX() {

}