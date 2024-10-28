#include "MenuEleccionKlostermon.h"

void MenuEleccionKlostermon::Load()
{
	imageLaras.loadFromFile("Sprites/laras.png");
	klostermon[0].setTexture(imageLaras);
	imageUrkos.loadFromFile("Sprites/urkos.png");
	klostermon[1].setTexture(imageUrkos);
	imageTrinitus.loadFromFile("Sprites/trinitus.png");
	klostermon[2].setTexture(imageTrinitus);
	imageTorus.loadFromFile("Sprites/torus.png");
	klostermon[3].setTexture(imageTorus);
	imageDriller.loadFromFile("Sprites/driller.png");
	klostermon[4].setTexture(imageDriller);
	imageBomber.loadFromFile("Sprites/bomber.png");
	klostermon[5].setTexture(imageBomber);
	imageNuxias.loadFromFile("Sprites/nuxias.png");
	klostermon[6].setTexture(imageNuxias);
	imageMercias.loadFromFile("Sprites/mercias.png");
	klostermon[7].setTexture(imageMercias);
	imageCuadro.loadFromFile("Sprites/cuadro.png");
	int posicionX = 0;
	int posicionY = 0;
	for (int i = 0; i < 8; i++) {
		if (i==0) {
			posicionX = 0;
			posicionY = 100;
		}
		if (i==3) {
			posicionX = 300;
			posicionY = 100; 
		}
		if (i == 6) {
			posicionX = 600;
			posicionY = 100; 
		}
		posicionY += 100;
		klostermon[i].setScale(2, 2);
		klostermon[i].setPosition(posicionX, posicionY);
		cuadro[i].setTexture(imageCuadro);
		cuadro[i].setScale(2, 2);
		cuadro[i].setPosition(posicionX, posicionY); 
	}
	imageFondo.loadFromFile("Sprites/fondoGris.png");
	fondoMenu.setTexture(imageFondo); 
}

void MenuEleccionKlostermon::Update()
{

}

void MenuEleccionKlostermon::Draw(RenderWindow& window)
{
	window.draw(fondoMenu);
	for (int i = 0; i < 8; i++) {
		window.draw(klostermon[i]);
		window.draw(cuadro[i]);
	}
	
}
