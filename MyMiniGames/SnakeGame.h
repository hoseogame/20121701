#pragma once
#include "Game.h"
#include "SnakeScreen.h"
class Snake;
class Food;

class SnakeGame : public Game
{
private:
	Snake* m_pSnake;
	Food* m_pFood;
	SnakeScreen m_Screen;
public:
	SnakeGame();
	~SnakeGame();

	void Initialize();

	void Update();
	void Render();
	bool IsEnd();
	void MassageHandler();
};

