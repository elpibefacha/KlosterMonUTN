#include "Gameplay.h"

void Gameplay::IniciarGameplay(Player& jugador, Text& combateText, Sprite& spriteAliado, Sprite& spriteEnemigo)
{
	player = &jugador;
	textoCombate = &combateText;
	k_sprite_aliado = &spriteAliado;
	k_sprite_enemigo = &spriteEnemigo;

	String string = player->getName() + " saca un Pokemon!";
	textoCombate->setString(string);

	//ACA SE CONSEGUIRIA LA TEXTURA DE CADA UNO
	String path_texture_enemy = "Sprites/laras.png";
	String path_texture_aly = "Sprites/laras.png";

	enemigoTexture.loadFromFile(path_texture_enemy);
	alidadoTexture.loadFromFile(path_texture_aly);

	k_sprite_aliado->setTexture(alidadoTexture);
	k_sprite_enemigo->setTexture(enemigoTexture);
}
