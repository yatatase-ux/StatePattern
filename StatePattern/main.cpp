#include <iostream>
#include "GameManager.h"
#include "StartupState.h"
#include <memory>

GameManager manager;

int main()
{
    manager.ChangeState(std::make_unique<StartupState>());
    float time = 0;

    while (1)
    {
        time++;
        manager.Update(time);
    }
}

