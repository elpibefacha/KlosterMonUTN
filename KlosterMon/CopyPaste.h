#pragma once
#include "Objeto.h"
class CopyPaste : public Objeto
{
public:
	CopyPaste();
	String usarObjeto(Klostermon& klostermonPropio, Klostermon& klostermonEnemigo) override;
};

