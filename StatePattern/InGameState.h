#pragma once
#include "GameState.h"
class InGameState : public GameState
{
	int random;
	int count = 0;

public:
	STATE_CLASS(InGameState);
};

