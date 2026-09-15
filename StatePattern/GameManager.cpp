#include "GameManager.h"
#include "GameState.h"

GameManager::GameManager(std::unique_ptr<GameState> initialState)
	: isRunning(true), gameTime(0.0f), currentState(std::move(initialState))
{
	currentState->OnEnter(this);
}

void GameManager::ChangeState(std::unique_ptr<GameState> newState)
{
	currentState->OnExit(this);
	currentState = std::move(newState);
	currentState->OnEnter(this);
}

void GameManager::Update(float deltaTime)
{
	gameTime += deltaTime;

	currentState->OnUpdate(this, gameTime);
}