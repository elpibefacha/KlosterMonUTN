#include "MenuNuevaPartida.h"

void MenuNuevaPartida::IniciarName()
{

	configTexto.ConfigurarTexto(playerNameText, fuente, "", 30, Color::Black);
	configTexto.ConfigurarTexto(title, fuenteTitle, "Ingresa tu nombre!", 50, Color::Black);
	configTexto.CentrarTexto(title, -200);
	//Importante
	framesCooldown = 0;
	configTexto.CentrarTexto(playerNameText);
}

void MenuNuevaPartida::IniciarSlots()
{
	//Importante
	framesCooldown = 0;
	//FONDO
	imageFondo.loadFromFile("Sprites/fondoMenu.jpg");
	fondoMenu.setTexture(imageFondo);
	//FUENTE
	fuente = configTexto.gameplayFont;
	fuenteTitle = configTexto.gameTitleFont;

	configTexto.CentrarTexto(savesText[0], -200);
	configTexto.CentrarTexto(savesText[1], -100);
	configTexto.CentrarTexto(savesText[2], 0);
}

MenuNuevaPartida::MenuNuevaPartida()
{
	seleccionSlot = true;
	IniciarSlots();
}

void MenuNuevaPartida::Update()
{
	if (seleccionSlot)
	{
		SlotUpdate();
	}
	else
	{
		NameUpdate();
	}

}

void MenuNuevaPartida::Draw(RenderWindow& window)
{
	if (seleccionSlot)
	{
		SlotDraw(window);
	}
	else
	{
		NameDraw(window);
	}
}

void MenuNuevaPartida::SlotUpdate()
{
	if (Keyboard::isKeyPressed(Keyboard::Up) && framesCooldown >= 15)
	{
		Subir();
	}
	if (Keyboard::isKeyPressed(Keyboard::Down) && framesCooldown >= 15)
	{
		Bajar();
	}
	if (Keyboard::isKeyPressed(Keyboard::Enter) && framesCooldown >= 45)
	{
		seleccionSlot = false;
		gameplayManager.setSaveSlot(slotSeleccionado);
		IniciarName();
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		seleccionSlot = false;
	}
	framesCooldown++;
}

void MenuNuevaPartida::Subir()
{
	framesCooldown = 0;
	if (slotSeleccionado - 1 <= -1)
	{
		slotSeleccionado = 2;
	}
	else
	{
		slotSeleccionado--;
	}
	ActualizarSeleccion();
}

void MenuNuevaPartida::Bajar()
{
	framesCooldown = 0;
	if (slotSeleccionado + 1 >= 3)
	{
		slotSeleccionado = 0;
	}
	else
	{
		slotSeleccionado++;
	}
	ActualizarSeleccion();
}

void MenuNuevaPartida::ActualizarSeleccion()
{
	for (int i = 0; i < 3; i++)
	{
		savesText[i].setFillColor(Color::Black);
		savesText[i].setScale(1, 1);
	}
	savesText[slotSeleccionado].setFillColor(Color::Red);
	savesText[slotSeleccionado].setScale(1.2, 1.2);
}

void MenuNuevaPartida::Load()
{
	archivo.ArchiveExist();
	for (int i = 0; i < 3;i++)
	{
		configTexto.ConfigurarTexto(savesText[i], fuente, "", 25, Color::Black);
		
		player = archivo.leerArchivo(i);
		if (player.getName() != "")
		{
			savesText[i].setString(std::to_string(i + 1) + " - " + player.getName());
		}
		else
		{
			savesText[i].setString(std::to_string(i + 1) + " - " + "Sin Datos");
		}//Se fija el nombre, si no esta registrado dice sin datos
	}
	configTexto.CentrarTexto(savesText[0], -200);
	configTexto.CentrarTexto(savesText[1], -100);
	configTexto.CentrarTexto(savesText[2], 0);
	

	slotSeleccionado = 0;
	ActualizarSeleccion();

	framesCooldown = 0;
	seleccionSlot = true;
}

void MenuNuevaPartida::NameUpdate()
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
		archivo.sobreEscribir(slotSeleccionado, player);
		gameplayManager.setSaveSlot(slotSeleccionado);

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


void MenuNuevaPartida::SlotDraw(RenderWindow& window)
{
	window.draw(fondoMenu);
	for (int i = 0; i < 3; i++)
	{
		window.draw(savesText[i]);
	}
}


void MenuNuevaPartida::NameDraw(RenderWindow& window)
{
	window.draw(fondoMenu);
	window.draw(playerNameText);
	window.draw(title);
}

