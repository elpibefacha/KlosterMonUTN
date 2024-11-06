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

		//enemyKlos[i] = archivoKlostermon.leerArchivo(5);

		//se mejora al enemigo dependiendo de los combates ganados
		enemyKlos[i].setMaxVida(enemyKlos[i].getMaxVida() + (rand() % (3 + 1 - 6) + 3)*player.getEnfrentamientosGanados());

		enemyKlos[i].setMultiplicador(enemyKlos[i].getMultiplicador() + 0.4*float(player.getEnfrentamientosGanados()));

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
	UpdateAnimaciones(); 
	UpdateEstado();
	if (Keyboard::isKeyPressed(Keyboard::Enter) && frameCooldown > 15 && combate.interfaz == combate.TEXTO && tiempoAnimacion.asSeconds() > 2)
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
	if (tiempoAnimacion.asSeconds() <= 2) {
		combate.efectos.Draw(window);
	} 
}

void Gameplay::loadGameplay()
{
	// Load Sounds
	damageBuffer.loadFromFile("Sounds/danio.ogg");
	damageSound.setBuffer(damageBuffer); 
	damageSound.setVolume(50); 
	explosionBuffer.loadFromFile("Sounds/explosion.ogg");
	explosionSound.setBuffer(explosionBuffer);
	explosionSound.setVolume(60); 
	mejoraBuffer.loadFromFile("Sounds/mejora.ogg");
	mejoraSound.setBuffer(mejoraBuffer);
	mejoraSound.setVolume(50);
	decadenciaBuffer.loadFromFile("Sounds/decadencia.ogg");
	decadenciaSound.setBuffer(decadenciaBuffer);
	decadenciaSound.setVolume(25);
	muerteBuffer.loadFromFile("Sounds/muerte.ogg");
	muerteSound.setBuffer(muerteBuffer);
	muerteSound.setVolume(40);
	// Musica
	musica.stopMusic();
	musica.setVolumen(20);
	musica.playMusic("combate.ogg");

	frameCooldown = 0;
	combate.CargarInterfaz();

	initKlostermons();

	enemigo.randomNameSetter();
	if (player.getEnfrentamiento() == 4)
	{
		musica.setVolumen(40);
		musica.playMusic("Sounds/combatefinal.ogg");
		enemigo.forceName("Klost");
		enemyKlos[0] = archivoKlostermon.leerArchivo(2);
		enemyKlos[0].setMaxVida(150);
		enemyKlos[0].setVida(enemyKlos[0].getMaxVida());
		enemyKlos[0].setMultiplicador(2.0f);

		enemyKlos[1] = archivoKlostermon.leerArchivo(3);
		enemyKlos[1].setMaxVida(200);
		enemyKlos[1].setVida(enemyKlos[1].getMaxVida());
		enemyKlos[1].setMultiplicador(2.0f);

		enemyKlos[2] = archivoKlostermon.leerArchivo(0);
		enemyKlos[2].setMaxVida(100);
		enemyKlos[2].setVida(enemyKlos[2].getMaxVida());
		enemyKlos[2].setMultiplicador(2.0f);
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
	else if (player.getEnfrentamiento() == 3)
	{
		stringCombate = ">>Estas en la final.../No dejes que la victoria\n se escape de tus manos!/";
	}
	else if (player.getEnfrentamiento() == 4)
	{
		stringCombate = ">>Eres el campeón.../Te toca enfretarte contra el inventor\nde los Klostermones./Klosterman!/";
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
	//Inicia bools de estado
    k_player_attack = false;
	k_enemy_attack = false;
	k_enemy_died = false;
	k_player_died = false;
	k_enemy_won = false;
	k_player_won = false;
	playerMoreFast = false;
	// bools de animaciones
	k_player_mejora = false;
	k_enemy_decadencia = false;
	k_enemy_danio = false;
	k_player_danio = false;
	k_danio_propio = false;
	iniciarAMejora = false;
	iniciarADecadencia = false;
	iniciarADanio_E = false;
	iniciarADanio_P = false;
	iniciarAExplosion = false;
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

void Gameplay::UpdateAnimaciones()
{
	tiempoAnimacion = clockAnimacion.getElapsedTime();
	if (iniciarAExplosion && tiempoAnimacion.asSeconds() < 3)
	{
		combate.efectos.UpdateFX();
		combate.klostermonEnemigo.setColor(Color::Red);
	}
	else if (iniciarAExplosion && tiempoAnimacion.asSeconds() >= 3)
	{
		combate.klostermonEnemigo.setColor(Color::White);
		iniciarAExplosion = false;
	}
	if (iniciarAMejora && tiempoAnimacion.asSeconds() < 2) {

		combate.efectos.UpdateFX();
	}
	else if (iniciarAMejora && tiempoAnimacion.asSeconds() >= 2) {

		iniciarAMejora = false;
	}
	if (iniciarADecadencia && tiempoAnimacion.asSeconds() < 2) {
		combate.efectos.UpdateFX();
	}
	else if (iniciarADecadencia && tiempoAnimacion.asSeconds() >= 2) {

		iniciarADecadencia= false;
	} 
	if (iniciarADanio_E && tiempoAnimacion.asSeconds() < 2) {
		combate.efectos.UpdateFX(); 
		combate.klostermonEnemigo.setColor(Color::Red); 
	}
	else if (iniciarADanio_E && tiempoAnimacion.asSeconds() >= 2) {
		iniciarADanio_E = false;
		combate.klostermonEnemigo.setColor(Color::White);
	}
	if (iniciarADanio_P && tiempoAnimacion.asSeconds() < 2) {
		combate.efectos.UpdateFX(); 
		combate.klostermonAliado.setColor(Color::Red); 
	}
	else if (iniciarADanio_P && tiempoAnimacion.asSeconds() >= 2) {
		iniciarADanio_P = false;
		combate.klostermonAliado.setColor(Color::White);
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
			if (k_player_mejora) {
				mejoraSound.play();
				combate.efectos.changeFX(1);
				combate.efectos.setPosition(60+17*6, 110+17*6);
				iniciarAMejora = true; 
				clockAnimacion.restart();
				k_player_mejora = false; 
			}
			if (k_enemy_decadencia) {
				decadenciaSound.play(); 
				combate.efectos.changeFX(2);
				combate.efectos.setPosition(550+17*6, 110+17*6);
				iniciarADecadencia = true; 
				clockAnimacion.restart();
				k_enemy_decadencia = false; 
			}
			if (k_enemy_danio) {
				damageSound.play(); 
				combate.efectos.changeFX(0);
				combate.efectos.setPosition(550+17*6, 110+17*6);
				iniciarADanio_E = true;
				clockAnimacion.restart();
				k_enemy_danio = false; 
			}
			if (k_danio_propio)
			{
				explosionSound.play();
				combate.efectos.changeFX(3);
				combate.efectos.setPosition(60 + 17 * 6, 110 + 17 * 6);
				iniciarAExplosion = true;
				clockAnimacion.restart();
				k_danio_propio = false;
			}
			break;
		case 1:
			if (k_enemy_died) {
				muerteSound.play(); 
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
			if (k_player_danio) {
				damageSound.play();
				combate.efectos.changeFX(0);
				combate.efectos.setPosition(60+17*6, 110+17*6);
				combate.efectos.mirror();
				iniciarADanio_P = true; 
				clockAnimacion.restart();
				k_player_danio = false; 
			}
			break;
		case 3:
			if (k_player_died)
			{
				muerteSound.play(); 
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
			if (k_player_danio) {
				damageSound.play();
				combate.efectos.changeFX(0);
				combate.efectos.setPosition(60 + 17 * 6, 110 + 17 * 6);
				combate.efectos.mirror();
				iniciarADanio_P = true;
				clockAnimacion.restart();
				k_player_danio = false;
			}
			break;
		case 1:
			if (k_player_died)
			{
				muerteSound.play(); 
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
				combate.changeHPPlayer(playerKlos[klostermonIndexPlayer].getVida());
			}
			if (k_player_mejora) {
				mejoraSound.play();
				combate.efectos.changeFX(1);
				combate.efectos.setPosition(60 + 17 * 6, 110 + 17 * 6);
				iniciarAMejora = true;
				clockAnimacion.restart();
				k_player_mejora = false;
			}
			if (k_enemy_decadencia) {
				decadenciaSound.play(); 
				combate.efectos.changeFX(2);
				combate.efectos.setPosition(550 + 17 * 6, 110 + 17 * 6);
				iniciarADecadencia = true;
				clockAnimacion.restart();
				k_enemy_decadencia = false;
			}
			if (k_enemy_danio) {
				damageSound.play();
				combate.efectos.changeFX(0);
				combate.efectos.setPosition(550 + 17 * 6, 110 + 17 * 6);
				iniciarADanio_E = true;
				clockAnimacion.restart();
				k_enemy_danio = false;
			}
			if (k_danio_propio)
			{
				explosionSound.play();
				combate.efectos.changeFX(3);
				combate.efectos.setPosition(60 + 17 * 6, 110 + 17 * 6);
				iniciarAExplosion = true;
				clockAnimacion.restart();
				k_danio_propio = false;
			}
			break;
		case 3:
			if (k_enemy_died) {
				muerteSound.play(); 
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
	if (playerKlos[klostermonIndexPlayer].getVelocidad() >= enemyKlos[klostermonIndexEnemy].getVelocidad() || ataqueUsado.getNombre() == "Explotar")
	{
		//ataca primero
		playerMoreFast = true;
		String ataquePlayer;  
		String ataqueEnemy;
		String endString;
		//Si random es menor que efectividad significa que esta dentro del rango, el ataque se efectua
		int random = rand() % 101;
		if ( random < playerKlos[klostermonIndexPlayer].getEfectividad() )
		{
			ataquePlayer = ataqueUsado.utilizarAtaque(enemyKlos[klostermonIndexEnemy], playerKlos[klostermonIndexPlayer]);
			combate.changeHPPlayer(playerKlos[klostermonIndexPlayer].getVida());
			k_player_attack = true;
			detectarTipoAnimacion(ataqueUsado, false);
			if (playerKlos[klostermonIndexPlayer].getVida() <= 0)//Si el jugador muere lo sumo al string de endString
			{
				endString = playerKlos[klostermonIndexPlayer].getNameKlostermon() + " se apago!";
				klostermonRestantes_player--;
				combate.setKlostermonApagado(klostermonIndexPlayer);

				if (klostermonRestantes_player <= 0)//Si el enemigo gana
				{
					PerdioPartida(endString);
				}
				else //Si me quedan klostermones
				{
					QuedanKlostermones(endString);
				}
			}
			if (playerKlostermonDie(ataqueEnemy, ataquePlayer,endString)) { return; }
		}
		else
		{
			ataquePlayer = ataqueUsado.fallarAtaque(playerKlos[klostermonIndexPlayer]);
			k_player_attack = false;
		}

		vidaEnemy = enemyKlos[klostermonIndexEnemy].getVida();
		//Si muere el klostermon enemigo
		if (enemyKlostermonDie(ataqueEnemy, ataquePlayer,endString)) { return; }
		
		random = rand() % 101;
		if (random < enemyKlos[klostermonIndexEnemy].getEfectividad())
		{
			ataqueEnemy = enemyKlos[klostermonIndexEnemy].ataquePesado.utilizarAtaque(playerKlos[klostermonIndexPlayer], enemyKlos[klostermonIndexEnemy]);
			detectarTipoAnimacion(enemyKlos[klostermonIndexEnemy].ataquePesado,true);
			k_enemy_attack = true;
		}
		else
		{
			ataqueEnemy = enemyKlos[klostermonIndexEnemy].ataquePesado.fallarAtaque(enemyKlos[klostermonIndexEnemy]);
			k_enemy_attack = false;
		}
		vidaPlayer = playerKlos[klostermonIndexPlayer].getVida();
		//Si muere el klostermon del jugador
		if (playerKlostermonDie(ataqueEnemy, ataquePlayer,endString)) { return; }

		//Si no muere ninguno de los dos
		
		combate.interfaz = combate.TEXTO;
		combate.MostrarTexto(ataquePlayer + "/" + ataqueEnemy + "/" + endString);
		//combate.changeHPText(playerKlos[klostermonIndexPlayer].getVida(), enemyKlos[klostermonIndexEnemy].getVida());
		return;
	}	
	else
	{
		playerMoreFast = false;
		String ataqueEnemy;
		String ataquePlayer;
		String endString;
		int random = rand() % 101;
		if (random < enemyKlos[klostermonIndexEnemy].getEfectividad())
		{
			ataqueEnemy = enemyKlos[klostermonIndexEnemy].ataquePesado.utilizarAtaque(playerKlos[klostermonIndexPlayer], enemyKlos[klostermonIndexEnemy]);
			detectarTipoAnimacion(enemyKlos[klostermonIndexEnemy].ataquePesado,true);
			k_enemy_attack = true;
		}
		else
		{
			ataqueEnemy = enemyKlos[klostermonIndexEnemy].ataquePesado.fallarAtaque(enemyKlos[klostermonIndexEnemy]);
			k_enemy_attack = false;
		}
		vidaPlayer = playerKlos[klostermonIndexPlayer].getVida();//Se hace para saber la vida que tiene 
		//que mostrar (y no mostrar la del nuevo klostermon si es que el anterior murio
		
		//SI MUERE EL KLOSTERMON DEL JUGADOR
		if (playerKlostermonDie(ataqueEnemy, ataquePlayer,endString)) { return; }

		random = rand() % 101;
		if (random < playerKlos[klostermonIndexPlayer].getEfectividad())
		{
			ataquePlayer = ataqueUsado.utilizarAtaque(enemyKlos[klostermonIndexEnemy], playerKlos[klostermonIndexPlayer]);
			//combate.changeHPPlayer(playerKlos[klostermonIndexPlayer].getVida());
			k_player_attack = true;
			detectarTipoAnimacion(ataqueUsado, false);
			if (playerKlos[klostermonIndexPlayer].getVida() <= 0)//Si el jugador muere lo sumo al string de endString
			{
				endString = playerKlos[klostermonIndexPlayer].getNameKlostermon() + " se apago!";
				klostermonRestantes_player--;
				combate.setKlostermonApagado(klostermonIndexPlayer);

				if (klostermonRestantes_player <= 0)//Si el enemigo gana
				{
					PerdioPartida(endString);
				}
				else //Si me quedan klostermones
				{
					QuedanKlostermones(endString);
				}
			}
		}
		else
		{
			ataquePlayer = ataqueUsado.fallarAtaque(playerKlos[klostermonIndexPlayer]);
			k_player_attack = false;
		}
		vidaEnemy = enemyKlos[klostermonIndexEnemy].getVida();
		//Si muere el klostermon del enemigo
		if (enemyKlostermonDie(ataqueEnemy, ataquePlayer,endString)) { return; }
		//si no muere ninguno

		combate.interfaz = combate.TEXTO;
		combate.MostrarTexto(ataqueEnemy + "/" + ataquePlayer + "/" + endString);
		return;
	}
}

bool Gameplay::playerKlostermonDie(String& ataqueEnemy, String& ataquePlayer, String& endString)
{
	if (playerKlos[klostermonIndexPlayer].getVida() <= 0)//Si muere mi klostermon
	{

		endString = endString + playerKlos[klostermonIndexPlayer].getNameKlostermon() + " se apago!";
		klostermonRestantes_player--;
		combate.setKlostermonApagado(klostermonIndexPlayer);

		if (klostermonRestantes_player <= 0)//Si el enemigo gana
		{
			PerdioPartida(endString);
			//Se muestra el texto
			combate.interfaz = combate.TEXTO;
			if (playerMoreFast) { combate.MostrarTexto(ataquePlayer + "/" + ataqueEnemy + "/" + endString); }
			else { combate.MostrarTexto(ataqueEnemy + "/" + ataquePlayer + "/" + endString); }
			partidaTermino = true;
			return true;
		}
		else //Si me quedan klostermones
		{
			QuedanKlostermones(endString);
			combate.interfaz = combate.TEXTO;
			if (playerMoreFast) { combate.MostrarTexto(ataquePlayer + "/" + ataqueEnemy + "/" + endString); }
			else { combate.MostrarTexto(ataqueEnemy + "/" + ataquePlayer + "/" + endString); }
			return true;
		}
	}
	else { return false; }
}

bool Gameplay::enemyKlostermonDie(String& ataqueEnemy, String& ataquePlayer, String& endString)
{
	if (enemyKlos[klostermonIndexEnemy].getVida() <= 0)//Si muere el klostermon enemigo
	{
		if (playerMoreFast)
		{
			ataqueEnemy = enemyKlos[klostermonIndexEnemy].getNameKlostermon() + " se apago!";
		}
		else { endString = endString +"/" + enemyKlos[klostermonIndexEnemy].getNameKlostermon() + " se apago!"; }
		klostermonRestantes_enemy--;
		if (klostermonRestantes_enemy <= 0)//SI GANA EL JUGADOR
		{
			Enemigo_PerdioPartida(endString);
			//Se muestra el texto
			combate.interfaz = combate.TEXTO;
			if (playerMoreFast) { combate.MostrarTexto(ataquePlayer + "/" + ataqueEnemy + "/" + endString); }
			else { combate.MostrarTexto(ataqueEnemy + "/" + ataquePlayer + "/" + endString); }
			partidaTermino = true;
			return true;
		}
		else//Si le quedan klostermones
		{
			Enemigo_QuedanKlostermones(endString);
			combate.interfaz = combate.TEXTO;
			if (playerMoreFast) { combate.MostrarTexto(ataquePlayer + "/" + ataqueEnemy + "/" + endString); }
			else { combate.MostrarTexto(ataqueEnemy + "/" + ataquePlayer + "/" + endString); }
			return true;
		}
	}
	else { return false; }
}

void Gameplay::PerdioPartida(String& endString)
{
	k_player_died = true;
	k_enemy_won = true;

	if (player.getEnfrentamiento() != 4)
	{
		endString = endString + enemigo.getName() + " gana la partida!/"
			+ "Le das 10 UTs.../Aca termina la aventura de este\ncuatrimestre...";
	}
	else
	{
		endString = endString +"/" + enemigo.getName() + " gana la partida!/"
			+ "Te derroto el inventor.../Todavia no estas a su nivel.../Gana el siguente torneo y \nvuelve a enfrentarlo!";
	}
	player.setAnio(player.getAnio() + 1);
	player.setEnfrentamientoNum(1);
	player.setMoney(player.getMoney() - 10);
	archivo.sobreEscribir(gameplayManager.getSaveSlot(), player);
	for (int i = 0; i < 4;i++)
	{
		delete objeto[i];
	}
}

void Gameplay::QuedanKlostermones(String& endString)
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
	combate.setNombreAtaques(playerKlos[klostermonIndexPlayer].ataquePesado.getNombre(), playerKlos[klostermonIndexPlayer].ataqueEspecial.getNombre());
	endString = endString +"/"+ player.getName() + " saca a " + playerKlos[klostermonIndexPlayer].getNameKlostermon() + "!";
}

void Gameplay::Enemigo_PerdioPartida(String& endString)
{
	k_enemy_died = true;
	k_player_won = true;

	endString = endString +"/"+ player.getName() + " gana la partida!/";
	int dineroGanado = rand() % (70 + 1 - 15) + 15;
	endString = endString + "Ganaste " + to_string(dineroGanado) + "UTs!/" +
		"Tus klostermones suben sus estadisticas!";
	//SE VERIFICA SI ES EL ULTIMO COMBATE DEL AÑO (3), SI ES SE ENTREGA MAS DINERO
	if (player.getEnfrentamiento() == 3)
	{
		endString = endString + "/Eres el campeon del \ntorneo klostermon " + to_string(player.getAnio()) + "!/"
			+ "Obtienes 100Uts extra!\n Te serviran para el siguente torneo!";
		player.setMoney(player.getMoney() + 100);
		if (!player.completoElJuego())
		{
			player.setEnfrentamientoNum(4);
		}
		else
		{
			player.setEnfrentamientoNum(1);
			player.setAnio(player.getAnio() + 1);
		}
	}
	else if (player.getEnfrentamiento() == 4)
	{
		endString = endString + "/Lograste ganarle a KlosterMan!/Felicitaciones "
			+ player.getName(); +".../Eres el mejor entrenador Klostermon!/Obtienes 1000Uts!\n Puedes seguir participando del torneo!";
		player.setMoney(player.getMoney() + 1000);
		player.completarJuego(true);
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
		player.SetKlostermon(mejorado, i);//Setea el klostermon
	}
	//Guarda
	player.setEnfrentamientosGanados(player.getEnfrentamientosGanados() + 1);
	archivo.sobreEscribir(gameplayManager.getSaveSlot(), player);
	for (int i = 0; i < 4;i++)
	{
		delete objeto[i];
	}
}

void Gameplay::Enemigo_QuedanKlostermones(String& endString)
{
	k_enemy_died = true;
	vidaEnemy = enemyKlos[klostermonIndexEnemy].getVida();
	klostermonIndexEnemy++;//Utiliza el siguente klostermon

	endString = endString + "/" + enemigo.getName() + " saca a " + enemyKlos[klostermonIndexEnemy].getNameKlostermon() + "!";
}

void Gameplay::AvanzarTurno(String accionString)
{
	//Se hace primero lo del jugador ya que es una accion
	String endString;
	String ataqueEnemy;
	playerMoreFast = true;
	k_enemy_attack = true;
	k_player_attack = false;
	combate.interfaz = combate.TEXTO;
	combate.changeHPPlayer(playerKlos[klostermonIndexPlayer].getVida());
	//Ataca
	int random = rand() % 101;
	if (random < enemyKlos[klostermonIndexEnemy].getEfectividad())
	{
		ataqueEnemy = enemyKlos[klostermonIndexEnemy].ataquePesado.utilizarAtaque(playerKlos[klostermonIndexPlayer], enemyKlos[klostermonIndexEnemy]);
		detectarTipoAnimacion(enemyKlos[klostermonIndexEnemy].ataquePesado, true);
		k_enemy_attack = true;
	}
	else
	{
		ataqueEnemy = enemyKlos[klostermonIndexEnemy].ataquePesado.fallarAtaque(enemyKlos[klostermonIndexEnemy]);
		k_enemy_attack = false;
	}
	vidaPlayer = playerKlos[klostermonIndexPlayer].getVida();
	//Si murio el klostermon
	playerKlostermonDie(ataqueEnemy, accionString,endString);
	combate.MostrarTexto(accionString + "/" + ataqueEnemy);
}

void Gameplay::detectarTipoAnimacion(Ataque ataqueUsado, bool enemigo)
{
	//Si se hace daño propio explota
	if (ataqueUsado.getDanioPropio() > 0 && !enemigo)
	{
		k_danio_propio = true;
	}
	//Efecto visual del ataque
	else if ((ataqueUsado.getDanio() > 0) && !enemigo)//Si hace daño
	{
		k_enemy_danio = true;
	}
	else if ((ataqueUsado.getEfectividadAtaque() > 0 || ataqueUsado.getVelocidadAtaque() > 0 ||
		 ataqueUsado.getMultPropio() > 0 || ataqueUsado.getModVidaTotal() > 0 || ataqueUsado.getDanioPropio() < 0)&&!enemigo)
	{//Si se mejora a si mismo
		k_player_mejora = true;
	}
	else if ((ataqueUsado.getEfectividadEnemiga() < 0 || ataqueUsado.getMultEnemigo() < 0 || 
		ataqueUsado.getVelocidadEnemiga() < 0 || ataqueUsado.getModVidaTotalEnemiga() < 0)&&!enemigo)
	{//Si hace un ataque que afecta a stats enemigas
		k_enemy_decadencia = true;
	}
	//Si el ataque es del enemgio
	if ((ataqueUsado.getDanio() > 0) && enemigo)
	{
		k_player_danio = true;
	}
}



