#include "Tienda.h"

void Tienda::loadTienda()
{
	imageCCP.loadFromFile("Sprites/codigo_curacion_p.png");
	objeto[0].setTexture(imageCCP);
	imageCCG.loadFromFile("Sprites/codigo_curacion_g.png");
	objeto[1].setTexture(imageCCG);
	imageInye.loadFromFile("Sprites/inyeccion_codigo.png");
	objeto[2].setTexture(imageInye);
	imageEstru.loadFromFile("Sprites/estructuracion.png");
	objeto[3].setTexture(imageEstru);
	imageOpti.loadFromFile("Sprites/optimizacion.png");
	objeto[4].setTexture(imageOpti);
	imageCopy.loadFromFile("Sprites/copy_paste.png");
	objeto[5].setTexture(imageCopy); 

	imageCuadro.loadFromFile("Sprites/cuadro.png"); 
	for (int i=0; i < 6; i++) {
		cuadro[i].setTexture(imageCuadro); 
	}

	imageFondo.loadFromFile("Sprites/fondoGris.png");
	fondo.setTexture(imageFondo);
	scenemanager.sceneLoaded(); 
}

void Tienda::Draw(RenderWindow& window)
{
	window.draw(fondo); 
	window.draw(objeto[0]); 
}
