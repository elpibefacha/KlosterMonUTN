#include "ArchivoPlayer.h"

ArchivoPlayer::ArchivoPlayer()
{
	strcpy(nombreArchivo, "ArchivoPlayer.dat");
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

bool ArchivoPlayer::sobreEscribir(int pos, Player reg)
{
    FILE* p = nullptr;

	p = fopen(nombreArchivo, "rb+");
    if (p == nullptr)
    {
		std::cerr << "error al abrir el archivo " << endl;
        return false;
    }

    if (fseek(p, pos * sizeof(Player), SEEK_SET) != 0)
    {
        std::cerr << "Hubo un error en el fseek" << std::endl;
        fclose(p);
        return false;
    }

    int escribio = fwrite(&reg, sizeof(reg), 1, p);
    if (escribio != 1)
    {
        std::cerr << "Hubo un error al usar fwrite" << std::endl;
        fclose(p);
        return false;
    }

    fclose(p);
    return true;
}

bool ArchivoPlayer::ArchiveExist()
{
	FILE* p;
	p = fopen(nombreArchivo, "rb");
	if (p == nullptr)
	{
		p = fopen(nombreArchivo, "wb");
		if (p == nullptr)
		{
			std::cerr << "Error al crear un archivo"<<endl;
			return false;
		}
		Player vacio;
		vacio.SetName("");
		for (int i = 0;i < 3;i++)
		{
			fseek(p, i * sizeof(Player), SEEK_SET);
			fwrite(&vacio, sizeof(vacio),1, p);
		}
		fclose(p);
		return true;
	}
	fclose(p);
	return true;
}

