#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "Player.h"
#include "ArchivoPlayer.h"
#include "ArchivoKlostermon.h"
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
	ArchivoKlostermon archivoKlostermon;
	MusicManager musica;
	Combate combate;

	Player player;

	Klostermon playerKlos[3];
	Klostermon enemyKlos[3];

	Text textoCombate;
	Enemy enemigo; 
	//Klostermones
	Klostermon KlostermonAliado;

	Texture enemigoTexture;
	Texture alidadoTexture;
	Sprite k_sprite_aliado;
	Sprite k_sprite_enemigo;

	//
	int frameCooldown;
	String stringCombate;
	//Seleccion (entre ataque y objeto)
	int SelecctionMenu;
	//Ataque (entre pesado y especial)
	bool ataquePesadoSelect;
	//Objetos
	int seleccionObj;
	//KlostermonSelect
	int k_sel_int;//Se usa para saber cual esta seleccionado en el menu
	void initKlostermons();
public:
	void IniciarGameplay();
	void Update(); 
	void Draw(RenderWindow&);
	void loadGameplay();
	void UpdateSeleccion();
	void UpdateAtaque();
	void UpdateSelKlos();
	void Atacar(String);
	void UpdateObjetos();
};

