#pragma once
#include "GameState.h"

class ResultState : public GameState
{
	int countSum;

public:
	ResultState(int count);

	STATE_CLASS(ResultState);
};

