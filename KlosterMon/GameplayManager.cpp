#include "GameplayManager.h"

int GameplayManager::saveSlot = 0;

int GameplayManager::getSaveSlot()
{
    return saveSlot;
}

void GameplayManager::setSaveSlot(int newSlot)
{
    saveSlot = newSlot;
}
