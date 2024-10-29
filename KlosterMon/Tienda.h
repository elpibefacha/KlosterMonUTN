#pragma once
#include <SFML/Graphics.hpp>
#include "GenerarTexto.h"
#include "SceneManager.h"
using namespace sf; 
class Tienda
{
private: 
	SceneManager scenemanager;  
	// Texto
	Text info; 
	GenerarTexto configtexto; 
	// Objetos
	Sprite objeto[6];
	Texture imageCopy;
	Texture imageInye;
	Texture imageEstru;
	Texture imageCCP; 
	Texture imageCCG;
	Texture imageOpti; 
	// Cuadros
	Sprite cuadro[6];
	Texture imageCuadro; 
	// Fondo
	Sprite fondo; 
	Texture imageFondo; 
public: 
	void loadTienda(); 
	void Draw(RenderWindow& window); 
};

