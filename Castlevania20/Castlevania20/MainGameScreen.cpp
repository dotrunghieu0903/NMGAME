#include "GameState.h"
#include "FinishLevelScreen.h"

int MainGameScreen::score = 0;
int MainGameScreen::coin = 0;
int MainGameScreen::life = 3;
float MainGameScreen::time = 300;
bool MainGameScreen::hasBonus = true;
MainGameScreen::MainGameScreen() : IGameState()
{
	//quadtree = new CQuadtree();
	//loadMap->LoadToQuadtree(quadtree);
	//mapWidth = loadMap->mapWidth;
	mapWidth = 1024;
	simon = new Simon(D3DXVECTOR2(200, 500), ESimonState::Ebig);
	camera = new CCamera();
	backGround = new Sprite(ResourceManager::GetIns()->GetBackGround(MainGameBG1));
	level = 1;
	timeWait = 0;
	changeToBonusMap = false;
	m_text = new CText();
}

MainGameScreen::MainGameScreen(Simon* simon, __int8 level) : IGameState()
{
	this->simon = simon;
	switch (level)
	{
	case 1:
		//loadMap = new CLoadMa
		this->level = level;
		backGround = new Sprite(ResourceManager::GetIns()->GetBackGround(MainGameBG1));
		break;
	case 2:
		//loadMap = new CLoadMap
		this->level = level;
		backGround = new Sprite(ResourceManager::GetIns()->GetBackGround(Black));
		break;
	default:
		break;
	}

	this->level = level;
	mapWidth = 1024;

	camera = new CCamera();
	loadMap::getCurrentMap()->load();

	m_text = new CText();
	timeWait = 0;
	changeToBonusMap = false;
}

MainGameScreen::~MainGameScreen()
{

}

void MainGameScreen::Create()
{

}

void MainGameScreen::Release()
{
	//_listObjectsInViewport.clear();
}

void MainGameScreen::HandleInput(Input* input, float dt)
{
	if (simon->GetObjectState() == EState::Die)
		return;
	if (input->IsKeyDown(DIK_RIGHT))
	{
		simon->TurnRight();
	}
	else
		//If arrow key left is pressing
		if (input->IsKeyDown(DIK_LEFT))
		{
			simon->TurnLeft();
		}
		else 
			simon->Stop();

	//If arrow key down is pressing
	if (input->IsKeyDown(DIK_DOWN))
	{
		simon->Sit();
	}
	////If arrow key up is pressing
	if (input->IsKeyDown(DIK_UP))
	{
		//simon->Jump();
	}
	if (input->IsKeyPress(DIK_SPACE))
	{
		simon->Jump();
		//SoundManager::GetInst()->PlaySoundEffect(ES_CastlevaniaJump);
	}

	if (input->IsKeyPress(DIK_C))
	{
		StateManager::GetInstance()->AddScreen(new MainGameScreen(simon, 2));
	}
}

void MainGameScreen::Update(float dt)
{
	//Update cac thong so trong game
	time -= dt;
	if (simon->GetScore()<score)
		simon->SetScore(score);
	if (simon->GetCoin() < coin)
		simon->SetCoin(coin);
	coin = simon->GetCoin();
	life = simon->GetLife();
	score = simon->GetScore();

	camera->Update(simon->GetPosition(), mapWidth);

	////Gioi han vi tri cua simon
	int posy = simon->GetPosition().y;
	if (simon->GetPosition().x < camera->GetPosition().x)
	{
		simon->SetPosition(D3DXVECTOR2(camera->GetPosition().x, posy));
	}
	if (simon->GetPosition().x > mapWidth - 50)
		simon->SetPosition(D3DXVECTOR2(mapWidth - 50, simon->GetPosition().y));

}

void MainGameScreen::Draw()
{
	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	GL_graphic->m_pSpriteHandler->SetTransform(&matrix);
	backGround->Draw(D3DXVECTOR2(400, 300), SpriteEffect::Vertical, 0, 20);
	//GL_graphic->m_pSpriteHandler->SetTransform(&camera->GetTransform());

	simon->Draw();

	DrawString();
}

void MainGameScreen::DrawString()
{
	RECT m_textPosition;
	char* _text = new char;
	LPCSTR _p;

	//Score
	SetRect(&m_textPosition, 20, 10, 200, 790);
	_itoa(score, _text, 10);
	_p = _text;
	m_text->Draw(_p, m_textPosition, DT_LEFT, D3DCOLOR_XRGB(255, 255, 0));

	//Time
	SetRect(&m_textPosition, 600, 10, 800, 790);
	m_text->Draw("Life X ", m_textPosition, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	SetRect(&m_textPosition, 730, 10, 800, 790);
	_itoa(life, _text, 10);
	_p = _text;
	m_text->Draw(_p, m_textPosition, DT_CENTER, D3DCOLOR_XRGB(255, 0, 0));

	//Level
	SetRect(&m_textPosition, 400, 10, 600, 790);
	m_text->Draw("STATE: ", m_textPosition, DT_CENTER, D3DCOLOR_XRGB(255, 255, 255));
	SetRect(&m_textPosition, 530, 10, 600, 790);
	_itoa(level, _text, 10);
	_p = _text;
	m_text->Draw(_p, m_textPosition, DT_CENTER, D3DCOLOR_XRGB(255, 0, 0));

	//Life
	SetRect(&m_textPosition, 100, 10, 300, 790);
	m_text->Draw("Times: ", m_textPosition, DT_CENTER, D3DCOLOR_XRGB(255, 255, 255));
	SetRect(&m_textPosition, 240, 10, 300, 790);
	_itoa(time, _text, 10);
	_p = _text;
	m_text->Draw(_p, m_textPosition, DT_LEFT, D3DCOLOR_XRGB(255, 0, 0));
}