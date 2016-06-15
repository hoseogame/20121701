#include "Print.h"
#include <windows.h>
#include <stdio.h>

Print::Print()
{
	ScreenInit();
}

Print::~Print()
{
	ScreenRelease();
}


Print * Print::Instance()
{
	static Print instance;
	return &instance;
}

void Print::ScreenInit()
{
	CONSOLE_CURSOR_INFO cci;

	// 가상의 콘솔창 2개룰 만든다.
	m_hscreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	m_hscreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// 커서 숨기기
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(m_hscreen[0], &cci);
	SetConsoleCursorInfo(m_hscreen[1], &cci);
}

void Print::SetColor(int color)

{
	static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(std_output_handle, color);
}


// x , y 좌표에 문자열 출력
void Print::ScreenPrint(int _x, int _y, char* _string)
{
	DWORD dw;
	COORD CursorPosition = { _x, _y };
	SetConsoleCursorPosition(m_hscreen[m_nscreenIndex], CursorPosition);
	WriteFile(m_hscreen[m_nscreenIndex], _string, strlen(_string), &dw, NULL);
}




// m_hscreen 끼리 바꿔사용(Flipping)
void Print::ScreenFlipping()
{
	Sleep(10);
	SetConsoleActiveScreenBuffer(m_hscreen[m_nscreenIndex]);
	m_nscreenIndex = !m_nscreenIndex;
}


// Screen을 비워준다
void Print::ScreenClear()
{
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(m_hscreen[m_nscreenIndex], ' ', 80 * 25, Coor, &dw);
}

// m_hscreen 을 지워준다
void Print::ScreenRelease()
{
	CloseHandle(m_hscreen[0]);
	CloseHandle(m_hscreen[1]);
}