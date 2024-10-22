#include "MenuNuevaPartida.h"

void MenuNuevaPartida::Iniciar()
{
	fuente = configTexto.gameplayFont;
	fuenteTitle = configTexto.gameTitleFont;

	configTexto.ConfigurarTexto(playerNameText, fuente, "", 30, Color::Black);
	configTexto.ConfigurarTexto(title, fuenteTitle, "Ingresa tu nombre!", 50, Color::Black);
	configTexto.CentrarTexto(title, -200);
	//Fondo
	imageFondo.loadFromFile("Sprites/fondoMenu.jpg");
	fondoMenu.setTexture(imageFondo);
	//Importante
	framesCooldown = 0;
	configTexto.CentrarTexto(playerNameText);
}



MenuNuevaPartida::MenuNuevaPartida()
{
	Iniciar();
}

void MenuNuevaPartida::Update()
{
	event = menuManager.getEvent();
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		playerInputName = "";
		playerNameText.setString("");
		menuManager.setMenuID(0);
		return;
	}
	if (playerInputName.getSize() >= 3 && Keyboard::isKeyPressed(Keyboard::Enter))
	{
		player.SetName(playerInputName);
		archivo.grabarArchivo(player);
		

		sceneManager.setScene(1);
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
		configTexto.CentrarTexto(playerNameText, -150);
	}
	framesCooldown++;

}

void MenuNuevaPartida::Draw(RenderWindow& window)
{
	window.draw(fondoMenu);
	window.draw(playerNameText);
	window.draw(title);
}

