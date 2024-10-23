#pragma once
#include <SFML/Graphics.hpp>
#include "GenerarTexto.h"
#include "MenuManager.h"
#include "SceneManager.h"
#include "Player.h"
#include "ArchivoPlayer.h"
#include "GameplayManager.h"

#include <iostream>

using namespace sf;
using namespace std;

class MenuNuevaPartida
{
private:
	GameplayManager gameplayManager;
	bool seleccionSlot;
	int slotSeleccionado;
	//Player INFO
	Player player;
	ArchivoPlayer archivo;
	//Managers
	SceneManager sceneManager;
	MenuManager menuManager;
	//Texto
	Font fuente;
	Font fuenteTitle;
	Text title;

	Text titleSelect;
	Text savesText[3];

	GenerarTexto configTexto;
	//INPUT TEXT VARIABLES
	Event event;
	String playerInputName;
	Text playerNameText;
	int framesCooldown;
	const size_t LIMITE_CARACTERES = 6;
	//FONDO
	Sprite fondoMenu;
	Texture imageFondo;
	//METODOS PRIVADOS
	void IniciarName();
	void IniciarSlots();

	void SlotUpdate();
	void NameUpdate();

	void SlotDraw(RenderWindow&);
	void NameDraw(RenderWindow&);
	//Slots Metodos
	void Subir();
	void Bajar();
	void ActualizarSeleccion();
public:
	MenuNuevaPartida();
	void Update();
	void Load();
	void Draw(RenderWindow&);
};

