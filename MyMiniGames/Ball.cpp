#include "Ball.h"
#include "Game.h"
#include "Player.h"
#include "GoalPost.h"
#include "Print.h"

Ball::Ball()
{
}


Ball::~Ball()
{
}

void Ball::Initialized(Player * _playerInfo)
{
	m_pPlayer = _playerInfo;

	ResetBall();

	m_MoveTime = 100;
	m_OldTime;
}

void Ball::Kick()
{
	if (true == m_isReady)
	{
		ResetBall();
		m_OldTime = clock();
		m_isReady = false;
		//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[5], 0, &g_Channel[5]); // 슛 동작 소리 출력
	}
}


void Ball::Update(clock_t _time)
{
	if (false == GetReady()) // 이동 중일 때 
	{	// 이동 시간 간격에 의한 이동
		if ((_time - GetOldTime()) > GetMoveTime())
		{
			if (GetY() - 1 > 0)
			{
				m_nMoveY--;
				m_OldTime = _time; // 다음 이동 시각과 비교하기 위해 현재 시간을 이전 시간 변수에 저장

			}
			else
			{ // 공 초기화
				ResetBall();
			}
		}
	}
	else
	{
		SetX(m_pPlayer->GetMoveX());
	}
}

void Ball::Render()
{
	PRINT->ScreenPrint(m_nMoveX, m_nMoveY, "⊙");
}

void Ball::ResetBall()
{
	m_isReady = true;
	m_nMoveX = m_pPlayer->GetMoveX();
	m_nMoveY = m_pPlayer->GetMoveY() - 1;
}
