#include "Stage2.h"
#include "GoalPost.h"
#include "Ball.h"
#include "Player.h"


Stage2::Stage2()
{
}


Stage2::~Stage2()
{
}

void Stage2::Initialize()
{
	m_pGoalPost = new GoalPost();
	m_pPlayer = new Player();
	m_pBall = new Ball();
	m_nGoalBall = 10;
	m_nGPLength = 2;
	m_nResetGPX = 20;
	m_nResetGPY = 5;
	m_nGPMoveDistance = 1;

	m_LimitTime = 1000 * 30;
	m_MoveTime = 300;

	m_pPlayer->Initialize();
	m_pBall->Initialized(m_pPlayer);
	m_pGoalPost->Initialize(*this);
}
