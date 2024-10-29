#pragma once
#include <SFML/Graphics.hpp>
#include "GenerarTexto.h"
#include "SceneManager.h"
#include "MusicManager.h"
using namespace sf; 
class Tienda
{
private: 
	MusicManager musica; 
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
	int cuadroSeleccionado; 
	bool elegido[6] = { false }; 
	int elegidos; 
	int framescooldown = 0; 
	// Fondo
	Sprite fondo; 
	Texture imageFondo; 
public: 
	void loadTienda(); 
	void Update(); 
	void Arriba();
	void Abajo();
	void Izquierda();
	void Derecha(); 
	void actualizarCuadro(); 
	void configInfo(int cuadroSeleccionado); 
	void Draw(RenderWindow& window); 
};

