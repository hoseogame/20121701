#include "SnakeScreen.h"
#include "Resources.h"
#include "Print.h"

using namespace SNAKEGAME;

SnakeScreen::SnakeScreen()
{
}


SnakeScreen::~SnakeScreen()
{
}

int SnakeScreen::ShowGameOver()
{
	PRINT->SetColor(RED);
	PRINT->ScreenPrint(15, 8, "旨收收收收收收收收收收收收收旬");
	PRINT->ScreenPrint(15, 9, "早**************************早");
	PRINT->ScreenPrint(15, 10,"早*        GAME OVER       *早");
	PRINT->ScreenPrint(15,11, "早**************************早");
	PRINT->ScreenPrint(15,12, "曲收收收收收收收收收收收收收旭");

	
	fflush(stdin);
	fflush(stdout);
	return 0;
}

int SnakeScreen::ShowGameFrame()
{
	int i;
	PRINT->SetColor(COLOR::GRAY);

	PRINT->ScreenPrint(0, 1, "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");

	for (i = 2;i < 22;i++)
	{
		PRINT->ScreenPrint(0, i, "早");
		PRINT->ScreenPrint(72, i, "早");
	}

	PRINT->ScreenPrint(0, 20 + ABS_Y, "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

	for (i = 4;i < 20;i += 2)
	{
		PRINT->ScreenPrint(76, i , "∞");
	}

	for (i = 5;i < 20;i += 2)
	{
		PRINT->ScreenPrint(75, i, "∞");
	}

	PRINT->ScreenPrint(75, 2, "��");
	PRINT->ScreenPrint(75, 3, "≒");
	PRINT->ScreenPrint(4, 0, "Snake Ver 0.1                                    Made By Jae-Dong");
	return 0;
}
