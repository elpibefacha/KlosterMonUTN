#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Menu
{
	Sprite fondoMenu;
	Texture imageFondo;
	String 
public:
	Menu();
	void DibujarMenu(RenderWindow&);
	void UpdateMenu();
};

