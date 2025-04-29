#pragma once
#include "Objeto.h"
class EstructuracionCod : public Objeto
{
public:
	EstructuracionCod();
	String usarObjeto(Klostermon& klostermonPropio, Klostermon& klostermonEnemigo) override;
};

