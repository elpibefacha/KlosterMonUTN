#pragma once
class SceneManager
{
private:
	static int scene;
public:
	void Iniciar();
	int getScene();
	void setScene(int);
};

