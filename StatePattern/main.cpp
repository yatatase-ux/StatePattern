#include <iostream>
#include "GameManager.h"
#include "StartupState.h"
#include <memory>

GameManager manager(std::make_unique<StartupState>());

int main()
{
    while (1)
    {
        manager.Update(1.0f);
    }
}