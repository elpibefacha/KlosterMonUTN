#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "GenerarTexto.h"

using namespace sf;


class Menu
{
	SceneManager sceneManager;
	GenerarTexto configTexto;

	enum Estado {
		MenuPrincipal,
		MenuCreditos
	};
	Estado estadoMenu;

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

	Text textoCreditos;
	Text textoNombresCreditos;

public:
	Menu();
	void UpdateMenu();
	void DibujarMenu(RenderWindow&);
};