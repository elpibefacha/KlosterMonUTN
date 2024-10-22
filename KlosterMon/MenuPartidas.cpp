#include "MenuPartidas.h"

void MenuPartidas::SeleccionarOpcion()
{
	switch (opcionSeleccionada)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	}
}

void MenuPartidas::ActualizarSeleccion()
{
	for (int i = 0; i < 3; i++)
	{
		textoSave[i].setFillColor(Color::Black);
		textoSave[i].setScale(1, 1);
	}
	textoSave[opcionSeleccionada].setFillColor(Color::Red);
	textoSave[opcionSeleccionada].setScale(1.2, 1.2);
}

void MenuPartidas::Subir()
{
	frameCooldown = 0;
	if (opcionSeleccionada - 1 <= -1)
	{
		opcionSeleccionada = 2;
	}
	else
	{
		opcionSeleccionada--;
	}
	ActualizarSeleccion();
}

void MenuPartidas::Bajar()
{
	frameCooldown = 0;
	if (opcionSeleccionada + 1 >= 3)
	{
		opcionSeleccionada = 0;
	}
	else
	{
		opcionSeleccionada++;
	}
	ActualizarSeleccion();
}

MenuPartidas::MenuPartidas()
{
	Iniciar();
}

void MenuPartidas::Iniciar()
{
	fuenteGuardados = configTexto.gameplayFont;
	for (int i = 0; i < 3;i++)
	{
		configTexto.ConfigurarTexto(textoSave[i],fuenteGuardados,"",25,Color::Black);
		//Se verifica si hay save
		int cant = archivoPlayer.contarRegistros();
		if (cant < i)//Por ahora asi porque no contamos con saves
		{
			textoSave[i].setString(std::to_string(i + 1) + " - Sin Datos");
		}
		else
		{
			

			player = archivoPlayer.leerArchivo(i);
			textoSave[i].setString(std::to_string(i + 1) + " - " + player.getName());
			std::cerr << "NUMERO " << i << " - " << player.getName()<<endl;
		}
	}
	configTexto.CentrarTexto(textoSave[0], - 200);
	configTexto.CentrarTexto(textoSave[1], -100);
	configTexto.CentrarTexto(textoSave[2], 0);
	//fondo 
	imageFondo.loadFromFile("Sprites/fondoMenu.jpg");
	fondoMenu.setTexture(imageFondo);
	//Importante
	frameCooldown = 15;
	opcionSeleccionada = 0;
	ActualizarSeleccion();
}

void MenuPartidas::Update()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		menuManager.setMenuID(0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Up) && frameCooldown >= 15)
	{
		Subir();
	}
	if (Keyboard::isKeyPressed(Keyboard::Down) && frameCooldown >= 15)
	{
		Bajar();
	}
	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		SeleccionarOpcion();
	}
	frameCooldown++;
}

void MenuPartidas::Draw(RenderWindow& window)
{
	window.draw(fondoMenu);
	for (int i = 0;i < 3;i++)
	{
		window.draw(textoSave[i]);
	}
}
