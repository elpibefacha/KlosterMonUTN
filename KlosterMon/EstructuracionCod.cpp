#include "EstructuracionCod.h"

EstructuracionCod::EstructuracionCod()
{
	strcpy_s(nombre_obj, "Est.de C�digo");
}

String EstructuracionCod::usarObjeto(Klostermon& klostermonPropio, Klostermon& klostermonEnemigo)
{
	klostermonPropio.setEfectividad(100);
	return klostermonPropio.getNameKlostermon() + " recibe una estructuraci�n \nde c�digo!/Ahora es un 100% efectivo!";
}
