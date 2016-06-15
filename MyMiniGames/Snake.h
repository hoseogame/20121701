#pragma once
#include "Resources.h"

using namespace SNAKEGAME;

struct Body {
	int	m_iX;
	int m_iY;
	struct Body * m_pNext;
};

class Snake
{
private:
	int m_iLength;
	int m_iSpeed;
	int m_iBeforeX;
	int m_iBeforeY;

	DIRECTION m_eDirection;
	DIRECTION m_eLastDirection;



	Body* m_pSnakeHead;
	Body* m_pSnakeTail;
public:
	Snake();
	~Snake();

	void Initialize();

	void Move();
	void AddTail();
	bool IsEnd();
	bool IsEat(int _fX , int _fY);
	void Render();
	void Update();



	const Body* GetSnakeHead() const { return m_pSnakeHead; }
	const Body* GetSnakeTail() const { return m_pSnakeTail; }

	DIRECTION GetDirection() const { return m_eDirection; }
	void SetDirection(DIRECTION val) { m_eDirection = val; }

	DIRECTION GetLastDirection() const { return m_eLastDirection; }
	void SetLastDirection(DIRECTION val) { m_eLastDirection = val; }

	int GetSpeed() const { return m_iSpeed; }
	void SetSpeed(int val) { m_iSpeed = val; }
	int GetLength() const { return m_iLength; }
	void SetLength(int val) { m_iLength = val; }
};

