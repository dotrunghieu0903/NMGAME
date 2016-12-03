#include "BaseObject.h"

BaseObject::BaseObject(Texture * text, D3DXVECTOR2 pos)
{
	this->objName = ObjectName::NONE;

	this->m_Texture = text;
	this->m_position = pos;
	this->m_OffSetX = 0;
	this->m_OffSetY = 0;

	// mặc định nếu không set
	if (this->m_Texture != NULL)
	{
		//this->m_width = m_Texture->GetWidth();
		//this->m_height = m_Texture->GetHeight();
	}
	else
	{
		this->m_width = 0;
		this->m_height = 0;
	}

	//this->UpdateBound();
}

BaseObject::~BaseObject()
{
}
