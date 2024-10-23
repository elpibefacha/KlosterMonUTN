#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "ArchivoPlayer.h"
#include "GameplayManager.h"

class Gameplay
{
private:
	//Importante
	GameplayManager gameplayManager;
	ArchivoPlayer archivo;

	Player* player;
	Text* textoCombate;
	//Klostermones
	Texture enemigoTexture;
	Texture alidadoTexture;
	Sprite* k_sprite_aliado;
	Sprite* k_sprite_enemigo;

	String stringCombate;
public:
	void IniciarGameplay(Player& jugador, Text& combateText, Sprite& spriteAliado, Sprite& spriteEnemigo);

};

