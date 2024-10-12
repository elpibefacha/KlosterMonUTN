#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Combate.h"
#include "SceneManager.h"
using namespace sf;

class GameLoopManager
{

private:
	Menu menu;
	Combate combate;
	SceneManager sceneManager;

	int sceneActual;

	void GameLoop();
public:
	void Iniciar();
};

