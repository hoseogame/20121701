#pragma once
#include <time.h>
class Stage;

class GoalPost
{
private:
	int m_nX;
	int m_nY;
	int m_nLength;
	int m_nMaxLength;
	int m_nArrLineX[7];
	int m_nDistance;

	clock_t m_MoveTime;
	clock_t m_OldTime;

public:
	GoalPost();
	~GoalPost();

	void Initialize(const Stage& _stageInfo);

	void Update();
	void Render();

	void MoveX(int _x) { m_nX += _x; }

	void MoveGoalPost(clock_t _time);
	void DistanceFlip() { m_nDistance = m_nDistance * -1; }

	int GetX() const { return m_nX; }
	int GetY() const { return m_nY; }
	int GetLength() const { return m_nLength; }
	int GetDistance() const { return m_nDistance; }
	int GetMaxLength() const { return m_nMaxLength; }
	int GetLineX(int _index) { return m_nArrLineX[_index]; }

	clock_t GetMoveTime() const { return m_MoveTime; }
	clock_t GetOldTime() const { return m_OldTime; }

	void SetOldTIme(clock_t _clock) { m_OldTime = _clock; }


};

