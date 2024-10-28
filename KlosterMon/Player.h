#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
using namespace sf;
using namespace std;
class Player
{
private:
	char nombre[6];
public:
	~Player();
	string getName();
	void SetName(String);
};

