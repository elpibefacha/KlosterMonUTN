#pragma once
#include "Objeto.h"
class CuracionPeque�a : public Objeto
{
public:
	CuracionPeque�a();
	String usarObjeto(Klostermon& klostermonPropio, Klostermon& klostermonEnemigo) override;
};

