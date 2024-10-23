#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"
#include "SceneManager.h"
#include "Player.h"
#include "ArchivoPlayer.h"
#include "GenerarTexto.h"
using namespace sf;

class Combate
{
private:
	SceneManager sceneManager;
	//Player
	Player player;
	ArchivoPlayer archivoPlayer;
	//Interfaz
	Sprite  fondoContenedor; 
	Texture imageContenedor;
	Sprite fondoGris;
	Texture imagefondoGris; 
	// Klostermons
	Sprite Urkos; 
	Texture imageUrkos; 
	Sprite Laras; 
	Texture imageLaras;   
	// Sombras
	Sprite Sombra; 
	Sprite Sombra2;
	Sprite Sombra3; 
	Texture imageSombra; 
	// microestadio
	Sprite microestadio;
	Texture imageMicroestadio; 
	CircleShape circulo;
	void CargarInterfaz();
	String enfrentamientoString;
	Text textoBatalla;
	Font fuenteCombate;
	String nombreJugador;
	GenerarTexto configTexto;
public:
	Combate();
	void IniciarEnfrentamiento();
	void Draw(RenderWindow&);
	void IniciarNombre();

};

