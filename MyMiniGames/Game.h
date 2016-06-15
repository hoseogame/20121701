#pragma once
class Game
{
public:
	Game();
	~Game();

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual bool IsEnd() = 0;
};

