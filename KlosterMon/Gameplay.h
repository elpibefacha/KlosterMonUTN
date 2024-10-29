#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "Player.h"
#include "ArchivoPlayer.h"
#include "Combate.h"
#include "GameplayManager.h"
#include "MusicManager.h"
#include "Enemy.h"
class Gameplay
{
private:
	//Importante
	SceneManager sceneManager;
	GameplayManager gameplayManager;
	ArchivoPlayer archivo;
	MusicManager musica;
	Combate combate;

	Player player;
	Text textoCombate;
	Enemy enemigo; 
	//Klostermones
	Texture enemigoTexture;
	Texture alidadoTexture;
	Sprite k_sprite_aliado;
	Sprite k_sprite_enemigo;

	//
	int frameCooldown;
	String stringCombate;
	//Seleccion (entre ataque y objeto)
	bool attackSelect;
	//Ataque (entre pesado y especial)
	bool ataquePesadoSelect;
	//Objetos
	int seleccionObj;
public:
	void IniciarGameplay();
	void Update(); 
	void Draw(RenderWindow&);
	void loadGameplay();
	void UpdateSeleccion();
	void UpdateAtaque();
	void Atacar(String);
	void UpdateObjetos();
};

