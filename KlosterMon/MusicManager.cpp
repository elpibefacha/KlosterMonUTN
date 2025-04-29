#include "MusicManager.h"

void MusicManager::playMusic(String music_path)
{
	musica.openFromFile(music_path);
	musica.setLoop(true);
	musica.play(); 
}

void MusicManager::setVolumen(int valor)
{
	musica.setVolume(valor); 
}

void MusicManager::stopMusic()
{
	musica.stop(); 
}

Music MusicManager::musica;