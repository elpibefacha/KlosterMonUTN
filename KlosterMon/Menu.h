#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "MenuManager.h"
#include "GenerarTexto.h"

#include "MenuCreditos.h"
#include "MenuNuevaPartida.h"
#include "MenuPartidas.h"
#include "MusicManager.h"
#include "ArchivoKlostermon.h"
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

public:
	Menu();
	void UpdateMenu();
	void DibujarMenu(RenderWindow&);
	void loadMenu();
};