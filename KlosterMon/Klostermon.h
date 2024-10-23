#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Klostermon
{
private: 
	char _nombre[8];
	Texture imageKlostermon; 
	int _vida;
	int _velocidad; 
	int _efectividad; 
public:
	void ataquePesado();
	void ataqueEspecial(); 
	int getVida(); 
	int getEfectividad(); 
	int getVelocidad();
	void setVida();
	void setEfectividad();
	void setVelocidad(); 
};

