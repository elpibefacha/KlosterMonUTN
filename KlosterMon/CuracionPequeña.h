#pragma once
#include "Objeto.h"
class CuracionPequeña : public Objeto
{
public:
	CuracionPequeña();
	String usarObjeto(Klostermon& klostermonPropio, Klostermon& klostermonEnemigo) override;
};

