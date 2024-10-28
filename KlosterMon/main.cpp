#include "GameLoopManager.h"
#include <ctime>
#include "Enemy.h"
int main()
{
    srand(time(NULL));
    GameLoopManager GameLoop;
    GameLoop.Iniciar();

    return 0;
}