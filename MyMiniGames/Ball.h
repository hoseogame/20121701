#pragma once

#include <time.h>

class Player;
class Game;
class GoalPost;

class Ball
{
private:
	Player * m_pPlayer;
	bool m_isReady;
	int m_nMoveX;
	int m_nMoveY;

	clock_t m_MoveTime;
	clock_t m_OldTime;

public:
	Ball();
	~Ball();

	void Initialized(Player * _playerInfo);
	void Kick();

	void Update(clock_t _time);
	void Render();
	void ResetBall();

	void SetX(int _num) { m_nMoveX = _num; }
	void SetY(int _num) { m_nMoveY = _num; }
	void SetReady(bool _ready) { m_isReady = _ready; }

	int GetX() const { return m_nMoveX; }
	int GetY() const { return m_nMoveY; }
	bool GetReady() const { return m_isReady; }
	clock_t GetOldTime() const { return m_OldTime; }
	clock_t GetMoveTime() const { return m_MoveTime; }
};
