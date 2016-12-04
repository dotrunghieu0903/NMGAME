#include "Simon.h"

Simon::Simon()
{
}

Simon::Simon(int _x,int _y) {
	Box *_box = new Box((float)_x, (float)_y, SIMON_WIDTH, SIMON_HEIGHT);
}

bool Simon::isDead() {
	return true;
}

void Simon::SetFrame() {
	switch (m_State)
	{
	case StateSimon::STANDING: {
		//m_Texture->LoadTextureFromFile(GL_graphic->GetDevice(), "simon.png", D3DCOLOR_ARGB(100, 255, 255, 255));
		//m_Sprite = new Sprite(m_Texture, 8, 3 , 24);
		//m_Sprite->getAnimationAction()->setIndexEnd(0);
		//m_Sprite->getAnimationAction()->setIndexEnd(0);
//		m_Sprite->getAnimationAction()->setCurrentFrame(1);
		break;
		}
	default:
		break;
	}
}
void Simon::Draw() {
	//if (this->_isMoveRight) {
	//	m_Sprite = new Sprite(m_Texture, 8, 3, 24);
	//	m_Sprite->RenderFlipX(m_x, m_y);
	//}
	//else
	//{
	//	m_Sprite->RenderXY(m_x, m_y);
	//}
}

Simon* Simon::getCurrentSimon() {
	if (!_simon)
		_simon = new Simon(150, 150);
	return _simon;
}
Simon* Simon::_simon = 0;

Simon::~Simon()
{
}