#include "GameLoopManager.h"



void GameLoopManager::GameLoop()
{
    RenderWindow window(VideoMode(800, 600), "KlosterMon");
    window.setFramerateLimit(60);
    
	while (window.isOpen())
	{

        sceneActual = sceneManager.getScene();

		Event event;
        menuManager.setEvent(event);
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
        if (sceneActual == 0) {//Menu
            //Load
            if (!sceneManager.getBoolLoad())
            {
                menu.loadMenu();    
            }
            //CMD
            menu.UpdateMenu();
            window.clear();
            //DRAW
            menu.DibujarMenu(window);

        }
        else if (sceneActual == 1)//En el combate
        {
            if (!sceneManager.getBoolLoad())
            {
                gameplay.loadGameplay();
            }
            //CMD
            gameplay.Update();
            window.clear();
            //DRAW
            gameplay.Draw(window);
        }
        else if (sceneActual == 2)//En la tienda
        {
            if (!sceneManager.getBoolLoad())
            {
                tienda.loadTienda();
            }
            //CMD
            tienda.Update();
            window.clear();
            //DRAW
            tienda.Draw(window);
        }

        window.display();
	}
}

void GameLoopManager::Iniciar()
{
    sceneManager.setScene(0);
    GameLoop();
}

