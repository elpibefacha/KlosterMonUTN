#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Funciones.h"
using namespace sf;



int main()
{
    RenderWindow window(VideoMode(800, 600), "KlosterMon");
    window.setFramerateLimit(60);
    Menu menu;
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
        else if(gameState == JUEGO)
        {
            //CMD
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                gameState = MENU;
            }
            window.clear();
            //DRAW
            CircleShape circulo(100.f);
            circulo.setFillColor(Color::Red);
            window.draw(circulo);
        }
        
        window.display();
    }

    return 0;
}