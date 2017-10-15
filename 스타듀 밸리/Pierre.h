#pragma once
#include "NPC.h"

class Pierre : public NPC
{
private:

public:
	HRESULT init();
	void release();
	void update();
	void render();

	Pierre() {}
	~Pierre() {}
};

