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

void Enemy::forceName(String nameForced)
{
	string name = nameForced.toAnsiString();
	strcpy(nombre, name.c_str());
}

Klostermon Enemy::randomKlostermonSetter()
{
	int random = rand() % (7 + 1 - 0) + 0;
	return archivoKlos.leerArchivo(random);
}

string Enemy::getName() {
	return nombre; 
}