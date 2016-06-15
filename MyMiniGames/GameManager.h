#pragma once
#include "Resources.h"

using namespace GAME;

class Game;

class GameManager
{
private:
	GameManager();
	Game* m_pGame;
public:
	~GameManager();
	static GameManager* Instance();

	void SelectGame(eGAME _game);
	void Update();
	void Render();
	bool IsEnd();
};

