#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class GenerarTexto
{
	public:
		void ConfigurarTexto(Text& texto, 
							const Font& fuente, 
							const String& contenido,
							unsigned int tamanio,
							const Color color = Color::White,//apartir de aca se autogenera si no se pone nada
							const Color outlineColor = Color::Black,
							float outlineThickness = 0.0f		
							);


};

