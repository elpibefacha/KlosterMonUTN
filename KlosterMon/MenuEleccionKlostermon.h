#pragma once
#include <SFML/Graphics.hpp>
using namespace sf; 
class MenuEleccionKlostermon 
{
private: 
	// Sprite Laras
	Sprite laras; 
	Texture imageLaras; 
	// Sprite Urkos
	Sprite urkos; 
	Texture imageUrkos; 
	// Sprite Torus
	Sprite torus; 
	Texture imageTorus; 
	// Sprite Mercias
	Sprite mercias; 
	Texture imageMercias; 
	// Sprite Bomber
	Sprite bomber;
	Texture imageBomber; 
	// Sprite Driller
	Sprite driller;
	Texture imageDriller; 
	// Sprite Nuxias
	Sprite nuxias; 
	Texture imageNuxias; 
	// Sprite Trinitus
	Sprite trinitus;
	Texture imageTrinitus; 
public:
	void load(); 
};

