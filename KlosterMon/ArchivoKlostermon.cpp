#include "ArchivoKlostermon.h"

ArchivoKlostermon::ArchivoKlostermon()
{
	strcpy(nombreArchivo, "KlostermonesCargados.dat");
}

Klostermon ArchivoKlostermon::leerArchivo(int pos)
{
	FILE* p = fopen(nombreArchivo, "rb");
	if (p == NULL) {
		return Klostermon();
	}
	Klostermon klostermon;
	fseek(p, sizeof(Klostermon) * pos, SEEK_SET);
	fread(&klostermon, sizeof(Klostermon), 1, p);
	fclose(p);
	return klostermon;
}

int ArchivoKlostermon::contarRegistros()
{
	FILE* p = fopen(nombreArchivo, "rb");
	if (p == NULL) {
		return -1;
	}
	fseek(p, 0, 2);
	int cant = ftell(p) / sizeof(Klostermon);
	fclose(p);
	return cant;
}

bool ArchivoKlostermon::sobreEscribir(int pos, Klostermon kl)
{
	FILE* p = nullptr;

	p = fopen(nombreArchivo, "rb+");
	if (p == nullptr)
	{
		std::cerr << "error al abrir el archivo " << endl;
		return false;
	}

	if (fseek(p, pos * sizeof(Klostermon), SEEK_SET) != 0)
	{
		std::cerr << "Hubo un error en el fseek" << std::endl;
		fclose(p);
		return false;
	}

	int escribio = fwrite(&kl, sizeof(kl), 1, p);
	if (escribio != 1)
	{
		std::cerr << "Hubo un error al usar fwrite" << std::endl;
		fclose(p);
		return false;
	}

	fclose(p);
	cout << "Se sobre escribio!" << endl;
	return true;
}





bool ArchivoKlostermon::grabarArchivo(Klostermon reg)
{
	FILE* p;
	p = fopen(nombreArchivo, "ab");
	int escribio = fwrite(&reg, sizeof reg, 1, p);
	fclose(p);
	return escribio;
}

void ArchivoKlostermon::cargarConsola()
{
	Klostermon creado;
	cout << "Creacion de klostermon" << endl;

	cout << "Nombre: " << endl;
	string nombre;
	cin >> nombre;
	creado.setNameKlostermon(nombre);
	cout << "Vida maxima" << endl;
	int vidamax;
	cin >> vidamax;
	creado.setMaxVida(vidamax);
	creado.setVida(vidamax);
	cout << "Velocidad:" << endl;
	int velocidad;
	cin >> velocidad;
	creado.setVelocidad(velocidad);
	cout << "Efectividad" << endl;
	int efec;
	cin >> efec;
	creado.setEfectividad(efec);
	string path;
	cout << "Nombre del png del klostermon" << endl;
	cin >> path;
	creado.setTexture(path);
	cout << "El path de texture es" << creado.getPathTexture().toAnsiString() << endl;
	//Ataque pesado
	cout << "Nombre ataque pesado" << endl;
	string nombreAtaque;
	cin >> nombreAtaque;
	creado.ataquePesado.setName(nombreAtaque);
	cout << "Danio Min ataque" << endl;
	int danio;
	cin >> danio;
	creado.ataquePesado.setDanioMin(danio);
	cout << "Danio Max ataque" << endl;
	cin >> danio;
	creado.ataquePesado.setDanioMax(danio);
	cout << "Danio propio" << endl;
	cin >> danio;
	creado.ataquePesado.setDanioPropio(danio);
	cout << "Efectividad ataque" << endl;
	int efecti;
	cin >> efecti;
	creado.ataquePesado.setEfectividadAtaque(efecti);
	cout << "Efectividad enemiga" << endl;
	cin >> efecti;
	creado.ataquePesado.setEfectividadEnemiga(efecti);
	cout << "Velocidad ataque" << endl;
	cin >> velocidad;
	creado.ataquePesado.setVelocidadAtaque(velocidad);
	cout << "Velocidad enemiga" << endl;
	cin >> velocidad;
	creado.ataquePesado.setVelocidadEnemiga(velocidad);
	cout << "Multiplicador Propio(0.1 = +10%)";
	float mult;
	cin >> mult;
	creado.ataquePesado.setMultPropio(mult);
	cout << "Multiplicador Enemigo(-0.1 = -10%)";
	cin >> mult;
	creado.ataquePesado.setMultEnemigo(mult);
	//Ataque especial
	cout << "Nombre ataque especial" << endl;
	cin >> nombreAtaque;
	creado.ataqueEspecial.setName(nombreAtaque);
	cout << "Danio Min ataque" << endl;
	cin >> danio;
	creado.ataqueEspecial.setDanioMin(danio);
	cout << "Danio Max ataque" << endl;
	cin >> danio;
	creado.ataqueEspecial.setDanioMax(danio);
	cout << "Danio propio" << endl;
	cin >> danio;
	creado.ataqueEspecial.setDanioPropio(danio);
	cout << "Efectividad ataque" << endl;
	cin >> efecti;
	creado.ataqueEspecial.setEfectividadAtaque(efecti);
	cout << "Efectividad enemiga" << endl;
	cin >> efecti;
	creado.ataqueEspecial.setEfectividadEnemiga(efecti);
	cout << "Velocidad ataque" << endl;
	cin >> velocidad;
	creado.ataqueEspecial.setVelocidadAtaque(velocidad);
	cout << "Velocidad enemiga" << endl;
	cin >> velocidad;
	creado.ataqueEspecial.setVelocidadEnemiga(velocidad);
	cout << "Multiplicador Propio(0.1 = +10%)";
	cin >> mult;
	creado.ataqueEspecial.setMultPropio(mult);
	cout << "Multiplicador Enemigo(-0.1 = -10%)";
	cin >> mult;
	creado.ataqueEspecial.setMultEnemigo(mult);
	creado.setMultiplicador(1.0f);

	cout << "Random Danio: " << creado.ataqueEspecial.getDanio() << endl;
	cout << "El path de texture es" << creado.getPathTexture().toAnsiString()<<endl;
	cout << "Ingrese -1 si quiere que el Klostermon sea añadido al siguente ID DISPONIBLE" << endl;
	cout << "Sino, ingrese el numero que quiere que reemplaze el Klostermon! (CUIDADO PUEDE CAUSAR ERRORES UNA POS NO VALIDA)" << endl;
	int numero;
	cin >> numero;
	if (numero == -1)
	{
		grabarArchivo(creado);
		cout << "Se guardo perfectamente!" << endl;
	}
	else 
	{
		sobreEscribir(numero, creado);
		cout << "Se sobre escribio perfectamente!" << endl;
	}

}

