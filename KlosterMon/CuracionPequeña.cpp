#include "CuracionPeque�a.h"

CuracionPeque�a::CuracionPeque�a()
{
	strcpy_s(nombre_obj, "C. Peque�a");
}

String CuracionPeque�a::usarObjeto(Klostermon& klostermonPropio, Klostermon& klostermonEnemigo)
{
	int curacion = 15;
	klostermonPropio.setVida(klostermonPropio.getVida() + curacion);
	
	return klostermonPropio.getNameKlostermon() + " recibe una Curacion Peque�a!/Recupera 15 de vida!";
}
