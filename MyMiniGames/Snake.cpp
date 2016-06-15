#include "Snake.h"
#include "Print.h"

using namespace SNAKEGAME;

Snake::Snake()
{
}

Snake::~Snake()
{
	struct Body *tmp1, *tmp2;

	tmp1 = m_pSnakeHead;
	tmp2 = m_pSnakeHead->m_pNext;
	while (tmp2 != NULL)
	{
		free(tmp1);
		tmp1 = tmp2;
		tmp2 = tmp2->m_pNext;
	}
}

void Snake::Initialize()
{
	SetLength(1);
	SetSpeed(25);
	m_iBeforeX = 0;
	m_iBeforeX = 0;
	SetDirection(DIRECTION::RIGHT);
	SetLastDirection(GetDirection());

	m_pSnakeTail = (struct Body *)malloc(sizeof(struct Body));
	m_pSnakeTail->m_iX = 5;
	m_pSnakeTail->m_iY = 3;
	m_pSnakeHead = m_pSnakeTail;
	m_pSnakeTail = (struct Body *)malloc(sizeof(struct Body));
	m_pSnakeTail->m_iX = 4;
	m_pSnakeTail->m_iY = 3;
	m_pSnakeTail->m_pNext = NULL;
	m_pSnakeHead->m_pNext = m_pSnakeTail;

}

void Snake::Move()
{
	struct Body *temp_body = m_pSnakeHead->m_pNext;

	int tempX = 0;
	int tempY = 0;
	m_iBeforeX = m_pSnakeHead->m_iX;
	m_iBeforeY = m_pSnakeHead->m_iY;

	switch (m_eDirection)
	{
	case DIRECTION::UP:
		m_pSnakeHead->m_iY--;
		break;
	case DIRECTION::LEFT:
		m_pSnakeHead->m_iX--;
		break;
	case DIRECTION::RIGHT:
		m_pSnakeHead->m_iX++;
		break;
	case DIRECTION::DOWN:
		m_pSnakeHead->m_iY++;
		break;
	}

	while (temp_body != NULL)
	{
		tempX = temp_body->m_iX;
		tempY = temp_body->m_iY;

		temp_body->m_iX = m_iBeforeX;
		temp_body->m_iY = m_iBeforeY;

		m_iBeforeX = tempX;
		m_iBeforeY = tempY;

		temp_body = temp_body->m_pNext;
	}
}

void Snake::AddTail()
{
	Body* new_body = (struct Body *)malloc(sizeof(struct Body));
	new_body->m_iX = 0;
	new_body->m_iY = 0;
	new_body->m_pNext = NULL;

	switch (m_eDirection)
	{
	case DIRECTION::UP:
		new_body->m_iX = m_pSnakeHead->m_iX;
		new_body->m_iY = m_pSnakeHead->m_iY - 1;
		break;
	case DIRECTION::LEFT:
		new_body->m_iX = m_pSnakeHead->m_iX - 1;
		new_body->m_iY = m_pSnakeHead->m_iY;
		break;
	case DIRECTION::RIGHT:
		new_body->m_iX = m_pSnakeHead->m_iX + 1;
		new_body->m_iY = m_pSnakeHead->m_iY;
		break;
	case DIRECTION::DOWN:
		new_body->m_iX = m_pSnakeHead->m_iX;
		new_body->m_iY = m_pSnakeHead->m_iY + 1;
		break;
	}
	new_body->m_pNext = m_pSnakeHead;
	m_pSnakeHead = new_body;

	//화면 깨짐을 막기위함
	PRINT->ScreenPrint(77, 23, "");
	fflush(stdout);
}

bool Snake::IsEnd()
{
	struct Body *temp_body = m_pSnakeHead;

	while (temp_body != m_pSnakeTail) // 자기몸에 박았는지
	{
		if ((temp_body->m_iX == m_iBeforeX) && (temp_body->m_iY == m_iBeforeY))
			return true;
		temp_body = temp_body->m_pNext;
	}

	if (m_pSnakeHead->m_iX < 0 || m_pSnakeHead->m_iX>34 || m_pSnakeHead->m_iY < 0 || m_pSnakeHead->m_iY>19)		//머리가 벽에 부닥침
		return true;
	else
		return false;
}

bool Snake::IsEat(int _fX, int _fY)
{
	if (_fX == m_pSnakeHead->m_iX && _fY == m_pSnakeHead->m_iY )	//먹이를 물었음
		return true;
	else
		return false;
}


void Snake::Render()
{
	struct Body *temp_body = m_pSnakeHead->m_pNext;
	int tempX = 0;
	int tempY = 0;

	//화면 깨짐을 막기위함
	PRINT->ScreenPrint(77, 23, "");
	fflush(stdout);
	
	PRINT->SetColor(COLOR::GRAY);
	PRINT->ScreenPrint((m_pSnakeHead->m_iX * 2) + ABS_X, m_pSnakeHead->m_iY + ABS_Y, "●");


	while (temp_body != NULL)
	{
		//tempX = temp_body->m_iX;
		//tempY = temp_body->m_iY;
		//temp_body->m_iX = m_iBeforeX;
		//temp_body->m_iY = m_iBeforeY;
		//m_iBeforeX = tempX;
		//m_iBeforeY = tempY;

		PRINT->ScreenPrint((temp_body->m_iX * 2) + ABS_X, temp_body->m_iY + ABS_Y, "○");

		temp_body = temp_body->m_pNext;
	}

	PRINT->ScreenPrint(77, 23, "");		//화면 깨짐을 막기위함
	PRINT->SetColor(COLOR::BLACK);
}

void Snake::Update()
{
	
}
