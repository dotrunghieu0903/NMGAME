#include "GMenuScene.h"

void GMenuScene::InitializeState(LPDIRECT3DDEVICE9 _lpDirectDevice)
{
	spriteDemo = new GSpriteDx9();
	spriteDemo->LoadContent(_lpDirectDevice, "MarioLager.png", 6, 1, 6);
	spriteDemo->getAnimationAction()->setIndexStart(0);
	spriteDemo->getAnimationAction()->setIndexEnd(2);
}

void GMenuScene::HandleInput()
{
}

void GMenuScene::Update()
{
	spriteDemo->UpdateAnimation(500);
}

void GMenuScene::Render(LPD3DXSPRITE _lpDSpriteHandle)
{
	spriteDemo->Render(_lpDSpriteHandle, D3DXVECTOR2(100, 100), 1, 0, 1, ESpriteEffect::NONE);
}

void GMenuScene::Pause()
{
}

void GMenuScene::Resume()
{
}

void GMenuScene::Release()
{
}
