#include "GameManager.h"
#include "SnakeGame.h"
#include "FootballGame.h"
#include "Game.h"

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
	SAFE_DELETE(m_pGame);
}

GameManager * GameManager::Instance()
{
	static GameManager instance;
	return &instance;
}

void GameManager::SelectGame(eGAME _game)
{
	if (m_pGame != NULL)
	{
		return;
	}
	switch (_game)
	{
	case eGAME::FOOTBALL:
		m_pGame = new FootballGame();
		break;
	case eGAME::SNAKEGAME:
		m_pGame = new SnakeGame();
		break;
	default:
		MessageBoxA(NULL, "error", 0, 0);
		exit(true);
		return;
	}
	m_pGame->Initialize();
}

void GameManager::Update()
{
	m_pGame->Update();
}

void GameManager::Render()
{
	m_pGame->Render();
}

bool GameManager::IsEnd()
{
	if (m_pGame->IsEnd() == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
