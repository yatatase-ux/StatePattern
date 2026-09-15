#pragma once
#include <string>

class GameManager;

class GameState
{
public:
	virtual ~GameState() = default;
	virtual void OnEnter(GameManager* manager) = 0;
	virtual void OnUpdate(GameManager* manager, float deltaTime) = 0;
	virtual void OnExit(GameManager* manager) = 0;
	/*　シーンの切り替わり処理（例：フェードイン・フェードアウトなど）を
　　実装するのに非常に使える　*/
	virtual const std::string GetName() const = 0;
};

#define STATE_CLASS(className)\
	void OnEnter(GameManager* manager)override;\
	void OnUpdate(GameManager* manager, float deltaTime)override;\
	void OnExit(GameManager* manager)override;\
	const std::string GetName()const override;