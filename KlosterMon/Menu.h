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
	int frameWait;


	void PosicionarTextos();
	void CambiarSeleccion();
	void Bajar();
	void Subir();
	void ActivarSeleccion();
public:
	Menu();
	void UpdateMenu();
	void DibujarMenu(RenderWindow&);
};

