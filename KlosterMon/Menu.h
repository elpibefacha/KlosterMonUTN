#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Menu
{
	Sprite fondoMenu;
	Texture imageFondo;
	Font fuente;

	Font fuenteOpciones;

	Text textoTitulo;
	String menuNombreJuego;

	Text textoOpciones[4];

	int opcionSeleccionada;



	void PosicionarTextos();
	void UpdateMenu();
	void CambiarSeleccion();
public:
	Menu();
	void DibujarMenu(RenderWindow&);
	void Bajar();
	void Subir();
};

