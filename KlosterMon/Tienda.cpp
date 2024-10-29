#include "Tienda.h"

void Tienda::loadTienda()
{
	elegidos = 0; 
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
	elegidos = 0;
	imageCuadro.loadFromFile("Sprites/cuadro.png"); 
	int posicionX=0;
	int posicionY=0;
	for (int i=0; i < 6; i++) {
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

	imageFondo.loadFromFile("Sprites/fondoGris.png");
	fondo.setTexture(imageFondo);
	scenemanager.sceneLoaded(); 
	cuadroSeleccionado = 0; 
	actualizarCuadro(); 
}

void Tienda::Draw(RenderWindow& window)
{
	window.draw(fondo); 
	for (int i = 0; i < 6; i++) {
	window.draw(objeto[i]); 
	window.draw(cuadro[i]); 
	}
}

void Tienda::Update()
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
			objeto[cuadroSeleccionado].setColor(Color::Green);
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
	for (int i = 0; i < 8; i++) {
		if (!elegido[i]) {
			cuadro[i].setColor(Color::Black);
			cuadro[i].setScale(3, 3);
			objeto[i].setScale(3, 3);
			objeto[i].setColor(Color::White);
			configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "", 5, Color::Black, Color::Red, 0.3f);
			info.setPosition(0, 0);
		}

	}
	configInfo(cuadroSeleccionado);
	cuadro[cuadroSeleccionado].setColor(Color::Red);
	cuadro[cuadroSeleccionado].setScale(4, 4);
	objeto[cuadroSeleccionado].setScale(4, 4);
}


void Tienda::configInfo(int cuadroSeleccionado)
{
	switch (cuadroSeleccionado) {
	case 0:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "Sentidos muy agudos. No tiene \n gran tamaño, pero eso le \n permite moverse con más \n facilidad. Puede aumentar \n su daño general.", 7.5f, Color::Black, Color::Red, 0.3f);
		info.setPosition(106, 220);
		break;

	case 1:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "Sabe leer a sus rivales, se \n camufla con el entorno para \n engañar. Aumenta la \n probabilidad de que el enemigo \n falle sus ataques.", 7.5f, Color::Black, Color::Red, 0.3f);
		info.setPosition(106, 320);
		break;

	case 2:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "De aspecto terrorífico, \n provoca pánico \n y decrece el daño de sus \n enemigos.", 7.5f, Color::Black, Color::Red, 0.3f);
		info.setPosition(106, 420);
		break;
	case 3:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "Tiene un gran tamaño, \n puede aturdir enemigos \n y disminuir su  \n velocidad.", 7.5f, Color::Black, Color::Yellow, 0.3f);
		info.setPosition(406, 220);
		break;
	case 4:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "Su cabeza es literalmente un \n taladro. No puede ver. \n Disminuye la vida total \n del enemigo.", 7.5f, Color::Black, Color::Yellow, 0.3f);
		info.setPosition(406, 320);
		break;
	case 5:
		configtexto.ConfigurarTexto(info, configtexto.gameplayFont, "Experto en demoliciones. \n Explota y provoca daño \n mortal al enemigo. \n Pero a costa de quedar \n inutilizable durante el \n combate.", 7.5f, Color::Black, Color::Yellow, 0.3f);
		info.setPosition(406, 420);
		break;
	}
}
