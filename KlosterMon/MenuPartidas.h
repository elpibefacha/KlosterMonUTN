#pragma once
#include <SFML/Graphics.hpp>
#include "GenerarTexto.h"
#include "MenuManager.h"
#include "SceneManager.h"
#include "ArchivoPlayer.h"
#include "Player.h"
#include "GameplayManager.h"

using namespace sf;

class MenuPartidas
{
private:
	ArchivoPlayer archivoPlayer;
	Player player;
	GameplayManager gameplayManager;

	MenuManager menuManager;
	SceneManager sceneManager;
	GenerarTexto configTexto;
	//Fuentes
	Font fuenteGuardados;
	//Textos
	Text textoSave[3];
	
	//Fondo
	Sprite fondoMenu;
	Texture imageFondo;
	//importante
	int frameCooldown;
	int opcionSeleccionada;
	void SeleccionarOpcion();
	void ActualizarSeleccion();
	void Subir();
	void Bajar();
public:
	MenuPartidas();
	void Load();
	void Iniciar();
	void Update();
	void Draw(RenderWindow&);

};

