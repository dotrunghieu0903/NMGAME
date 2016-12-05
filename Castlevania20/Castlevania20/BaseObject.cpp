#include"BaseObject.h"
list<BaseObject*> BaseObject::_creatingAfterObjects;

BaseObject::BaseObject() {

}

BaseObject::BaseObject(D3DXVECTOR2 pos, EObjectType type, EState state)
{
	m_state = state;
	m_direction = EDirection::NONE;
	m_velocity = D3DXVECTOR2(0, 0);
	m_position = pos;
	m_type = type;
	rotate = 0;
	m_isFall = true;
	canUpdate = false;
	m_effect = SpriteEffect::None;

	// add to _creatingAfterObjects	
}

BaseObject::BaseObject(D3DXVECTOR2 pos, EObjectType type, int id, EState state)
{
	m_state = state;
	m_direction = EDirection::NONE;
	m_velocity = D3DXVECTOR2(0, 0);
	m_position = pos;
	m_type = type;
	rotate = 0;
	m_isFall = true;
	canUpdate = false;
	m_effect = SpriteEffect::None;
	_id = id;
}

BaseObject::~BaseObject()
{
	if (this->m_pSprite != NULL)
	{
		delete m_pSprite;
		this->m_pSprite = NULL;
	}
}

void BaseObject::RemoveDiedObject()
{
	list<BaseObject*>::iterator it = BaseObject::_creatingAfterObjects.begin();
	while (it != BaseObject::_creatingAfterObjects.end())
	{
		if ((*it)->GetObjectState() == EState::Die)
			BaseObject::_creatingAfterObjects.erase(it++);
		else
			++it;
	}
}

CRect BaseObject::GetBound() const
{
	CRect rectOut = m_pSprite->GetBound();
	rectOut._x = m_position.x - rectOut._width / 2;
	rectOut._y = m_position.y - rectOut._height / 2;
	return rectOut;
}

EObjectType BaseObject::GetObjectType() const
{
	return this->m_type;
}

void BaseObject::Update(float deltaTime)
{

}

void BaseObject::Draw()
{
	m_pSprite->Draw(m_position, m_effect, 0, 1, 0.5f);
}

//Get & Set

Box BaseObject::GetBox()
{
	CRect rect = GetBound();
	Box result(rect._x, rect._y, rect._width, rect._height, m_velocity.x, m_velocity.y);
	return result;
}

void BaseObject::SetDirection(EDirection di)
{
	m_direction = di;
}

D3DXVECTOR2 BaseObject::GetPosition()
{
	return m_position;
}

void BaseObject::SetPosition(D3DXVECTOR2 pos)
{
	this->m_position = pos;
}

D3DXVECTOR2 BaseObject::GetVelocity()
{
	return m_velocity;
}

void BaseObject::SetVelocity(D3DXVECTOR2 vel)
{
	this->m_velocity = vel;
}

Sprite* BaseObject::GetSprite()
{
	return m_pSprite;
}

EState BaseObject::GetObjectState()
{
	return m_state;
}

void BaseObject::SetObjectState(EState state)
{
	m_state = state;
}

EKind BaseObject::GetKindOfObject()
{
	if (m_type == ESimon )
		return EKind::EDynamic;
	return EKind::EStatic;
}

EDirection BaseObject::GetDirection()
{
	return m_direction;
}

void BaseObject::SetFall(bool isfall)
{
	m_isFall = isfall;
}