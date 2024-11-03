#include "Gameplay.h"

void Gameplay::initKlostermons()
{
	//Se carga el jugador y sus klostermones (para que estos no se modifiquen fuera de la batalla
	partidaTermino = false;
	int pos;
	pos = gameplayManager.getSaveSlot();
	player = archivo.leerArchivo(pos);

	for (int i = 0; i < 3;i++)
	{
		playerKlos[i] = player.getKlostermon(i);

		playerKlos[i].setVida(playerKlos[i].getMaxVida());

		enemyKlos[i] = enemigo.randomKlostermonSetter();

		enemyKlos[i].setVida(enemyKlos[i].getMaxVida());

		cout << "Klostermon enemigo num " << i + 1 << " : " << enemyKlos[i].getNameKlostermon().toAnsiString()<<endl;
		cout << "Klostermon jugador num " << i + 1 << " : " << playerKlos[i].getNameKlostermon().toAnsiString() << endl;
	}
	for (int i = 0;i < 4;i++)
	{
		//cargo los items
		objeto[i] = Objeto::cargarObjeto(player.getObjeto(i));
		String nombreObj;
		if (objeto[i])
		{
			nombreObj = objeto[i]->getNombre();
		}
		else { nombreObj = "Vacio"; }
		combate.setNombreObjetos(nombreObj,i);
	}
	combate.setKlostermonNames(playerKlos[0].getNameKlostermon(), playerKlos[1].getNameKlostermon(), playerKlos[2].getNameKlostermon());
}

void Gameplay::Update()
{
	UpdateEstado();
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
	if (player.getAnio() == 2024 && player.getEnfrentamiento() == 3)
	{
		enemigo.forceName("Klostr");
	}

	sceneManager.sceneLoaded();
	
	String stringCombate;
	if (player.getEnfrentamiento() == 1 && player.getAnio() == 2024)
	{
		stringCombate = ">>Aqui comienza tu aventura.../Tu primer torneo Klostermon!/";
	}
	else if (player.getEnfrentamiento() == 1)
	{
		stringCombate = ">>Empieza el torneo Klostermon de " + to_string(player.getAnio()) + "./" + "Haz lo posible para ganarlo!/";
	}
	else if (player.getEnfrentamiento() == 3 && player.getAnio() == 2024)
	{
		stringCombate = ">>Estas en la final.../Sientes los nervios.../Te toca enfretarte contra el inventor\nde los Klostermones./Klosterman!/";
		musica.playMusic("Sounds/combatefinal.ogg");
	}
	else if (player.getEnfrentamiento() == 3)
	{
		stringCombate = ">>Estas en la final.../Otra vez.../No dejes que la victoria escape de tus manos!/";
		musica.playMusic("Sounds/combatefinal.ogg");
	}

	stringCombate = stringCombate + ">> Comienza el combate!/>> " 
		+ player.getName() + " saca a " + playerKlos[0].getNameKlostermon() + "!/"
		+ ">> " + enemigo.getName() + " saca a " + enemyKlos[0].getNameKlostermon() + "!";
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
	//Carga la textura del klostermon
	combate.setTexture_K_Ally(playerKlos[0].getPathTexture());
	combate.setTexture_K_Enemy(enemyKlos[0].getPathTexture());
	//Se inicia datos(que klostermon tienen actualmente y cuantos tiene vivos
	klostermonIndexEnemy = 0;
	klostermonIndexPlayer = 0;
	klostermonRestantes_enemy = 3;
	klostermonRestantes_player = 3;
	//Se le asigna la vida al texto
	combate.changeHPText(playerKlos[0].getVida(), enemyKlos[0].getVida());
	//carga los nombres de ataque del klostermon
	combate.setNombreAtaques(playerKlos[0].ataquePesado.getNombre(), playerKlos[0].ataqueEspecial.getNombre());

}

void Gameplay::UpdateSeleccion()
{

	if (partidaTermino)
	{
		sceneManager.setScene(2);
	}

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
			Atacar(playerKlos[klostermonIndexPlayer].ataquePesado);
			//AvanzarTurno(playerKlos[klostermonIndexPlayer].ataquePesado.utilizarAtaque(enemyKlos[klostermonIndexEnemy], playerKlos[klostermonIndexPlayer]));
		}//Manda cual es el string del ataque
		else
		{
			Atacar(playerKlos[klostermonIndexPlayer].ataqueEspecial);
			//AvanzarTurno(playerKlos[klostermonIndexPlayer].ataqueEspecial.utilizarAtaque(enemyKlos[klostermonIndexEnemy], playerKlos[klostermonIndexPlayer]));
		}//Manda cual es el string del ataque

		frameCooldown = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		combate.interfaz = combate.SELECCION;
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
		if (playerKlos[k_sel_int].getVida() <= 0) { return; }
		if (k_sel_int == klostermonIndexPlayer) { return; }
		string nombreAnterior = playerKlos[klostermonIndexPlayer].getNameKlostermon();
		klostermonIndexPlayer = k_sel_int;
		//actualiza la vida
		combate.changeHPText(playerKlos[klostermonIndexPlayer].getVida(), enemyKlos[klostermonIndexEnemy].getVida());
		//carga los nombres de ataque del klostermon
		combate.setNombreAtaques(playerKlos[klostermonIndexPlayer].ataquePesado.getNombre(), playerKlos[klostermonIndexPlayer].ataqueEspecial.getNombre());
		//cambia la textura
		combate.setTexture_K_Ally(playerKlos[klostermonIndexPlayer].getPathTexture());
		frameCooldown = 0;
		AvanzarTurno(player.getName() + " guarda a " + nombreAnterior 
			+ "!/" + playerKlos[klostermonIndexPlayer].getNameKlostermon() + " entra al combate!");
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		combate.interfaz = combate.SELECCION;
	}
}

void Gameplay::UpdateEstado()
{
	if (textoIndex != combate.parteActual)
	{
		avanzoTexto();
		textoIndex = combate.parteActual;
	}
}

void Gameplay::avanzoTexto()
{
	if (playerMoreFast)
	{
		switch (textoIndex)
		{
		case 0:
			if (k_player_attack) {
				combate.changeHPEnemy(vidaEnemy);
			}
			break;
		case 1:
			if (k_enemy_died) {
				combate.setTexture_K_Enemy("Sprites/transparente.png");
			}
			break;
		case 2:
			if (k_enemy_died && !k_player_won) {
				combate.setTexture_K_Enemy(enemyKlos[klostermonIndexEnemy].getPathTexture());
				combate.changeHPEnemy(enemyKlos[klostermonIndexEnemy].getVida());
				k_enemy_died = false;
			}
			else if (k_enemy_attack)
			{
				combate.changeHPPlayer(vidaPlayer);
			}
			break;
		case 3:
			if (k_player_died)
			{
				combate.setTexture_K_Ally("Sprites/transparente.png");
			}
			break;
		case 4:
			if (k_player_died && !k_enemy_won)
			{
				combate.setTexture_K_Ally(playerKlos[klostermonIndexPlayer].getPathTexture());
				combate.changeHPPlayer(playerKlos[klostermonIndexPlayer].getVida());
				k_player_died = false;
			}
		break;
		default:
			break;
		}
	}
	else
	{
		switch (textoIndex)
		{
		case 0:
			if (k_enemy_attack)
			{
				combate.changeHPPlayer(vidaPlayer);
			}
			break;
		case 1:
			if (k_player_died)
			{
				combate.setTexture_K_Ally("Sprites/transparente.png");
			}
			break;
		case 2:
			if (k_player_died && !k_enemy_won)
			{
				combate.setTexture_K_Ally(playerKlos[klostermonIndexPlayer].getPathTexture());
				combate.changeHPPlayer(playerKlos[klostermonIndexPlayer].getVida());
				k_player_died = false;
			}
			else if(k_player_attack)
			{
				combate.changeHPEnemy(vidaEnemy);
			}
			break;
		case 3:
			if (k_enemy_died) {
				combate.setTexture_K_Enemy("Sprites/transparente.png");
			}
			break;
		case 4:
			if (k_enemy_died && !k_player_won) {
				combate.setTexture_K_Enemy(enemyKlos[klostermonIndexEnemy].getPathTexture());
				combate.changeHPEnemy(enemyKlos[klostermonIndexEnemy].getVida());
				k_enemy_died = false;
			}
			break;
		}
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
		if (!objeto[seleccionObj]) { return; }
		combate.interfaz = combate.TEXTO;
		
		AvanzarTurno(objeto[seleccionObj]->usarObjeto(playerKlos[klostermonIndexPlayer],enemyKlos[klostermonIndexEnemy]));
		objeto[seleccionObj] = nullptr;
		combate.setNombreObjetos("Vacio", seleccionObj);
		player.setObjeto(0, seleccionObj);

		seleccionObj = 0;
		combate.ChangeObjeto(seleccionObj);

		frameCooldown = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		combate.interfaz = combate.SELECCION;
	}
}

void Gameplay::Atacar(Ataque ataqueUsado)
{
	if (playerKlos[klostermonIndexPlayer].getVelocidad() >= enemyKlos[klostermonIndexEnemy].getVelocidad())
	{
		//ataca primero
		playerMoreFast = true;
		String ataquePlayer = ataqueUsado.utilizarAtaque(enemyKlos[klostermonIndexEnemy], playerKlos[klostermonIndexPlayer]);
		String ataqueEnemy;
		vidaEnemy = enemyKlos[klostermonIndexEnemy].getVida();
		k_player_attack = true;
		//Si muere el klostermon enemigo
		if (enemyKlostermonDie(ataqueEnemy, ataquePlayer)) { return; }
		
		ataqueEnemy = enemyKlos[klostermonIndexEnemy].ataquePesado.utilizarAtaque(playerKlos[klostermonIndexPlayer], enemyKlos[klostermonIndexEnemy]);
		
		vidaPlayer = playerKlos[klostermonIndexPlayer].getVida();
		k_enemy_attack = true;
		//Si muere el klostermon del jugador
		if (playerKlostermonDie(ataqueEnemy, ataquePlayer)) { return; }

		//Si no muere ninguno de los dos
		
		combate.interfaz = combate.TEXTO;
		combate.MostrarTexto(ataquePlayer + "/" + ataqueEnemy);
		//combate.changeHPText(playerKlos[klostermonIndexPlayer].getVida(), enemyKlos[klostermonIndexEnemy].getVida());
		return;
	}	
	else
	{
		playerMoreFast = false;
		String ataqueEnemy = enemyKlos[klostermonIndexEnemy].ataquePesado.utilizarAtaque(playerKlos[klostermonIndexPlayer], enemyKlos[klostermonIndexEnemy]);
		String ataquePlayer = "";
		vidaPlayer = playerKlos[klostermonIndexPlayer].getVida();
		k_enemy_attack = true;
		//SI MUERE EL KLOSTERMON DEL JUGADOR
		if (playerKlostermonDie(ataqueEnemy, ataquePlayer)) { return; }

		ataquePlayer = ataqueUsado.utilizarAtaque(enemyKlos[klostermonIndexEnemy], playerKlos[klostermonIndexPlayer]);
		vidaEnemy = enemyKlos[klostermonIndexEnemy].getVida();
		k_player_attack = true;
		//Si muere el klostermon del enemigo
		if (enemyKlostermonDie(ataqueEnemy, ataquePlayer)) { return; }
		//si no muere ninguno

		combate.interfaz = combate.TEXTO;
		combate.MostrarTexto(ataqueEnemy + "/" + ataquePlayer);
		combate.changeHPText(playerKlos[klostermonIndexPlayer].getVida(), enemyKlos[klostermonIndexEnemy].getVida());
		return;
	}
}

bool Gameplay::playerKlostermonDie(String& ataqueEnemy, String& ataquePlayer)
{
	if (playerKlos[klostermonIndexPlayer].getVida() <= 0)//Si muere mi klostermon
	{
		ataqueEnemy = ataqueEnemy + "/" + playerKlos[klostermonIndexPlayer].getNameKlostermon() + " se apago!/";
		klostermonRestantes_player--;
		combate.setKlostermonApagado(klostermonIndexPlayer);

		if (klostermonRestantes_player <= 0)//Si el enemigo gana
		{
			k_player_died = true;
			k_enemy_won = true;
			//combate.setTexture_K_Ally("Sprites/transparente.png");//ImagenVacia
			//combate.changeHPText(0, enemyKlos[klostermonIndexEnemy].getVida());

			ataqueEnemy = ataqueEnemy + enemigo.getName() + " gana la partida!/"
				+ "Le das 10 UTs.../Aca termina la aventura de este\ncuatrimestre...";

			player.setAnio(player.getAnio() + 1);
			player.setEnfrentamientoNum(1);
			player.setMoney(player.getMoney() - 10);
			archivo.sobreEscribir(gameplayManager.getSaveSlot(), player);
			//Se muestra el texto
			combate.interfaz = combate.TEXTO;
			combate.MostrarTexto(ataquePlayer + "/" + ataqueEnemy);
			partidaTermino = true;
			return true;
		}
		else //Si me quedan klostermones
		{
			k_player_died = true;
			for (int i = 0; i < 3;i++)
			{
				if (playerKlos[i].getVida() > 0)
				{
					klostermonIndexPlayer = i;//Se le asigna al primero klostermon con vida
					i = 3;
				}
			}
			//combate.setTexture_K_Ally(playerKlos[klostermonIndexPlayer].getPathTexture());
			//combate.changeHPText(playerKlos[klostermonIndexPlayer].getVida(), enemyKlos[klostermonIndexEnemy].getVida());
			combate.setNombreAtaques(playerKlos[klostermonIndexPlayer].ataquePesado.getNombre(), playerKlos[klostermonIndexPlayer].ataqueEspecial.getNombre());
			ataqueEnemy = ataqueEnemy + player.getName() + " saca a " + playerKlos[klostermonIndexPlayer].getNameKlostermon() + "!";

			combate.interfaz = combate.TEXTO;
			combate.MostrarTexto(ataquePlayer + "/" + ataqueEnemy);
			return true;
		}
	}
	else { return false; }
}

bool Gameplay::enemyKlostermonDie(String& ataqueEnemy, String ataquePlayer)
{
	if (enemyKlos[klostermonIndexEnemy].getVida() <= 0)//Si muere el klostermon enemigo
	{
		ataqueEnemy = enemyKlos[klostermonIndexEnemy].getNameKlostermon() + " se apago!/";
		klostermonRestantes_enemy--;
		if (klostermonRestantes_enemy <= 0)//SI GANA
		{
			k_enemy_died = true;
			k_player_won = true;
			//combate.setTexture_K_Enemy("Sprites/transparente.png");//ImagenVacia
			//combate.changeHPText(playerKlos[klostermonIndexPlayer].getVida(), 0);


			ataqueEnemy = ataqueEnemy + player.getName() + " gana la partida!/";
			int dineroGanado = rand() % (70 + 1 - 15) + 15;
			ataqueEnemy = ataqueEnemy + "Ganaste " + to_string(dineroGanado) + "UTs!/" +
				"Tus klostermones suben sus estadisticas!";
			player.setEnfrentamientoNum(player.getEnfrentamiento() + 1);//Avanzamos un puesto
			//SE VERIFICA SI ES EL ULTIMO COMBATE DEL AÑO (3), SI ES SE ENTREGA MAS DINERO
			if (player.getEnfrentamiento() == 3)
			{
				ataqueEnemy = ataqueEnemy + "/Eres el campeon del \ntorneo klostermon " + to_string(player.getAnio()) + "!/"
					+ "Obtienes 100Uts extra!\n Te serviran para el siguente torneo!";
				player.setMoney(player.getMoney() + 100);
				player.setAnio(player.getAnio() + 1);
				player.setEnfrentamientoNum(1);
			}
			else { player.setEnfrentamientoNum(player.getEnfrentamiento() + 1); }//Avanzamos un puesto}
			player.setMoney(player.getMoney() + dineroGanado);
			for (int i = 0; i < 3;i++)
			{
				Klostermon mejorado;
				for (int ii = 0; ii < 8;ii++)
				{
					if (archivoKlostermon.leerArchivo(ii).getNameKlostermon() == playerKlos[i].getNameKlostermon())
					{//Busca al klostermon por nombre y lo modifica para que tenga la stats mejoradas.
						mejorado = archivoKlostermon.leerArchivo(ii);
						mejorado.setMaxVida(playerKlos[i].getMaxVida() + 4);
						mejorado.setMultiplicador(playerKlos[i].getMultiplicador() + 0.1f);
					}
				}
				player.SetKlostermon(mejorado,i);//Setea el klostermon
			}
			//Guarda
			archivo.sobreEscribir(gameplayManager.getSaveSlot(), player);
			//Se muestra el texto
			combate.interfaz = combate.TEXTO;
			combate.MostrarTexto(ataquePlayer + "/" + ataqueEnemy);
			partidaTermino = true;
			return true;
		}
		else//Si le quedan klostermones
		{
			k_enemy_died = true;
			vidaEnemy = enemyKlos[klostermonIndexEnemy].getVida();
			klostermonIndexEnemy++;//Utiliza el siguente klostermon
			//combate.setTexture_K_Enemy(enemyKlos[klostermonIndexEnemy].getPathTexture());
			//combate.changeHPText(playerKlos[klostermonIndexPlayer].getVida(), enemyKlos[klostermonIndexEnemy].getVida());

			ataqueEnemy = ataqueEnemy + enemigo.getName() + " saca a " + enemyKlos[klostermonIndexEnemy].getNameKlostermon() + "!";
			combate.interfaz = combate.TEXTO;
			combate.MostrarTexto(ataquePlayer + "/" + ataqueEnemy);
			return true;
		}
	}
	else { return false; }
}

void Gameplay::AvanzarTurno(String accionString)
{
	//Se hace primero lo del jugador ya que es una accion
	playerMoreFast = true;
	k_enemy_attack = true;
	combate.interfaz = combate.TEXTO;
	combate.changeHPPlayer(playerKlos[klostermonIndexPlayer].getVida());
	//Enemy.ai() //Nos da un string (El ataque del enemigo)
	String ataqueEnemy = enemyKlos[klostermonIndexEnemy].ataquePesado.utilizarAtaque(playerKlos[klostermonIndexPlayer],enemyKlos[klostermonIndexEnemy]);
	vidaPlayer = playerKlos[klostermonIndexPlayer].getVida();
	//Si murio el klostermon
	playerKlostermonDie(ataqueEnemy, accionString);
	combate.MostrarTexto(accionString + "/" + ataqueEnemy);
}


