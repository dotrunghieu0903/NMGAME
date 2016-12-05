#include "ResourceManager.h"

ResourceManager* ResourceManager::_instance = NULL;

ResourceManager::ResourceManager()
{

}
ResourceManager::~ResourceManager()
{

}
ResourceManager* ResourceManager::GetIns()
{
	if (_instance == NULL)
	{
		_instance = new ResourceManager();
	}
	return _instance;
}

void ResourceManager::Init()
{
	simon_Big = new Texture("resource\\Image\\simon.png");

	//background
	menuBackground = new Texture("resource\\Image\\BackGround\\MenuBackGround.png");
	mainGameBG1 = new Texture("resource\\Image\\BackGround\\MainGameBG1.png");
	blackBG = new Texture("resource\\Image\\BackGround\\black.png");
	helpBG = new Texture("resource\\Image\\BackGround\\about.png");
}


Texture* ResourceManager::GetTexture(EResource id)
{
	switch (id)
	{
	case EResource::Simon_Big_ID:
		return simon_Big;
	default:
		break;
	}
	return NULL;
}

Texture* ResourceManager::GetBackGround(EBackGround id)
{
	switch (id)
	{
	case EBackGround::MenuBackGround:
		return menuBackground;
	case EBackGround::MainGameBG1:
		return mainGameBG1;
	case Black:
		return blackBG;
	case Help:
		return helpBG;
	}
	return NULL;
}