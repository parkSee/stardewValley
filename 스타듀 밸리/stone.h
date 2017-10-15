#pragma once
#include "motherObject.h"

class stone : public motherObject
{
public:
	stone() {}
	~stone() {}

	virtual HRESULT init(tagFloat pos);
	virtual void release();
	virtual void update();
	virtual void render();

	void stoneAttack();
};

