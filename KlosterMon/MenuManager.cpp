#include "MenuManager.h"

int MenuManager::menuID = 0;
Event MenuManager::event;

int MenuManager::getMenuID()
{
	return menuID;
}

void MenuManager::setMenuID(int newMenuID)
{
	menuID = newMenuID;
}

Event MenuManager::getEvent()
{
	return event;
}

void MenuManager::setEvent(Event& evento)
{
	event = evento;
}
