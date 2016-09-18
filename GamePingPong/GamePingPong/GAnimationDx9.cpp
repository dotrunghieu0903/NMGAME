#include "GAnimationDx9.h"


GAnimationDx9::GAnimationDx9(void)
{
	this->m_columnFrame = 0;
	this->m_rowFrame = 0;
	this->m_heightFrame = 0;
	this->m_index_End = 0;
	this->m_index_Start = 0;
	this->m_index_Current = 0;
	this->m_sourceRect = 0;
	this->m_timeAnimation = 0;
	this->m_totalFrame = 0;
	this->m_widthFrame = 0;
}

GAnimationDx9::GAnimationDx9(int width, int height, int column, int total)
{
	this->m_widthFrame = width;
	this->m_heightFrame = height;
	this->m_columnFrame = column;
	this->m_rowFrame = (int)total/column;
	this->m_totalFrame = total;

	this->m_index_Current = 0;
	this->m_index_Start = 0;
	this->m_index_End = total - 1;

	this->m_sourceRect = new RECT();
	this->m_sourceRect->top = 0;
	this->m_sourceRect->left = 0;
	this->m_sourceRect->bottom = m_heightFrame;
	this->m_sourceRect->right = m_widthFrame;

	this->m_timeAnimation = 0;
}

GAnimationDx9::GAnimationDx9(const GAnimationDx9 & Animation)
{
	this->m_columnFrame = Animation.m_columnFrame;
	this->m_rowFrame = Animation.m_rowFrame;
	this->m_heightFrame = Animation.m_heightFrame;
	this->m_index_End = Animation.m_index_End;
	this->m_index_Start = Animation.m_index_Start;
	this->m_index_Current = Animation.m_index_Current;
	this->m_timeAnimation = 0;
	this->m_totalFrame = Animation.m_totalFrame;
	this->m_widthFrame = Animation.m_widthFrame;


	this->m_sourceRect = new RECT();
	this->m_sourceRect->top = Animation.m_sourceRect->top;
	this->m_sourceRect->left = Animation.m_sourceRect->left;
	this->m_sourceRect->right = Animation.m_sourceRect->right;
	this->m_sourceRect->bottom = Animation.m_sourceRect->bottom;
}

void GAnimationDx9::setIndexStart(int _start)
{
	this->m_index_Start = _start;
}

void GAnimationDx9::setIndexEnd(int _end)
{
	this->m_index_End = _end;
}

void GAnimationDx9::setCurrentFrame(int index)
{
	this->m_index_Current = index;
	CreateSourceRectangle();
}

void GAnimationDx9::setSourceRectAtIndex(int Index)
{
	m_sourceRect->top = (Index / m_columnFrame)	* m_heightFrame;
	m_sourceRect->left = (Index % m_columnFrame)	* m_widthFrame;
	m_sourceRect->bottom = m_sourceRect->top + m_heightFrame;
	m_sourceRect->right = m_sourceRect->left + m_widthFrame;
}

RECT * GAnimationDx9::getSourceRect()
{
	return m_sourceRect;
}

void GAnimationDx9::setSourceRect(RECT _rect)
{
	this->m_sourceRect->top = _rect.top;
	this->m_sourceRect->left = _rect.left;
	this->m_sourceRect->right = _rect.right;
	this->m_sourceRect->bottom = _rect.bottom;
}

void GAnimationDx9::NextFrame()
{
	this->m_index_Current ++;
	if(this->m_index_Current > this->m_index_End)
	{
		this->m_index_Current = this->m_index_Start;
	}
}

void GAnimationDx9::UpdateAnimation(int timeNexframe)
{
	this->m_timeAnimation += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
	if(this->m_timeAnimation > timeNexframe)
	{
		NextFrame();
		CreateSourceRectangle();
		this->m_timeAnimation = 0;
	}
}

void GAnimationDx9::CreateSourceRectangle()
{
	m_sourceRect->top = (m_index_Current / m_columnFrame) * m_heightFrame;
	m_sourceRect->left = (m_index_Current % m_columnFrame) * m_widthFrame;
	m_sourceRect->bottom = m_sourceRect->top + m_heightFrame;
	m_sourceRect->right = m_sourceRect->left + m_widthFrame;
}

D3DXVECTOR2 GAnimationDx9::getFrameSize()
{
	return D3DXVECTOR2((float)this->m_widthFrame, (float)this->m_heightFrame);
}

void GAnimationDx9::Reset()
{
	this->m_sourceRect->top = 0;
	this->m_sourceRect->left = 0;
	this->m_sourceRect->bottom = m_heightFrame;
	this->m_sourceRect->right = m_widthFrame;

	this->m_timeAnimation = 0;
	this->m_index_Current = 0;
}

void GAnimationDx9::Release()
{
	SAFE_DELETE(m_sourceRect);
}

GAnimationDx9::~GAnimationDx9(void)
{
}
