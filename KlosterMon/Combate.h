#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"
using namespace sf;

class Combate
{
private:
	//Interfaz
	RectangleShape Contenedor;
	CircleShape circulo;
	void CargarInterfaz();
	String enfrentamientoString;
	Text textoBatalla;
	Font fuenteCombate;
public:
	Combate();
	void IniciarEnfrentamiento();
	void Draw(RenderWindow&);

};

