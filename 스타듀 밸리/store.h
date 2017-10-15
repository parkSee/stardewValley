#pragma once
#include "gameObject.h"


struct tagStore
{
	image* ui;
	image* item;
	string txt;
	RECT rc;

};
class store : public gameObject

{
private:

public:
	HRESULT init();
	void release();
	void update();
	void render();


	store() {}
	~store() {}
};

