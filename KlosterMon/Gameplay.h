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
#include "FX.h"
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

	bool partidaTermino;
	//Klostermones

	Klostermon playerKlos[3];
	Klostermon enemyKlos[3];

	Texture enemigoTexture;
	Texture alidadoTexture;
	Sprite k_sprite_aliado;
	Sprite k_sprite_enemigo;

	//
	int frameCooldown;
	int textoIndex;
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
	//Diferentes bools
	bool k_player_attack = false;
	bool k_enemy_attack = false;
	bool k_enemy_died = false;
	bool k_player_died = false;
	bool k_enemy_won = false;
	bool k_player_won = false;
	bool playerMoreFast = false;
	// bools de animacion 
	bool k_player_mejora = false;
	bool k_enemy_decadencia = false;
	bool k_enemy_danio = false;
	bool k_player_danio = false;
	bool iniciarAMejora = false;
	bool iniciarADecadencia = false;
	bool iniciarADanio_E = false;
	bool iniciarADanio_P = false;
	// Tiempos animacion
	Clock clockAnimacion; 
	Time tiempoAnimacion; 

	int vidaEnemy;
	int vidaPlayer;

	void initKlostermons();

	void UpdateSeleccion();
	void UpdateAtaque();
	void UpdateSelKlos();
	void UpdateEstado();
	void UpdateAnimaciones(); 
	void avanzoTexto();
	void Atacar(Ataque ataqueUsado);
	bool playerKlostermonDie(String& ataqueEnemy, String& ataquePlayer);
	bool enemyKlostermonDie(String& ataqueEnemy, String ataquePlayer);
	void AvanzarTurno(String);
	void detectarTipoAnimacion(Ataque ataqueUsado, Klostermon k); 
public:
	void Update(); 
	void Draw(RenderWindow&);
	void loadGameplay();
	void UpdateObjetos();
};

