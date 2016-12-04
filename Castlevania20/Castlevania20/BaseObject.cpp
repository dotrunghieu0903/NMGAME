﻿#include "BaseObject.h"

BaseObject::BaseObject() {

}

BaseObject::BaseObject(int X,int Y) {
	objName = ObjectName::NONE;
	_x = X;
	_y = Y;
	_vx = 0;
	_vy = 0;
	_rectObj.left = _x;
	_rectObj.top = _y;
	_rectObj.right = _x + _Width;
	_rectObj.bottom = _y + _Height;

}
//BaseObject::BaseObject(Texture * text, D3DXVECTOR2 pos)
//{
//	this->objName = ObjectName::NONE;
//
//	this->m_Texture = text;
//	this->m_position = pos;
//	this->m_OffSetX = 0;
//	this->m_OffSetY = 0;
//
//	// default if not set
//	if (this->m_Texture != NULL)
//	{
//		this->m_width = m_Texture->m_Width;
//		this->m_height = m_Texture->m_Height;
//	}
//	else
//	{
//		this->m_width = 0;
//		this->m_height = 0;
//	}
//
//	this->UpdateBound();
//}
//void BaseObject::Update(GameTime *gameTime) {
//	this->UpdateBound();
//}

//void BaseObject::Draw(IGame *iGame, Camera *camera) {
//
//}

//void BaseObject::UpdateBound() {
//	//Update rectangle around object
//	m_rectObj.left = m_position.x - m_width / 2;
//	m_rectObj.right = m_rectObj.left + m_width;
//	m_rectObj.top=m_position.y+ m_height / 2;
//	m_rectObj.bottom = m_rectObj.top - m_height;
//}

Box BaseObject::GetObjectBox() {
	return ConvertRectToBox(_rectObj);
}

ObjectName BaseObject::GetName() {
	return this->objName;
}

BaseObject::~BaseObject()
{
}
