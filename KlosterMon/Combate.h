#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"
#include "SceneManager.h"
#include "Player.h"
#include "ArchivoPlayer.h"
using namespace sf;

class Combate
{
private:
	SceneManager sceneManager;
	//Player
	Player player;
	ArchivoPlayer archivoPlayer;
	//Interfaz
	RectangleShape Contenedor;
	CircleShape circulo;
	void CargarInterfaz();
	String enfrentamientoString;
	Text textoBatalla;
	Font fuenteCombate;
	String nombreJugador;
public:
	Combate();
	void IniciarEnfrentamiento();
	void Draw(RenderWindow&);
	void IniciarNombre();

};

