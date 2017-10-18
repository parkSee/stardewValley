#pragma once
#include "npc.h"

class pierre : public npc
{
private:
	

public:
	HRESULT init(string name, string imageKey, tagFloat pos);
	void release();
	void update();
	void render();

	pierre() {}
	~pierre() {}
};

