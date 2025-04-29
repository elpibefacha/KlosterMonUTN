#include "SceneManager.h"

int SceneManager::scene = 0;
bool SceneManager::sceneLoad = false;
void SceneManager::Iniciar()
{
	scene = 0;
}

int SceneManager::getScene()
{
	return scene;
}

void SceneManager::sceneLoaded()
{

	sceneLoad = true;
}

bool SceneManager::getBoolLoad()
{
	return sceneLoad;
}

void SceneManager::setScene(int nuevaScene)
{
	scene = nuevaScene;
	sceneLoad = false;
}
