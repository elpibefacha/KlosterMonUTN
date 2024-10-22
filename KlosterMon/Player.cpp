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
