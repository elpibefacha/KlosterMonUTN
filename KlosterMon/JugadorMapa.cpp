#include "JugadorMapa.h"

JugadorMapa::JugadorMapa()//CONSTRUCTOR
{
	velocity = 3;
	playerTexture.loadFromFile("Sprites/player.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(400,300);
	playerSprite.setScale(0.5f,0.5f);
}

void JugadorMapa::UpdatePlayer()
{
	//MOVIMIENTO
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		playerSprite.move(0, -velocity);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		playerSprite.move(0, velocity);
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		playerSprite.move(-velocity, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		playerSprite.move(velocity, 0);
	}
}

void JugadorMapa::DrawPlayer(RenderWindow& window)
{
	window.draw(playerSprite);
}
