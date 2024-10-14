#pragma once
#include <SFML/Graphics.hpp>
#include "GenerarTexto.h"
#include "MenuManager.h"

using namespace sf;
class MenuCreditos
{
private:

	MenuManager menuManager;

	//TEXTOS
	GenerarTexto configTexto;
	Font fuente;
	Font fuenteOpciones;
	Text textoCreditos;
	Text textoNombresCreditos;
	//Fondo
	Sprite fondoMenu;
	Texture imageFondo;

	void Iniciar();

public:
	MenuCreditos();
	void drawCreditos(RenderWindow&);
	void Update();
};

