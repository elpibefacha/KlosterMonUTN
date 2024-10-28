#include "Enemy.h"
Enemy::~Enemy()
{
	cout << "Se destruyo un enemy " << nombre << endl;
}
void Enemy::randomNameSetter() {
	FILE* pNombres;
	pNombres = fopen("listaNombres.dat", "rb");
	int leyo = fread(nombres, sizeof(nombres), 1, pNombres);
	if (leyo == 0) {
		std::cerr << "error al abrir archivo" << endl; 
		nombre[0] = 'e';
		nombre[1] = 'r';
		nombre[2] = 'r';
		nombre[3] = 'o';
		nombre[4] = 'r'; 
	}
	fclose(pNombres);
	int random = rand() % 50;
	for (int i = 0; i < 7; i++) {
		nombre[i] = nombres[random][i];
	}
}

string Enemy::getName() {
	return nombre; 
}