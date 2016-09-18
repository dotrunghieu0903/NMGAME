#ifndef __DEFINE_MACRO_H__
#define __DEFINE_MACRO_H__

#define SAFE_DELETE(p)			if(p){ delete (p);		(p) = 0;}

#define SAFE_DELETE_ARRAY(p)	if(p){ delete[] (p);	(p) = 0;}

#define SAFE_RELEASE(p)			if(p){ (p)->Release();	(p) = 0;}

enum ESpriteEffect
{
	NONE,
	VER,
	HOR
};

enum ESceneGameID
{
	INTRO,
	MENU,
	GAME,
	EXIT
};
#endif