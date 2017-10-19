#pragma once
#include "npc.h"

class caroline : public npc
{
private:
	
public:
	HRESULT init(string name, string imageKey, tagFloat pos);
	void release();
	void update();
	void render();


	caroline();
	~caroline();
};

