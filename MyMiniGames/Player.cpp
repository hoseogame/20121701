#include "Player.h"
#include <windows.h>
#include "Print.h"

Player::Player()
{
	m_strPlayer = "┗━●━┛";
	Initialize();
}


Player::~Player()
{
}

void Player::Initialize()
{
	m_nCenterX = 4;
	m_nCenterY = 0;

	m_nMoveX = 20;
	m_nMoveY = 22;

	m_nX = m_nMoveX - m_nCenterX;

	m_nLength = strlen(m_strPlayer);
}

void Player::Render()
{
	char string[100] = { 0, };
	if (m_nX < 2)  //  왼쪽 클리핑 처리  g_nLength : Player
		PRINT->ScreenPrint(2, m_nMoveY, &m_strPlayer[(m_nX - 2)*-1]);	 // 좌표를 배열 인덱스 
	else if (m_nMoveX + (m_nLength - m_nCenterX + 1) > 43) // 오른쪽 클리핑 처리
	{
		strncat_s(string, m_strPlayer, m_nLength - ((m_nMoveX + m_nCenterX + 1) - 43));
		PRINT->ScreenPrint(m_nX, m_nMoveY, string);
	}
	else { // 1 컬럼씩 이동
		PRINT->ScreenPrint(m_nX, m_nMoveY, m_strPlayer);
	}
}

void Player::LMove()
{
	int nRemain = 0;
	if (m_nMoveX > 2) // 왼쪽 충돌 경계 좌표 체크
	{
		m_nMoveX--;
		nRemain = m_nLength - m_nCenterX + 1; // 전체 길이 - ( 중심 좌표 + 1 )은 남은 길이
											  // Note: 2컬럼씩 이동하기 위한 부분 ( 팔이 걸친 경우 ) 
		if (m_nMoveX - m_nCenterX < 2 || m_nMoveX + nRemain > 43)
			m_nMoveX--;

		m_nX = m_nMoveX - m_nCenterX;
	}
}

void Player::RMove()
{
	int nRemain = 0;

	if (m_nMoveX + 1 < 43) // 오른쪽 충돌 경계 좌표 체크
	{
		m_nMoveX++;
		nRemain = m_nLength - m_nCenterX + 1; // 전체 길이 - ( 중심 좌표 + 1 )은 남은 길이
											  // Note: 2컬럼씩 이동하기 위한 부분 ( 팔이 걸친 경우 )
		if (m_nMoveX + nRemain > 43 || (m_nMoveX - m_nCenterX < 2))
			m_nMoveX++;

		m_nX = m_nMoveX - m_nCenterX;
	}
}
