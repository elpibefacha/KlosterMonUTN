#include "GenerarTexto.h"

void GenerarTexto::ConfigurarTexto(Text& texto, const Font& fuente, const String& contenido, unsigned int tamanio, const Color color, const Color outlineColor, float outlineThickness)
{
	texto.setFont(fuente);
	texto.setString(contenido);
	texto.setCharacterSize(tamanio);
	texto.setFillColor(color);
	texto.setOutlineColor(outlineColor);
	texto.setOutlineThickness(outlineThickness);
}
