#include "FootballScreen.h"
#include "Print.h"
#include "Stage.h"
#include <windows.h>
#include <stdio.h>

FootballScreen::FootballScreen()
{
}


FootballScreen::~FootballScreen()
{
}


// 시작 배경
void FootballScreen::InitScreen()
{
	PRINT->ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	PRINT->ScreenPrint(0, 1, "┃                                          ┃");
	PRINT->ScreenPrint(0, 2, "┃             □━━━□                   ┃");
	PRINT->ScreenPrint(0, 3, "┃                                          ┃");
	PRINT->ScreenPrint(0, 4, "┃                        ///.   슛~~~      ┃");
	PRINT->ScreenPrint(0, 5, "┃                       (^.^)              ┃");
	PRINT->ScreenPrint(0, 6, "┃                      ┗┫ ┣┓           ┃");
	PRINT->ScreenPrint(0, 7, "┃                         ┏┛             ┃");
	PRINT->ScreenPrint(0, 8, "┃                     ⊙  ┛＼             ┃");
	PRINT->ScreenPrint(0, 9, "┃                                          ┃");
	PRINT->ScreenPrint(0, 10, "┃                                          ┃");
	PRINT->ScreenPrint(0, 11, "┃       슛 골인 게임  Go! Go!              ┃");
	PRINT->ScreenPrint(0, 12, "┃                                          ┃");
	PRINT->ScreenPrint(0, 13, "┃                                          ┃");
	PRINT->ScreenPrint(0, 14, "┃       j :왼쪽 l : 오른쪽 k :슛           ┃");
	PRINT->ScreenPrint(0, 15, "┃                                          ┃");
	PRINT->ScreenPrint(0, 16, "┃                                          ┃");
	PRINT->ScreenPrint(0, 17, "┃                                          ┃");
	PRINT->ScreenPrint(0, 18, "┃        ┗●┛  space 키를 눌러주세요     ┃");
	PRINT->ScreenPrint(0, 19, "┃                                          ┃");
	PRINT->ScreenPrint(0, 20, "┃                                          ┃");
	PRINT->ScreenPrint(0, 21, "┃                                          ┃");
	PRINT->ScreenPrint(0, 22, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}


// 준비 배경
void FootballScreen::ReadyScreen(int _stage)
{
	char string[100];

	PRINT->ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	PRINT->ScreenPrint(0, 1, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	PRINT->ScreenPrint(0, 2, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	PRINT->ScreenPrint(0, 3, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	PRINT->ScreenPrint(0, 4, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	PRINT->ScreenPrint(0, 5, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	PRINT->ScreenPrint(0, 6, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	PRINT->ScreenPrint(0, 7, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	PRINT->ScreenPrint(0, 8, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	PRINT->ScreenPrint(0, 9, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	PRINT->ScreenPrint(0, 10, "┃■■■■■                    ■■■■■■┃");
	sprintf_s(string, "┃■■■■■     %d   스테이지   ■■■■■■┃", _stage + 1);
	PRINT->ScreenPrint(0, 11, string);
	PRINT->ScreenPrint(0, 12, "┃■■■■■                    ■■■■■■┃");
	PRINT->ScreenPrint(0, 13, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	PRINT->ScreenPrint(0, 14, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	PRINT->ScreenPrint(0, 15, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	PRINT->ScreenPrint(0, 16, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	PRINT->ScreenPrint(0, 17, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	PRINT->ScreenPrint(0, 18, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	PRINT->ScreenPrint(0, 19, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	PRINT->ScreenPrint(0, 20, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	PRINT->ScreenPrint(0, 21, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	PRINT->ScreenPrint(0, 22, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	PRINT->ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}


// 플레이 배경
void FootballScreen::BackScreen(const Stage& _StageInfo, int _stage, int _ballCount, clock_t _time)
{
	char string[100];

	PRINT->ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	PRINT->ScreenPrint(0, 1, "┃                                          ┃");
	PRINT->ScreenPrint(0, 2, "┃                                          ┃");
	PRINT->ScreenPrint(0, 3, "┃                                          ┃");
	sprintf_s(string, "┃                                          ┃스테이지: %d", _stage + 1);
	PRINT->ScreenPrint(0, 4, string);
	PRINT->ScreenPrint(0, 5, "┃                                          ┃");
	sprintf_s(string, "┣━━━━━━━━━━━━━━━━━━━━━┫제한 시간: %d", _StageInfo.GetLimitTime() / 1000);
	PRINT->ScreenPrint(0, 6, string);
	PRINT->ScreenPrint(0, 7, "┃                                          ┃");
	sprintf_s(string, "┃                                          ┃현재 시간: %d", (clock() - _time) / 1000);
	PRINT->ScreenPrint(0, 8, string);
	PRINT->ScreenPrint(0, 9, "┃                                          ┃");
	sprintf_s(string, "┃                                          ┃목표 골인: %d ", _StageInfo.GetGoalBall());
	PRINT->ScreenPrint(0, 10, string);
	PRINT->ScreenPrint(0, 11, "┃                                          ┃");
	sprintf_s(string, "┃                                          ┃골인 공 개수: %d ", _ballCount);
	PRINT->ScreenPrint(0, 12, string);

	PRINT->ScreenPrint(0, 13, "┃                                          ┃");
	sprintf_s(string, "┃                                          ┃");
	PRINT->ScreenPrint(0, 14, string);
	PRINT->ScreenPrint(0, 15, "┃                                          ┃");
	sprintf_s(string, "┃                                          ┃");
	PRINT->ScreenPrint(0, 16, string);
	PRINT->ScreenPrint(0, 17, "┃                                          ┃");
	PRINT->ScreenPrint(0, 18, "┃                                          ┃");
	PRINT->ScreenPrint(0, 19, "┃                                          ┃");
	PRINT->ScreenPrint(0, 20, "┃                                          ┃");
	PRINT->ScreenPrint(0, 21, "┃                                          ┃");
	PRINT->ScreenPrint(0, 22, "┃                                          ┃");
	PRINT->ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}

// 골인 이펙트
void FootballScreen::GoalMessage(int _x, int _y)
{
	PRINT->ScreenPrint(_x, _y, "☆ )) 골인 (( ★");
	PRINT->ScreenPrint(_x, _y + 1, "＼(^^')/ ＼(\"*')/");
	PRINT->ScreenPrint(_x, _y + 2, "   ■       ■");
	PRINT->ScreenPrint(_x, _y + 3, "  ┘┐    ┌└");
}


// Stage 성공 이펙트
void FootballScreen::SuccessScreen()
{
	PRINT->ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	PRINT->ScreenPrint(0, 1, "┃                                          ┃");
	PRINT->ScreenPrint(0, 2, "┃                                          ┃");
	PRINT->ScreenPrint(0, 3, "┃                                          ┃");
	PRINT->ScreenPrint(0, 4, "┃                                          ┃");
	PRINT->ScreenPrint(0, 5, "┃                                          ┃");
	PRINT->ScreenPrint(0, 6, "┃                ////＼＼                  ┃");
	PRINT->ScreenPrint(0, 7, "┃               q ∧  ∧ p                 ┃");
	PRINT->ScreenPrint(0, 8, "┃               (└──┘)                 ┃");
	PRINT->ScreenPrint(0, 9, "┃             ♬ 미션 성공 ♪              ┃");
	PRINT->ScreenPrint(0, 10, "┃                                          ┃");
	PRINT->ScreenPrint(0, 11, "┃                                          ┃");
	PRINT->ScreenPrint(0, 12, "┃                                          ┃");
	PRINT->ScreenPrint(0, 13, "┃                                          ┃");
	PRINT->ScreenPrint(0, 14, "┃                                          ┃");
	PRINT->ScreenPrint(0, 15, "┃                                          ┃");
	PRINT->ScreenPrint(0, 16, "┃                                          ┃");
	PRINT->ScreenPrint(0, 17, "┃                                          ┃");
	PRINT->ScreenPrint(0, 18, "┃                                          ┃");
	PRINT->ScreenPrint(0, 19, "┃                                          ┃");
	PRINT->ScreenPrint(0, 20, "┃                                          ┃");
	PRINT->ScreenPrint(0, 21, "┃                                          ┃");
	PRINT->ScreenPrint(0, 22, "┃                                          ┃");
	PRINT->ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}


// Stage 실패 이펙트
void FootballScreen::FailureScreen()
{
	PRINT->ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	PRINT->ScreenPrint(0, 1, "┃                                          ┃");
	PRINT->ScreenPrint(0, 2, "┃                                          ┃");
	PRINT->ScreenPrint(0, 3, "┃                                          ┃");
	PRINT->ScreenPrint(0, 4, "┃                                          ┃");
	PRINT->ScreenPrint(0, 5, "┃                                          ┃");
	PRINT->ScreenPrint(0, 6, "┃                                          ┃");
	PRINT->ScreenPrint(0, 7, "┃                                          ┃");
	PRINT->ScreenPrint(0, 8, "┃                                          ┃");
	PRINT->ScreenPrint(0, 9, "┃                                          ┃");
	PRINT->ScreenPrint(0, 10, "┃                                          ┃");
	PRINT->ScreenPrint(0, 11, "┃                    미션 실패 !!!!        ┃");
	PRINT->ScreenPrint(0, 12, "┃                                          ┃");
	PRINT->ScreenPrint(0, 13, "┃                                          ┃");
	PRINT->ScreenPrint(0, 14, "┃                 ●┳━┓                 ┃");
	PRINT->ScreenPrint(0, 15, "┃                   ┛  ┗                 ┃");
	PRINT->ScreenPrint(0, 16, "┃                  ■■■■                ┃");
	PRINT->ScreenPrint(0, 17, "┃                                          ┃");
	PRINT->ScreenPrint(0, 18, "┃        다시 하시겠습니까? (y/n)          ┃");
	PRINT->ScreenPrint(0, 19, "┃                                          ┃");
	PRINT->ScreenPrint(0, 20, "┃                                          ┃");
	PRINT->ScreenPrint(0, 21, "┃                                          ┃");
	PRINT->ScreenPrint(0, 22, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}


// 결과 배경
void FootballScreen::ResultScreen(int _stage)
{
	char string[100];
	PRINT->ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	PRINT->ScreenPrint(0, 1, "┃                                          ┃");
	PRINT->ScreenPrint(0, 2, "┃                                          ┃");
	PRINT->ScreenPrint(0, 3, "┃             □━━━□                   ┃");
	PRINT->ScreenPrint(0, 4, "┃                                          ┃");
	PRINT->ScreenPrint(0, 5, "┃                                          ┃");
	PRINT->ScreenPrint(0, 6, "┃                                          ┃");
	PRINT->ScreenPrint(0, 7, "┃                                          ┃");
	sprintf_s(string, "┃      성공한 스테이지 :  %2d               ┃", _stage + 1);
	PRINT->ScreenPrint(0, 8, string);
	PRINT->ScreenPrint(0, 9, "┃                                          ┃");
	PRINT->ScreenPrint(0, 10, "┃                                          ┃");
	PRINT->ScreenPrint(0, 11, "┃   ___▒▒▒___                           ┃");
	PRINT->ScreenPrint(0, 12, "┃     (*^  ^*)                             ┃");
	PRINT->ScreenPrint(0, 13, "┃ =====○==○=====                         ┃");
	PRINT->ScreenPrint(0, 14, "┃                                          ┃");
	PRINT->ScreenPrint(0, 15, "┃                                          ┃");
	PRINT->ScreenPrint(0, 16, "┃                                          ┃");
	PRINT->ScreenPrint(0, 17, "┃                                          ┃");
	PRINT->ScreenPrint(0, 18, "┃                      ┗●┛              ┃");
	PRINT->ScreenPrint(0, 19, "┃                                          ┃");
	PRINT->ScreenPrint(0, 20, "┃                                          ┃");
	PRINT->ScreenPrint(0, 21, "┃                                          ┃");
	PRINT->ScreenPrint(0, 22, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}
