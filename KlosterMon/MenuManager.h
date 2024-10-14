#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class MenuManager
{
private:
	static int menuID;
	static Event event;
public:
	int getMenuID();
	void setMenuID(int);
	Event getEvent();
	void setEvent(Event&);
};

