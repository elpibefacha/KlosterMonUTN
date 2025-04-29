#include "InyeccionCodigo.h"

InyeccionCodigo::InyeccionCodigo()
{
	strcpy_s(nombre_obj, "Iny.de Código");
}

String InyeccionCodigo::usarObjeto(Klostermon& klostermonPropio, Klostermon& klostermonEnemigo)
{
	int efectividad = klostermonEnemigo.getEfectividad() - 15;
	klostermonEnemigo.setEfectividad(efectividad);
	return "El " + klostermonEnemigo.getNameKlostermon() + " enemigo recibe una Inyección \nde codigo!/Ahora es un 15% menos efectivo!";
}
