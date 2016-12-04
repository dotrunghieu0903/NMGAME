#include "StateManager.h"

StateManager* StateManager::_instance = 0;

StateManager::StateManager()
{

}

StateManager::~StateManager()
{

}

StateManager* StateManager::GetInstance()
{
	if (!_instance)
		_instance = new StateManager();
	return _instance;
}

void StateManager::Init()
{

}

void StateManager::Update(float dt)
{
	if (!_listState.empty())
		_listState.back()->Update(dt);
}

void StateManager::UpdateInput(Input* input, float dt)
{
	if (!_listState.empty())
		_listState.back()->HandleInput(input, dt);
}

void StateManager::Draw()
{
	if (!_listState.empty())
		_listState.back()->Draw();
	/*for (int i = 0; i < _listState.size(); i++)
	{
	 	_listState[i]->Draw();
	}*/
}

void StateManager::AddScreen(IGameState* screen)
{
	if (!_listState.empty())
	{
		//_listState.back()->Pause();
	}
	_listState.push_back(screen);
	_listState.back()->Create();
}

void StateManager::RemoveScreen(IGameState* screen)
{
	if (!_listState.empty())
	{
		IGameState* temp;
		for (int i = 0; i<_listState.size(); i++)
		{
			if (screen == _listState[i])
			{
				_listState[i]->Release();
				_listState.erase(_listState.begin() + i);
			}
		}
		_listState.back()->Release();
		_listState.pop_back();
	}
}

void StateManager::ClearAllScreen()
{
	while (_listState.empty() == false)
		ExitScreen();
}
void StateManager::ExitScreen()
{
	if (!_listState.empty())
	{
		_listState.back()->Release();
		_listState.pop_back();
	}
}

IGameState* StateManager::GetPreviousScreen()
{
	if (_listState.size()<2)
		return NULL;
	return _listState[_listState.size() - 2];
}