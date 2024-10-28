#pragma once
#include <SFML/Audio.hpp>
using namespace sf; 
class MusicManager
{
	static Music musica; 
public: 
	void playMusic(String music_path);
	void setVolumen(int valor);
	void stopMusic();
};

