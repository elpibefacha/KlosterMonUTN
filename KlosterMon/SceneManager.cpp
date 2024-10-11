#include "SceneManager.h"



void SceneManager::GameLoop()
{
    RenderWindow window(VideoMode(800, 600), "KlosterMon");
    window.setFramerateLimit(60);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
        if (gameState == MENU) {
            //CMD
            menu.UpdateMenu();
            window.clear();
            //DRAW
            menu.DibujarMenu(window);

        }
        else if (gameState == JUEGO)//EN EL MAPA
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


void SceneManager::SetGameState(GameState estadoJuego)
{
    gameState = estadoJuego;
}

void SceneManager::Iniciar()
{
    gameState = MENU;
    GameLoop();
}

