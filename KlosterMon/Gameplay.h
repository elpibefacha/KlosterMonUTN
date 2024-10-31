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
#include "Objeto.h"
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
	int klostermonIndexPlayer;
	int klostermonRestantes_player;
	Text textoCombate;
	Enemy enemigo; 
	int klostermonIndexEnemy;
	int klostermonRestantes_enemy;
	//Klostermones

	Klostermon playerKlos[3];
	Klostermon enemyKlos[3];

	Texture enemigoTexture;
	Texture alidadoTexture;
	Sprite k_sprite_aliado;
	Sprite k_sprite_enemigo;

	//
	int frameCooldown;
	String stringCombate;
	//Seleccion (entre ataque,objeto y cambiar)
	int SelecctionMenu;
	//Ataque (entre pesado y especial)
	bool ataquePesadoSelect;
	//Objetos
	Objeto* objeto[4];

	int seleccionObj;
	//KlostermonSelect
	int k_sel_int;//Se usa para saber cual esta seleccionado en el menu
	void initKlostermons();
public:
	void Update(); 
	void Draw(RenderWindow&);
	void loadGameplay();
	void UpdateSeleccion();
	void UpdateAtaque();
	void UpdateSelKlos();
	void AvanzarTurno(String);
	void UpdateObjetos();
};

