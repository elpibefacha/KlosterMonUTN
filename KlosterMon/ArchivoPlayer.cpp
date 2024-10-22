#include "ArchivoPlayer.h"

ArchivoPlayer::ArchivoPlayer()
{
	strcpy(nombreArchivo, "archivoFinalTest.dat");
    //leerArchivo(1);
}

Player ArchivoPlayer::leerArchivo(int pos)
{
	FILE* p = fopen(nombreArchivo, "rb");
	if (p == NULL) {
		return Player();
	}
	Player player;
	fseek(p, sizeof(Player) * pos, SEEK_SET);
	fread(&player, sizeof(Player), 1, p);
	fclose(p);
	return player;
}

int ArchivoPlayer::contarRegistros()
{
	FILE* p = fopen(nombreArchivo, "rb");
	if (p == NULL) {
		return -1;
	}
	fseek(p, 0, 2);
	int cant = ftell(p) / sizeof(Player);
	fclose(p);
	return cant;
}

bool ArchivoPlayer::grabarArchivo(Player reg)
{
	FILE *p;
	p = fopen(nombreArchivo, "ab");
	int escribio = fwrite(&reg, sizeof reg, 1, p);
	fclose(p);
	return escribio;
}
