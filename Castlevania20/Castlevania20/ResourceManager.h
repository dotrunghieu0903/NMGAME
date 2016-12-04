#ifndef _RESOURCEMANAGER_H_
#define _RESOURCEMANAGER_H_
#include "FrameWork.h"
#define IMAGAE_PATH "resource\\Image\\"
enum EResource
{
	Castlevania_Big_ID,
	Castlevania_Small_ID,
	Castlevania_Gun_ID,
};

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
	Texture *castlevania_Big;
	Texture *castlevania_Small;
	Texture *castlevania_Gun;

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
	void Init(); //khoi tao tat ca texture
				 //Get Texture
	Texture* GetTexture(EResource id);
	Texture* GetBackGround(EBackGround id);
};

#endif