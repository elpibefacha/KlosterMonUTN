#pragma once
#include "Klostermon.h"
class Enemy
{
private:
	char nombre[6];
	Klostermon klostermon[3]; 
public:
	~Enemy();
	void atacarIA(); 
	void randomNameSetter();
};

