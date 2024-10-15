#include "Menu.h"

Menu::Menu()
{
	//MENU PRINCIPAL
	imageFondo.loadFromFile("Sprites/fondoMenu.jpg");
	fondoMenu.setTexture(imageFondo);
	fuente.loadFromFile("Fonts/Ketchum.otf");
	menuNombreJuego = "Klostermon";

	configTexto.ConfigurarTexto(textoTitulo, fuente, menuNombreJuego, 85, Color::Yellow,Color::Black,8);
	configTexto.CentrarTexto(textoTitulo, -200);
	//DemasOpciones
	fuenteOpciones.loadFromFile("Fonts/Pokemon Classic.ttf");

	textoOpciones[0].setString("Jugar");
	textoOpciones[1].setString("Nueva Partida");
	textoOpciones[2].setString("Creditos");
	textoOpciones[3].setString("Salir");


	for (int i = 0; i < 4; i++)
	{
		//Pone el estilo a cada texto
		textoOpciones[i].setCharacterSize(20);
		textoOpciones[i].setFont(fuenteOpciones);
		textoOpciones[i].setFillColor(Color::Black);
	}
	opcionSeleccionada = 0;
	frameWait = 30;
	PosicionarTextos();
	CambiarSeleccion();
}

void Menu::DibujarMenu(RenderWindow& window)
{
	if (menuManager.getMenuID()==0)
	{
		window.draw(fondoMenu);
		window.draw(textoTitulo);
		for (int i = 0; i < 4;i++)
		{
			//Dibuja cada texto dentro de textoOpciones
			window.draw(textoOpciones[i]);
		}
	}
	else if (menuManager.getMenuID() == 1)
	{
		menuCreditos.drawCreditos(window);
	}
	else if (menuManager.getMenuID() == 2)
	{
		menuNuevaPartida.Draw(window);
	}
}

void Menu::getEvent(Event& evento)
{
	menuManager.setEvent(evento);
}

void Menu::UpdateMenu()
{
	if (menuManager.getMenuID() == 0)
	{
		if (Keyboard::isKeyPressed(Keyboard::Up) && frameWait >= 15)
		{
			Subir();
		}
		if (Keyboard::isKeyPressed(Keyboard::Down) && frameWait >= 15)
		{
			Bajar();
		}
		if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			ActivarSeleccion();
		}
		frameWait++;
	}
	else if(menuManager.getMenuID()==1)
	{
		menuCreditos.Update();
	}
	else if (menuManager.getMenuID()== 2)
	{
		menuNuevaPartida.Update();
	}
}

void Menu::PosicionarTextos()
{
	//Posiciona las opciones
	textoOpciones[0].setPosition(50, 200);
	textoOpciones[1].setPosition(50, 300);
	textoOpciones[2].setPosition(50, 400);
	textoOpciones[3].setPosition(50, 500);
}

void Menu::CambiarSeleccion()
{
	for (int i = 0; i < 4; i++)
	{
		textoOpciones[i].setFillColor(Color::Black);
		textoOpciones[i].setScale(1, 1);
	}
	textoOpciones[opcionSeleccionada].setFillColor(Color::Red);
	textoOpciones[opcionSeleccionada].setScale(1.3, 1.3);
}

void Menu::Bajar()
{
	frameWait = 0;
	if (opcionSeleccionada + 1 >= 4)
	{
		opcionSeleccionada = 0;
	}
	else
	{
		opcionSeleccionada++;
	}
	CambiarSeleccion();
}

void Menu::Subir()
{
	frameWait = 0;
	if (opcionSeleccionada - 1 <= -1)
	{
		opcionSeleccionada = 3;
	}
	else
	{
		opcionSeleccionada--;
	}
	CambiarSeleccion();
}

void Menu::ActivarSeleccion()
{
	switch (opcionSeleccionada)
	{
	case 0:
		sceneManager.setScene(1);
		break;
	case 1:
		menuManager.setMenuID(2);
		break;
	case 2:
		menuManager.setMenuID(1);
		break;
	case 3:
		exit(0);
		break;
	}
}