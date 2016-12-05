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
	//SoundManager::GetInst()->RemoveAllBGM();
	//SoundManager::GetInst()->PlayBGSound(EBGSound::EMainGameSound1);
	level = 1;
	timeWait = 0;
	changeToBonusMap = false;
	m_text = new CText();
}

//MainGameScreen::MainGameScreen(SaveGameInfor data) : IGameState()
//{
//	level = data._level;
//	loadMap = data._cloadMap;
//	quadtree = new CQuadtree();
//	loadMap->LoadToQuadtree(quadtree);
//	mapWidth = loadMap->mapWidth;
//	simon = data._simon;
//	simon->SetLife(data._life);
//	simon->SetCoin(data._money);
//	simon->SetScore(data._score);
//	camera = new CCamera();
//
//	switch (level)
//	{
//	case 1:
//		backGround = new Sprite(ResourceManager::GetIns()->GetBackGround(MainGameBG1));
//		SoundManager::GetInst()->RemoveAllBGM();
//		SoundManager::GetInst()->PlayBGSound(EBGSound::EMainGameSound1);
//		break;
//	case 2:
//		backGround = new Sprite(ResourceManager::GetIns()->GetBackGround(Black));
//		SoundManager::GetInst()->RemoveAllBGM();
//		SoundManager::GetInst()->PlayBGSound(EBGSound::EMainGameSound2);
//		break;
//	case 3:
//		backGround = new Sprite(ResourceManager::GetIns()->GetBackGround(MainGameBG1));
//		SoundManager::GetInst()->RemoveAllBGM();
//		SoundManager::GetInst()->PlayBGSound(EBGSound::EMainGameSound1);
//		break;
//	case 0: //bonus
//		backGround = new Sprite(ResourceManager::GetIns()->GetBackGround(Black));
//		this->simon->SetPosition(D3DXVECTOR2(100, 300));
//		break;
//	}
//	timeWait = 0;
//	changeToBonusMap = false;
//	m_text = new CText();
//}
//
MainGameScreen::MainGameScreen(Simon* simon, __int8 level) : IGameState()
{
	this->simon = simon;
	switch (level)
	{
	case 1:
		//loadMap = new CLoadMap("MapCastlevania\\lv1\\mapObjects.txt", "MapCastlevania\\lv1\\map.txt");
		this->level = level;
		backGround = new Sprite(ResourceManager::GetIns()->GetBackGround(MainGameBG1));
		//SoundManager::GetInst()->RemoveAllBGM();
		//SoundManager::GetInst()->PlayBGSound(EBGSound::EMainGameSound1);
		break;
	case 2:
		//loadMap = new CLoadMap("MapCastlevania\\lv2\\mapObjects.txt", "MapCastlevania\\lv2\\map.txt");
		this->level = level;
		backGround = new Sprite(ResourceManager::GetIns()->GetBackGround(Black));
		//SoundManager::GetInst()->RemoveAllBGM();
		//SoundManager::GetInst()->PlayBGSound(EBGSound::EMainGameSound2);
		break;
	case 0: //bonus
		//loadMap = new CLoadMap("MapCastlevania\\lvbonus\\mapObjects.txt", "MapCastlevania\\lvbonus\\map.txt");
		backGround = new Sprite(ResourceManager::GetIns()->GetBackGround(Black));
		this->simon->SetPosition(D3DXVECTOR2(100, 300));
		break;
	}

	this->level = level;
	//quadtree = new CQuadtree();
	//loadMap->LoadToQuadtree(quadtree);
	//mapWidth = loadMap->mapWidth;
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
	//	else if (simon->GetObjectState() != EShooting)
	//		simon->Stop();
	////If arrow key down is pressing
	if (input->IsKeyDown(DIK_DOWN))
	{
		if (simon->GetIsInPipe() == false)
		{
			simon->Sit();
		}
		else if (hasBonus == true)
		{
			changeToBonusMap = true;
		}
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
	//if (input->IsKeyPress(DIK_P))
	//{
	//	// get information in case save
	//	SaveGameInfor data;
	//	data._level = level;
	//	data._life = life;
	//	data._money = coin;
	//	data._score = score;
	//	data._simon = this->simon;
	//	data._cloadMap = this->loadMap;
	//	data._tree = this->quadtree;
	//	data._listCreatingAfter = BaseObject::_creatingAfterObjects;
	//	StateManager::GetInstance()->AddScreen(new PauseScreen(data));
	//}


	if (input->IsKeyPress(DIK_C))
	{
		StateManager::GetInstance()->AddScreen(new MainGameScreen(simon, 2));
	}

	//if (input->IsKeyPress(DIK_Q))
	//{
	//	ExitSceen();
	//	StateManager::GetInstance()->AddScreen(new FinishLevelScreen(simon, level));

	//}

	//if (input->IsKeyPress(DIK_D))
	//{
	//	ExitSceen();
	//	simon->SetPosition(D3DXVECTOR2(100, 400));
	//}
	//if (input->IsKeyPress(DIK_Z))
	//{
	//	simon->Shoot();
	//}

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

	////Insert object moi sinh ra
	//if (BaseObject::_creatingAfterObjects.size()>0)
	//{
	//	quadtree->Insert(BaseObject::_creatingAfterObjects);
	//	BaseObject::_creatingAfterObjects.clear();
	//}
	////Lay danh sach cac doi tuong trong man hinh
	//_listObjectsInViewport = quadtree->GetObjectsInViewport(camera->GetBound());

	//list<BaseObject*>::iterator i, j;

	//simon->Update(dt);

	////Chui xuong cong
	//if (changeToBonusMap == false)
	//{
	//	list<BaseObject*> tmpList = quadtree->GetObjectsInViewport(simon->GetBoundCheckCollision());
	//	simon->UpdateCollision(tmpList, dt);
	//}
	//else
	//{
	//	simon->Fall();
	//	simon->SetVelocity(D3DXVECTOR2(0, -1));
	//	if (simon->GetPosition().y < 50)
	//	{
	//		changeToBonusMap = false;
	//		StateManager::GetInstance()->AddScreen(new MainGameScreen(simon, 0));
	//	}
	//}

	//for (i = _listObjectsInViewport.begin(); i != _listObjectsInViewport.end(); i++)
	//{
	//	if ((*i)->GetObjectState() != EState::Die)
	//	{
	//		(*i)->Update(dt);
	//		if ((*i)->GetKindOfObject() == EDynamic)
	//		{
	//			list<BaseObject*> tmpList2 = quadtree->GetObjectsInViewport((*i)->GetBoundCheckCollision());
	//			(*i)->UpdateCollision(tmpList2, dt);
	//		}
	//	}
	//}

	camera->Update(simon->GetPosition(), mapWidth);
	////Gioi han vi tri cua simon
	int posy = simon->GetPosition().y;
	if (simon->GetPosition().x < camera->GetPosition().x)
	{
		simon->SetPosition(D3DXVECTOR2(camera->GetPosition().x, posy));
	}
	if (simon->GetPosition().x > mapWidth - 50)
		simon->SetPosition(D3DXVECTOR2(mapWidth - 50, simon->GetPosition().y));

	////Qua man
	//if (simon->isLevelFinish == true)
	//{
	//	timeWait += dt;
	//	//SoundManager::GetInst()->StopAllBGSound();
	//	//SoundManager::GetInst()->PlaySoundEffect(ESoundEffect::ES_Win);
	//	if (timeWait>3)
	//	{
	//		timeWait = 0;
	//		ExitSceen();
	//		//StateManager::GetInstance()->AddScreen(new FinishLevelScreen(simon, level));
	//	}
	//}
	//Thua
	//if (life <= 0)
	//{
	//	//SoundManager::GetInst()->StopAllBGSound();
	//	//SoundManager::GetInst()->PlaySoundEffect(ESoundEffect::ES_Lose);
	//	timeWait += dt;
	//	if (timeWait>3)
	//	{
	//		timeWait = 0;
	//		ExitSceen();
	//		//StateManager::GetInstance()->AddScreen(new FinishLevelScreen(simon, level));
	//	}
	//}

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