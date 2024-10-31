#include "Optimizacion.h"

Optimizacion::Optimizacion()
{
	strcpy_s(nombre_obj, "Optimización");
}

String Optimizacion::usarObjeto(Klostermon& klostermonPropio, Klostermon& klostermonEnemigo)
{
	klostermonPropio.setVelocidad(klostermonPropio.getVelocidad() + 50);
	return "Tu " + klostermonPropio.getNameKlostermon() + " se optimizo!/Ahora es un 50% mas rapido!";
}
