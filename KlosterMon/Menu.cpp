#include "Menu.h"

Menu::Menu()
{
	imageFondo.loadFromFile("Sprites/fondoMenu.jpg");
	fondoMenu.setTexture(imageFondo);
}

void Menu::DibujarMenu(RenderWindow& window)
{
	window.draw(fondoMenu);
}

void Menu::UpdateMenu()
{

}
