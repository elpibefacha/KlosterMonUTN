#include "InyeccionCodigo.h"

InyeccionCodigo::InyeccionCodigo()
{
	strcpy_s(nombre_obj, "Iny.de C�digo");
}

String InyeccionCodigo::usarObjeto(Klostermon& klostermonPropio, Klostermon& klostermonEnemigo)
{
	int efectividad = klostermonEnemigo.getEfectividad() - 15;
	klostermonEnemigo.setEfectividad(efectividad);
	return "El " + klostermonEnemigo.getNameKlostermon() + " enemigo recibe una Inyecci�n \nde codigo!/Ahora es un 15% menos efectivo!";
}
