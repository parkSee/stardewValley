#pragma once
#include "gameNode.h"
#include "effect.h"

class effectTest : public gameNode
{
private:
	effect* _effect;
	int _count;

public:
	HRESULT init();
	void release();
	void update();
	void render();
	
	effectTest();
	~effectTest();
};

