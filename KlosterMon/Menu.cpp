#include "Menu.h"

Menu::Menu()
{
	imageFondo.loadFromFile("Sprites/fondoMenu.jpg");
	fondoMenu.setTexture(imageFondo);
	fuente.loadFromFile("Fonts/Ketchum.otf");
	menuNombreJuego = "Klostermon";
	textoTitulo.setFont(fuente);
	textoTitulo.setFillColor(Color::Black);
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
	PosicionarTextos();
	CambiarSeleccion();

}

void Menu::DibujarMenu(RenderWindow& window)
{
	window.draw(fondoMenu);
	window.draw(textoTitulo);
	for (int i = 0; i < 4;i++)
	{
		//Dibuja cada texto dentro de textoOpciones
		window.draw(textoOpciones[i]);
	}
}

void Menu::UpdateMenu()
{

}

void Menu::PosicionarTextos()
{
	//Posiciona las opciones
	textoOpciones[0].setPosition(100, 200);
	textoOpciones[1].setPosition(100, 300);
	textoOpciones[2].setPosition(100, 400);
	textoOpciones[3].setPosition(100, 500);
}

void Menu::CambiarSeleccion()
{
	opcionSeleccionada = 0;
	textoOpciones[opcionSeleccionada].setFillColor(Color::Red);
}

void Menu::Bajar()
{
	if (opcionSeleccionada + 1 >= 4)
	{
		opcionSeleccionada = 0;
	}
	else
	{
		opcionSeleccionada++;
	}
}

void Menu::Subir()
{
	if (opcionSeleccionada - 1 <= -1)
	{
		opcionSeleccionada = 3;
	}
	else
	{
		opcionSeleccionada--;
	}
}
