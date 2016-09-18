#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "CGameTimeDx9.h"
#include "DefineMacro.h"
#include "d3d9.h"
#include "d3dx9.h"


class GAnimationDx9
{
private:
	int		m_widthFrame;
	int		m_heightFrame;
	int		m_columnFrame;
	int		m_rowFrame;
	int		m_totalFrame;
	int		m_index_Start;
	int		m_index_End;
	int		m_index_Current;
	int		m_timeAnimation;
	RECT*	m_sourceRect;
public:
	GAnimationDx9(void);
	~GAnimationDx9(void);
	GAnimationDx9(int width, int height, int column, int total);
	GAnimationDx9(const GAnimationDx9& Animation);
	void			setIndexStart(int _start);
	void			setIndexEnd(int _end);
	void			setCurrentFrame(int Index);
	void			setSourceRectAtIndex(int Index);
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
};
#endif

