#include "MenuEleccionKlostermon.h"

void MenuEleccionKlostermon::Load()
{
	cuadroSeleccionado = 0; 
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
		cuadro[i].setColor(Color::Black);
		cuadro[i].setPosition(posicionX, posicionY); 
	}
	imageFondo.loadFromFile("Sprites/fondoGris.png");
	fondoMenu.setTexture(imageFondo); 
}

void MenuEleccionKlostermon::Update()
{
	if (Keyboard::isKeyPressed(Keyboard::Up) && framescooldown >= 15)
	{
		Arriba();
	}
	if (Keyboard::isKeyPressed(Keyboard::Down) && framescooldown >= 15)
	{
		Abajo();
	}
	if (Keyboard::isKeyPressed(Keyboard::Left) && framescooldown >= 15)
	{
		Izquierda();
	}
	if (Keyboard::isKeyPressed(Keyboard::Right) && framescooldown >= 15)
	{
		Derecha();
	}
	framescooldown++;
}

void MenuEleccionKlostermon::Draw(RenderWindow& window)
{
	window.draw(fondoMenu);
	for (int i = 0; i < 8; i++) {
		window.draw(klostermon[i]);
		window.draw(cuadro[i]);
	}
	
}

void MenuEleccionKlostermon::Izquierda()
{
	framescooldown = 0;
	if (cuadroSeleccionado - 3 <= -1) {
		cuadroSeleccionado == 7; 
	}
	else {
		cuadroSeleccionado -= 3;
	}
	actualizarCuadro();
}

void MenuEleccionKlostermon::Derecha()
{
	framescooldown = 0; 
	if (cuadroSeleccionado + 3 <= 8) {
		cuadroSeleccionado == 0;
	}
	else {
		cuadroSeleccionado += 3; 
	}
	actualizarCuadro();
}


void MenuEleccionKlostermon::Abajo()
{
	framescooldown = 0; 
	if (cuadroSeleccionado + 1 >= 8) {
		cuadroSeleccionado = 0; 
	}
	else {
		cuadroSeleccionado++;
	}
	actualizarCuadro();
}

void MenuEleccionKlostermon::Arriba()
{
	framescooldown = 0; 
	if (cuadroSeleccionado -1 <= -1) {
		cuadroSeleccionado = 7;
	}
	else {
		cuadroSeleccionado--;
	}
	actualizarCuadro();
}

void MenuEleccionKlostermon::actualizarCuadro()
{
	for (int i = 0; i < 8; i++) {
		cuadro[i].setColor(Color::Black);
		cuadro[i].setScale(2, 2);
		klostermon[i].setScale(2, 2);
	}
	cuadro[cuadroSeleccionado].setColor(Color::Red);
	cuadro[cuadroSeleccionado].setScale(3,3);
	klostermon[cuadroSeleccionado].setScale(3,3);
}