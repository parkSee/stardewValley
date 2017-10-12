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


	townScene() 
	: a(false){}
	~townScene() {}
};

