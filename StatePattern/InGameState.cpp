#include "InGameState.h"
#include <iostream>
#include <conio.h>
#include "KeyCord.h"
#include <memory>
#include "GameManager.h"
#include "ResultState.h"

#include <random>
// エンジンとシードは「プログラム起動時に1回だけ」生成する
// グローバル変数、あるいはクラスのメンバ変数として持たせる
std::random_device rd;              // ハードウェア由来のシード生成器(1回だけ使う)
std::mt19937 engine(rd());          // メルセンヌ・ツイスタ本体(状態を持ち続ける)

// 分布オブジェクトも使い回してOK(状態は持たないので毎回作っても軽いが、
// まとめておくと見通しが良い)
std::uniform_int_distribution<int> dist(1, 100);

void InGameState::OnEnter(GameManager* manager)
{
	std::cout << "インゲーム画面" << std::endl;
	std::cout << "エンターキーで１を出そう" << std::endl;

}

void InGameState::OnUpdate(GameManager* manager, float deltaTime)
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == Enter)
		{
			count++;
			random = dist(engine) % 10 + 1;
			std::cout << "実行結果：" << random << std::endl;
		}
	}

	if (random == 1)
	{
		manager->ChangeState(std::make_unique<ResultState>(count));
	}

}

void InGameState::OnExit(GameManager* manager)
{
	std::cout << std::endl;
}

const std::string InGameState::GetName() const
{
	return "InGameState";
}