#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Menu
{
	Sprite fondoMenu;
	Texture imageFondo;
public:
	Menu();
	void DibujarMenu();
	void UpdateMenu();
};

