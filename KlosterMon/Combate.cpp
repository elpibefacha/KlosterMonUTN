#include "Combate.h"

void Combate::CargarInterfaz()
{
	/// FONDO 
	imagefondoGris.loadFromFile("Sprites/fondoGris.jpg");
	fondoGris.setTexture(imagefondoGris);

	fuenteCombate.loadFromFile("Fonts/Pokemon Classic.ttf");
	textoBatalla.setFont(fuenteCombate);
	
	enfrentamientoString = nombreJugador + " saca un Klostermon!";
	textoBatalla.setString(enfrentamientoString);
	textoBatalla.setCharacterSize(20);
	textoBatalla.setFillColor(Color::Black);
	//textoBatalla.setOrigin(textoBatalla.getScale().x/2, textoBatalla.getScale().y / 2);
	textoBatalla.setPosition(30, 375);

	//RECTANGULO
	imageContenedor.loadFromFile("Sprites/rectangulo.png");
	fondoContenedor.setTexture(imageContenedor);
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
	window.draw(fondoGris);
	window.draw(fondoContenedor);
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
