#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include "Combate.h"
#include "SceneManager.h"
#include "MenuManager.h"
using namespace sf;

class GameLoopManager
{

private:
	Menu menu;
	MenuManager menuManager;
	Combate combate;
	SceneManager sceneManager;
	sf::Music musica; 
	int sceneActual;

	void GameLoop();
public:
	void Iniciar();
};

