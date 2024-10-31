#pragma once
#include "Objeto.h"
class InyeccionCodigo : public Objeto
{
public:
	InyeccionCodigo();
	String usarObjeto(Klostermon& klostermonPropio, Klostermon& klostermonEnemigo) override;
};

