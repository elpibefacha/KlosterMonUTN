#include "MenuEleccionKlostermon.h"

void MenuEleccionKlostermon::load()
{
	imageLaras.loadFromFile("laras.png");
	laras.setTexture(imageLaras);
	imageUrkos.loadFromFile("urkos.png");
	urkos.setTexture(imageUrkos); 
	imageNuxias.loadFromFile("nuxias.png");
	urkos.setTexture(imageNuxias);
	imageTorus.loadFromFile("torus.png");
	torus.setTexture(imageTorus);
	imageDriller.loadFromFile("driller.png");
	driller.setTexture(imageDriller);
	imageMercias.loadFromFile("mercias.png");
	mercias.setTexture(imageMercias);
	imageTrinitus.loadFromFile("trinitus.png");
	trinitus.setTexture(imageTrinitus); 
	imageBomber.loadFromFile("bomber.png");
	bomber.setTexture(imageBomber); 
}
