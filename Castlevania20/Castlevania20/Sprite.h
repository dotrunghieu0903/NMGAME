#ifndef _SPRITE_H_
#define _SPRITE_H_

//#include "Texture.h"
#include "Animation.h"
#include "CSprite.h"
class Sprite
{
private:
	CSprite csprite;
	Animation* animationAction;
//	Texture* myTexture;
	int col;
	int row;
	int total;
	float scale;
	float rotate;

public:
	Sprite();
	Sprite(const Sprite &spite);
	~Sprite();
	CSprite getCSprite() const { return csprite; };
	Animation* getAnimation() const { return animationAction; };
	Animation* getAnimationAction() const { return animationAction; };
	//Texture* getMyTexture() const { return myTexture; };
	float  getScale() const { return scale; };
	float getRotation() const { return rotate; };
	int getColumn() const { return col; };
	int getRow() const { return row; };
	int getTotal()const { return total; };

	void setAnimation(Animation* m_animation) { animationAction = m_animation; }
	//void setTexture(Texture* m_texture) { myTexture = m_texture; }
	void setCol(int m_col) { col = m_col ;}
	void setRow(int m_row) { row = m_row; }

};
#endif