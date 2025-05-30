#include "Player.h"


Player::~Player()
{
	cout << "Se destruyo un player "<< nombre<<endl;
}


string Player::getName()
{
	return nombre;
}

void Player::SetName(String newName)
{
	string nombreString = newName.toAnsiString();
	strcpy(nombre, nombreString.c_str());

}

void Player::SetKlostermon(Klostermon k, int pos)
{
	if (pos > 2 || pos < 0)
	{
		std::cerr << "POSICION INCORRECTA setKlostermon() TIENE QUE SER ENTRE 0 y 2 " << endl;
		return;
	}
	klostermon[pos] = k;
}

void Player::setMoney(int n_money)
{
	if (n_money < 0) { n_money = 0; }
	money = n_money;
}

void Player::setObjeto(int id, int pos)
{
	std::cerr << "pos: " << pos << " id: " << id << endl;
	objetos[pos] = id;
}

void Player::setEnfrentamientoNum(int enf)
{
	enfrentamientoNum = enf;
}

void Player::setAnio(int newAnio)
{
	anioTorneo = newAnio;
}

void Player::setEnfrentamientosGanados(int newEnfrentamiento)
{
	enfrentamientosGanados = newEnfrentamiento;
}

void Player::completarJuego(bool com)
{
	completoJuego = com;
}

bool Player::completoElJuego()
{
	return completoJuego;
}

int Player::getAnio()
{
	return anioTorneo;
}

int Player::getEnfrentamiento()
{
	return enfrentamientoNum;
}

int Player::getEnfrentamientosGanados()
{
	return enfrentamientosGanados;
}


int Player::getObjeto(int pos)
{
	return objetos[pos];
}

Klostermon Player::getKlostermon(int pos)
{
	if (pos > 2 || pos < 0)
	{
		std::cerr << "POSICION INCORRECTA getKlostermon() TIENE QUE SER ENTRE 0 y 2 " << endl;
		return Klostermon();
	}
	return klostermon[pos];
}

int Player::getMoney()
{
	return money;
}
