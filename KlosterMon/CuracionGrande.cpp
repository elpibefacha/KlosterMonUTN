#include "CuracionGrande.h"

CuracionGrande::CuracionGrande()
{
	strcpy_s(nombre_obj, "C. Grande");
}

String CuracionGrande::usarObjeto(Klostermon& klostermonPropio, Klostermon& klostermonEnemigo)
{
	int curacion = 50;
	klostermonPropio.setVida(klostermonPropio.getVida() + curacion);
	return klostermonPropio.getNameKlostermon() + " recibe una Curacion Grande!/Recupera 50 de vida!";
}