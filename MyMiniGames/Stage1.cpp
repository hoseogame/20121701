#include "Stage1.h"
#include "GoalPost.h"
#include "Ball.h"
#include "Player.h"
Stage1::Stage1()
{
}


Stage1::~Stage1()
{
}

void Stage1::Initialize()
{
	m_pGoalPost = new GoalPost();
	m_pPlayer = new Player();
	m_pBall = new Ball();
	

	m_nGoalBall = 3;
	m_nGPLength = 1;
	m_nResetGPX = 20;
	m_nResetGPY = 3;
	m_nGPMoveDistance = 1;

	m_LimitTime = 1000 * 20;
	m_MoveTime = 300;
	m_pPlayer->Initialize();
	m_pBall->Initialized(m_pPlayer);
	m_pGoalPost->Initialize(*this);
}
