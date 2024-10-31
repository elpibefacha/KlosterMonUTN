#include "CuracionPequeña.h"

CuracionPequeña::CuracionPequeña()
{
	strcpy_s(nombre_obj, "C. Pequeña");
}

String CuracionPequeña::usarObjeto(Klostermon& klostermonPropio, Klostermon& klostermonEnemigo)
{
	int curacion = 15;
	klostermonPropio.setVida(klostermonPropio.getVida() + curacion);
	
	return klostermonPropio.getNameKlostermon() + " recibe una Curacion Pequeña!/Recupera 15 de vida!";
}
