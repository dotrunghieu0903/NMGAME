#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "Globals.h"
#include "GameTime.h"
class Animation
{
private:
	int		m_columnFrame;
	int		m_rowFrame;
	int		m_totalFrame;
	int		m_index_Start;
	int		m_index_End;
	int		m_index_Current;
	int		m_timeAnimation;
	RECT*	m_sourceRect;

public:
	int		m_widthFrame;
	int		m_heightFrame;
	Animation();
	Animation(int width, int height, int column, int total);
	Animation(const Animation& Animation);
	void			setIndexStart(int _start);
	void			setIndexEnd(int _end);
	void			setCurrentFrame(int Index);
	RECT*			getSourceRectAtIndex(int Index);
	int				getCurrentIndex() { return this->m_index_Current; }
	int				getStartIndex() { return this->m_index_Start; }
	int				getEndIndex() { return this->m_index_End; }
	int				getRowFrame() { return this->m_rowFrame; }
	int				getColumnFrame() { return this->m_columnFrame; }
	RECT*			getSourceRect();
	void			setSourceRect(RECT _rect);
	void			NextFrame();
	void			UpdateAnimation(int timeNexframe);
	void			CreateSourceRectangle();
	D3DXVECTOR2		getFrameSize();
	void			Reset();
	void			Release();
	~Animation();
};


#endif // 