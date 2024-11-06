#pragma once
#include <SFML/Graphics.hpp>
#include "Klostermon.h"
//Objetos

using namespace sf;
class Objeto
{
protected:
	char nombre_obj[20];
	int id_obj;
public:
	virtual ~Objeto() {}
	static Objeto* cargarObjeto(int);
	String getNombre();
	virtual String usarObjeto(Klostermon& klostermonPropio, Klostermon& klostermonEnemigo) = 0;
};

