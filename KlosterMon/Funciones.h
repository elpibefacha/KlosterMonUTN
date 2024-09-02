#pragma once
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <SFML/Graphics.hpp>
using namespace sf;

enum EstadoJuego
{
	MENU,
	JUEGO
};
extern EstadoJuego gameState;

#endif