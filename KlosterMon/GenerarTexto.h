#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class GenerarTexto
{
	public:
		GenerarTexto();
		void ConfigurarTexto(Text& texto, 
							const Font& fuente, 
							const String& contenido,
							unsigned int tamanio,
							const Color color = Color::White,//apartir de aca se autogenera si no se pone nada
							const Color outlineColor = Color::Black,
							float outlineThickness = 0.0f		
							);
		
		Font gameTitleFont;
		Font gameplayFont;

		void CentrarTexto(Text& texto, const float yOffSet = 0, const float xOffSet = 0);
};

