#include "Player.h"

Player::Player()
{
	money = 50;
}

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

Klostermon Player::getKlostermon(int pos)
{
	if (pos > 2 || pos < 0)
	{
		std::cerr << "POSICION INCORRECTA getKlostermon() TIENE QUE SER ENTRE 0 y 2 " << endl;
		return Klostermon();
	}
	return klostermon[pos];
}
