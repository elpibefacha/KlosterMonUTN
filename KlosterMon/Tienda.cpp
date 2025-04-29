#include "Tienda.h"

void Tienda::loadTienda()
{
	framescooldown = 0;
	musica.stopMusic();
	musica.playMusic("tienda.ogg");
	musica.setVolumen(30);
	imageCCP.loadFromFile("Sprites/codigo_curacion_p.png");
	objeto[0].setTexture(imageCCP);
	imageCCG.loadFromFile("Sprites/codigo_curacion_g.png");
	objeto[1].setTexture(imageCCG);
	imageInye.loadFromFile("Sprites/inyeccion_codigo.png");
	objeto[2].setTexture(imageInye);
	imageEstru.loadFromFile("Sprites/estructuracion.png");
	objeto[3].setTexture(imageEstru);
	imageOpti.loadFromFile("Sprites/optimizacion.png");
	objeto[4].setTexture(imageOpti);
	imageCopy.loadFromFile("Sprites/copy_paste.png");
	objeto[5].setTexture(imageCopy);
	imageCuadro.loadFromFile("Sprites/cuadro.png");
	int posicionX = 0;
	int posicionY = 0;
	for (int i = 0; i < 6; i++) {
		if (i == 0) {
			posicionX = 50;
			posicionY = 65;
		}
		else if (i == 3) {
			posicionX = 450;
			posicionY = 65;
		}
		cuadro[i].setTexture(imageCuadro);
		cuadro[i].setPosition(posicionX, posicionY);
		cuadro[i].setColor(Color::Black);
		cuadro[i].setScale(3, 3);
		objeto[i].setScale(3, 3);
		objeto[i].setPosition(posicionX, posicionY);
		posicionY += 200;
	}
	//Iniciamos el player
	player = archivoPlayer.leerArchivo(gameplayManager.getSaveSlot());
	String dinero = "Dinero: "+ to_string(player.getMoney());
	configtexto.ConfigurarTexto(Dinero, configtexto.gameplayFont, dinero, 14, Color::Black);
	configtexto.CentrarTexto(Dinero, -280, -280);
	imageFondo.loadFromFile("Sprites/tienda.jpg");
	fondo.setTexture(imageFondo);
	cuadroSeleccionado = 0;
	actualizarCuadro();
	comprarBuff.loadFromFile("Sounds/comprar.ogg");
	errorBuff.loadFromFile("Sounds/erro.ogg");
	sonidoComprar.setBuffer(comprarBuff);
	sonidoComprar.setVolume(50);
	sonidoError.setBuffer(errorBuff);
	sonidoError.setVolume(50);
	//Iniciamos los precios
	precios[0] = 20;
	precios[1] = 50;
	precios[2] = 50;
	precios[3] = 100;
	precios[4] = 180;
	precios[5] = 250;

	scenemanager.sceneLoaded();
}

void Tienda::Draw(RenderWindow& window)
{
	window.draw(fondo);
	window.draw(info);
	window.draw(Dinero);
	for (int i = 0; i < 6; i++) {
		window.draw(objeto[i]);
		window.draw(cuadro[i]);
	}
}

void Tienda::Update()
{
	tiempo = clock.getElapsedTime();
	if (tiempo.asSeconds() > 1) {
		objeto[cuadroSeleccionado].setColor(Color::White);
	}

	if (Keyboard::isKeyPressed(Keyboard::Up) && framescooldown >= 15)
	{
		Arriba();
	}
	if (Keyboard::isKeyPressed(Keyboard::Down) && framescooldown >= 15)
	{
		Abajo();
	}
	if (Keyboard::isKeyPressed(Keyboard::Left) && framescooldown >= 15)
	{
		Izquierda();
	}
	if (Keyboard::isKeyPressed(Keyboard::Right) && framescooldown >= 15)
	{
		Derecha();
	}
	if (Keyboard::isKeyPressed(Keyboard::Enter) && framescooldown >= 60)
	{
		int slot = -1;
		tiempo = clock.restart();
		for (int i = 0;i < 4;i++)//Verifica si hay slot disponible
		{
			if (player.getObjeto(i) == 0)
			{
				slot = i;
				i = 4;
			}
		}
		if (player.getMoney() >= precios[cuadroSeleccionado] && slot != -1)//Mayor o igual que el precio
		{
			objeto[cuadroSeleccionado].setColor(Color::Green);
			player.setObjeto(cuadroSeleccionado +1, slot);

			//se quita la plata y se deberia añadir el objeto al jugador
			player.setMoney(player.getMoney() - precios[cuadroSeleccionado]);
			String dinero = "Dinero: " + to_string(player.getMoney());
			configtexto.ConfigurarTexto(Dinero, configtexto.gameplayFont, dinero, 14, Color::Black);
			configtexto.CentrarTexto(Dinero, -280, -280);
			sonidoComprar.play();
		}
		else
		{
			objeto[cuadroSeleccionado].setColor(Color::Red);
			sonidoError.play();
		}
		
		framescooldown = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		std::cerr << "obj1 = " + to_string(player.getObjeto(0))<<endl;
		std::cerr << "obj2 = " + to_string(player.getObjeto(1)) << endl;
		std::cerr << "obj3 = " + to_string(player.getObjeto(2)) << endl;
		archivoPlayer.sobreEscribir(gameplayManager.getSaveSlot(), player);
		scenemanager.setScene(1);
	}
	framescooldown++;
}

void Tienda::Izquierda()
{
	framescooldown = 0;
	if (cuadroSeleccionado == 0) {
		cuadroSeleccionado = 3;
	}
	else
		if (cuadroSeleccionado == 1) {
			cuadroSeleccionado = 4;
		}
		else
			if (cuadroSeleccionado == 2) {
				cuadroSeleccionado = 5;
			}
			else {
				cuadroSeleccionado -= 3;
			}
	actualizarCuadro();
}

void Tienda::Derecha()
{
	framescooldown = 0;
	if (cuadroSeleccionado == 3) {
		cuadroSeleccionado = 0;
	}
	else
		if (cuadroSeleccionado == 4) {
			cuadroSeleccionado = 1;
		}
		else
			if (cuadroSeleccionado == 5) {
				cuadroSeleccionado = 2;
			}
			else {
				cuadroSeleccionado += 3;
			}
	actualizarCuadro();
}


void Tienda::Abajo()
{
	framescooldown = 0;
	if (cuadroSeleccionado == 5) {
		cuadroSeleccionado = 0;
	}
	else {
		cuadroSeleccionado++;
	}
	actualizarCuadro();
}

void Tienda::Arriba()
{
	framescooldown = 0;
	if (cuadroSeleccionado == 0) {
		cuadroSeleccionado = 5;
	}
	else {
		cuadroSeleccionado--;
	}
	actualizarCuadro();
}

void Tienda::actualizarCuadro()
{
	for (int i = 0; i < 6; i++) {
		cuadro[i].setColor(Color::Black);
		cuadro[i].setScale(3, 3);
		objeto[i].setScale(3, 3);
		objeto[i].setColor(Color::White);
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "", 5, Color::Black, Color::Red, 0.3f);
		info.setPosition(0, 0);
	}
	configInfo(cuadroSeleccionado);
	cuadro[cuadroSeleccionado].setColor(Color::Red);
	cuadro[cuadroSeleccionado].setScale(4, 4);
	objeto[cuadroSeleccionado].setScale(4, 4);
	//Se efectua la compra
}


void Tienda::configInfo(int cuadroSeleccionado)
{
	switch (cuadroSeleccionado) {
	case 0:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "Código de curación pequeño \n Costo: 20 UTs \n \n Este  objeto  ayudará a  \n que  tu  Klostermon  recupere \n 15  puntos  de  salud.", 9, Color::White, Color::Red, 0.3f);
		info.setPosition(200, 70);
		break;

	case 1:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "Código de curación grande \n Costo: 50 UTs \n \n Recuperará  50  puntos  de  \n salud  para  tu  Klostermon.", 9, Color::White, Color::Red, 0.3f);
		info.setPosition(200, 270);
		break;

	case 2:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "Inyección de código \n Costo: 50 UTs \n \n El  Klostermon  rival  perderá \n un  20%  de  efectividad  en  \n sus  ataques.", 9, Color::White, Color::Red, 0.3f);
		info.setPosition(200, 470);
		break;
	case 3:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "Estructuración de código \n Costo: 100 UTs \n \n Tu  Klostermon  logra  \n organizarse bien, \n otorga  un  100% \n de  efectividad  de \n ataque.  ¡No puede \n fallar!", 9, Color::White, Color::Red, 0.3f);
		info.setPosition(590, 70);
		break;
	case 4:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "Optimización \n Costo: 180 UTs \n \n Aumenta  en  un  50% \n la  velocidad  de \n tu  Klostermon.", 9, Color::White, Color::Red, 0.3f);
		info.setPosition(590, 270);
		break;
	case 5:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "CopyPaste \n Costo: 250 UTs \n \n Copiará  los  puntos  de   \n vida  totales  del  rival  y \n los  aplicará  a  tu \n Klostermon.", 9, Color::White, Color::Red, 0.3f);
		info.setPosition(590, 470);
		break;
	}
}