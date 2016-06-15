#include "Stage.h"
#include "Resources.h"
Stage::Stage()
{
	m_nGoalBall = 0;
	m_nGPLength = 0;
	m_nResetGPX = 0;
	m_nResetGPY = 0;
	m_nGPMoveDistance = 0;
	m_LimitTime = 0;
	m_MoveTime = 0;
}


Stage::~Stage()
{
	SAFE_DELETE(m_pGoalPost);
	SAFE_DELETE(m_pBall);
	SAFE_DELETE(m_pPlayer);
}
