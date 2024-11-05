#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace sf; 
class FX
{
	Sprite fx;
	Texture imageFX;
	float _frame; 
public: 
	FX(); 
	void UpdateFX(); 
	void Draw(RenderWindow& window); 
	void setPosition(float X, float Y); 
	void mirror(); 
	void changeFX(int tipo);
};

