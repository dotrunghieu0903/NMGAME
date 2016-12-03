//#include "resourceManager.h"
//
//ResourceManager* ResourceManager::_instance = NULL;
//
//ResourceManager::ResourceManager()
//{
//
//}
//ResourceManager::~ResourceManager()
//{
//
//}
//ResourceManager* ResourceManager::GetIns()
//{
//	if (_instance == NULL)
//	{
//		_instance = new ResourceManager();
//	}
//	return _instance;
//}
//
//void ResourceManager::Init()
//{
//	/*mario_Gun = new Texture("resource\\Image\\Mario_Gun.png");
//	mario_Small = new Texture("resource\\Image\\Mario_Small.png");
//	mario_Big = new Texture("resource\\Image\\Mario_Big.png");
//	fungi = new Texture("resource\\Image\\Fungi.png");
//	coin = new Texture("resource\\Image\\Coin.png");
//	flower = new Texture("resource\\Image\\Flower.png");
//	star = new Texture("resource\\Image\\star.png");
//	turtle_alive = new Texture("resource\\Image\\Turtle_alive.png");
//	turtle_die = new Texture("resource\\Image\\Turtle_die.png");
//	flowerMonster = new Texture("resource\\Image\\FlowerMonster.png");
//	brick = new Texture("resource\\Image\\brick.png");
//	land1 = new Texture("resource\\Image\\103.png");
//	land2 = new Texture("resource\\Image\\104.png");
//	land3 = new Texture("resource\\Image\\105.png");
//	pipe = new Texture("resource\\Image\\106.png");
//	pipe2 = new Texture("resource\\Image\\pipe2.png");
//	pipe3 = new Texture("resource\\Image\\pipe3.png");
//	bar = new Texture("resource\\Image\\bar.png");
//	mushroom = new Texture("resource\\Image\\mushroom.png");
//	questionBox = new Texture("resource\\Image\\Question.png");
//	breakbrick = new Texture("resource\\Image\\Brick_Break.png");
//	brickPart = new Texture("resource\\Image\\Brick_Break_Part.png");
//	bullet = new Texture("resource\\Image\\Bullet.png");
//	cloud = new Texture("resource\\Image\\Cloud.png");
//	fence = new Texture("resource\\Image\\Fence.png");
//	grass = new Texture("resource\\Image\\Grass.png");
//	moutain = new Texture("resource\\Image\\Moutain.png");
//	mark = new Texture("resource\\Image\\END_MARK.png");
//	collum = new Texture("resource\\Image\\END_COLUMN.png");
//	ladder = new Texture("resource\\Image\\LADDER.png");*/
//
//	//background
//	/*menuBackground = new Texture("resource\\Image\\BackGround\\MenuBackGround.png");
//	mainGameBG1 = new Texture("resource\\Image\\BackGround\\MainGameBG1.png");
//	blackBG = new Texture("resource\\Image\\BackGround\\black.png");
//	helpBG = new Texture("resource\\Image\\BackGround\\about.png");
//}*/
//
//
////Texture* ResourceManager::GetTexture(EResource id)
////{
////	switch (id)
////	{
////	case  EResource::Mario_Gun_ID:
////		return mario_Gun;
////	case EResource::Mario_Big_ID:
////		return mario_Big;
////	case EResource::Mario_Small_ID:
////		return mario_Small;
////	case EResource::Fungi_ID:
////		return fungi;
////	case EResource::Coin_ID:
////		return coin;
////	case EResource::Flower_ID:
////		return flower;
////	case EResource::Star_ID:
////		return star;
////	case EResource::Turtle_alive_ID:
////		return turtle_alive;
////	case EResource::Turtle_die_ID:
////		return turtle_die;
////	case FlowerMonster_ID:
////		return flowerMonster;
////	case EResource::Brick_ID:
////		return brick;
////	case EResource::LAND1_ID:
////		return land1;
////	case EResource::LAND2_ID:
////		return land2;
////	case EResource::LAND3_ID:
////		return land3;
////	case EResource::PIPE_ID:
////		return pipe;
////	case EResource::PIPE2_ID:
////		return pipe2;
////	case EResource::PIPE3_ID:
////		return pipe3;
////	case EResource::Bar_ID:
////		return bar;
////	case EResource::Mushroom_ID:
////		return mushroom;
////	case EResource::QuestionBox_ID:
////		return questionBox;
////	case EResource::BrickBreak_ID:
////		return breakbrick;
////	case EResource::BreakBrickPart_ID:
////		return brickPart;
////	case EResource::Bullet_ID:
////		return bullet;
////	case Cloud_ID:
////		return cloud;
////	case Grass_ID:
////		return grass;
////	case Fence_ID:
////		return fence;
////	case Moutain_ID:
////		return moutain;
////	case Mark_ID:
////		return mark;
////	case Collum_ID:
////		return collum;
////	case Ladder_ID:
////		return ladder;
////	default:
////		break;
////	}
////	return NULL;
////}
////
////Texture* ResourceManager::GetBackGround(EBackGround id)
////{
////	switch (id)
////	{
////	case EBackGround::MenuBackGround:
////		return menuBackground;
////	case EBackGround::MainGameBG1:
////		return mainGameBG1;
////	case Black:
////		return blackBG;
////	case Help:
////		return helpBG;
////	}
////	return NULL;
////}