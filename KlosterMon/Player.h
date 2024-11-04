#pragma once
#include <SFML/Graphics.hpp>
#include "Klostermon.h"
#include <iostream>
#include <cstring>
using namespace sf;
using namespace std;
class Player
{
private:
	char nombre[6];
	Klostermon klostermon[3];
	int objetos[4];
	int money;
	int enfrentamientoNum;
	int anioTorneo;
	bool completoJuego;
public:
	~Player();
	string getName();
	void SetName(String);
	void SetKlostermon(Klostermon k, int pos);
	void setMoney(int);
	void setObjeto(int id, int pos);
	void setEnfrentamientoNum(int);
	void setAnio(int);
	void completarJuego(bool);
	bool completoElJuego();
	int getAnio();
	int getEnfrentamiento();
	int getObjeto(int pos);
	Klostermon getKlostermon(int pos);
	int getMoney();
};

