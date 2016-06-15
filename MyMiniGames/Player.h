#pragma once

class Player
{
private:
	char* m_strPlayer;

	int m_nCenterX;
	int m_nCenterY;

	int m_nMoveX;
	int m_nMoveY;

	int m_nX;
	int m_nY;

	int m_nLength;
public:
	Player();
	virtual ~Player();

	void Initialize();
	void Render();
	void LMove();
	void RMove();

	int GetMoveX() const { return m_nMoveX; }
	int GetMoveY() const { return m_nMoveY; }

};

