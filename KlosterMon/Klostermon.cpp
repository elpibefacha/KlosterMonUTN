#include "Klostermon.h"




void Klostermon::setNameKlostermon(String nombre)
{
	std::string namestd = nombre.toAnsiString();
	strcpy(_nombre, namestd.c_str());
}

String Klostermon::getNameKlostermon()
{
	String nombreAtaque = _nombre;
	//ya que setteamos el nombre significa que es la primera vez que se crea este klostermon
	//Asi que le decimos que el mult es 1.0f(daño base)
	multiplicadoDanio = 1.0f;
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

void Klostermon::setVida(int vida) {
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
