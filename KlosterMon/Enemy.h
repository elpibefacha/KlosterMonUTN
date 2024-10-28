#pragma once
#include "Klostermon.h"
#include <iostream>
using namespace std; 

class Enemy
{
private:
	char nombre[6];
	Klostermon klostermon[3]; 
	char nombres[50][7];
public:
	~Enemy();
	void atacarIA(); 
	void randomNameSetter();
	string getName();
};

