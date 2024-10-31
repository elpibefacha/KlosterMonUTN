#include "CopyPaste.h"

CopyPaste::CopyPaste()
{
	strcpy_s(nombre_obj, "CopyPaste");
}

String CopyPaste::usarObjeto(Klostermon& klostermonPropio, Klostermon& klostermonEnemigo)
{
	int vidaMaxima = klostermonEnemigo.getMaxVida();
	int vida = klostermonEnemigo.getVida();

	klostermonPropio.setMaxVida(vidaMaxima);
	klostermonPropio.setVida(vida);

	return klostermonPropio.getNameKlostermon() + " esta copiando a el " + klostermonEnemigo.getNameKlostermon() 
		+ "\nenemigo!/Ahora tiene sus mismas estadisticas de vida!";
}
