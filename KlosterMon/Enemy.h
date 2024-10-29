#pragma once
#include "Klostermon.h"
#include "ArchivoKlostermon.h"
#include <iostream>
using namespace std; 

class Enemy
{
private:
	ArchivoKlostermon archivoKlos;
	char nombre[6];
	char nombres[50][7];
public:
	~Enemy();
	void atacarIA(); 
	void randomNameSetter();
	Klostermon randomKlostermonSetter();
	string getName();
};

