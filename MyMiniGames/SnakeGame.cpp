#include "SnakeGame.h"
#include "Snake.h"
#include "Food.h"
#include "Print.h"

SnakeGame::SnakeGame()
{
}


SnakeGame::~SnakeGame()
{
	SAFE_DELETE(m_pSnake);
	SAFE_DELETE(m_pFood);
}

void SnakeGame::Initialize()
{
	m_pSnake = new Snake();
	m_pFood = new Food();
	m_pSnake->Initialize();
	m_pFood->Make();
}

void SnakeGame::Update()
{
	static int i = 0;
	MassageHandler();
	if (i%m_pSnake->GetSpeed() == 0)
	{
		if (true == m_pSnake->IsEat(m_pFood->GetX(), m_pFood->GetY()))
		{
			m_pSnake->AddTail();

			if (m_pSnake->GetLength() % 5 == 0)
				m_pSnake->SetSpeed(m_pSnake->GetSpeed()-1);

			if (m_pSnake->GetSpeed() < 1)
				m_pSnake->SetSpeed(1);

			m_pSnake->SetLength(m_pSnake->GetLength() + 1);
			m_pFood->Make();
			i = 1;	//스피드관련 변수 초기화
		}
		else 
		{
			//fflush(stdin);
			m_pSnake->Move();	//단순히 이동
		}
		m_pSnake->SetLastDirection(m_pSnake->GetDirection());
	}
	++i;
}

void SnakeGame::Render()
{
	PRINT->ScreenClear();
	
	
	if (true == m_pSnake->IsEnd())		//충돌할때
	{
		m_Screen.ShowGameOver();
	}
	else
	{
		m_pSnake->Render();
		m_pFood->Render();
		m_Screen.ShowGameFrame();
	}

	PRINT->ScreenFlipping();
}

bool SnakeGame::IsEnd()
{
	if (true == m_pSnake->IsEnd())
		return true;
	else
		return false;
}

void SnakeGame::MassageHandler()
{
	int keytemp;

	if (_kbhit())
	{
		keytemp = _getche();
		switch (keytemp)
		{
		case KEY_UP:
			if (m_pSnake->GetLastDirection() != DIRECTION::DOWN)
				m_pSnake->SetDirection(DIRECTION::UP);
			break;
		case KEY_LEFT:
			if (m_pSnake->GetLastDirection() != DIRECTION::RIGHT)
				m_pSnake->SetDirection(DIRECTION::LEFT);
			break;
		case KEY_RIGHT:
			if (m_pSnake->GetLastDirection() != DIRECTION::LEFT)
				m_pSnake->SetDirection(DIRECTION::RIGHT);

			break;
		case KEY_DOWN:
			if (m_pSnake->GetLastDirection() != DIRECTION::UP)
				m_pSnake->SetDirection(DIRECTION::DOWN);
			break;
		}
	}
}
