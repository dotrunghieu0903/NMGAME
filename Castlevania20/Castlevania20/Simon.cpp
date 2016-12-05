#include "Simon.h"

Simon::Simon(D3DXVECTOR2 pos, ESimonState stateSimon, ESimonState previousState) :BaseObject(pos, EObjectType::ESimon)
{
	simonState = stateSimon;
	this->previousState = previousState;
	smallSimon = new Sprite(ResourceManager::GetIns()->GetTexture(EResource::Simon_Big_ID), 8, 3, 24, 0, 7);
	smallSimon->m_TimeAni = 0.1f;
	if (simonState != Edie)
	{
		switch (simonState)
		{
		case Ebig:
			m_pSprite = smallSimon;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (previousState)
		{
		case Ebig:
			m_pSprite = smallSimon;
			break;
		default:
			break;
		}
	}
	isLeft = false;
	m_effect = SpriteEffect::None;
	m_velocity = D3DXVECTOR2(0, 0);
	hasJumped = true;
	tmpCheck = false;
	timeImmortal = 0;

	alpha_immortal = 255;
	gold = 0;
	score = 0;
	life = 3;
	isLevelFinish = false;
}

Simon::~Simon()
{
	BaseObject::~BaseObject();
}

void Simon::TurnLeft()
{
	if (simonAction != ESitting)
	{
		simonAction = ERunning;
		isLeft = true;
		m_effect = SpriteEffect::Horizontally;
		if (hasJumped == false && simonAction != EFalling)
		{
			if (simonState == Ebig )
			{
				m_pSprite->_Start = 0;
				m_pSprite->_End = 1;
			}
			if (simonState == Ebig)
			{
				if (m_velocity.x > -SIMON_SPEED)
					m_velocity.x -= 0.4f;
				else
					m_velocity.x = -SIMON_SPEED;
			}
		}
		else
		{
			if (m_velocity.x > -SIMON_SPEEDWJUMP)
				m_velocity.x -= 0.2f;
			else
				m_velocity.x = -SIMON_SPEEDWJUMP;
		}
	}
}

void Simon::TurnRight()
{
	if (simonAction != ESitting)
	{
		simonAction = ERunning;
		isLeft = false;
		m_effect = SpriteEffect::None;
		if (hasJumped == true){
			if (m_velocity.x < SIMON_SPEEDWJUMP)
				m_velocity.x += 0.2f;
			else
				m_velocity.x = SIMON_SPEEDWJUMP;
		}
	}
}

void Simon::Jump(int v)
{

	if (simonAction != ESitting)
	{
		simonAction = EJumping;
		if (hasJumped == false)
		{
			if ( simonState == Ebig )
			{
				m_pSprite->_Start = 3;
				m_pSprite->SetIndex(3);
				m_pSprite->_End = 3;
			}
			//m_position.y += 5;
			if (simonState == Ebig)
				m_velocity.y = v;
			else
				m_velocity.y = v + 2;
			hasJumped = true;
		}
	}
}

void Simon::Sit()
{
	simonAction = ESitting;
	int indextmp;
	if (simonState == Ebig)
		indextmp = 3;
	else
		indextmp = 4;
	m_pSprite->_Start = indextmp;
	m_pSprite->SetIndex(indextmp);
	m_pSprite->_End = indextmp;
}

void Simon::Fall()
{
	hasJumped = true;
}

void Simon::Stop()
{
	if (hasJumped == false && simonAction != EShooting)
	{
		if (m_velocity.x>0)
			m_velocity.x -= FRICTION;
		if (m_velocity.x <0)
			m_velocity.x += FRICTION;
		if ((m_velocity.x < 0.2f && m_velocity.x > 0) || (m_velocity.x > -0.2f && m_velocity.x < 0))
			m_velocity.x = 0;
		m_pSprite->SetIndex(0);
		simonAction = EStanding;
	}
	else
	{
		if (m_velocity.x>0)
			m_velocity.x -= 0.04f;
		if (m_velocity.x <0)
			m_velocity.x += 0.04f;
	}
}

void Simon::Update(float dt)
{
	m_pSprite->Update(dt);
	m_position.x += m_velocity.x*dt * 60;

	//Xu ly
	//Xu ly hanh dong simon nhay
	if (hasJumped == true)
	{
		if (simonState == Ebig )
		{
			m_pSprite->_Start = 5;
			m_pSprite->SetIndex(5);
			m_pSprite->_End = 5;
		}
		m_position.y += m_velocity.y*dt * 60;
		m_velocity.y -= 1.20f*dt * 60;
	}

}

void Simon::Draw()
{
	D3DCOLOR color = D3DCOLOR_ARGB(255, 255, 255, 255);
	m_pSprite->Draw(m_position, m_effect, 0, 1, 0.5f, color);
}

void Simon::ChangeState(float dt)
{

}