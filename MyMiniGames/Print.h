#pragma once

class Print
{
private:
	Print();

	void* m_hscreen[2];
	int m_nscreenIndex;

public:
	static Print* Instance();
	~Print();

	void ScreenPrint(int _x, int _y, char* _string);
	// Screen 초기화
	void ScreenInit();
	// m_hscreen 끼리 바꿔사용(Flipping)
	void ScreenFlipping();
	// Screen을 비워준다
	void ScreenClear();
	// m_hscreen 을 지워준다
	void ScreenRelease();

	// 색설정
	void SetColor(int color);
};


#define PRINT Print::Instance()
