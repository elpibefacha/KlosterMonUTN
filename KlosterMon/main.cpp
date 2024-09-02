#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "JugadorMapa.h"
#include "Funciones.h"
using namespace sf;



int main()
{
    RenderWindow window(VideoMode(800, 600), "KlosterMon");
    window.setFramerateLimit(60);
    Menu menu;
    JugadorMapa player;
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
        else if(gameState == JUEGO)//EN EL MAPA
        {
            //CMD
            player.UpdatePlayer();//DETECTA EL MOVIMiENTO
            //VUELVE AL MENU
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                gameState = MENU;
            }
            window.clear();
            //DRAW
            player.DrawPlayer(window);
        }
        
        window.display();
    }

    return 0;
}