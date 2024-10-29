#include "Gameplay.h"

void Gameplay::initKlostermons()
{
	//Se carga el jugador y sus klostermones (para que estos no se modifiquen fuera de la batalla
	int pos;
	pos = gameplayManager.getSaveSlot();
	player = archivo.leerArchivo(pos);

	for (int i = 0; i < 3;i++)
	{
		playerKlos[i] = player.getKlostermon(i);
		enemyKlos[i] = enemigo.randomKlostermonSetter();
		cout << "Klostermon enemigo num " << i + 1 << " : " << enemyKlos[i].getNameKlostermon().toAnsiString()<<endl;
		cout << "Klostermon jugador num " << i + 1 << " : " << playerKlos[i].getNameKlostermon().toAnsiString() << endl;
	}
	combate.setKlostermonNames(playerKlos[0].getNameKlostermon(), playerKlos[1].getNameKlostermon(), playerKlos[2].getNameKlostermon());
}

void Gameplay::IniciarGameplay()
{

	String string = player.getName() + " saca un Pokemon!";
	textoCombate.setString(string);
	
	//ACA SE CONSEGUIRIA LA TEXTURA DE CADA UNO
	String path_texture_enemy = "Sprites/laras.png";
	String path_texture_aly = "Sprites/laras.png";

	enemigoTexture.loadFromFile(path_texture_enemy);
	alidadoTexture.loadFromFile(path_texture_aly);
	
	k_sprite_aliado.setTexture(alidadoTexture);
	k_sprite_enemigo.setTexture(enemigoTexture);

}

void Gameplay::Update()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		sceneManager.setScene(0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Enter) && frameCooldown > 15 && combate.interfaz == combate.TEXTO)
	{
		combate.avanzarDialogo();
		frameCooldown = 0;
	}
	if (combate.interfaz == combate.SELECCION)
	{
		UpdateSeleccion();
	}
	if (combate.interfaz == combate.ATAQUE)
	{
		UpdateAtaque();
	}
	if (combate.interfaz == combate.OBJETO)
	{
		UpdateObjetos();
	}
	if (combate.interfaz == combate.KLOS_SEL)
	{
		UpdateSelKlos();
	}
	frameCooldown++;
}

void Gameplay::Draw(RenderWindow& window)
{
	combate.Draw(window);
}

void Gameplay::loadGameplay()
{
	musica.stopMusic();
	musica.setVolumen(20);
	musica.playMusic("combate.ogg");

	frameCooldown = 0;

	initKlostermons();

	enemigo.randomNameSetter();

	sceneManager.sceneLoaded();
	String stringCombate = ">> Comienza el combate!/>> " 
		+ player.getName() + " saca a Urkos!/"
		+ ">> " + enemigo.getName() + " Saca a Laras!";
	combate.IniciarCombate(stringCombate);

	//Se inicializa para que aparezca como la primera decision default
	SelecctionMenu = 0;
	combate.ChangeSeleccion(SelecctionMenu);
	ataquePesadoSelect = true;
	combate.ChangeAtaque(ataquePesadoSelect);
	seleccionObj = 0;
	combate.ChangeObjeto(seleccionObj);
	k_sel_int = 0;
	combate.ChangeKlostermon(k_sel_int);
	//carga los nombres de ataque del klostermon
	KlostermonAliado = player.getKlostermon(2);
	combate.setTexture_K_Ally(KlostermonAliado.getPathTexture());
	combate.setNombreAtaques(KlostermonAliado.ataquePesado.getNombre(),KlostermonAliado.ataqueEspecial.getNombre());

}

void Gameplay::UpdateSeleccion()
{
	if ((Keyboard::isKeyPressed(Keyboard::Right) && frameCooldown > 25))
	{
		SelecctionMenu ++;
		if (SelecctionMenu == 3) { SelecctionMenu = 0; }
		combate.ChangeSeleccion(SelecctionMenu);
		frameCooldown = 0;
	}
	if ((Keyboard::isKeyPressed(Keyboard::Left) && frameCooldown > 25))
	{
		SelecctionMenu--;
		if (SelecctionMenu == -1) { SelecctionMenu = 2; }
		combate.ChangeSeleccion(SelecctionMenu);
		frameCooldown = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Enter) && frameCooldown > 25)
	{
		if (SelecctionMenu == 0)
		{
			combate.interfaz = combate.ATAQUE;
		}
		else if(SelecctionMenu == 1)
		{
			combate.interfaz = combate.OBJETO;
			std::cerr << "Se selecciono Objeto" << endl;
		}
		else if (SelecctionMenu == 2)
		{
			combate.interfaz = combate.KLOS_SEL;
		}
		
		frameCooldown = 0;
	}

}

void Gameplay::UpdateAtaque()
{
	if ((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::Right)) && frameCooldown > 25)
	{
		ataquePesadoSelect = !ataquePesadoSelect;
		combate.ChangeAtaque(ataquePesadoSelect);
		frameCooldown = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Enter) && frameCooldown > 25)
	{
		if (ataquePesadoSelect)
		{
			combate.interfaz = combate.TEXTO;
			Atacar("Urkos usa ataque pesado!/Es superefectivo!");
		}
		else
		{
			combate.interfaz = combate.TEXTO;
			combate.MostrarTexto("Urkos usa ataque especial!/Ahora Laras tiene mas chance de fallar!");
		}

		frameCooldown = 0;
	}
}

void Gameplay::UpdateSelKlos()
{
	if ((Keyboard::isKeyPressed(Keyboard::Right) && frameCooldown > 25))
	{
		k_sel_int++;
		if (k_sel_int == 3) { k_sel_int = 0; }
		combate.ChangeKlostermon(k_sel_int);
		frameCooldown = 0;
	}
	if ((Keyboard::isKeyPressed(Keyboard::Left) && frameCooldown > 25))
	{
		k_sel_int--;
		if (k_sel_int == -1) { k_sel_int = 2; }
		combate.ChangeKlostermon(k_sel_int);
		frameCooldown = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Enter) && frameCooldown > 25)
	{
		frameCooldown = 0;
	}
}

void Gameplay::UpdateObjetos()
{
	if (Keyboard::isKeyPressed(Keyboard::Left) && frameCooldown > 25)
	{
		if (seleccionObj == 0)
		{
			seleccionObj = 1;
		}
		else if(seleccionObj == 2)
		{
			seleccionObj = 3;
		}
		else
		{
			seleccionObj -= 1;
		}
		combate.ChangeObjeto(seleccionObj);
		frameCooldown = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right) && frameCooldown > 25)
	{
		if (seleccionObj == 1)
		{
			seleccionObj = 0;
		}
		else if (seleccionObj == 3)
		{
			seleccionObj = 0;
		}
		else
		{
			seleccionObj += 1;
		}
		combate.ChangeObjeto(seleccionObj);
		frameCooldown = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down) && frameCooldown > 25)
	{
		if((seleccionObj + 2) <= 3){ seleccionObj += 2; }else seleccionObj -= 2; 
		frameCooldown = 0;
		combate.ChangeObjeto(seleccionObj);
	}
	if (Keyboard::isKeyPressed(Keyboard::Up) && frameCooldown > 25)
	{
		if ((seleccionObj - 2) >= 0) { seleccionObj -= 2; }
		else seleccionObj += 2;
		frameCooldown = 0;
		combate.ChangeObjeto(seleccionObj);
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Enter) && frameCooldown > 25)
	{
		combate.interfaz = combate.TEXTO;
		switch (seleccionObj)
		{
		case 0:
			combate.MostrarTexto("Se utilizo objeto 1!/Perfecto!");
			break;
		case 1:
			combate.MostrarTexto("Se utilizo objeto 2!/Genial!");
			break;
		case 2:
			combate.MostrarTexto("Se utilizo objeto 3!/God!");
			break;
		case 3:
			combate.MostrarTexto("Se utilizo objeto 4!/Epico!");
			break;
		}
		frameCooldown = 0;
	}
}


void Gameplay::Atacar(String ataqueString)
{
	//Se verifica quien tiene mas velocidad
	if (true)
	{
		combate.interfaz = combate.TEXTO;
		//Enemy.ai() //Nos da un string
		String ataqueEnemigo = "Laras usa ataque pesado!/Fallo!";
		combate.MostrarTexto(ataqueString + "/" + ataqueEnemigo);
	}
}


