#include "EstructuracionCod.h"

EstructuracionCod::EstructuracionCod()
{
	strcpy_s(nombre_obj, "Est.de Código");
}

String EstructuracionCod::usarObjeto(Klostermon& klostermonPropio, Klostermon& klostermonEnemigo)
{
	klostermonPropio.setEfectividad(100);
	return klostermonPropio.getNameKlostermon() + " recibe una estructuración \nde código!/Ahora es un 100% efectivo!";
}
