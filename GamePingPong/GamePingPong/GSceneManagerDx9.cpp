#include "GSceneManagerDx9.h"

GSceneManagerDx9* GSceneManagerDx9::s_Instance = NULL;

GSceneManagerDx9 * GSceneManagerDx9::getInstance()
{
	if (!s_Instance)
	{
		s_Instance = new GSceneManagerDx9();
	}
	return s_Instance;
}

void GSceneManagerDx9::setDirectDevice(const LPDIRECT3DDEVICE9 & lpDirectDevice)
{
	this->m_lpDirectDevice = lpDirectDevice;
}

void GSceneManagerDx9::Initialize()
{
	if (!m_ListGameScene.empty())
	{
		m_ListGameScene.back()->InitializeState(m_lpDirectDevice);
	}
}

void GSceneManagerDx9::HandleInput()
{
	if (!m_ListGameScene.empty())
	{
		m_ListGameScene.back()->HandleInput();
	}
}

void GSceneManagerDx9::Update()
{
	if (!m_ListGameScene.empty())
	{
		m_ListGameScene.back()->Update();
	}
}

void GSceneManagerDx9::Render(LPD3DXSPRITE _lpDSpriteHandle)
{
	if (!m_ListGameScene.empty())
	{
		m_ListGameScene.back()->Render(_lpDSpriteHandle);
	}
}

void GSceneManagerDx9::AddElement(GSceneDx9 * gameScene)
{
	if (!m_ListGameScene.empty())
	{
		m_ListGameScene[m_ListGameScene.size() - 1]->Pause();
	}
	m_ListGameScene.push_back(gameScene);
	m_ListGameScene.back()->InitializeState(m_lpDirectDevice);
}

void GSceneManagerDx9::ExitState()
{
	if (!m_ListGameScene.empty())
	{
		m_ListGameScene.back()->Release();
		m_ListGameScene.pop_back();
	}
}

void GSceneManagerDx9::ReplaceBy(GSceneDx9 * gameScene)
{
	ExitState();
	AddElement(gameScene);
}

void GSceneManagerDx9::ClearAll()
{
	while (!m_ListGameScene.empty())
	{
		ExitState();
	}
}
