#pragma once
#include "gameNode.h"
#include "worldNode.h"
#include "mapToolNode.h"
#include "tileMap.h"

class townScene : public gameNode
{
private:
	bool a;
	tileMap* _map;
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

