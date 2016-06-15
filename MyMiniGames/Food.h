#pragma once

class Food
{
	
private:
	int m_iFoodX;
	int m_iFoodY;
public:
	Food();
	~Food();

	int Make();

	void Update();
	void Render();

	int GetX() const { return m_iFoodX; }
	int GetY() const { return m_iFoodY; }
};

