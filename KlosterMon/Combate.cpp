#include "Combate.h"

void Combate::CargarInterfaz()
{
	fuenteCombate.loadFromFile("Fonts/Pokemon Classic.ttf");
	textoBatalla.setFont(fuenteCombate);
	
	enfrentamientoString = nombreJugador + " saca un Pokemon!";
	textoBatalla.setString(enfrentamientoString);
	textoBatalla.setCharacterSize(20);
	textoBatalla.setFillColor(Color::Black);
	//textoBatalla.setOrigin(textoBatalla.getScale().x/2, textoBatalla.getScale().y / 2);
	textoBatalla.setPosition(30, 375);

	//RECTANGULO
	Contenedor.setSize(Vector2f(800, 300));
	Contenedor.setOrigin(400, 150);
	Contenedor.setPosition(400, 500);
	Contenedor.setFillColor(Color::White);
}

Combate::Combate()
{
	CargarInterfaz();
}

void Combate::IniciarEnfrentamiento()
{

	enfrentamientoString = nombreJugador;
	CargarInterfaz();
}

void Combate::Draw(RenderWindow& window)
{
	window.draw(Contenedor);
	window.draw(textoBatalla);
}

void Combate::IniciarNombre()
{
	int cant;
	cant = archivoPlayer.contarRegistros();

	player = archivoPlayer.leerArchivo(cant - 1);

	cout << "IniciarNombre" << endl;

	nombreJugador = player.getName();

	sceneManager.sceneLoaded();
}
