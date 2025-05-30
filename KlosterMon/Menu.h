#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "MenuManager.h"
#include "GenerarTexto.h"
#include "ArchivoKlostermon.h"
#include "MusicManager.h"

#include "MenuCreditos.h"
#include "MenuNuevaPartida.h"
#include "MenuPartidas.h"
#include "MenuEleccionKlostermon.h"

using namespace sf;


class Menu
{
	MenuManager menuManager;
	SceneManager sceneManager;
	GenerarTexto configTexto;
	MusicManager musica; 
	ArchivoKlostermon archivoKlostermon;
	//MENU PRINCIPAL
	Sprite fondoMenu;
	Texture imageFondo;

	Font fuente;
	Font fuenteOpciones;

	Text textoTitulo;
	String menuNombreJuego;

	SoundBuffer bufferSound;
	Sound moveSound;

	Text textoOpciones[4];
	int opcionSeleccionada;
	int frameWait;
	void PosicionarTextos();
	void CambiarSeleccion();
	void Bajar();
	void Subir();
	void ActivarSeleccion();

	//Menu Creditos
	MenuCreditos menuCreditos;
	//Menu Nueva Partida
	MenuNuevaPartida menuNuevaPartida;
	//Menu Partidas
	MenuPartidas menuPartidas;
	//Menu Eleccion Klostermon
	MenuEleccionKlostermon menuEleccion;
public:
	Menu();
	void UpdateMenu();
	void DibujarMenu(RenderWindow&);
	void loadMenu();
};