#pragma once
#include "Objeto.h"
class Optimizacion : public Objeto
{
public:
	Optimizacion();
	String usarObjeto(Klostermon& klostermonPropio, Klostermon& klostermonEnemigo) override;
};

