#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class MenuManager
{
private:
	static int menuID;
	static Event event;
	static bool menuLoaded;
public:
	int getMenuID();
	void setMenuID(int);
	Event getEvent();
	void setEvent(Event&);
	bool getLoaded();
	void loadMenu();

};

