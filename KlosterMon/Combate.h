#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"
#include "SceneManager.h"
#include "Player.h"
#include "GenerarTexto.h"
#include "ArchivoPlayer.h"
#include "GameplayManager.h"
#include "Gameplay.h"
using namespace sf;

class Combate
{
private:
	Gameplay gameplay;
	GameplayManager gameplayManager;
	SceneManager sceneManager;
	GenerarTexto configText;
	//Player
	Player player;
	ArchivoPlayer archivoPlayer;
	//Interfaz
	void CargarInterfaz();
	String enfrentamientoString;
	Text textoBatalla;
	Font fuenteCombate;
	String nombreJugador;
	//FONDO
	Texture imagenGris;
	Sprite fondo;
	//Klostermon
	Sprite klostermonAliado;
	Texture klostermonA;
	Sprite klostermonEnemigo;
	Texture klostermonE;
	//HP
	Text klostermon_ally_hp;
	Text klostermon_enemy_hp;
	//Sombras
	Sprite sombraAliada;
	Sprite sombraEnemiga;
	Sprite sombraEstadio;
	Texture sombraTexture;
	//Estadio
	Sprite microEstadio;
	Texture estadioTexture;
	//Contenedor
	Sprite contenedorSprite;
	Texture contenedorTexture;

	
public:
	Combate();
	void IniciarEnfrentamiento();
	void Draw(RenderWindow&);
	void IniciarNombre();
};

