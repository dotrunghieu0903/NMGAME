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
	isFall = false;
	isStandInBar = false;
	canShoot = true;
	isImmortal = false;
	tmpCheck = false;
	tmpCheck2 = false;
	timeShoot = 0;
	timeNextShoot = 0;
	timeChangeState = 0;
	timeCheckLastPoint = 0;
	timeImmortal = 0;
	timeSuperStar = 0;
	positionLastCheck = pos;

	isInPiPe = false;

	alpha_immortal = 255;
	alpha_superstar = 255;
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
		if (hasJumped == false && isFall == false)
		{
			if (simonState == Ebig )
			{
				m_pSprite->_Start = 0;
				m_pSprite->_End = 2;
			}
			if (simonState == Ebig)
			{
				if (m_velocity.x < SIMON_SPEED)
					m_velocity.x += 0.4f;
				else
					m_velocity.x = SIMON_SPEED;
			}
		}
		else
		{

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

void Simon::Shoot()
{

}

void Simon::Update(float dt)
{
	m_pSprite->Update(dt);
	m_position.x += m_velocity.x*dt * 60;

	isInPiPe = false;

	//Cu 5 s luu lai vi tri hien tai 1 lan
	if (m_state != Die) //neu dang o trang thai nay thi ko tinh thoi gian
	{
		timeCheckLastPoint += dt;
		if ((int)timeCheckLastPoint % 5 == 0 && (int)timeCheckLastPoint > 5)
		{
			positionLastCheck = m_position;
			timeCheckLastPoint = 0;
		}
	}
	//Xu ly luc simon chet
	//Neu chet do roi xuong vuc
	if (m_position.y < -20 && m_state != Die)
	{
		life--;
		simonState = Edie;
		hasJumped = false;
		//SoundManager::GetInst()->StopAllBGSound();
		//SoundManager::GetInst()->PlaySoundEffect(ES_SimonDie);
	}
	//Xu ly
	if (simonState == Edie)
	{
		timeChangeState += dt;
		if (timeChangeState > 0.5f)
		{
			m_state = EState::Die;
			timeChangeState = 0;
		}
		m_pSprite->SetIndex(4);
		m_velocity.x = 0;
		Jump(20);
	}
	//Hoi Sinh
	if (m_position.y < -9000)
		simonState = EResborn;
	if (simonState == EResborn && life>0)
	{
		//SoundManager::GetInst()->PlayBGSound(EBGSound::EMainGameSound1);
		m_position = positionLastCheck;
		m_velocity = D3DXVECTOR2(0, 0);
		simonState = Ebig;
		m_pSprite = smallSimon;
		m_state = Alive;
		isImmortal = true;
	}
	//Update trang thai simon

	//if (nextSimonState != Enone)
	//{
	//	ChangeState(dt);
	//}

	//Xu ly thao tac ban dan cua simon
	if (simonAction == EShooting)
	{
		m_pSprite->SetIndex(1);
		timeShoot += dt;
		if (timeShoot >= 0.2f)
		{
			simonAction = EStanding;
			timeShoot = 0;
		}
	}
	if (canShoot == false)
	{
		timeNextShoot += dt;
		if (timeNextShoot>0.3f)
		{
			canShoot = true;
			timeNextShoot = 0;
		}
	}

	//Trang thai bat tu
	if (isImmortal == true)
	{
		timeImmortal += dt;
		if (alpha_immortal>100 && tmpCheck == false)
		{
			alpha_immortal -= 5;
			if (alpha_immortal <= 100)
				tmpCheck = true;
		}
		if (alpha_immortal < 255 && tmpCheck == true)
		{
			alpha_immortal += 5;
			if (alpha_immortal >= 255)
				tmpCheck = false;
		}

		if (timeImmortal > TIME_IMMORTAL_AFTER_HIT)
		{
			isImmortal = false;
			timeImmortal = 0;
		}
	}
	else
	{
		alpha_immortal = 255;
		tmpCheck = false;
	}

	//Xu ly hanh dong simon nhay
	if (hasJumped == true)
	{
		if (simonState == Ebig)
		{
			m_pSprite->_Start = 5;
			m_pSprite->SetIndex(5);
			m_pSprite->_End = 5;
		}
		m_position.y += m_velocity.y*dt * 60;
		m_velocity.y -= 1.20f*dt * 60;
	}
	if (hasJumped == false && isStandInBar == false)
	{
		m_velocity.y = 0;
	}

}

//void Simon::UpdateCollision(list<BaseObject*> listObjects, float dt)
//{
//
//	if (simonState == Edie)
//		return;
//	float timeTmp = 0;
//	list<BaseObject*>::iterator it;
//	float moveX, moveY;
//	float normalx, normaly;
//	float timeCols = 0;
//	Box tmpBox = this->GetBox();
//	Box tmpBox2 = tmpBox;
//	tmpBox2.y -= 2;
//	bool tmpIsFall = true;
//	bool isTopCollision = false;
//	float tmpTimeTopCollision = 0;
//	for (it = listObjects.begin(); it != listObjects.end(); ++it)
//	{
//		BaseObject* otherObject = (*it);
//		//neu doi tuong da chet thi bo qua
//		if (otherObject->GetObjectState() == EState::Die || otherObject->GetObjectState() == EState::Breaking ||
//			otherObject->GetObjectState() == EState::NoCheckCollision ||
//			otherObject->GetObjectState() == EState::KickUp)
//			continue;
//		EObjectType typeOther = otherObject->GetObjectType();
//		Box otherBox = otherObject->GetBox();
//
//		//////////////////////////////////////////////////////////////////////////
//		//Kiem tra neu hien tai simon dang di tren Land
//		if (AABB(tmpBox2, otherObject->GetBox(), moveX, moveY) == true)
//		{
//			if (typeOther == EBreakBrick || typeOther == EQuestionBox)
//			{
//				if (moveY != 0)
//				{
//					tmpIsFall = false;
//					isStandInBar = false;
//					isInPiPe = false;
//				}
//			}
//
//			if (typeOther == EPipe)
//			{
//				Pipe* tmpPipe = (Pipe*)otherObject;
//				if (moveY != 0)
//				{
//					if (tmpPipe->GetDirectToChange() == Colls_Bot)
//						isInPiPe = true;
//					tmpIsFall = false;
//				}
//			}
//
//			if (typeOther == ELand)
//			{
//				Land* tmpLand = (Land*)otherObject;
//				if (tmpLand->GetVelocity().y == 0)
//				{
//					if (moveY != 0)
//					{
//						tmpIsFall = false;
//						isStandInBar = false;
//					}
//				}
//				else
//				{
//					isStandInBar = true;
//					tmpIsFall = false;
//				}
//			}
//		}
//
//
//
//
//		if (AABB(tmpBox, otherBox, moveX, moveY) == false)
//		{
//			//thay doi van toc 2 box
//			if (otherObject->GetKindOfObject() == EDynamic)
//			{
//				tmpBox.vx -= otherBox.vx;
//				tmpBox.vy -= otherBox.vy;
//				otherBox.vx = 0;
//				otherBox.vy = 0;
//			}
//			else
//			{
//				tmpBox = this->GetBox();
//			}
//
//			if (AABBCheck(GetSweptBroadphaseBox(tmpBox), otherBox) == true || AABBCheck(GetSweptBroadphaseBox(otherBox), tmpBox) == true)
//			{
//
//				timeCols = SweptAABB(tmpBox, otherBox, normalx, normaly);
//
//				if (timeCols > 0 && timeCols < 1)
//				{
//					timeCols *= dt;
//					ECollisionDirect collDriect = GetCollisionDirect(normalx, normaly);
//					float remainingtime = dt - timeCols;
//
//
//					switch (typeOther)
//					{
//					case ELand:
//					{
//						switch (collDriect)
//						{
//						case Colls_Bot:
//						{
//							if (otherObject->GetVelocity().y < 0)
//							{
//								m_position.y += m_velocity.y*timeCols * 60;
//								m_velocity.y = otherObject->GetVelocity().y;
//								hasJumped = false;
//								isStandInBar = true;
//								tmpIsFall = false;
//							}
//							else
//							{
//								m_position.y += m_velocity.y*timeCols * 60 + 1;
//								hasJumped = false;
//								tmpIsFall = false;
//							}
//						}
//						break;
//						case Colls_Top:
//						{
//							m_position.y += m_velocity.y*timeCols * 60;
//							m_velocity.y = -m_velocity.y / 2;
//						}
//						break;
//						case Colls_Left:
//						{
//							m_position.x += m_velocity.x*timeCols * 60 + 1;
//							m_velocity.x = 0;
//						}
//						break;
//						case Colls_Right:
//						{
//							m_position.x += m_velocity.x*timeCols * 60 - 1;
//							m_velocity.x = 0;
//						}
//						break;
//						}
//					}
//					break;
//					//////////////////////////////---QuestionBox---//////////////////////////////////
//
//					case EQuestionBox:
//					{
//						switch (collDriect)
//						{
//						case Colls_Bot:
//						{
//							m_position.y += m_velocity.y*timeCols * 60 + 1;
//							hasJumped = false;
//							tmpIsFall = false;
//						}
//						break;
//						case Colls_Top:
//						{
//							isTopCollision = true;
//							tmpTimeTopCollision = timeCols;
//							if (otherObject->GetObjectState() != EState::Blocked)
//							{
//								otherObject->SetObjectState(Hit);
//								QuestionBox* tmpQues = (QuestionBox*)otherObject;
//								if (tmpQues->GetItem()->GetObjectType() == ECoin)
//									gold++;
//							}
//						}
//						break;
//						case Colls_Left:
//						{
//							m_position.x += m_velocity.x*timeCols * 60 + 1;
//							m_velocity.x = 0;
//						}
//						break;
//						case Colls_Right:
//						{
//							m_position.x += m_velocity.x*timeCols * 60 - 1;
//							m_velocity.x = 0;
//						}
//						break;
//						}
//					}
//					break;
//					//////////////////////////////---BreakBrick---//////////////////////////////////
//
//					case  EBreakBrick:
//					{
//						if (otherObject->GetObjectState() != EState::Breaking)
//						{
//
//							switch (collDriect)
//							{
//							case Colls_Bot:
//							{
//								m_position.y += m_velocity.y*timeCols * 60 + 1;
//								hasJumped = false;
//								tmpIsFall = false;
//							}
//							break;
//							case Colls_Top:
//							{
//								isTopCollision = true;
//								tmpTimeTopCollision = timeCols;
//								if (simonState == Ebig || simonState == Egun || simonState == Esuperstar)
//								{
//									otherObject->SetObjectState(EState::Hit);
//									SoundManager::GetInst()->PlaySoundEffect(ES_BreakBrick);
//								}
//								if (simonState == Esmall)
//									otherObject->SetObjectState(EState::Move);
//							}
//							break;
//							case Colls_Left:
//							{
//								m_position.x += m_velocity.x*timeCols * 60 + 1;
//								m_velocity.x = 0;
//							}
//							break;
//							case Colls_Right:
//							{
//								m_position.x += m_velocity.x*timeCols * 60 - 1;
//								m_velocity.x = 0;
//							}
//							break;
//							}
//						}
//					}
//					break;
//					////////////////////////////////Pipie/////////////////////////////////////
//					case  EPipe:
//					{
//						Pipe* tmpPipe = (Pipe*)otherObject;
//
//						switch (collDriect)
//						{
//						case Colls_Bot:
//						{
//							m_position.y += m_velocity.y*timeCols * 60 + 1;
//							hasJumped = false;
//							tmpIsFall = false;
//						}
//						break;
//						case Colls_Top:
//						{
//
//						}
//						break;
//						case Colls_Left:
//						{
//							m_position.x += m_velocity.x*timeCols * 60 + 1;
//							m_velocity.x = 0;
//						}
//						break;
//						case Colls_Right:
//						{
//							if (tmpPipe->GetDirectToChange() != ECollisionDirect::Colls_Right)
//							{
//								m_position.x += m_velocity.x*timeCols * 60 - 1;
//								m_velocity.x = 0;
//							}
//						}
//						break;
//						}
//					}
//					break;
//					////////////////////////////////Fungi///////////////////////////////////////
//					case EFungi:
//					{
//						if (otherObject->GetObjectState() == EState::Hit)
//							continue;
//						Fungi* tmpFungi = (Fungi*)otherObject;
//						if (simonState == Esuperstar)
//						{
//							SoundManager::GetInst()->PlaySoundEffect(ES_KickUp);
//							otherObject->SetObjectState(KickUp);
//							score += 100;
//						}
//						else
//							switch (collDriect)
//							{
//							case Colls_Bot:
//							{
//								m_position.y += m_velocity.y*timeCols * 60 + 1;
//								hasJumped = false;
//								Jump(20);
//								tmpIsFall = false;
//								tmpFungi->SetObjectState(EState::Hit);
//								SoundManager::GetInst()->PlaySoundEffect(ES_FungiDie);
//								score += 100;
//							}
//							break;
//							case Colls_Top:
//							{
//								tmpFungi->SetFall(false);
//								m_position.y += m_velocity.y*timeCols * 60 - 1;
//								m_velocity.y = -m_velocity.y;
//								if (isImmortal == false)
//									nextSimonState = Ehit;
//							}
//							break;
//							case Colls_Left:
//							{
//								m_position.x += m_velocity.x*timeCols * 60 + 1;
//								m_velocity.x = -m_velocity.x;
//								tmpFungi->SetDirection(EDirection::Left);
//								if (isImmortal == false)
//									nextSimonState = Ehit;
//							}
//							break;
//							case Colls_Right:
//							{
//								m_position.x += m_velocity.x*timeCols * 60 - 1;
//								m_velocity.x = -m_velocity.x;
//								Fungi* tmpFungi = (Fungi*)otherObject;
//								tmpFungi->SetDirection(EDirection::Right);
//								if (isImmortal == false)
//									nextSimonState = Ehit;
//							}
//							break;
//							}
//					}
//					break;
//					////////////////////////////////Turtle///////////////////////////////////////
//					case  ETurtle:
//					{
//						Turtle* tmpTurtle = (Turtle*)otherObject;
//						if (simonState == Esuperstar)
//						{
//							SoundManager::GetInst()->PlaySoundEffect(ES_KickUp);
//							otherObject->SetObjectState(KickUp);
//							score += 100;
//						}
//						else
//							switch (collDriect)
//							{
//							case Colls_Bot:
//							{
//								m_position.y += m_velocity.y*timeCols * 60 + 1;
//								hasJumped = false;
//								Jump(15);
//								tmpIsFall = false;
//								if (tmpTurtle->GetObjectState() == EState::Alive)
//									tmpTurtle->SetObjectState(Hit);
//								SoundManager::GetInst()->PlaySoundEffect(ES_TurtleHit);
//								tmpTurtle->SetVelocity(D3DXVECTOR2(0, 0));
//								tmpTurtle->SetDirection(EDirection::NONE);
//							}
//							break;
//							case Colls_Top:
//							{
//								tmpTurtle->SetFall(false);
//								m_position.y += m_velocity.y*timeCols * 60 - 1;
//								m_velocity.y = -m_velocity.y;
//								if (isImmortal == false)
//								{
//									hasJumped = false;
//									Jump(20);
//									nextSimonState = Ehit;
//								}
//							}
//							break;
//							case Colls_Left:
//							{
//								m_position.x += m_velocity.x*timeCols * 60 + 5;
//								m_velocity.x = -m_velocity.x;
//
//								if (tmpTurtle->GetVelocity().x != 0)
//								{
//									if (isImmortal == false)
//									{
//										hasJumped = false;
//										Jump(20);
//										nextSimonState = Ehit;
//									}
//								}
//								tmpTurtle->SetDirection(EDirection::Left);
//								SoundManager::GetInst()->PlaySoundEffect(ES_TurtleHit);
//							}
//							break;
//							case Colls_Right:
//							{
//								m_position.x += m_velocity.x*timeCols * 60 - 5;
//								m_velocity.x = -m_velocity.x;
//
//								if (tmpTurtle->GetVelocity().x != 0)
//								{
//									if (isImmortal == false)
//									{
//										hasJumped = false;
//										Jump(20);
//										nextSimonState = Ehit;
//									}
//								}
//								tmpTurtle->SetDirection(EDirection::Right);
//								SoundManager::GetInst()->PlaySoundEffect(ES_TurtleHit);
//							}
//							break;
//							}
//					}
//					break;
//					///////////////////////////FlowerMonster//////////////////////////////
//					case EFlowerMonster:
//					{
//						FlowerMonster* tmpMonster = (FlowerMonster*)otherObject;
//						if (simonState == Esuperstar)
//						{
//							SoundManager::GetInst()->PlaySoundEffect(ES_KickUp);
//							otherObject->SetObjectState(Die);
//							score += 100;
//						}
//						else
//							if (collDriect == Colls_Bot && m_velocity.y == 0)
//							{
//								tmpMonster->SetCanUp(false);
//							}
//							else
//							{
//								if (isImmortal == false)
//								{
//									hasJumped = false;
//									Jump(20);
//									nextSimonState = Ehit;
//								}
//							}
//					}
//					break;
//					////////////////////////////MushRoom-Red//////////////////////////////
//					//if (typeOther==EObjectType::EMushroom_Red)
//					//{						
//					//	nextSimonState = Ebig;
//					//	otherObject->SetObjectState(EState::Die);
//					//}
//					//////////////////////////Flower//////////////////////////////////
//					case  EFlower:
//					{
//						nextSimonState = Egun;
//						otherObject->SetObjectState(EState::Die);
//						SoundManager::GetInst()->PlaySoundEffect(ES_SimonGrowUp);
//						score += 100;
//					}
//					break;
//					///////////////////Coin///////////////////
//					case ECoin:
//					{
//						otherObject->SetObjectState(EState::Die);
//						SoundManager::GetInst()->PlaySoundEffect(ES_Coin);
//						gold++;
//					}
//					break;
//					//////////////////Star///////////////////
//					case EStar:
//					{
//						otherObject->SetObjectState(Die);
//						nextSimonState = Esuperstar;
//						SoundManager::GetInst()->PlaySoundEffect(ES_SimonGrowUp);
//						score += 100;
//					}
//					break;
//					///////////////////////Goal/////////////////////
//					case EGoal:
//					{
//						otherObject->SetVelocity(D3DXVECTOR2(3, 3));
//						isLevelFinish = true;
//					}
//					break;
//					}
//				}
//			}
//		}
//		else
//		{
//			if (typeOther == ELand || typeOther == EBreakBrick || typeOther == EQuestionBox)
//			{
//				if (moveX<0)
//				{
//					m_velocity.x = -m_velocity.x;
//					m_position.x += moveX - 1;
//				}
//				else if (moveX > 0)
//				{
//					m_velocity.x = -m_velocity.x;
//					m_position.x += moveX + 1;
//				}
//				if (moveY != 0)
//				{
//					m_velocity.y = 0;
//					m_position.y += moveY;
//				}
//			}
//			if (typeOther == EPipe)
//			{
//				Pipe* tmpPipe = (Pipe*)otherObject;
//				if (moveX<0 && tmpPipe->GetDirectToChange() != Colls_Right)
//				{
//					m_velocity.x = -m_velocity.x;
//					m_position.x += moveX - 1;
//				}
//				else if (moveX > 0)
//				{
//					m_velocity.x = -m_velocity.x;
//					m_position.x += moveX + 1;
//				}
//				if (moveY != 0)
//				{
//					m_velocity.y = 0;
//					m_position.y += moveY;
//					hasJumped = false;
//				}
//			}
//
//			if (typeOther == ETurtle)
//			{
//				Turtle* tmpTurtle = (Turtle*)otherObject;
//				if (moveX < 0)		//Va cham phai
//				{
//					m_position.x += moveX - 10;
//					if (tmpTurtle->GetVelocity().x != 0 && isImmortal == false)
//						nextSimonState = Ehit;
//					tmpTurtle->SetDirection(EDirection::Right);
//					SoundManager::GetInst()->PlaySoundEffect(ES_TurtleHit);
//				}
//				else if (moveX > 0)	//Va cham trai
//				{
//					m_position.x += moveX + 10;
//					if (tmpTurtle->GetVelocity().x != 0 && isImmortal == false)
//						nextSimonState = Ehit;
//					tmpTurtle->SetDirection(EDirection::Left);
//					SoundManager::GetInst()->PlaySoundEffect(ES_TurtleHit);
//				}
//				if (moveY>0)			//Va cham duoi
//				{
//					hasJumped = false;
//					Jump(20);
//					tmpTurtle->SetObjectState(Hit);
//					tmpTurtle->SetVelocity(D3DXVECTOR2(0, 0));
//					tmpTurtle->SetDirection(EDirection::NONE);
//					SoundManager::GetInst()->PlaySoundEffect(ES_TurtleHit);
//				}
//				else if (moveY<0)	//Va cham tren
//				{
//					tmpTurtle->SetFall(false);
//					m_position.y += moveY - 1;
//					m_velocity.y = -m_velocity.y / 2;
//					if (isImmortal == false)
//						nextSimonState = Ehit;
//				}
//			}
//
//			if (typeOther == EFungi)
//			{
//				if (otherObject->GetObjectState() == EState::Hit)
//					continue;
//				Fungi* tmpFungi = (Fungi*)otherObject;
//				if (moveX < 0)
//				{
//					m_position.x += moveX - 1;
//					tmpFungi->SetDirection(EDirection::Right);
//					if (isImmortal == false)
//						nextSimonState = Ehit;
//				}
//				else if (moveX > 0)
//				{
//					m_position.x += moveX + 1;
//					tmpFungi->SetDirection(EDirection::Left);
//					if (isImmortal == false)
//						nextSimonState = Ehit;
//				}
//				if (moveY>0)
//				{
//					hasJumped = false;
//					Jump(20);
//					tmpFungi->SetObjectState(EState::Hit);
//					SoundManager::GetInst()->PlaySoundEffect(ES_FungiDie);
//					score += 100;
//				}
//				else if (moveY < 0)
//				{
//					tmpFungi->SetFall(false);
//					m_position.y += moveY - 1;
//					m_velocity.y = -m_velocity.y / 2;
//					if (isImmortal == false)
//						nextSimonState = Ehit;
//				}
//			}
//
//			////////////////////////////FlowerMonster//////////////////////
//			if (typeOther == EFlowerMonster)
//			{
//				FlowerMonster* tmpMonster = (FlowerMonster*)otherObject;
//				if (moveY != 0 && m_velocity.y == 0)
//				{
//					tmpMonster->SetCanUp(false);
//				}
//				else
//				{
//					if (moveY != 0)
//					{
//						hasJumped = false;
//						Jump(20);
//					}
//					if (isImmortal == false)
//						nextSimonState = Ehit;
//				}
//			}
//			////////////////////////////Coin///////////////////////////////
//			if (typeOther == EObjectType::ECoin)
//			{
//				gold++;
//				otherObject->SetObjectState(EState::Die);
//				SoundManager::GetInst()->PlaySoundEffect(ES_Coin);
//			}
//			////////////////////////////MushRoom-Red//////////////////////////////
//			if (typeOther == EObjectType::EMushroom_Red)
//			{
//				nextSimonState = Ebig;
//				otherObject->SetObjectState(EState::Die);
//				SoundManager::GetInst()->PlaySoundEffect(ES_SimonGrowUp);
//				score += 100;
//			}
//			////////////////////////////MushRoom-Green//////////////////////////////
//			if (typeOther == EObjectType::EMushroom_Green)
//			{
//				life++;
//				otherObject->SetObjectState(EState::Die);
//				SoundManager::GetInst()->PlaySoundEffect(ES_SimonLifeUp);
//				score += 100;
//			}
//			//////////////////////////Flower//////////////////////////////////
//			if (typeOther == EFlower)
//			{
//				nextSimonState = Egun;
//				otherObject->SetObjectState(EState::Die);
//				SoundManager::GetInst()->PlaySoundEffect(ES_SimonGrowUp);
//				score += 100;
//			}
//			//////////////////////////Goal////////////////////////////////
//			if (typeOther == EGoal)
//			{
//				otherObject->SetVelocity(D3DXVECTOR2(4, 4));
//				isLevelFinish = true;
//			}
//		}
//	}
//	//Xu ly hanh dong nhay len va cham nhieu doi tuong 1 luc
//	if (isTopCollision == true)
//	{
//		m_position.y += m_velocity.y*tmpTimeTopCollision * 60;
//		m_velocity.y = -m_velocity.y / 4;
//	}
//	if (tmpIsFall == true)
//		Fall();
//}

void Simon::Draw()
{
	D3DCOLOR color = D3DCOLOR_ARGB(255, 255, 255, 255);
	if (isImmortal == true)
		color = D3DCOLOR_ARGB(alpha_immortal, 255, 255, 255);
	m_pSprite->Draw(m_position, m_effect, 0, 1, 0.5f, color);
}

void Simon::ChangeState(float dt)
{

}