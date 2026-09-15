#include "StartupState.h"
#include <iostream>

#include <conio.h>
#include "KeyCord.h"

#include "GameManager.h"
#include "TitleState.h"

void StartupState::OnEnter(GameManager* manager)
{
	std::cout << "スタートアップ処理" << std::endl;
}

void StartupState::OnUpdate(GameManager* manager, float deltaTime)
{
	manager->ChangeState(std::make_unique<TitleState>());
}

void StartupState::OnExit(GameManager* manager)
{
	std::cout << "スタートアップ処理が完了" << std::endl;
	std::cout << std::endl;
}