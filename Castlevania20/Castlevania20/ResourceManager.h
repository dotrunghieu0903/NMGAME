#ifndef _RESOURCEMANAGER_H_
#define _RESOURCEMANAGER_H_
#include "FrameWork.h"
#define IMAGAE_PATH "resource\\Image\\"
//enum EResource
//{
//	Mario_Big_ID,
//	Mario_Small_ID,
//	Mario_Gun_ID,
//	Mushroom_ID,
//	Star_ID,
//	Brick_ID,
//	BrickBreak_ID,
//	Fungi_ID,
//	Coin_ID,
//	Flower_ID,
//	Turtle_alive_ID,
//	Turtle_die_ID,
//	FlowerMonster_ID,
//	LAND1_ID,
//	LAND2_ID,
//	LAND3_ID,
//	PIPE_ID,
//	PIPE2_ID,
//	PIPE3_ID,
//	Bar_ID,
//	QuestionBox_ID,
//	BreakBrickPart_ID,
//	Bullet_ID,
//	Cloud_ID,
//	Grass_ID,
//	Fence_ID,
//	Moutain_ID,
//	Mark_ID,
//	Collum_ID,
//	Ladder_ID
//};

enum EBackGround
{
	MenuBackGround,
	MainGameBG1,
	Black,
	Help
};
class ResourceManager
{
private:
	////Texture
	//Texture *mario_Big;
	//Texture *mario_Small;
	//Texture *mario_Gun;
	//Texture *mushroom;
	//Texture *star;
	//Texture *brick;
	//Texture *fungi;
	//Texture *coin;
	//Texture *flower;
	//Texture *turtle_alive;
	//Texture *turtle_die;
	//Texture *flowerMonster;
	//Texture *land1;
	//Texture *land2;
	//Texture *land3;
	//Texture *pipe;
	//Texture *pipe2;
	//Texture *pipe3;
	//Texture *bar;
	//Texture *questionBox;
	//Texture *breakbrick;
	//Texture *brickPart;
	//Texture *bullet;
	//Texture *cloud;
	//Texture *grass;
	//Texture *fence;
	//Texture *moutain;
	//Texture *mark;
	//Texture *collum;
	//Texture *ladder;

	//BackGround
	Texture *menuBackground;
	Texture *mainGameBG1;
	Texture *blackBG;
	Texture *helpBG;
	ResourceManager();
	static ResourceManager* _instance;
public:
	~ResourceManager();
	static ResourceManager* GetIns();
	void Init(); //khoi tao tat ca texture va surface
				 //Get Texture
	//Texture* GetTexture(EResource id);
	Texture* GetBackGround(EBackGround id);
};

#endif