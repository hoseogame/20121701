#include "Food.h"
#include <time.h>
#include <stdlib.h>
#include "Resources.h"
#include "Print.h"

using namespace SNAKEGAME;

Food::Food()
{
	srand(time(NULL));
}


Food::~Food()
{
}

int Food::Make()
{
	m_iFoodX = rand() % 35;
	m_iFoodY = rand() % 20;
	
	return 0;
}

void Food::Update()
{
	//while (strike_check(m_iFoodX, m_iFoodY) == 1)
	//{
	//	m_iFoodY = rand() % 20;
	//	m_iFoodX = rand() % 35;
	//}
}

void Food::Render()
{
	PRINT->ScreenPrint(77, 23, "");		//È­¸é ±úÁüÀ» ¸·±âÀ§ÇÔ
	fflush(stdout);

	PRINT->SetColor(COLOR::RED);
	PRINT->ScreenPrint(m_iFoodX * 2 + ABS_X, m_iFoodY + ABS_Y, "¡ß");
	PRINT->SetColor(COLOR::BLACK);
}
