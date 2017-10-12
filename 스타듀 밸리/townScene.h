#pragma once
#include "gameNode.h"
#include "worldNode.h"



class townScene : public gameNode
{
private:
	bool a;
public:
	HRESULT init();
	void release();
	void update();
	void render();
	
	void seeyoungInit();
	void soonwooInit();
	void jerichoInit();
	void guenhwaInit();
	void youngjaeInit();
	void dongjinInit();

	townScene() 
	: a(false){}
	~townScene() {}
};

