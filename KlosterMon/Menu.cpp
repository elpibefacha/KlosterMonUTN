#include "Menu.h"

Menu::Menu()
{
	//MENU PRINCIPAL
	imageFondo.loadFromFile("Sprites/fondoMenu.jpg");
	fondoMenu.setTexture(imageFondo);
	fuente = configTexto.gameTitleFont;
	menuNombreJuego = "Klostermon";
	configTexto.ConfigurarTexto(textoTitulo, fuente, menuNombreJuego, 85, Color::Yellow,Color::Black,8);
	configTexto.CentrarTexto(textoTitulo, -200);
	bufferSound.loadFromFile("Sounds/moveMenu.ogg");
	moveSound.setBuffer(bufferSound);
	moveSound.setVolume(50); 
	//DemasOpciones
	fuenteOpciones = configTexto.gameplayFont;

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
		textoOpciones[i].setOutlineThickness(1.5f);
		textoOpciones[i].setOutlineColor(Color::White);
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
	else if (menuManager.getMenuID() == 3)
	{
		menuPartidas.Draw(window);
	}
	else if (menuManager.getMenuID() == 4)
	{
		menuEleccion.Draw(window);
	}
}

void Menu::loadMenu()
{
	musica.stopMusic();
	musica.setVolumen(50); 
	musica.playMusic("menu.ogg");
	sceneManager.sceneLoaded();
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
		if (Keyboard::isKeyPressed(Keyboard::P))
		{
			archivoKlostermon.cargarConsola();
		}
		frameWait++;
	}
	else if(menuManager.getMenuID()==1)
	{
		if (!menuManager.getLoaded()) { menuCreditos.Iniciar(); menuManager.loadMenu(); }
		menuCreditos.Update();
	}
	else if (menuManager.getMenuID()== 2)
	{
		if (!menuManager.getLoaded()) { menuNuevaPartida.Load(); menuManager.loadMenu();}//CARGA
		menuNuevaPartida.Update();
	}
	else if (menuManager.getMenuID() == 3)
	{
		if (!menuManager.getLoaded()) { menuPartidas.Load(); menuManager.loadMenu();}//CARGA
		menuPartidas.Update();
	}
	else if (menuManager.getMenuID() == 4)
	{
		if (!menuManager.getLoaded()) { menuEleccion.Load(); menuManager.loadMenu(); }//CARGA
		menuEleccion.Update();
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
	moveSound.play();
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
	moveSound.play();
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
		menuManager.setMenuID(3);
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