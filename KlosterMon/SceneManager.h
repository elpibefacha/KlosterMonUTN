#pragma once
class SceneManager
{
private:
	static int scene;
	static bool sceneLoad;
public:
	void Iniciar();
	int getScene();
	void sceneLoaded();
	bool getBoolLoad();
	void setScene(int);
};

