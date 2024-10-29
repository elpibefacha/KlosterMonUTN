#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include "Gameplay.h"
#include "SceneManager.h"
#include "MenuManager.h"
using namespace sf;

class GameLoopManager
{

private:
	Menu menu;
	MenuManager menuManager;
	Gameplay gameplay;
	SceneManager sceneManager;
	sf::Music musica; 
	int sceneActual;

	void GameLoop();
public:
	void Iniciar();
};

