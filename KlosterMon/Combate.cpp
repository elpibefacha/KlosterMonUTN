#include "Combate.h"

void Combate::CargarInterfaz()
{
	fuenteCombate.loadFromFile("Fonts/Pokemon Classic.ttf");
	textoBatalla.setFont(fuenteCombate);
	
	textoBatalla.setCharacterSize(20);
	textoBatalla.setFillColor(Color::Green);
	textoBatalla.setPosition(35, 395);
	//FONDO
	imagenGris.loadFromFile("Sprites/fondoGris.png");
	fondo.setTexture(imagenGris);
	//KLOSTERMONES

	klostermonAliado.setScale(6, 6);
	klostermonEnemigo.setScale(6, 6);

	klostermonAliado.setPosition(60, 110);
	klostermonEnemigo.setPosition(550, 110);
	//HP
	configText.ConfigurarTexto(klostermon_ally_hp, fuenteCombate, "", 20, Color::Green, Color::Black, 2.0f);
	configText.ConfigurarTexto(klostermon_enemy_hp, fuenteCombate, "", 20, Color::Green, Color::Black, 2.0f);

	//Sombras
	sombraTexture.loadFromFile("Sprites/shadow.png");
	sombraAliada.setTexture(sombraTexture);
	sombraEnemiga.setTexture(sombraTexture);
	sombraEstadio.setTexture(sombraTexture);

	sombraAliada.setPosition(17, 190);
	sombraEnemiga.setPosition(505, 190);

	sombraEstadio.setScale(2, 2);
	sombraEstadio.setPosition(117, -10);
	//Estadio
	estadioTexture.loadFromFile("Sprites/utn_microestadio.png");
	microEstadio.setTexture(estadioTexture);
	microEstadio.setScale(4, 4);
	microEstadio.setPosition(300, 80);
	//RECTANGULO
	contenedorTexture.loadFromFile("Sprites/contenedor.png");
	contenedorSprite.setTexture(contenedorTexture);
	//Select
	configText.ConfigurarTexto(Elige, fuenteCombate, "¡Elige una opción!", 20, Color::Green);
	configText.ConfigurarTexto(ObjetoSelect, fuenteCombate, "Objetos", 20, Color::Green);
	configText.ConfigurarTexto(AtacarSelect, fuenteCombate, "Atacar", 20, Color::Green);
	configText.ConfigurarTexto(CambiarSelect, fuenteCombate, "Cambiar", 20, Color::Green);
	configText.CentrarTexto(Elige, 100);
	configText.CentrarTexto(ObjetoSelect, 250, 0);
	configText.CentrarTexto(AtacarSelect, 250, -200);
	configText.CentrarTexto(CambiarSelect, 250, 200);
	//Ataques
	configText.ConfigurarTexto(AtaqueEspecial, fuenteCombate, "AtaqueEspecial", 20, Color::Green);
	configText.ConfigurarTexto(AtaquePesado, fuenteCombate, "AtaquePesado", 20, Color::Green);
	configText.CentrarTexto(AtaqueEspecial, 250, 150);
	configText.CentrarTexto(AtaquePesado, 250, -150);
	//Objetos
	configText.ConfigurarTexto(Objetos[0], fuenteCombate, "Objeto1", 20, Color::Green);
	configText.ConfigurarTexto(Objetos[1], fuenteCombate, "Objeto2", 20, Color::Green);
	configText.ConfigurarTexto(Objetos[2], fuenteCombate, "Objeto3", 20, Color::Green);
	configText.ConfigurarTexto(Objetos[3], fuenteCombate, "Objeto4", 20, Color::Green);
	configText.CentrarTexto(Objetos[0], 125, -150);
	configText.CentrarTexto(Objetos[1], 125, 150);
	configText.CentrarTexto(Objetos[2], 225, -150);
	configText.CentrarTexto(Objetos[3], 225, 150);
	//Klostermon Sel 

	configText.ConfigurarTexto(k_slot[0], fuenteCombate, "Klos1", 20, Color::Green, Color::Transparent, 2.0f);
	configText.ConfigurarTexto(k_slot[1], fuenteCombate, "Klos2", 20, Color::Green, Color::Transparent, 2.0f);
	configText.ConfigurarTexto(k_slot[2], fuenteCombate, "Klos2", 20, Color::Green, Color::Transparent, 2.0f);
	configText.CentrarTexto(k_slot[0], 200, -150);
	configText.CentrarTexto(k_slot[1], 200, 0);
	configText.CentrarTexto(k_slot[2], 200, 150);
}


void Combate::Draw(RenderWindow& window)
{
	window.draw(fondo);
	window.draw(contenedorSprite);

	window.draw(sombraAliada);
	window.draw(sombraEnemiga);
	window.draw(sombraEstadio);

	window.draw(microEstadio);

	window.draw(klostermon_ally_hp);
	window.draw(klostermon_enemy_hp);

	window.draw(klostermonEnemigo);
	window.draw(klostermonAliado);
	if (interfaz == TEXTO)
	{
		window.draw(textoBatalla); 
	}
	else if (interfaz == SELECCION)
	{
		window.draw(Elige);
		window.draw(ObjetoSelect);
		window.draw(AtacarSelect);
		window.draw(CambiarSelect);
	}
	else if (interfaz == ATAQUE)
	{
		window.draw(AtaqueEspecial);
		window.draw(AtaquePesado);
	}
	else if (interfaz == OBJETO)
	{
		for (int i = 0;i < 4;i++)
		{
			window.draw(Objetos[i]);
		}
	}
	else if (interfaz == KLOS_SEL)
	{
		for (int i = 0;i < 3;i++)
		{
			window.draw(k_slot[i]);
		}
	}
}

void Combate::IniciarCombate(String combateText)
{
	interfaz = TEXTO;
	DividirTexto(combateText,stringPartes);
	parteActual = 0;
	textoBatalla.setString(stringPartes[0]);
}

void Combate::DividirTexto(const String& string, String partes[])
{

	for (int i = 0; i < 15;i++)
	{
		partes[i] = "";
	}

	size_t inicio = 0;
	size_t pos = 0;
	partesEncontradas = 0;
	while ((pos = string.find("/", inicio)) != String::InvalidPos)
	{
		if (string.substring(inicio, pos - inicio) != "/"|| string.substring(inicio, pos - inicio)!=" /")
		{
			partes[partesEncontradas++] = string.substring(inicio, pos - inicio);
			inicio = pos + 1;
		}
	}

	if (inicio < string.getSize())
	{
		partes[partesEncontradas++] = string.substring(inicio);
	}

}

void Combate::avanzarDialogo()
{
	parteActual++;
	if (parteActual < partesEncontradas)
	{
		textoBatalla.setString(stringPartes[parteActual]);
	}
	else 
	{
		interfaz = SELECCION;
		parteActual = 0;
		std::cerr << "Fin del texto" << endl;
	}
}

void Combate::ChangeSeleccion(int num)
{
	if (num == 0)
	{
		AtacarSelect.setFillColor(Color::Red);
		ObjetoSelect.setFillColor(Color::Green);
		CambiarSelect.setFillColor(Color::Green);
	}
	else if(num == 1)
	{
		ObjetoSelect.setFillColor(Color::Red);
		AtacarSelect.setFillColor(Color::Green);
		CambiarSelect.setFillColor(Color::Green);
	}
	else if (num == 2)
	{
		CambiarSelect.setFillColor(Color::Red);
		ObjetoSelect.setFillColor(Color::Green);
		AtacarSelect.setFillColor(Color::Green);
	}
}

void Combate::ChangeAtaque(bool pesado)
{
	if (pesado)
	{
		AtaquePesado.setFillColor(Color::Red);
		AtaqueEspecial.setFillColor(Color::Green);
	}else
	{
		AtaqueEspecial.setFillColor(Color::Red);
		AtaquePesado.setFillColor(Color::Green);
	}
}

void Combate::ChangeObjeto(int sel)
{
	for (int i = 0;i < 4;i++)
	{
		Objetos[i].setFillColor(Color::Green);
	}
	Objetos[sel].setFillColor(Color::Red);
}

void Combate::ChangeKlostermon(int sel)
{
	for (int i = 0;i < 3; i++)
	{
		k_slot[i].setOutlineColor(Color::Transparent);
	}
	k_slot[sel].setOutlineColor(Color::Yellow);
}

void Combate::MostrarTexto(String texto)
{
	DividirTexto(texto, stringPartes);
	parteActual = 0;
	textoBatalla.setString(stringPartes[0]);
}

void Combate::setNombreAtaques(String pesado, String especial)
{
	AtaquePesado.setString(pesado);
	AtaqueEspecial.setString(especial);
	configText.CentrarTexto(AtaqueEspecial, 250, 150);
	configText.CentrarTexto(AtaquePesado, 250, -150);
}

void Combate::setNombreObjetos(String nombreObj, int pos)
{
	configText.ConfigurarTexto(Objetos[pos], fuenteCombate,nombreObj, 20, Color::Green);
	//Centramos para que quede bien
	configText.CentrarTexto(Objetos[0], 125, -150);
	configText.CentrarTexto(Objetos[1], 125, 150);
	configText.CentrarTexto(Objetos[2], 225, -150);
	configText.CentrarTexto(Objetos[3], 225, 150);
}

void Combate::setKlostermonNames(String k1, String k2, String k3)
{
	k_slot[0].setString(k1);
	k_slot[1].setString(k2);
	k_slot[2].setString(k3);

	configText.CentrarTexto(k_slot[0], 200, -150);
	configText.CentrarTexto(k_slot[1], 200, 0);
	configText.CentrarTexto(k_slot[2], 200, 150);
}

void Combate::setKlostermonApagado(int pos)
{
	k_slot[pos].setFillColor(Color::Red);
}

void Combate::setTexture_K_Ally(String path)
{
	if (!klostermonA.loadFromFile(path))
	{
		std::cerr << "Error al cargar la textura desde el path" << path.toAnsiString()<<endl;
	}else
	klostermonAliado.setTexture(klostermonA);
}

void Combate::setTexture_K_Enemy(String path)
{
	klostermonE.loadFromFile(path);
	klostermonEnemigo.setTexture(klostermonE);
}

void Combate::changeHPText(int pla, int ene)
{
	klostermon_ally_hp.setString(to_string(pla));
	klostermon_enemy_hp.setString(to_string(ene));

	configText.CentrarTexto(klostermon_ally_hp,-215,-245);
	configText.CentrarTexto(klostermon_enemy_hp,-215,245);

}

void Combate::changeHPEnemy(int vida)
{
	klostermon_enemy_hp.setString(to_string(vida));
	configText.CentrarTexto(klostermon_enemy_hp, -215, 245);
}

void Combate::changeHPPlayer(int vida)
{
	klostermon_ally_hp.setString(to_string(vida));
	configText.CentrarTexto(klostermon_ally_hp, -215, -245);
}




