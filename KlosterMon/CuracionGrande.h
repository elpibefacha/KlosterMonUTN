#pragma once
#include "Objeto.h"
class CuracionGrande : public Objeto
{
public:
	CuracionGrande();
	String usarObjeto(Klostermon& klostermonPropio, Klostermon& klostermonEnemigo) override;
};
