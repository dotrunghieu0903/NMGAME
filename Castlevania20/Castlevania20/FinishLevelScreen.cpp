#include "GameState.h"
#include "FinishLevelScreen.h"

//FinishLevelScreen::FinishLevelScreen(Simon* simon, int level) : IGameState()
//{
//	backgroud = new Sprite(ResourceManager::GetIns()->GetBackGround(Black), 1, 1, 1, 0, 0);
//	this->simon = simon;
//	switch (simon->GetSimonState())
//	{
//	case ESimonState::Esmall:
//		simonLife = new Sprite(ResourceManager::GetIns()->GetTexture(EResource::Simon_Small_ID), 6, 1, 6, 0, 1);
//		break;
//	case ESimonState::Ebig:
//		simonLife = new Sprite(ResourceManager::GetIns()->GetTexture(EResource::Simon_Big_ID), 5, 1, 5, 0, 1);
//		break;
//	case ESimonState::Egun:
//	case ESimonState::Esuperstar:
//		simonLife = new Sprite(ResourceManager::GetIns()->GetTexture(EResource::Simon_Gun_ID), 5, 1, 5, 0, 1);
//		break;
//	}
//	simonLife->m_TimeAni = 0.1f;
//	coinCount = new Sprite(ResourceManager::GetIns()->GetTexture(EResource::Coin_ID), 7, 1, 7, 0, 6);
//	simonPos = D3DXVECTOR2(350, 200);
//	coinPos = D3DXVECTOR2(350, 300);
//	this->level = level;
//	m_text = new CText();
//	simon->SetPosition(D3DXVECTOR2(300, 300));
//	time = MainGameScreen::time;
//	score = MainGameScreen::score;
//	life = MainGameScreen::life;
//	coin = MainGameScreen::coin;
//	timeCountCoin = 0;
//	timeCountTimes = 0;
//	timeWaitToNextLv = 0;
//
//}

FinishLevelScreen::~FinishLevelScreen()
{
	IGameState::~IGameState();
}

void FinishLevelScreen::Create()
{

}

void FinishLevelScreen::Release()
{

}

void FinishLevelScreen::HandleInput(Input* input, float dt)
{

}

void FinishLevelScreen::Update(float dt)
{
	simonLife->Update(dt);
	coinCount->Update(dt);
	if (coin > 0)
	{
		timeCountCoin += dt;
		if (timeCountCoin > 0.1f)
		{
			coin--;
			score += 100;
			timeCountCoin = 0;
		}
	}
	else
	{
		if (time > 0)
		{
			timeCountTimes += dt;
			if (timeCountTimes > 0.1f)
			{
				time -= 5;
				score += 50;
				timeCountTimes = 0;
			}
		}
		else
		{
			time = 0;
		}
	}
	if (coin <= 0 && time <= 0 && life>0 && level<3)
	{
		timeWaitToNextLv += dt;
		if (timeWaitToNextLv >5)
		{
			/*simon = new Simon(D3DXVECTOR2(100, 200), simon->GetSimonState(), simon->GetPreviousState());
			simon->SetScore(score);
			simon->SetLife(life);*/

			level += 1;
			ExitSceen();
			/*StateManager::GetInstance()->AddScreen(new MainGameScreen(simon, level));*/
		}
	}
	else
		if ((coin <= 0 && time <= 0 && life == 0) || level == 3)
		{
			timeWaitToNextLv += dt;
			if (timeWaitToNextLv >5)
			{
				ExitSceen();
				StateManager::GetInstance()->AddScreen(new MenuScreen());
			}
		}
}

void FinishLevelScreen::Draw()
{
	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	GL_graphic->m_pSpriteHandler->SetTransform(&matrix);

	simonLife->Draw(simonPos, SpriteEffect::Vertical, 0, 1);
	coinCount->Draw(coinPos, SpriteEffect::None, 0, 1);

	char* _text = new char;
	LPCSTR _p;
	RECT m_textRect;

	//World
	SetRect(&m_textRect, 350, 100, 800, 600);
	m_text->Draw("WORLD:   ", m_textRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	SetRect(&m_textRect, 440, 100, 800, 600);
	_itoa(level, _text, 10);
	_p = _text;
	m_text->Draw(_p, m_textRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));

	//Life
	SetRect(&m_textRect, simonPos.x + simonLife->GetBound()._width + 50, simonPos.y, 800, 800);
	m_text->Draw(" X ", m_textRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	SetRect(&m_textRect, simonPos.x + simonLife->GetBound()._width + 100, simonPos.y, 800, 800);
	_itoa(life, _text, 10);
	_p = _text;
	m_text->Draw(_p, m_textRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));

	//Coin
	SetRect(&m_textRect, coinPos.x + coinCount->GetBound()._width + 50, coinPos.y, 800, 800);
	m_text->Draw(" X ", m_textRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	SetRect(&m_textRect, coinPos.x + coinCount->GetBound()._width + 100, coinPos.y, 800, 800);
	_itoa(coin, _text, 10);
	_p = _text;
	m_text->Draw(_p, m_textRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));

	//Time
	SetRect(&m_textRect, simonPos.x, coinPos.y + coinCount->GetBound()._height + 20, 800, 800);
	m_text->Draw("Times:     ", m_textRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	SetRect(&m_textRect, simonPos.x + 100, coinPos.y + coinCount->GetBound()._height + 20, 800, 800);
	_itoa(time, _text, 10);
	_p = _text;
	m_text->Draw(_p, m_textRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));

	//Score
	SetRect(&m_textRect, 300, 450, 400, 800);
	m_text->Draw("Scores : ", m_textRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	SetRect(&m_textRect, 380, 450, 800, 800);
	_itoa(score, _text, 10);
	_p = _text;
	m_text->Draw(_p, m_textRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));


}