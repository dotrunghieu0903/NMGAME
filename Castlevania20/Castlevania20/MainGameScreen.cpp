#include "GameState.h"
#include "FinishLevelScreen.h"

int MainGameScreen::score = 0;
int MainGameScreen::coin = 0;
int MainGameScreen::life = 3;
float MainGameScreen::time = 300;
bool MainGameScreen::hasBonus = true;
MainGameScreen::MainGameScreen() : IGameState()
{
	/*quadtree = new CQuadtree();
	loadMap->LoadToQuadtree(quadtree);
	mapWidth = loadMap->mapWidth;
	castlevania = new Castlevania(D3DXVECTOR2(150, 350), ECastlevaniaState::Esmall);
	camera = new CCamera();
	backGround = new CSprite(ResourceManager::GetIns()->GetBackGround(MainGameBG1));
	SoundManager::GetInst()->RemoveAllBGM();
	SoundManager::GetInst()->PlayBGSound(EBGSound::EMainGameSound1);
	level = 1;
	timeWait = 0;
	changeToBonusMap = false;
	m_text = new CText();*/
}

//MainGameScreen::MainGameScreen(SaveGameInfor data) : IGameState()
//{
//	level = data._level;
//	loadMap = data._cloadMap;
//	quadtree = new CQuadtree();
//	loadMap->LoadToQuadtree(quadtree);
//	mapWidth = loadMap->mapWidth;
//	castlevania = data._castlevania;
//	castlevania->SetLife(data._life);
//	castlevania->SetCoin(data._money);
//	castlevania->SetScore(data._score);
//	camera = new CCamera();
//
//	switch (level)
//	{
//	case 1:
//		backGround = new CSprite(ResourceManager::GetIns()->GetBackGround(MainGameBG1));
//		SoundManager::GetInst()->RemoveAllBGM();
//		SoundManager::GetInst()->PlayBGSound(EBGSound::EMainGameSound1);
//		break;
//	case 2:
//		backGround = new CSprite(ResourceManager::GetIns()->GetBackGround(Black));
//		SoundManager::GetInst()->RemoveAllBGM();
//		SoundManager::GetInst()->PlayBGSound(EBGSound::EMainGameSound2);
//		break;
//	case 3:
//		backGround = new CSprite(ResourceManager::GetIns()->GetBackGround(MainGameBG1));
//		SoundManager::GetInst()->RemoveAllBGM();
//		SoundManager::GetInst()->PlayBGSound(EBGSound::EMainGameSound1);
//		break;
//	case 0: //bonus
//		backGround = new CSprite(ResourceManager::GetIns()->GetBackGround(Black));
//		this->castlevania->SetPosition(D3DXVECTOR2(100, 300));
//		break;
//	}
//	timeWait = 0;
//	changeToBonusMap = false;
//	m_text = new CText();
//}
//
//MainGameScreen::MainGameScreen(Castlevania* castlevania, int level) : IGameState()
//{
//	this->castlevania = castlevania;
//	switch (level)
//	{
//	case 1:
//		loadMap = new CLoadMap("MapCastlevania\\lv1\\mapObjects.txt", "MapCastlevania\\lv1\\map.txt");
//		backGround = new CSprite(ResourceManager::GetIns()->GetBackGround(MainGameBG1));
//		SoundManager::GetInst()->RemoveAllBGM();
//		SoundManager::GetInst()->PlayBGSound(EBGSound::EMainGameSound1);
//		break;
//	case 2:
//		loadMap = new CLoadMap("MapCastlevania\\lv2\\mapObjects.txt", "MapCastlevania\\lv2\\map.txt");
//		backGround = new CSprite(ResourceManager::GetIns()->GetBackGround(Black));
//		SoundManager::GetInst()->RemoveAllBGM();
//		SoundManager::GetInst()->PlayBGSound(EBGSound::EMainGameSound2);
//		break;
//	case 3:
//		loadMap = new CLoadMap("MapCastlevania\\lv3\\mapObjects.txt", "MapCastlevania\\lv3\\map.txt");
//		backGround = new CSprite(ResourceManager::GetIns()->GetBackGround(MainGameBG1));
//		SoundManager::GetInst()->RemoveAllBGM();
//		SoundManager::GetInst()->PlayBGSound(EBGSound::EMainGameSound1);
//		break;
//	case 0: //bonus
//		loadMap = new CLoadMap("MapCastlevania\\lvbonus\\mapObjects.txt", "MapCastlevania\\lvbonus\\map.txt");
//		backGround = new CSprite(ResourceManager::GetIns()->GetBackGround(Black));
//		this->castlevania->SetPosition(D3DXVECTOR2(100, 300));
//		break;
//	}
//
//	this->level = level;
//	quadtree = new CQuadtree();
//	loadMap->LoadToQuadtree(quadtree);
//	mapWidth = loadMap->mapWidth;
//
//	camera = new CCamera();
//
//	m_text = new CText();
//	timeWait = 0;
//	changeToBonusMap = false;
//}

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
	//if (castlevania->GetObjectState() == EState::Die)
	//	return;
	//if (input->IsKeyDown(DIK_RIGHT))
	//{
	//	castlevania->TurnRight();
	//}
	//else
	//	//If arrow key left is pressing
	//	if (input->IsKeyDown(DIK_LEFT))
	//	{
	//		castlevania->TurnLeft();
	//	}
	//	else if (castlevania->GetObjectState() != EShooting)
	//		castlevania->Stop();
	////If arrow key down is pressing
	//if (input->IsKeyDown(DIK_DOWN))
	//{
	//	if (castlevania->GetIsInPipe() == false)
	//	{
	//		castlevania->Sit();
	//	}
	//	else if (hasBonus == true)
	//	{
	//		changeToBonusMap = true;
	//	}
	//}
	////If arrow key up is pressing
	//if (input->IsKeyDown(DIK_UP))
	//{
	//	//castlevania->Jump();
	//}
	//if (input->IsKeyPress(DIK_SPACE))
	//{
	//	castlevania->Jump();
	//	SoundManager::GetInst()->PlaySoundEffect(ES_CastlevaniaJump);
	//}
	//if (input->IsKeyPress(DIK_P))
	//{
	//	// get information in case save
	//	SaveGameInfor data;
	//	data._level = level;
	//	data._life = life;
	//	data._money = coin;
	//	data._score = score;
	//	data._castlevania = this->castlevania;
	//	data._cloadMap = this->loadMap;
	//	data._tree = this->quadtree;
	//	data._listCreatingAfter = GameObject::_creatingAfterObjects;
	//	StateManager::GetInstance()->AddScreen(new PauseScreen(data));
	//}


	//if (input->IsKeyPress(DIK_C))
	//{
	//	StateManager::GetInstance()->AddScreen(new MainGameScreen(castlevania, 0));
	//}

	//if (input->IsKeyPress(DIK_Q))
	//{
	//	ExitSceen();
	//	StateManager::GetInstance()->AddScreen(new FinishLevelScreen(castlevania, level));

	//}

	//if (input->IsKeyPress(DIK_D))
	//{
	//	ExitSceen();
	//	castlevania->SetPosition(D3DXVECTOR2(100, 400));
	//}
	//if (input->IsKeyPress(DIK_Z))
	//{
	//	castlevania->Shoot();
	//}

}

void MainGameScreen::Update(float dt)
{
	//Update cac thong so trong game
	Simon::getCurrentSimon()->Update(dt);
	//time -= dt;
	//if (castlevania->GetScore()<score)
	//	castlevania->SetScore(score);
	//if (castlevania->GetCoin() < coin)
	//	castlevania->SetCoin(coin);
	//coin = castlevania->GetCoin();
	//life = castlevania->GetLife();
	//score = castlevania->GetScore();

	////Insert object moi sinh ra
	//if (GameObject::_creatingAfterObjects.size()>0)
	//{
	//	quadtree->Insert(GameObject::_creatingAfterObjects);
	//	GameObject::_creatingAfterObjects.clear();
	//}
	////Lay danh sach cac doi tuong trong man hinh
	//_listObjectsInViewport = quadtree->GetObjectsInViewport(camera->GetBound());

	//list<GameObject*>::iterator i, j;

	//castlevania->Update(dt);

	////Chui xuong cong
	//if (changeToBonusMap == false)
	//{
	//	list<GameObject*> tmpList = quadtree->GetObjectsInViewport(castlevania->GetBoundCheckCollision());
	//	castlevania->UpdateCollision(tmpList, dt);
	//}
	//else
	//{
	//	castlevania->Fall();
	//	castlevania->SetVelocity(D3DXVECTOR2(0, -1));
	//	if (castlevania->GetPosition().y < 50)
	//	{
	//		changeToBonusMap = false;
	//		StateManager::GetInstance()->AddScreen(new MainGameScreen(castlevania, 0));
	//	}
	//}

	//for (i = _listObjectsInViewport.begin(); i != _listObjectsInViewport.end(); i++)
	//{
	//	if ((*i)->GetObjectState() != EState::Die)
	//	{
	//		(*i)->Update(dt);
	//		if ((*i)->GetKindOfObject() == EDynamic)
	//		{
	//			list<GameObject*> tmpList2 = quadtree->GetObjectsInViewport((*i)->GetBoundCheckCollision());
	//			(*i)->UpdateCollision(tmpList2, dt);
	//		}
	//	}
	//}

	//camera->Update(castlevania->GetPosition(), mapWidth);
	////Gioi han vi tri cua castlevania
	//int posy = castlevania->GetPosition().y;
	//if (castlevania->GetPosition().x < camera->GetPosition().x)
	//{
	//	castlevania->SetPosition(D3DXVECTOR2(camera->GetPosition().x, posy));
	//}
	//if (castlevania->GetPosition().x > mapWidth - 50)
	//	castlevania->SetPosition(D3DXVECTOR2(mapWidth - 50, castlevania->GetPosition().y));

	////Thoat khoi BonusMap
	//if (level == 0)
	//{
	//	if (castlevania->GetPosition().x > mapWidth - 150 && castlevania->GetPosition().y < 300)
	//	{
	//		timeWait += dt;
	//		if (timeWait>1)
	//		{
	//			if (StateManager::GetInstance()->GetListState().size()>1)
	//			{
	//				ExitSceen();
	//				castlevania->SetPosition(D3DXVECTOR2(2700, 200));
	//				hasBonus = false;
	//			}
	//			else
	//			{
	//				ExitSceen();
	//				castlevania->SetPosition(D3DXVECTOR2(2700, 200));
	//				StateManager::GetInstance()->AddScreen(new MainGameScreen(castlevania, 1));
	//				hasBonus = false;
	//			}
	//		}
	//	}
	//}

	////Qua man
	//if (castlevania->isLevelFinish == true)
	//{
	//	timeWait += dt;
	//	SoundManager::GetInst()->StopAllBGSound();
	//	SoundManager::GetInst()->PlaySoundEffect(ESoundEffect::ES_Win);
	//	if (timeWait>3)
	//	{
	//		timeWait = 0;
	//		ExitSceen();
	//		StateManager::GetInstance()->AddScreen(new FinishLevelScreen(castlevania, level));
	//	}
	//}
	////Thua
	//if (life <= 0)
	//{
	//	SoundManager::GetInst()->StopAllBGSound();
	//	SoundManager::GetInst()->PlaySoundEffect(ESoundEffect::ES_Lose);
	//	timeWait += dt;
	//	if (timeWait>3)
	//	{
	//		timeWait = 0;
	//		ExitSceen();
	//		castlevania->SetCastlevaniaState(Esmall);
	//		StateManager::GetInstance()->AddScreen(new FinishLevelScreen(castlevania, level));
	//	}
	//}

}

void MainGameScreen::Draw()
{
	loadMap::getCurrentMap()->load();
	Simon::getCurrentSimon()->Draw();
	/*D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	GL_graphic->m_pSpriteHandler->SetTransform(&matrix);
	backGround->Draw(D3DXVECTOR2(400, 300), SpriteEffect::Vertical, 0, 20);
	GL_graphic->m_pSpriteHandler->SetTransform(&camera->GetTransform());

	list<GameObject*>::iterator i;

	for (i = _listObjectsInViewport.begin(); i != _listObjectsInViewport.end(); i++)
	{
		if ((*i) != NULL && (*i)->GetKindOfObject() == EScene)
			(*i)->Draw();
	}
	castlevania->Draw();
	for (i = _listObjectsInViewport.begin(); i != _listObjectsInViewport.end(); i++)
	{
		if ((*i) != NULL && (*i)->GetKindOfObject() != EScene)
			(*i)->Draw();
	}*/

	DrawString();
}

void MainGameScreen::DrawString()
{
	//RECT m_textPosition;
	//char* _text = new char;
	//LPCSTR _p;
	////Life
	//SetRect(&m_textPosition, 100, 10, 200, 790);
	//m_text->Draw("Life X ", m_textPosition, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	//SetRect(&m_textPosition, 170, 10, 200, 790);
	//_itoa(life, _text, 10);
	//_p = _text;
	//m_text->Draw(_p, m_textPosition, DT_LEFT, D3DCOLOR_XRGB(255, 0, 0));

	////Score
	//SetRect(&m_textPosition, 20, 10, 200, 790);
	//_itoa(score, _text, 10);
	//_p = _text;
	//m_text->Draw(_p, m_textPosition, DT_LEFT, D3DCOLOR_XRGB(255, 255, 0));

	////Coin
	//SetRect(&m_textPosition, 200, 10, 400, 790);
	//m_text->Draw("Coin X", m_textPosition, DT_CENTER, D3DCOLOR_XRGB(255, 255, 255));
	//SetRect(&m_textPosition, 300, 10, 400, 790);
	//_itoa(coin, _text, 10);
	//_p = _text;
	//m_text->Draw(_p, m_textPosition, DT_CENTER, D3DCOLOR_XRGB(255, 0, 0));

	////Level
	//SetRect(&m_textPosition, 400, 10, 600, 790);
	//m_text->Draw("WORLD: ", m_textPosition, DT_CENTER, D3DCOLOR_XRGB(255, 255, 255));
	//SetRect(&m_textPosition, 530, 10, 600, 790);
	//_itoa(level, _text, 10);
	//_p = _text;
	//m_text->Draw(_p, m_textPosition, DT_CENTER, D3DCOLOR_XRGB(255, 0, 0));

	////Time
	//SetRect(&m_textPosition, 600, 10, 800, 790);
	//m_text->Draw("Times: ", m_textPosition, DT_CENTER, D3DCOLOR_XRGB(255, 255, 255));
	//SetRect(&m_textPosition, 730, 10, 800, 790);
	//_itoa(time, _text, 10);
	//_p = _text;
	//m_text->Draw(_p, m_textPosition, DT_CENTER, D3DCOLOR_XRGB(255, 0, 0));
}