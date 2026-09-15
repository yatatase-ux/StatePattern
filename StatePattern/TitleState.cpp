#include "TitleState.h"
#include <iostream>

#include <conio.h>
#include "KeyCord.h"

#include <memory>
#include "MainMenuState.h"
#include "GameManager.h"

void TitleState::OnEnter(GameManager* manager)
{
	std::cout << "タイトル画面" << std::endl;
	std::cout << "Any Keyでメインメニューに進む" << std::endl;
}

void TitleState::OnUpdate(GameManager* manager, float deltaTime)
{
	if (_kbhit())
	{
		manager->ChangeState(std::make_unique<MainMenuState>());
	}
}

void TitleState::OnExit(GameManager* manager)
{
	std::cout << "タイトル画面を終了" << std::endl;
	std::cout << std::endl;
}