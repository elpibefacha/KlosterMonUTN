#include "MenuNuevaPartida.h"

void MenuNuevaPartida::Iniciar()
{
	fuente = configTexto.gameplayFont;
	configTexto.ConfigurarTexto(playerNameText, fuente, "", 30, Color::Black);

	//Fondo
	imageFondo.loadFromFile("Sprites/fondoMenu.jpg");
	fondoMenu.setTexture(imageFondo);
	//Importante
	framesCooldown = 0;
	cout << "inicio";
}

MenuNuevaPartida::MenuNuevaPartida()
{
	Iniciar();
}

void MenuNuevaPartida::Update()
{
	event = menuManager.getEvent();
	if (playerInputName.getSize() > 3 && Keyboard::isKeyPressed(Keyboard::Enter))
	{
		menuManager.setMenuID(0);
		return;
	}
	if (event.type == Event::TextEntered && framesCooldown > 10)
	{
		//Si es enter o backspace se ignora
		if (event.text.unicode < 128 && event.text.unicode != 8 && event.text.unicode != 13)
		{
			if (playerInputName.getSize() < LIMITE_CARACTERES)
			{
				playerInputName += event.text.unicode;
				playerNameText.setString(playerInputName);
			}
		}
		//Si es backspace
		else if (event.text.unicode == 8 && !playerInputName.isEmpty())
		{
			playerInputName.erase(playerInputName.getSize() - 1, 1);
			playerNameText.setString(playerInputName);
		}
		framesCooldown = 0;
	}
	framesCooldown++;

}

void MenuNuevaPartida::Draw(RenderWindow& window)
{
	window.draw(fondoMenu);
	window.draw(playerNameText);
}

void MenuNuevaPartida::setEvent(Event& evento)
{
	event = evento;
}
