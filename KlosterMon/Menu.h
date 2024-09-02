#pragma once
#include <SFML/Graphics.hpp>
#include "Funciones.h"
using namespace sf;


class Menu
{
	enum Estado {
		MenuPrincipal,
		MenuCreditos
	};
	//MENU PRINCIPAL

	Estado estadoMenu;


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
	String stringCreditos;

	Text textoNombresCreditos;

public:
	Menu();
	void UpdateMenu();
	void DibujarMenu(RenderWindow&);
};

