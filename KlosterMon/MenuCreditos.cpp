#include "MenuCreditos.h"

void MenuCreditos::Iniciar()
{
	fuente = configTexto.gameTitleFont;
	fuenteOpciones = configTexto.gameplayFont;

	configTexto.ConfigurarTexto(textoCreditos, fuente, "CREDITOS", 30, Color::Black);
	textoCreditos.setPosition(300, 850);

	configTexto.ConfigurarTexto(textoNombresCreditos, fuenteOpciones, "Juego hecho por:\n Mateo Scataglini y Joaquin Sanchez", 15, Color::Black);
	textoNombresCreditos.setPosition(90, 950);
	//FONDO
	imageFondo.loadFromFile("Sprites/fondoMenu.jpg");
	fondoMenu.setTexture(imageFondo);
}

MenuCreditos::MenuCreditos()
{
	Iniciar();
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
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		menuManager.setMenuID(0);
		textoNombresCreditos.setPosition(90, 1000);
		textoCreditos.setPosition(300, 900);
	}
}
