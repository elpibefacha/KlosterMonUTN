#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Menu
{
	Sprite fondoMenu;
	Texture imageFondo;
	Font fuente;

	Font fuenteOpciones;

	Text textoTitulo;
	String menuNombreJuego;

	Text textoOpciones[4];

public:
	Menu();
	void DibujarMenu(RenderWindow&);
	void UpdateMenu();
};

