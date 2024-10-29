#pragma once
#include <SFML/Graphics.hpp>
#include "GenerarTexto.h"
using namespace sf; 
class MenuEleccionKlostermon 
{
private: 
	
	Sprite klostermon[8];
	Texture imageLaras; 
	Texture imageUrkos; 
	Texture imageTorus; 
	Texture imageMercias; 
	Texture imageBomber; 
	Texture imageDriller; 
	Texture imageNuxias; 
	Texture imageTrinitus; 
	// Cuadros
	Sprite cuadro[8];
	Texture imageCuadro; 
	bool seleccionado[8];
	int cuadroSeleccionado;
	int framescooldown; 
	//Fondo
	Sprite fondoMenu;
	Texture imageFondo;
public:
	void Load(); 
	void Update();
	void Draw(RenderWindow& window);
	void Arriba();
	void Abajo();
	void Izquierda();
	void Derecha(); 
	void actualizarCuadro();
};

