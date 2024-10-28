#pragma once
#include "Klostermon.h"
#include <iostream>
using namespace std; 

class Enemy
{
private:
	char nombre[7];
	Klostermon klostermon[3]; 
	char nombres[50][7];
public:
	void atacarIA(); 
	void randomNameSetter();
};

