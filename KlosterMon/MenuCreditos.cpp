#include "MenuCreditos.h"

void MenuCreditos::Iniciar()
{
	acum = 1; 
	musica.stopMusic(); 
	musica.setVolumen(30); 
	musica.playMusic("creditos.ogg"); 
	fuente = configTexto.gameTitleFont;
	fuenteOpciones = configTexto.gameplayFont;

	configTexto.ConfigurarTexto(textoCreditos, fuente, "CREDITOS", 30, Color::Red, Color::White, 0.5);
	textoCreditos.setPosition(300, 750);

	configTexto.ConfigurarTexto(textoNombresCreditos, fuenteOpciones, "Juego hecho por:\nMateo Scataglini y Joaquín Sánchez en C++ con el \nuso de la librería SFML\n\nSprites de Klostermon y efectos:\nHecho por nosotros en Libresprite", 15, Color::White);
	textoNombresCreditos.setPosition(90, 850);
	//FONDO
	imageFondo.loadFromFile("Sprites/fondoCreditos.jpg");
	fondoMenu.setTexture(imageFondo);
	menuManager.loadMenu(); 
}

void MenuCreditos::drawCreditos(RenderWindow& window)
{
	window.draw(fondoMenu);
	window.draw(textoCreditos);
	window.draw(textoNombresCreditos);
}

void MenuCreditos::Update()
{
	
	textoCreditos.move(0, -2);
	textoNombresCreditos.move(0, -2);
	if (textoNombresCreditos.getPosition().y < -100) {
		acum++; 
		textoNombresCreditos.setPosition(90, 850);
		switch (acum) {
			case 2: 
			{
				configTexto.ConfigurarTexto(textoCreditos, fuente, "Musica utilizada", 30, Color::Red, Color::White, 0.5);
				textoCreditos.setPosition(300, 750);
				configTexto.ConfigurarTexto(textoNombresCreditos, fuenteOpciones, "Menu: Tema original, compuesto por Joaquín Sánchez\n\nCombate: 'The Strokes - Juicebox' Versión 8-Bits\n\nTienda: 'Elevator Jam - LSPLASH'", 15, Color::White);
				break; 
			}
			case 3: 
			{
				configTexto.ConfigurarTexto(textoNombresCreditos, fuenteOpciones, "Klosterman Song: 'Consecuencias' - por Joaquín Sánchez\n\nCreditos: 'Leave Before The Lights Come On'", 15, Color::White);
				break;
			}
			case 4:
			{
				configTexto.ConfigurarTexto(textoCreditos, fuente, "Sprites de fondos", 30, Color::Red, Color::White, 0.5);
				textoCreditos.setPosition(300, 750);
				configTexto.ConfigurarTexto(textoNombresCreditos, fuenteOpciones, "Fondo Menu: Hecho por Kaleb da Silva Pereira\n\nFondo Tienda: Hecho por nosotros en Libresprite\n\nFondo Creditos: Hecho por Kaleb da Silva Pereira", 15, Color::White);
				break;
			}
			case 5:
			{
				configTexto.ConfigurarTexto(textoCreditos, fuente, "Gracias especiales", 30, Color::Red, Color::White, 0.5);
				textoCreditos.setPosition(300, 750);
				configTexto.ConfigurarTexto(textoNombresCreditos, fuenteOpciones, "Gracias a Ernesto, por su ayuda en los Zooms, a Kloster y \na Brian por sus Workshops!", 15, Color::White);
				break;
			}
			case 6:
			{
				configTexto.ConfigurarTexto(textoNombresCreditos, fuenteOpciones, "Ya no hay mas creditos, muchas gracias por jugar :)", 15, Color::White);
				break;
			}
			case 7:
			{
				menuManager.setMenuID(0);
				musica.stopMusic();
				musica.setVolumen(50);
				musica.playMusic("menu.ogg");
			}
		}

	}
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		menuManager.setMenuID(0);
		textoNombresCreditos.setPosition(90, 1000);
		textoCreditos.setPosition(300, 900);
		musica.stopMusic();
		musica.setVolumen(50);
		musica.playMusic("menu.ogg");
	}
}
