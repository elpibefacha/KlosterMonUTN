#include <SFML/Graphics.hpp>
#include "Menu.h"
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
        window.clear();

        //DRAW
        menu.DibujarMenu(window);

        window.display();
    }

    return 0;
}