#include "GenerarTexto.h"

GenerarTexto::GenerarTexto()
{
	gameplayFont.loadFromFile("Fonts/Pokemon Classic.ttf");
	gameTitleFont.loadFromFile("Fonts/Ketchum.otf");
}

void GenerarTexto::ConfigurarTexto(Text& texto, const Font& fuente, const String& contenido, unsigned int tamanio, const Color color, const Color outlineColor, float outlineThickness)
{
	texto.setFont(fuente);
	texto.setString(contenido);
	texto.setCharacterSize(tamanio);
	texto.setFillColor(color);
	texto.setOutlineColor(outlineColor);
	texto.setOutlineThickness(outlineThickness);
}

void GenerarTexto::CentrarTexto(Text& texto, const float yOffSet, const float xOffSet)
{
	FloatRect bounds = texto.getLocalBounds();

	float x = (800.0f / 2.0f) - (bounds.width / 2.0f) - bounds.left;
	float y = (600.0f / 2.0f) - (bounds.height / 2.0f) - bounds.top;

	//Los offset si no se declaran entonces son 0, significa que esta en medio de la pantalla
	y = y + yOffSet;
	x = x + xOffSet;

	texto.setPosition(x,y);

}
