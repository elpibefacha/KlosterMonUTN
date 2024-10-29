#pragma once
#include <SFML/Graphics.hpp>
#include "Klostermon.h"
#include <iostream>
#include <cstring>
using namespace sf;
using namespace std;
class Player
{
private:
	char nombre[6];
	Klostermon klostermon[3];
	int money;
public:
	Player();
	~Player();
	string getName();
	void SetName(String);
	void SetKlostermon(Klostermon k, int pos);
	Klostermon getKlostermon(int pos);
};

