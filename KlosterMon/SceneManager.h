#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Combate.h"

using namespace sf;

class SceneManager
{
private:
	Menu menu;
	Combate combate;
	void GameLoop();
public:
	enum GameState
	{
		MENU,
		JUEGO
	};
	GameState gameState;
	void SetGameState(GameState);
	void Iniciar();
};

