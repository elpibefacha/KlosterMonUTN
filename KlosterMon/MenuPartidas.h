#pragma once
#include <SFML/Graphics.hpp>
#include "GenerarTexto.h"
#include "MenuManager.h"
#include "SceneManager.h"
#include "ArchivoPlayer.h"
#include "Player.h"

using namespace sf;

class MenuPartidas
{
private:
	ArchivoPlayer archivoPlayer;
	Player player;

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
	void Iniciar();
	void Update();
	void Draw(RenderWindow&);

};

