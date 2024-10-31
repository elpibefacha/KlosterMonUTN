#include "Klostermon.h"




void Klostermon::setNameKlostermon(String nombre)
{
	std::string namestd = nombre.toAnsiString();
	strcpy(_nombre, namestd.c_str());
}

String Klostermon::getNameKlostermon()
{
	String nombreAtaque = _nombre;
	return nombreAtaque;
}

void Klostermon::setVelocidad(int speed) {
	_velocidad = speed;
}

void Klostermon::setTexture(String path)
{
	String pathCompleto = "Sprites/" + path;
	std::string stdstring = pathCompleto.toAnsiString();
	strcpy(pathTexture, stdstring.c_str());
}

void Klostermon::setMultiplicador(float nuevoMult)
{
	multiplicadorDanio = nuevoMult;
}

void Klostermon::setVida(int vida) {
	if (vida > _maxVida) { vida = _maxVida; }
	_vida = vida;
}

void Klostermon::setEfectividad(int efec)
{
	_efectividad = efec;
}

int Klostermon::getEfectividad() {
	return _efectividad;
}

int Klostermon::getVelocidad() {
	return _velocidad; 
}

float Klostermon::getMultiplicador()
{
	return multiplicadorDanio;
}

String Klostermon::getPathTexture()
{
	return pathTexture;
}

void Klostermon::setMaxVida(int maxvida)
{
	_maxVida = maxvida;
}

int Klostermon::getVida() {
	return _vida; 
}

int Klostermon::getMaxVida()
{
	return _maxVida;
}
