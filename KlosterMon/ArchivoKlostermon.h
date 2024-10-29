#pragma once
#include <SFML/Graphics.hpp>
#include "Klostermon.h"
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace sf;
using namespace std;

class ArchivoKlostermon
{
private:
	char nombreArchivo[30];
public:
	ArchivoKlostermon();
	Klostermon leerArchivo(int);
	int contarRegistros();
	bool sobreEscribir(int pos, Klostermon kl);
	bool grabarArchivo(Klostermon);
	void cargarConsola();
};

