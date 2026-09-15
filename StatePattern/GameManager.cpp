#include "GameManager.h"
#include "GameState.h"

GameManager::GameManager() 
	: isRunning(true), gameTime(0.0f)
{

}

void GameManager::ChangeState(std::unique_ptr<GameState> newState)
{
	if(currentState)
	{
		currentState->OnExit(this);
	}

	currentState = std::move(newState);
	currentState->OnEnter(this);
}

void GameManager::Update(float deltaTime)
{
	gameTime += deltaTime;
	if (currentState)
	{
		currentState->OnUpdate(this, gameTime);
	}
}