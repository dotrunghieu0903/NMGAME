#include"BaseObject.h"
list<BaseObject*> BaseObject::_creatingAfterObjects;

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

void BaseObject::UpdateCollision(list<BaseObject*> listUpdate, float dt)
{

}

ECollisionDirect BaseObject::CheckCollision(BaseObject* other, float deltaTime, float &timeCollision)
{
	ECollisionDirect result = ECollisionDirect::Colls_None;
	timeCollision = -1;
	Box otherBox = other->GetBox();
	Box thisBox = GetBox();
	//Kiem tra dieu kien de co xay ra va cham
	//Kiem tra 2 doi tuong dang co va cham hay la ko?
	float moveX, moveY;

	Box BroadphaseBox = GetSweptBroadphaseBox(this->GetBox());

	if (AABBCheck(BroadphaseBox, otherBox) == false) //Truong hop hien nhien khong co va cham
		return result;


	float nomarlx, nomarly;
	timeCollision = SweptAABB(thisBox, otherBox, nomarlx, nomarly);
	if (timeCollision > 0 && timeCollision < 1)
	{

		timeCollision *= deltaTime;
		if (nomarlx == 0 && nomarly == 1)
		{
			result = ECollisionDirect::Colls_Bot;
			return result;
		}
		if (nomarlx == 0 && nomarly == -1)
		{
			result = ECollisionDirect::Colls_Top;
			return result;
		}
		if (nomarlx == 1 && nomarly == 0)
		{
			result = ECollisionDirect::Colls_Left;
			return result;
		}
		if (nomarlx == -1 && nomarly == 0)
		{
			result = ECollisionDirect::Colls_Right;
			return result;
		}
	}
	return result;
}

// bool BaseObject::CheckIsPlatform(list<BaseObject*> listObjects, float dt)
// { 
// 	float tmpY = -1;
// 	float timeTmp = 0;
// 	list<BaseObject*>::iterator it;
// 	float moveX,moveY;	
// 	float normalx,normaly;
// 	float timeCols = 0;
// 	Box tmpBox = this->GetBox();
// 	tmpBox.y -= 2;
// 
// 	for(it=listObjects.begin(); it!=listObjects.end(); ++it)
// 	{
// 		BaseObject* tmp = (*it);
// 		EObjectType typeOther=tmp->GetObjectType();
// 		
// 		if(typeOther != EBreakBrick &&
// 			typeOther != ELand &&
// 			typeOther != EQuestionBox)
// 			continue;
// 
// 
// 		if(AABB(tmpBox,tmp->GetBox(),moveX,moveY) == false)
// 		{
// 			if(AABBCheck(GetSweptBroadphaseBox(this->GetBox()),tmp->GetBox()))
// 			{
// 				timeCols = SweptAABB(this->GetBox(),tmp->GetBox(),normalx,normaly);
// 				if(timeCols > 0 && timeCols < 1)
// 				{
// 					timeCols*=dt;
// 					ECollisionDirect collDriect = GetCollisionDirect(normalx,normaly);
// 					//float remainingtime = t - timeCols;
// 					if(collDriect == Colls_Bot)
// 					{
// 						switch(typeOther)
// 						{
// 						case EBreakBrick:
// 						case ELand:
// 						case EQuestionBox:
// 							if(tmpY < tmp->GetPosition().y)
// 							{
// 								tmpY = tmp->GetPosition().y;
// 								timeTmp = timeCols;
// 							}
// 		//					return true;
// 						}
// 					}
// 				}
// 			}
// 		}
// 		else
// 		{
// 			if(moveY != 0)
// 				return true;
// 		}
// 	}
// 	if(tmpY==-1)
// 		return false;
// 	else
// 	{
// 		m_position.y += m_velocity.y*timeTmp*60+1;
// 		m_velocity.y = 0;
// 		return true;
// 	}
// }

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
	//if (m_type == ESight)
	//	return EKind::EScene;
	//if (m_type == ELand || m_type == EBreakBrick || m_type == EQuestionBox || m_type == EPipe)
	//	return EKind::ESolid;
	return EKind::EStatic;
}

ECollisionDirect BaseObject::GetCollisionDirect(float normalx, float normaly)
{
	if (normalx == 0 && normaly == 1)
	{
		return ECollisionDirect::Colls_Bot;
	}
	if (normalx == 0 && normaly == -1)
	{
		return ECollisionDirect::Colls_Top;
	}
	if (normalx == 1 && normaly == 0)
	{
		return ECollisionDirect::Colls_Left;
	}
	if (normalx == -1 && normaly == 0)
	{
		return ECollisionDirect::Colls_Right;
	}
	return ECollisionDirect::Colls_None;
}

EDirection BaseObject::GetDirection()
{
	return m_direction;
}

CRect BaseObject::GetBoundCheckCollision()
{
	int x = m_position.x - m_velocity.x;
	int y = 600 - m_position.y - 100;
	int w = GetBound()._width + m_velocity.x;
	int h = GetBound()._height + m_velocity.y + 100;
	return CRect(x, y, w, h);
}
void BaseObject::SetFall(bool isfall)
{
	m_isFall = isfall;
}