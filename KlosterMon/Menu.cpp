#include "Menu.h"

Menu::Menu()
{
	//MENU PRINCIPAL
	estadoMenu = MenuPrincipal;
	imageFondo.loadFromFile("Sprites/fondoMenu.jpg");
	fondoMenu.setTexture(imageFondo);
	fuente.loadFromFile("Fonts/Ketchum.otf");
	menuNombreJuego = "Klostermon";
	textoTitulo.setFont(fuente);
	textoTitulo.setOutlineThickness(8);
	textoTitulo.setOutlineColor(Color::Black);
	textoTitulo.setFillColor(Color::Yellow);
	textoTitulo.setString(menuNombreJuego);
	textoTitulo.setPosition(180, 50);
	textoTitulo.setCharacterSize(85);
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
	//MENU CREDITO
	textoCreditos.setFont(fuente);
	textoCreditos.setFillColor(Color::Black);
	textoCreditos.setPosition(300, 850);
	stringCreditos = "CREDITOS";
	textoCreditos.setString(stringCreditos);

	textoNombresCreditos.setFont(fuenteOpciones);
	textoNombresCreditos.setFillColor(Color::Black);
	textoNombresCreditos.setOrigin(textoNombresCreditos.getPosition().x/2, textoNombresCreditos.getPosition().y / 2);
	textoNombresCreditos.setPosition(90, 950);
	textoNombresCreditos.setString("Juego hecho por:\n Mateo Scataglini y Joaquin Sanchez");
	textoNombresCreditos.setCharacterSize(15);
}

void Menu::DibujarMenu(RenderWindow& window)
{
	if (estadoMenu == MenuPrincipal)
	{
		window.draw(fondoMenu);
		window.draw(textoTitulo);
		for (int i = 0; i < 4;i++)
		{
			//Dibuja cada texto dentro de textoOpciones
			window.draw(textoOpciones[i]);
		}
	}
	else if(estadoMenu == MenuCreditos)
	{
		window.draw(fondoMenu);
		window.draw(textoCreditos);
		window.draw(textoNombresCreditos);
	}
}

void Menu::UpdateMenu()
{
	if (estadoMenu == MenuPrincipal)
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
	else if (estadoMenu == MenuCreditos)
	{
		textoCreditos.move(0, -2);
		textoNombresCreditos.move(0,-2);
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			estadoMenu = MenuPrincipal;
			textoNombresCreditos.setPosition(90, 1000);
			textoCreditos.setPosition(300, 900);
		}
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
	}
	textoOpciones[opcionSeleccionada].setFillColor(Color::Red);
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
	case 2:
		estadoMenu = MenuCreditos;
		break;
	case 3:
		exit(0);
		break;
	}
}
