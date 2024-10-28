#pragma once
#include <SFML/Graphics.hpp>
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
	//Fondo
	Sprite fondoMenu;
	Texture imageFondo;
public:
	void Load(); 
	void Update();
	void Draw(RenderWindow& window);
};

