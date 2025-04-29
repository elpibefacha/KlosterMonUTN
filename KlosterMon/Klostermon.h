#pragma once
#include <SFML/Graphics.hpp>
#include "Ataque.h"
using namespace sf;
class Ataque;
class Klostermon
{
private: 
	char _nombre[9]; 
	char pathTexture[30]; 
	int _vida;
	int _maxVida;
	int _velocidad; 
	int _efectividad; 
	float multiplicadorDanio;
public:
	Ataque ataquePesado;
	Ataque ataqueEspecial;

	void setNameKlostermon(String);
	String getNameKlostermon(); 
	int getVida();
	int getMaxVida();
	int getEfectividad(); 
	int getVelocidad();
	float getMultiplicador();
	String getPathTexture();
	void setMaxVida(int);
	void setVida(int);
	void setEfectividad(int);
	void setVelocidad(int); 
	void setTexture(String);
	void setMultiplicador(float);
};

