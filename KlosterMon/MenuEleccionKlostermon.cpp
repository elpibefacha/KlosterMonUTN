#include "MenuEleccionKlostermon.h"
#include <iostream>

void MenuEleccionKlostermon::Load()
{
	player.SetName(archivoPlayer.leerArchivo(gameplayManager.getSaveSlot()).getName());
	player.setMoney(50);//Iniciamos con 50 monedas
	player.completarJuego(false);
	for (int i = 0; i < 4; i++)
	{
		player.setObjeto(0, i);
	}
	//Lo que hace arriba es que setea el nombre del player de esta clase al mismo que se puso anteriormente
	elegidos = 0;
	framescooldown = 0;

	configtexto.ConfigurarTexto(caza, configtexto.gameplayFont, "Caza", 20, Color::Black, Color::Red, 0.3f);
	caza.setPosition(0, 150);
	configtexto.ConfigurarTexto(carga, configtexto.gameplayFont, "Carga", 20, Color::Black, Color::Yellow, 0.3f);
	carga.setPosition(300, 150);
	configtexto.ConfigurarTexto(asistencia, configtexto.gameplayFont, "Asistencia", 20, Color::Black, Color::Cyan, 0.3f);
	asistencia.setPosition(600, 150);
	configtexto.ConfigurarTexto(titulo, configtexto.gameTitleFont, "Elige 3 Klostermons!", 50, Color::Black);
	configtexto.CentrarTexto(titulo, -250, 0);
	cuadroSeleccionado = 0;
	imageLaras.loadFromFile("Sprites/laras.png");
	klostermon[0].setTexture(imageLaras);
	imageUrkos.loadFromFile("Sprites/urkos.png");
	klostermon[1].setTexture(imageUrkos);
	imageTrinitus.loadFromFile("Sprites/trinitus.png");
	klostermon[2].setTexture(imageTrinitus);
	imageTorus.loadFromFile("Sprites/torus.png");
	klostermon[3].setTexture(imageTorus);
	imageDriller.loadFromFile("Sprites/driller.png");
	klostermon[4].setTexture(imageDriller);
	imageBomber.loadFromFile("Sprites/bomber.png");
	klostermon[5].setTexture(imageBomber);
	imageNuxias.loadFromFile("Sprites/nuxias.png");
	klostermon[6].setTexture(imageNuxias);
	imageMercias.loadFromFile("Sprites/mercias.png");
	klostermon[7].setTexture(imageMercias);
	imageCuadro.loadFromFile("Sprites/cuadro.png");
	int posicionX = 0;
	int posicionY = 0;
	for (int i = 0; i < 8; i++) {
		if (i == 0) {
			posicionX = 0;
			posicionY = 100;
		}
		if (i == 3) {
			posicionX = 300;
			posicionY = 100;
		}
		if (i == 6) {
			posicionX = 600;
			posicionY = 100;
		}
		posicionY += 100;
		klostermon[i].setScale(2, 2);
		klostermon[i].setPosition(posicionX, posicionY);
		cuadro[i].setTexture(imageCuadro);
		cuadro[i].setScale(2, 2);
		cuadro[i].setColor(Color::Black);
		cuadro[i].setPosition(posicionX, posicionY);
	}
	imageFondo.loadFromFile("Sprites/fondoGris.png");
	fondoMenu.setTexture(imageFondo);

	cuadroSeleccionado = 0;
	actualizarCuadro();
}

void MenuEleccionKlostermon::Update()
{

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
	if (Keyboard::isKeyPressed(Keyboard::Enter) && framescooldown >= 15)
	{
		if (elegidos < 3 && !elegido[cuadroSeleccionado]) {
			elegido[cuadroSeleccionado] = true;
			elegidos++;
			klostermon[cuadroSeleccionado].setColor(Color::Green);
		}else if (elegidos == 3)
		{
			int num = 0;
			for (int i = 0;i < 8;i++)
			{
				if (elegido[i])
				{
					std::cout << num << " es la ID " << i << std::endl;
					klostermonSeleccionado = archivoKlostermon.leerArchivo(i);
					player.SetKlostermon(klostermonSeleccionado, num);
					num++;
				}
			}
			cerr <<"1- "<< player.getKlostermon(0).getNameKlostermon().toAnsiString() << endl;
			cerr << "2- " << player.getKlostermon(1).getNameKlostermon().toAnsiString() << endl;
			cerr << "3- " << player.getKlostermon(2).getNameKlostermon().toAnsiString() << endl;
			cerr << "Nombre " << player.getName() << endl;

			player.setEnfrentamientoNum(1);
			player.setAnio(2024);
			archivoPlayer.sobreEscribir(gameplayManager.getSaveSlot(),player);
			sceneManager.setScene(2);
		}
		framescooldown = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		elegidos = 0;
		for (int i = 0; i < 8; i++) {
			elegido[i] = false;
		}
		actualizarCuadro();
	}
	framescooldown++;
}

void MenuEleccionKlostermon::Draw(RenderWindow& window)
{
	window.draw(fondoMenu);
	window.draw(titulo);
	window.draw(carga);
	window.draw(caza);
	window.draw(asistencia);
	window.draw(info);
	for (int i = 0; i < 8; i++) {
		window.draw(klostermon[i]);
		window.draw(cuadro[i]);
	}

}

void MenuEleccionKlostermon::Izquierda()
{
	framescooldown = 0;
	if (cuadroSeleccionado == 0) {
		cuadroSeleccionado = 6;
	}
	else
		if (cuadroSeleccionado == 1) {
			cuadroSeleccionado = 7;
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

void MenuEleccionKlostermon::Derecha()
{
	framescooldown = 0;
	if (cuadroSeleccionado == 7) {
		cuadroSeleccionado = 1;
	}
	else
		if (cuadroSeleccionado == 6) {
			cuadroSeleccionado = 0;
		}
		else
			if (cuadroSeleccionado == 5) {
				cuadroSeleccionado = 7;
			}
			else {
				cuadroSeleccionado += 3;
			}
	actualizarCuadro();
}


void MenuEleccionKlostermon::Abajo()
{
	framescooldown = 0;
	if (cuadroSeleccionado == 7) {
		cuadroSeleccionado = 0;
	}
	else {
		cuadroSeleccionado++;
	}
	actualizarCuadro();
}

void MenuEleccionKlostermon::Arriba()
{
	framescooldown = 0;
	if (cuadroSeleccionado == 0) {
		cuadroSeleccionado = 7;
	}
	else {
		cuadroSeleccionado--;
	}
	actualizarCuadro();
}

void MenuEleccionKlostermon::actualizarCuadro()
{
	for (int i = 0; i < 8; i++) {
		if (!elegido[i]) {
			cuadro[i].setColor(Color::Black);
			cuadro[i].setScale(2, 2);
			klostermon[i].setScale(2, 2);
			klostermon[i].setColor(Color::White);
			configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "", 5, Color::Black, Color::Red, 0.3f);
			info.setPosition(50, 200);
		}

	}
	configInfo(cuadroSeleccionado);
	cuadro[cuadroSeleccionado].setScale(3, 3);
	klostermon[cuadroSeleccionado].setScale(3, 3);
}

void MenuEleccionKlostermon::configInfo(int cuadroSeleccionado)
{
	switch (cuadroSeleccionado) {
	case 0:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "Sentidos muy agudos. No tiene \n gran tamaño, pero eso le \n permite moverse con más \n facilidad. Puede aumentar \n su daño general.", 7.5f, Color::Black, Color::Red, 0.3f);
		info.setPosition(106, 220);
		cuadro[cuadroSeleccionado].setColor(Color::Red);
		break;

	case 1:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "Sabe leer a sus rivales, se \n camufla con el entorno para \n engañar. Aumenta la \n probabilidad de que el enemigo \n falle sus ataques.", 7.5f, Color::Black, Color::Red, 0.3f);
		info.setPosition(106, 320);
		cuadro[cuadroSeleccionado].setColor(Color::Red);
		break;

	case 2:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "De aspecto terrorífico, \n provoca pánico \n y decrece el daño de sus \n enemigos.", 7.5f, Color::Black, Color::Red, 0.3f);
		info.setPosition(106, 420);
		cuadro[cuadroSeleccionado].setColor(Color::Red);
		break;
	case 3:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "Tiene un gran tamaño, \n puede aturdir enemigos \n y disminuir su  \n velocidad.", 7.5f, Color::Black, Color::Yellow, 0.3f);
		info.setPosition(406, 220);
		cuadro[cuadroSeleccionado].setColor(Color::Yellow);
		break;
	case 4:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "Su cabeza es literalmente un \n taladro. No puede ver. \n Disminuye la vida total \n del enemigo.", 7.5f, Color::Black, Color::Yellow, 0.3f);
		info.setPosition(406, 320);
		cuadro[cuadroSeleccionado].setColor(Color::Yellow);
		break;
	case 5:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "Experto en demoliciones. \n Explota y provoca daño \n mortal al enemigo. \n Pero a costa de quedar \n inutilizable durante el \n combate.", 7.5f, Color::Black, Color::Yellow, 0.3f);
		info.setPosition(406, 420);
		cuadro[cuadroSeleccionado].setColor(Color::Yellow);
		break;
	case 6:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "Cura un  \n porcentaje de \n la vida de sus \n compañeros.", 7.5f, Color::Black, Color::Cyan, 0.3f);
		info.setPosition(706, 220);
		cuadro[cuadroSeleccionado].setColor(Color::Cyan);
		break;
	case 7:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "Aumenta su vida \n total propia.", 7.5f, Color::Black, Color::Cyan, 0.3f);
		info.setPosition(706, 320);
		cuadro[cuadroSeleccionado].setColor(Color::Cyan);
		break;
	}
}
