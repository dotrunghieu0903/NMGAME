#include "GameState.h"
#include "FinishLevelScreen.h"

FinishLevelScreen::FinishLevelScreen(Simon* simon, __int8 level) : IGameState()
{
	backgroud = new Sprite(ResourceManager::GetIns()->GetBackGround(Black), 1, 1, 1, 0, 0);
	this->simon = simon;
	switch (simon->GetSimonState())
	{
	case ESimonState::Ebig:
		simonLife = new Sprite(ResourceManager::GetIns()->GetTexture(EResource::Simon_Big_ID), 5, 1, 5, 0, 1);
		break;
	default:
		break;
	}
	simonLife->m_TimeAni = 0.1f;
	coinCount = new Sprite(ResourceManager::GetIns()->GetTexture(EResource::Coin_ID), 7, 1, 7, 0, 6);
	simonPos = D3DXVECTOR2(350, 200);
	coinPos = D3DXVECTOR2(350, 300);
	this->level = level;
	m_text = new CText();
	simon->SetPosition(D3DXVECTOR2(300, 300));
	time = MainGameScreen::time;
	score = MainGameScreen::score;
	life = MainGameScreen::life;
	coin = MainGameScreen::coin;
	timeCountCoin = 0;
	timeCountTimes = 0;
	timeWaitToNextLv = 0;

}

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

	//Score
	SetRect(&m_textRect, 20, 10, 200, 790);
	_itoa(score, _text, 10);
	_p = _text;
	m_text->Draw(_p, m_textRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 0));

	//Time
	SetRect(&m_textRect, 600, 10, 800, 790);
	m_text->Draw("Life X ", m_textRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	SetRect(&m_textRect, 730, 10, 800, 790);
	_itoa(life, _text, 10);
	_p = _text;
	m_text->Draw(_p, m_textRect, DT_CENTER, D3DCOLOR_XRGB(255, 0, 0));

	//Level
	SetRect(&m_textRect, 400, 10, 600, 790);
	m_text->Draw("STATE: ", m_textRect, DT_CENTER, D3DCOLOR_XRGB(255, 255, 255));
	SetRect(&m_textRect, 530, 10, 600, 790);
	_itoa(level, _text, 10);
	_p = _text;
	m_text->Draw(_p, m_textRect, DT_CENTER, D3DCOLOR_XRGB(255, 0, 0));

	//Life
	SetRect(&m_textRect, 100, 10, 300, 790);
	m_text->Draw("Times: ", m_textRect, DT_CENTER, D3DCOLOR_XRGB(255, 255, 255));
	SetRect(&m_textRect, 240, 10, 300, 790);
	_itoa(time, _text, 10);
	_p = _text;
	m_text->Draw(_p, m_textRect, DT_LEFT, D3DCOLOR_XRGB(255, 0, 0));


}