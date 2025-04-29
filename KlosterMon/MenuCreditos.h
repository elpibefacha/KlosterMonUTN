#pragma once
#include <SFML/Graphics.hpp>
#include "GenerarTexto.h"
#include "MenuManager.h"
#include "MusicManager.h"

using namespace sf;
class MenuCreditos
{
private:

	MenuManager menuManager;
	MusicManager musica; 

	//TEXTOS
	GenerarTexto configTexto;
	Font fuente;
	Font fuenteOpciones;
	Text textoCreditos;
	Text textoNombresCreditos;
	//Fondo
	Sprite fondoMenu;
	Texture imageFondo;
	int acum = 1; 


public:
	void Iniciar();
	void drawCreditos(RenderWindow&);
	void Update();
};

