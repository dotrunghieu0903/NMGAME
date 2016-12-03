#include "IGameState.h"
#include "StateManager.h"
IGameState::IGameState()
{

}

IGameState::~IGameState()
{

}

void IGameState::Create()
{

}

void IGameState::Release()
{

}

void IGameState::HandleInput(Input* input, float dt)
{

}

void IGameState::Update(float dt)
{

}

void IGameState::Draw()
{

}

void IGameState::ExitSceen()
{
	StateManager::GetInstance()->ExitScreen();
}