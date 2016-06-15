#pragma once
#include <time.h>

class Stage;

class FootballScreen
{
public:
	FootballScreen();
	~FootballScreen();

	// 시작 배경
	void InitScreen();
	// 준비 배경
	void ReadyScreen(int _stage);
	// 플레이 배경
	void BackScreen(const Stage& _StageInfo, int _stage, int _ballCount, clock_t _time);
	// 골인 이펙트
	void GoalMessage(int _x, int _y);
	// Stage 성공 이펙트
	void SuccessScreen();
	// Stage 실패 이펙트
	void FailureScreen();
	// 결과 배경
	void ResultScreen(int _stage);
};

