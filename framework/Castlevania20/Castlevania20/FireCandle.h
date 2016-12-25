#pragma once
#include "BaseObject.h"
#include "Resources.h"
#define CANDLE_SPRITE			L"resource\\sprite\\item\\Candle.bmp"
#define CANDLE_WIDTH			16
#define CANDLE_HEIGHT			32
#define TYPE 12
class FireCandle :
	public BaseObject
{
public:
	bool off;
	FireCandle();
	FireCandle(int id, int x, int y);
	void UpdateEvent(float deltatime);
	void Draw();
	~FireCandle();
};

