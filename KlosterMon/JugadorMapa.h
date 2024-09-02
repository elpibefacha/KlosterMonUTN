#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class JugadorMapa
{
private:
	Sprite playerSprite;
	Texture playerTexture;
	float velocity;
public:
	JugadorMapa();
	void UpdatePlayer();
	void DrawPlayer(RenderWindow&);
};

