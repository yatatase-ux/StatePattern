#include "ResultState.h"
#include <iostream>
#include <conio.h>
#include "KeyCord.h"
#include <memory>
#include "GameManager.h"
#include "MainMenuState.h"

ResultState::ResultState(int count)
	:countSum(count)
{
}

void ResultState::OnEnter(GameManager* manager)
{
	std::cout << "リザルト画面" << std::endl;
	std::cout << countSum << "回でクリア！！" << std::endl;
	std::cout << "Any Keyでメインメニューに戻る" << std::endl;
}

void ResultState::OnUpdate(GameManager* manager, float deltaTime)
{
	if (_kbhit())
	{
		manager->ChangeState(std::make_unique<MainMenuState>());
	}
}

void ResultState::OnExit(GameManager* manager)
{
	std::cout << "リザルト画面を終了" << std::endl;
	std::cout << std::endl;
}

const std::string ResultState::GetName() const
{
	return "ResultState";
}