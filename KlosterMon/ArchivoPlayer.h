#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace sf;
using namespace std;

class ArchivoPlayer
{
private:
	char nombreArchivo[30];
public:
	ArchivoPlayer();
	Player leerArchivo(int);
	int contarRegistros();
	bool grabarArchivo(Player);
};

