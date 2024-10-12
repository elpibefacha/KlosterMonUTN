#include "SceneManager.h"

int SceneManager::scene = 0;

void SceneManager::Iniciar()
{
	scene = 0;
}

int SceneManager::getScene()
{
	return scene;
}

void SceneManager::setScene(int nuevaScene)
{
	scene = nuevaScene;
}
