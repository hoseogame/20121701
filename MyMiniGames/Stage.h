#pragma once
#include <time.h>

// GP : GoalPost
class Ball;
class Player;
class GoalPost;

class Stage
{
public:
	Stage();
	virtual ~Stage();
protected:
	int m_nGoalBall;
	int m_nGPLength;
	int m_nResetGPX;
	int m_nResetGPY;
	int m_nGPMoveDistance;

	Ball* m_pBall;
	Player* m_pPlayer;
	GoalPost* m_pGoalPost;

	clock_t m_LimitTime;
	clock_t m_MoveTime;

public:
	virtual void Initialize() = 0;

	virtual int GetGoalBall() const { return m_nGoalBall; }
	virtual int GetGPLength() const { return m_nGPLength; }
	virtual int GetResetGPX() const { return m_nResetGPX; }
	virtual int GetResetGPY() const { return m_nResetGPY; }
	virtual int GetGPMoveDistance() const { return m_nGPMoveDistance; }
	virtual clock_t GetLimitTime() const { return  m_LimitTime; }
	virtual clock_t GetMoveTime() const { return m_MoveTime; }
	Ball* GetBall() { return m_pBall; };
	Player* GetPlayer() { return m_pPlayer; };
	GoalPost* GetGoalPost() { return m_pGoalPost; };
};

