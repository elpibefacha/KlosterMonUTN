#include "Combate.h"

void Combate::CargarInterfaz()
{
	/// FONDO 
	imagefondoGris.loadFromFile("Sprites/fondoGris.png");
	fondoGris.setTexture(imagefondoGris);

	/// Laras y urkos 
	imageLaras.loadFromFile("Sprites/laras.png"); 
	Laras.setTexture(imageLaras);
	Laras.setScale(6,6);
	Laras.setPosition(550, 150); 
	imageUrkos.loadFromFile("Sprites/urkos.png");
	Urkos.setTexture(imageUrkos);
	Urkos.setScale(6,6);
	Urkos.setPosition(60, 150);
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
	window.draw(Laras);
	window.draw(Urkos);
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
