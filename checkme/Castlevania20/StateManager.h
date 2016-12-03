#ifndef _STATEMANAGER_
#define _STATEMANAGER_
#include "IGameState.h"
#include "Input.h"
#include <vector>
using namespace std;
class StateManager
{
private:
	vector<IGameState*> _listState;
	static StateManager* _instance;
protected:
	StateManager();
public:
	~StateManager();
	//Init
	void Init();
	//Update & Draw method
	void Update(float dt);
	void UpdateInput(Input*, float);
	void Draw();
	//public method
	vector<IGameState*> GetListState() { return _listState; }
	void AddScreen(IGameState*);
	void RemoveScreen(IGameState*);
	void ClearAllScreen();
	void ExitScreen();
	IGameState* GetPreviousScreen();
	//Get Instance method
	static StateManager* GetInstance();
};

#endif // _STATEMANAGER_
