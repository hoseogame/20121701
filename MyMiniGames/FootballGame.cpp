#include "FootballGame.h"
#include "Stage1.h"
#include "Stage2.h"
#include "FootballScreen.h"
#include "GoalPost.h"
#include "Player.h"
#include "Ball.h"
#include "Print.h"
#include <conio.h>
#include <string.h>

FootballGame::FootballGame()
{
	m_pStage = new Stage1();
	m_pStage->Initialize();

	m_eGameState = GAME_STATE::INIT;

	m_LimitTime = 0;
	m_UpdateOldTime = 0;
	m_curTime = 0;
	m_GameStartTime = 0;

	m_nGoalBallCount = 0;
	m_nGoal = 0;
	m_nBallCount = 0;
	m_nCurStage = 0;

	m_IsGoal = false;
}

FootballGame::~FootballGame()
{
	SAFE_DELETE(m_pStage);
}

// GameEntitiy들을 그린다
void FootballGame::Render()
{
	PRINT->ScreenClear();

	RenderScene();

	// Note: 렌더링 끝 
	PRINT->ScreenFlipping();
}

// GameEntity 들을 Update시킨다
void FootballGame::Update()
{
	m_curTime = clock();

	MessageHandler();
	UpdateScene();
}

void FootballGame::MessageHandler()
{
	switch (InputKey())
	{
	case 'y':
	case 'Y':
		if (m_eGameState == GAME_STATE::FAILED)
		{
			Initialize();
			m_eGameState = GAME_STATE::READY;
			//	//FMOD_Channel_Stop( g_Channel[2] );  // 미션 실패 사운드 출력 중지 
			//	//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[3], 0, &g_Channel[3]);
		}
		break;
	case 'n':
	case 'N':
		if (m_eGameState == GAME_STATE::FAILED)
		{
			m_eGameState = GAME_STATE::RESULT;
			//FMOD_Channel_Stop( g_Channel[2] );  // 미션 실패 사운드 출력 중지							
		}
		break;

	case ' ':
		if (m_eGameState == GAME_STATE::INIT && m_nCurStage == 0)
		{
			m_eGameState = GAME_STATE::READY;
			//FMOD_Channel_Stop( g_Channel[0] ); // 배경음 중지
			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[3], 0, &g_Channel[3]); // ready 사운드
			m_UpdateOldTime = clock();  // ready를 일정시간 지속해 주기 위해 							
		}
		break;
	case 'j':
		m_pStage->GetPlayer()->LMove();
		break;
	case 'l':
		m_pStage->GetPlayer()->RMove();
		break;
	case 'k':
		if (m_eGameState == GAME_STATE::RUNNING)
		{
			m_pStage->GetBall()->Kick();
			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[5], 0, &g_Channel[5]); // 슛 동작 소리 출력
		}
		break;
	}
}

void FootballGame::ChangeStage(Stage * _newStage)
{
	SAFE_DELETE(m_pStage);
	m_pStage = _newStage;
	m_pStage->Initialize();
	m_nCurStage++;
	Initialize();	// Stage 변경 부분
	m_eGameState = GAME_STATE::READY;
}

void FootballGame::CollisionCheckBall_GP()
{
	if (m_pStage->GetBall()->GetX() >= m_pStage->GetGoalPost()->GetLineX(0) && m_pStage->GetBall()->GetX() + 1 <= m_pStage->GetGoalPost()->GetLineX(m_pStage->GetGoalPost()->GetMaxLength() - 1) + 1)
	{
		if (m_pStage->GetBall()->GetY() <= m_pStage->GetGoalPost()->GetY())
		{   // 공 초기화
			m_pStage->GetBall()->ResetBall();
			m_nBallCount++;


			if (m_nBallCount == m_nGoalBallCount) // 공과 목표 공과의 개수가 같으면 SUCCESS
			{
				m_eGameState = GAME_STATE::STOP;
				m_IsGoal = true;
				return;
			}

			// 효과 출력
			if (false == m_IsGoal)
			{
				m_IsGoal = true;
				m_StartTime = m_curTime;
			}

			// 골인 사운드 출력
			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[6], 0, &g_Channel[6]); // 골인 사운드 와우~
		}
		// 골대 충돌 
	}
	else if ((m_pStage->GetBall()->GetX() >= m_pStage->GetGoalPost()->GetLineX(0) - 2 && 
		m_pStage->GetBall()->GetX() <= m_pStage->GetGoalPost()->GetLineX(0) - 1) ||
		(m_pStage->GetBall()->GetX() + 1 >= m_pStage->GetGoalPost()->GetLineX(0) - 2 && 
			m_pStage->GetBall()->GetX() + 1 <= m_pStage->GetGoalPost()->GetLineX(0) - 1) ||
		(m_pStage->GetBall()->GetX() >= m_pStage->GetGoalPost()->GetLineX(m_pStage->GetGoalPost()->GetMaxLength() - 1) + 2 && 
			m_pStage->GetBall()->GetX() <= m_pStage->GetGoalPost()->GetLineX(m_pStage->GetGoalPost()->GetMaxLength() - 1) + 3) ||
		(m_pStage->GetBall()->GetX() + 1 >= m_pStage->GetGoalPost()->GetLineX(m_pStage->GetGoalPost()->GetMaxLength() - 1) + 2 && 
			m_pStage->GetBall()->GetX() + 1 <= m_pStage->GetGoalPost()->GetLineX(m_pStage->GetGoalPost()->GetMaxLength() - 1) + 3))
	{
		if (m_pStage->GetBall()->GetY() <= m_pStage->GetGoalPost()->GetY())
		{   // 공 초기화
			m_pStage->GetBall()->ResetBall();
		}
	}
}

bool FootballGame::IsEnd()
{
	if (m_eGameState == GAME_STATE::FAILED)
		return true;
	else
		return false;
}

void FootballGame::RenderScene()
{
	switch (m_eGameState)
	{
	case GAME_STATE::INIT:
		//if (g_nStage == 0)
		m_pScreen.InitScreen();
		break;
	case GAME_STATE::READY:
		m_pScreen.ReadyScreen(m_nCurStage);
		break;
	case GAME_STATE::RUNNING:
		m_pScreen.BackScreen(*m_pStage, m_nCurStage, m_nBallCount, m_GameStartTime);
		m_pStage->GetGoalPost()->Render();

		// Note: 효과 출력  	
		if (m_IsGoal == true)
		{
			m_pScreen.GoalMessage(10, 10);
		}

		// Note: 2 컬럼씩 클리핑 
		m_pStage->GetPlayer()->Render();
		m_pStage->GetBall()->Render();
		break;
	case GAME_STATE::SUCCESS:
		m_pScreen.SuccessScreen();
		break;
	case GAME_STATE::FAILED:
		m_pScreen.FailureScreen();
		break;
	case GAME_STATE::RESULT:
		m_pScreen.ResultScreen(m_nCurStage);
		break;
	}
}

void FootballGame::UpdateScene()
{
	switch (m_eGameState)
	{
	case GAME_STATE::READY:
		Ready();
		break;
	case GAME_STATE::RUNNING:
		Running();
		break;
	case GAME_STATE::STOP:
		Stop();
		break;
	case GAME_STATE::SUCCESS:
		Success();
		break;
	}
}

int FootballGame::InputKey()
{
	int nKey = 0;

	if (_kbhit())
	{
		if (m_eGameState == GAME_STATE::RESULT)
			return 0;

		nKey = _getch();

		return nKey;
	}
}

// Game 처음과 Stage 바뀔때 꼭 하자 , Player , Ball , GoalPost 초기화도 넣기
void FootballGame::Initialize()
{
	m_nGoalBallCount = m_pStage->GetGoalBall();
	m_LimitTime = m_pStage->GetLimitTime();
	m_StayTime = 2000;
	m_nGoal = 0;
	m_nBallCount = 0;
	m_UpdateOldTime = clock();
	m_IsGoal = false;
}

void FootballGame::Ready()
{
	if (m_curTime - m_UpdateOldTime > 2000)  // 2초
	{
		m_eGameState = GAME_STATE::RUNNING;
		m_GameStartTime = m_curTime;
	}
}

void FootballGame::Running()
{
	if (m_curTime - m_GameStartTime > m_LimitTime) // Note: 제한 시간
	{
		m_eGameState = GAME_STATE::STOP;
		return;
	}
	else
	{
		//Note: 골대
		m_pStage->GetGoalPost()->Update(m_curTime);

		if (false == m_pStage->GetBall()->GetReady()) // 이동 중일 때 
		{	// 이동 시간 간격에 의한 이동
			if ((m_curTime - m_pStage->GetBall()->GetOldTime()) > m_pStage->GetBall()->GetMoveTime())
			{
				if (m_pStage->GetBall()->GetY() - 1 > 0)
				{
					m_pStage->GetBall()->Update(m_curTime);
					// 다음 이동 시각과 비교하기 위해 현재 시간을 이전 시간 변수에 저장
					// 골대 라인 충돌
					CollisionCheckBall_GP();
				}
				else
				{ // 공 초기화
					m_pStage->GetBall()->ResetBall();
				}
			}
		}
		else
		{
			m_pStage->GetBall()->SetX(m_pStage->GetPlayer()->GetMoveX());
		}

		// 효과 
		if (true == m_IsGoal)
		{
			if (m_curTime - m_StartTime > m_StayTime)
				m_IsGoal = false;
		}
	}
}

void FootballGame::Stop()
{
	if (m_nBallCount == m_nGoalBallCount)
	{
		m_eGameState = GAME_STATE::SUCCESS;
		m_UpdateOldTime = m_curTime;
	}
	else {
		m_eGameState = GAME_STATE::FAILED;
	}
}

void FootballGame::Success()
{
	if (m_curTime - m_UpdateOldTime > 3000)
	{
		m_UpdateOldTime = m_curTime;
		ChangeStage(new Stage2());
	}
}