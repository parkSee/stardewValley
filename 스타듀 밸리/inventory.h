#pragma once
#include "gameObject.h"
#include "item.h"
#include <vector>


struct tagInventory
{
	tagFloat pos;
	RECT	rc;
	image*	img;
};

class inventory : public gameObject
{
private:
	vector<item*>		_vTotalItem;


	tagInventory		_subInventory;
public:
	HRESULT init(string name);
	void release();
	void update();
	void render();

	inventory() {}
	~inventory() {}
};

