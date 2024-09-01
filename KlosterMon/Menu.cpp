#include "Menu.h"

Menu::Menu()
{
	imageFondo.loadFromFile("Sprites/fondoMenu.jpg");
	fondoMenu.setTexture(imageFondo);
	fuente.loadFromFile("Fonts/Ketchum.otf");
	menuNombreJuego = "Klostermon";

	textoTitulo.setFont(fuente);
	textoTitulo.setFillColor(Color::Black);
	textoTitulo.setString(menuNombreJuego);
	textoTitulo.setPosition(180, 100);
	textoTitulo.setCharacterSize(85);
}

void Menu::DibujarMenu(RenderWindow& window)
{
	window.draw(fondoMenu);
	window.draw(textoTitulo);
}

void Menu::UpdateMenu()
{

}
