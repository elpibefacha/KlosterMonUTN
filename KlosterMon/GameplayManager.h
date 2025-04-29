#pragma once
class GameplayManager
{
private:
	static int saveSlot;
public:
	int getSaveSlot();
	void setSaveSlot(int);
};

