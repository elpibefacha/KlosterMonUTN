#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Klostermon;

class Ataque
{
	char nombre[9];
	int danioMin;
	int danioMax;
	int danioPropio;
	int modVidaTotal;
	int modVidaTotalEnemiga;
	int efectividadPropia;
	int efectividadEnemiga;
	int velocidad;
	int velocidadEnemiga;
	float multDanioPropio;
	float multDanioEnemigo;
public:
	String getNombre();
	void setName(String);

	int getDanio();
	void setDanioMin(int);
	void setDanioMax(int);

	int getDanioPropio();
	void setDanioPropio(int);

	int getModVidaTotal();
	void setModVidaTotal(int);
	int getModVidaTotalEnemiga();
	void setModVidaTotalEnemiga(int);

	int getEfectividadAtaque();
	void setEfectividadAtaque(int);
	int getEfectividadEnemiga();
	void setEfectividadEnemiga(int);

	int getVelocidadAtaque();
	void setVelocidadAtaque(int);
	int getVelocidadEnemiga();
	void setVelocidadEnemiga(int);

	float getMultPropio();
	void setMultPropio(float);
	float getMultEnemigo();
	void setMultEnemigo(float);

	String utilizarAtaque(Klostermon& enemigo,Klostermon& aliado);
	String fallarAtaque(Klostermon atacante);

};

