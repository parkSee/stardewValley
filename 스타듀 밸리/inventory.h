#pragma once
#include "gameObject.h"
#include "item.h"
#include <vector>

class inventory : public gameObject
{
private:
	
public:
	HRESULT init();
	void release();
	void update();
	void render();

	inventory() {}
	~inventory() {}
};

