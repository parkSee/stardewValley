#pragma once
#include "gameObject.h"


class store : public gameObject

{
private:

public:
	HRESULT init();
	void release();
	void update();
	void render();


	store() {};
	~store() {};
};

