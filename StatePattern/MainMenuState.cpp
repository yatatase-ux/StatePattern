#include "MainMenuState.h"
#include <iostream>
#include <conio.h>
#include "KeyCord.h"
#include <memory>
#include "GameManager.h"

#include "TitleState.h"
#include "InGameState.h"

void MainMenuState::OnEnter(GameManager* manager)
{
	std::cout << "メインメニュー画面" << std::endl;
	std::cout << "１でインゲームへ、BackSpaseでタイトルへ" << std::endl;
}

void MainMenuState::OnUpdate(GameManager* manager, float deltaTime)
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == One)
		{
			manager->ChangeState(std::make_unique<InGameState>());
		}
		else if(key == BackSpace)
		{
			manager->ChangeState(std::make_unique<TitleState>());
		}
	}
}

void MainMenuState::OnExit(GameManager* manager)
{
	std::cout << "メインメニュー画面を終了" << std::endl;
	std::cout << std::endl;
}

const std::string MainMenuState::GetName() const
{
	return "MainMenuState";
}