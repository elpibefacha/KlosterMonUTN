#include "Ataque.h"

String Ataque::getNombre()
{
    String nombreAtaque = nombre;
    return nombreAtaque;
}

void Ataque::setName(String name)
{
    std::string namestd = name.toAnsiString();
    strcpy(nombre, namestd.c_str());
}

int Ataque::getDanio()
{
    int danio = rand() % (danioMax + 1 - danioMin) + danioMin;
    return danio;
}

void Ataque::setDanioMin(int minDanio)
{
    danioMin = minDanio;
}

void Ataque::setDanioMax(int maxDanio)
{
    danioMax = maxDanio;
    
}


int Ataque::getDanioPropio()
{
    return danioPropio;
}

void Ataque::setDanioPropio(int selfDamage)
{
    danioPropio = selfDamage;
}

int Ataque::getEfectividadAtaque()
{
    return efectividad;
}

void Ataque::setEfectividadAtaque(int efecti)
{
    efectividad = efecti;
}

int Ataque::getEfectividadEnemiga()
{
    return efectividadEnemiga;
}

void Ataque::setEfectividadEnemiga(int efecEnemiga)
{
    efectividadEnemiga = efecEnemiga;
}

int Ataque::getVelocidadAtaque()
{
    return velocidad;
}

void Ataque::setVelocidadAtaque(int speed)
{
    velocidad = speed;
}

int Ataque::getVelocidadEnemiga()
{
    return velocidadEnemiga;
}

void Ataque::setVelocidadEnemiga(int speedEnemiga)
{
    velocidadEnemiga = speedEnemiga;
}

float Ataque::getMultPropio()
{
    return multDanioPropio;
}

void Ataque::setMultPropio(float mult)
{
    multDanioPropio = mult;
}

float Ataque::getMultEnemigo()
{
    return multDanioEnemigo;
}

void Ataque::setMultEnemigo(float mult)
{
    multDanioEnemigo = mult;
}
