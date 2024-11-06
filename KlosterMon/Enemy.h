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
	void randomNameSetter();
	void forceName(String);
	Klostermon randomKlostermonSetter();
	string getName();
};

