#include "GameLoopManager.h"



void GameLoopManager::GameLoop()
{
    RenderWindow window(VideoMode(800, 600), "KlosterMon");
    window.setFramerateLimit(60);

	while (window.isOpen())
	{

        sceneActual = sceneManager.getScene();

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
        if (sceneActual == 0) {//Menu
            //CMD
            menu.UpdateMenu();
            window.clear();
            //DRAW
            menu.DibujarMenu(window);

        }
        else if (sceneActual == 1)//EN EL MAPA
        {
            //CMD
            combate.IniciarEnfrentamiento();
            //VUELVE AL MENU
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                gameState = MENU;
            }
            window.clear();
            //DRAW
            combate.Draw(window);
        }

        window.display();
	}
}

void GameLoopManager::Iniciar()
{
    gameState = MENU;
    sceneManager.setScene(0);
    GameLoop();
}

