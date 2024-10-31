#pragma once
#include <SFML/Graphics.hpp>
#include "GenerarTexto.h"
#include "SceneManager.h"
#include "MusicManager.h"
#include "Player.h"
#include "ArchivoPlayer.h"
#include "GameplayManager.h"
#include <iostream>
using namespace sf;
class Tienda
{
private:
	MusicManager musica;
	SceneManager scenemanager;
	GameplayManager gameplayManager;
	ArchivoPlayer archivoPlayer;
	Player player;
	// Texto
	Text info;
	GenerarTexto configtexto;
	Text Dinero;
	int dinero;
	// Objetos
	Sprite objeto[6];
	Texture imageCopy;
	Texture imageInye;
	Texture imageEstru;
	Texture imageCCP;
	Texture imageCCG;
	Texture imageOpti;
	// Cuadros
	Sprite cuadro[6];
	Texture imageCuadro;
	int cuadroSeleccionado;
	int framescooldown = 0;
	// Fondo
	Sprite fondo;
	Texture imageFondo;
	// Tiempo
	Clock clock;
	Time tiempo;
	// Sonidos
	SoundBuffer comprarBuff;
	SoundBuffer errorBuff;
	Sound sonidoComprar;
	Sound sonidoError;
public:
	void loadTienda();
	void Update();
	void Arriba();
	void Abajo();
	void Izquierda();
	void Derecha();
	void actualizarCuadro();
	void configInfo(int cuadroSeleccionado);
	void Draw(RenderWindow& window);
};