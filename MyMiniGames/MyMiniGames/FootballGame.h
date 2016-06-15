#pragma once
#include "Game.h"
#include "Resources.h"
#include <time.h>
#include "FootballScreen.h"
class Stage;
class GoalPost;
class Player;
class Ball;

using namespace FOOTBALLGAME;

class FootballGame	: public Game
{
private:
	Stage * m_pStage;
	GoalPost * m_pGoalPost;
	Player * m_pPlayer;
	Ball * m_pBall;

	FootballScreen m_pScreen;
	GAME_STATE m_eGameState;
	clock_t m_LimitTime;
	clock_t m_UpdateOldTime;
	clock_t m_curTime;
	clock_t m_GameStartTime;

	clock_t m_StayTime;
	clock_t m_StartTime;

	int m_nGoalBallCount;
	int m_nGoal;
	int m_nBallCount;
	int m_nCurStage;
	bool m_IsGoal;

public:
	FootballGame();
	~FootballGame();
	// GameEntitiy들을 그린다
	void Render();
	// GameEntity 들을 Update시킨다
	void Update();
	void Initialize();
	void UpdateScene();
	void RenderScene();
	int InputKey();
	void MessageHandler();
	void ChangeStage(Stage* _newStage);
	void PlusGoalBallCount(int _num) { m_nGoalBallCount += _num; }

	void CollisionCheckBall_GP();

	virtual bool IsEnd();
};

