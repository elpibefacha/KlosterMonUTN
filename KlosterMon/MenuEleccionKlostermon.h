#pragma once
#include <SFML/Graphics.hpp>
#include "GenerarTexto.h"
#include "MenuManager.h"
#include "ArchivoKlostermon.h"
#include "ArchivoPlayer.h";
#include "GameplayManager.h"
#include "Player.h"
#include "SceneManager.h"
using namespace sf;
class MenuEleccionKlostermon
{
private:
	ArchivoKlostermon archivoKlostermon;
	ArchivoPlayer archivoPlayer;
	GameplayManager gameplayManager;
	MenuManager menumanager;
	SceneManager sceneManager;

	Player player;
	Klostermon klostermonSeleccionado;
	Sprite klostermon[8];
	Texture imageLaras;
	Texture imageUrkos;
	Texture imageTorus;
	Texture imageMercias;
	Texture imageBomber;
	Texture imageDriller;
	Texture imageNuxias;
	Texture imageTrinitus;
	// Cuadros
	Sprite cuadro[8];
	Texture imageCuadro;
	bool elegido[8] = { false };
	int elegidos;
	int cuadroSeleccionado;
	int framescooldown;
	//Fondo
	Sprite fondoMenu;
	Texture imageFondo;
	// Texto
	Text titulo;
	Text caza;
	Text carga;
	Text asistencia;
	Text info;
	GenerarTexto configtexto;
	// Metodos privados
	void configInfo(int cuadroSeleccionado);
	void Arriba();
	void Abajo();
	void Izquierda();
	void Derecha();
	void actualizarCuadro();
public:
	void Load();
	void Update();
	void Draw(RenderWindow& window);
};


