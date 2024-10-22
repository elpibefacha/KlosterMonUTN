#pragma once
#include <SFML/Graphics.hpp>
#include "GenerarTexto.h"
#include "MenuManager.h"
#include "SceneManager.h"
#include "Player.h"
#include "ArchivoPlayer.h"

#include <iostream>

using namespace sf;
using namespace std;

class MenuNuevaPartida
{
private:
	//Player INFO
	Player player;
	ArchivoPlayer archivo;
	//Managers
	SceneManager sceneManager;
	MenuManager menuManager;
	//Texto
	Font fuente;
	Font fuenteTitle;
	Text title;
	GenerarTexto configTexto;
	//INPUT TEXT VARIABLES
	Event event;
	String playerInputName;
	Text playerNameText;
	int framesCooldown;
	const size_t LIMITE_CARACTERES = 6;
	//FONDO
	Sprite fondoMenu;
	Texture imageFondo;
	//METODOS PRIVADOS
	void Iniciar();
public:
	MenuNuevaPartida();
	void Update();
	void Draw(RenderWindow&);
};

