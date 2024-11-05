#include "FX.h"

FX::FX()
{
	imageFX.loadFromFile("Sprites/ataque.png");
	fx.setTexture(imageFX);
	fx.setTextureRect({ 0, 0, 34, 34 });
	fx.setPosition(550, 110);
	fx.setScale(6, 6);
	fx.setOrigin(34 / 2, 34 / 2); 
	_frame = 0; 
}

void FX::changeFX(int tipo)
{
	switch (tipo) {
	case 0: 
	{
		imageFX.loadFromFile("Sprites/ataque.png");
		fx.setTexture(imageFX);
		fx.setTextureRect({ 0, 0, 34, 34 });
		fx.setScale(6, 6);
		_frame = 0;
		break;
	}
	case 1:
	{
		imageFX.loadFromFile("Sprites/mejora.png");
		fx.setTexture(imageFX);
		fx.setTextureRect({ 0, 0, 34, 34 });
		fx.setScale(6, 6);
		break;
	}
	case 2: 
	{
		imageFX.loadFromFile("Sprites/decadencia.png");
		fx.setTexture(imageFX);
		fx.setTextureRect({ 0, 0, 34, 34 });
		fx.setScale(6, 6);
		break;
	}
	}
	_frame = 0;
}

void FX::UpdateFX()
{
	_frame += 0.2; 
	if (_frame > 4) {
		_frame = 0;
	}
	fx.setTextureRect({ 0 + int(_frame) * 34, 0, 34, 34 });
}

void FX::Draw(RenderWindow& window)
{
	window.draw(fx); 
}

void FX::setPosition(float X, float Y)
{
	fx.setPosition(X, Y); 
}

void FX::mirror()
{
	fx.setScale(-6, 6); 
}
