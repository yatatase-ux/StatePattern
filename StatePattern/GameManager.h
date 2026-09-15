#pragma once
#include <memory>

class GameState;

class GameManager
{
	std::unique_ptr<GameState> currentState;
	bool isRunning;
	float gameTime;

public:
	GameManager();
	void ChangeState(std::unique_ptr<GameState> newState);
	void Update(float deltaTime);
};