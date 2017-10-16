#pragma once
#include "NPC.h"

class Pierre : public NPC
{
private:

public:
	HRESULT init(string npcName, char* imageName, int indexX, int indexY);
	void release();
	void update();
	void render();

	Pierre() {}
	~Pierre() {}
};

