#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"
#include "SceneManager.h"
#include "Player.h"
#include "GenerarTexto.h"
#include "ArchivoPlayer.h"
#include "GameplayManager.h"
#include "MusicManager.h"
using namespace sf;

class Combate
{
private:
	GameplayManager gameplayManager;
	SceneManager sceneManager;
	GenerarTexto configText;
	
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
	// Musica
	MusicManager musica; 
	//Opciones
	Text Elige;
	Text ObjetoSelect;
	Text AtacarSelect;
	Text CambiarSelect;
	//Ataques
	Text AtaquePesado;
	Text AtaqueEspecial;
	//Objetos
	Text Objetos[4];
	//Seleccionar Klostermon
	Text k_slot[3];
	//DividirTexto
	String stringPartes[5];//COMO MAX 5
	int partesEncontradas;
	int parteActual;
	
public:
	Combate();

	//Enum
	enum Interfaz
	{
		TEXTO,
		SELECCION,
		ATAQUE,
		OBJETO,
		KLOS_SEL,
	};
	Interfaz interfaz;
	//

	void Draw(RenderWindow&);
	void IniciarCombate(String);
	void DividirTexto(const String& string, String partes[]);
	void avanzarDialogo();
	void ChangeSeleccion(int);
	void ChangeAtaque(bool);
	void ChangeObjeto(int);
	void ChangeKlostermon(int);
	void MostrarTexto(String);
	void setNombreAtaques(String pesado, String especial);
	void setKlostermonNames(String k1, String k2, String k3);
	void setTexture_K_Ally(String path);
	void setTexture_K_Enemy(String path);
	void changeHPText(int pla, int ene);
};

