#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Ataque
{
	char nombre[9];
	int danioMin;
	int danioMax;
	int danioPropio;
	int efectividad;
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
};

