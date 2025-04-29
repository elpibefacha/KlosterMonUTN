#include "MenuManager.h"

int MenuManager::menuID = 0;
Event MenuManager::event;
bool MenuManager::menuLoaded = false;

int MenuManager::getMenuID()
{
	return menuID;
}

void MenuManager::setMenuID(int newMenuID)
{
	menuID = newMenuID;
	menuLoaded = false;
}

Event MenuManager::getEvent()
{
	return event;
}

void MenuManager::setEvent(Event& evento)
{
	event = evento;
}

bool MenuManager::getLoaded()
{
	return menuLoaded;
}

void MenuManager::loadMenu()
{
	menuLoaded = true;
}
