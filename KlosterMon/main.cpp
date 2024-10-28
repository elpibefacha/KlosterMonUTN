#include "GameLoopManager.h"
#include <ctime>
int main()
{
    srand(time(NULL));
    GameLoopManager GameLoop;
    GameLoop.Iniciar();

    return 0;
}