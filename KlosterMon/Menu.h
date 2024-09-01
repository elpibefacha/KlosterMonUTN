#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Menu
{
	Sprite fondoMenu;
	Texture imageFondo;
	Font fuente;
	Text textoTitulo;
	String menuNombreJuego;
public:
	Menu();
	void DibujarMenu(RenderWindow&);
	void UpdateMenu();
};

