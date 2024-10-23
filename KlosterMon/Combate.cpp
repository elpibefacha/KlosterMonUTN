#include "Combate.h"

void Combate::CargarInterfaz()
{
	fuenteCombate.loadFromFile("Fonts/Pokemon Classic.ttf");
	textoBatalla.setFont(fuenteCombate);
	
	textoBatalla.setCharacterSize(20);
	textoBatalla.setFillColor(Color::Green);
	textoBatalla.setPosition(35, 395);
	//FONDO
	imagenGris.loadFromFile("Sprites/fondoGris.png");
	fondo.setTexture(imagenGris);
	//KLOSTERMONES

	klostermonAliado.setScale(6,6);
	klostermonEnemigo.setScale(6,6);

	klostermonAliado.setPosition(60, 110);
	klostermonEnemigo.setPosition(550, 110);
	//HP
	configText.ConfigurarTexto(klostermon_ally_hp, fuenteCombate, "110", 20, Color::Green, Color::Black, 2.0f);
	configText.ConfigurarTexto(klostermon_enemy_hp, fuenteCombate, "120", 20, Color::Green, Color::Black, 2.0f);


	klostermon_ally_hp.setPosition(125, 90);
	klostermon_enemy_hp.setPosition(615, 90);

	//Sombras
	sombraTexture.loadFromFile("Sprites/shadow.png");
	sombraAliada.setTexture(sombraTexture);
	sombraEnemiga.setTexture(sombraTexture);
	sombraEstadio.setTexture(sombraTexture);

	sombraAliada.setPosition(17, 190);
	sombraEnemiga.setPosition(505, 190);

	sombraEstadio.setScale(2,2);
	sombraEstadio.setPosition(117, -10);
	//Estadio
	estadioTexture.loadFromFile("Sprites/utn_microestadio.png");
	microEstadio.setTexture(estadioTexture);
	microEstadio.setScale(4, 4);
	microEstadio.setPosition(300, 80);
	//RECTANGULO
	contenedorTexture.loadFromFile("Sprites/contenedor.png");
	contenedorSprite.setTexture(contenedorTexture);

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
	window.draw(fondo);
	window.draw(contenedorSprite);
	window.draw(textoBatalla);
	
	window.draw(sombraAliada);
	window.draw(sombraEnemiga);
	window.draw(sombraEstadio);

	window.draw(microEstadio);

	window.draw(klostermon_ally_hp);
	window.draw(klostermon_enemy_hp);

	window.draw(klostermonEnemigo);
	window.draw(klostermonAliado);
}

void Combate::IniciarNombre()
{
	int pos;
	pos = gameplayManager.getSaveSlot();
	player = archivoPlayer.leerArchivo(pos);

	gameplay.IniciarGameplay(player, textoBatalla, klostermonAliado, klostermonEnemigo);
	sceneManager.sceneLoaded();
}
