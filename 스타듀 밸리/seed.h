#pragma once
#include "motherObject.h"
class seed : public motherObject
{
private:
	int _growNum;

public:
	seed() {}
	~seed() {}

	virtual HRESULT init(tagFloat pos);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void grow();
	virtual void growAttack();
};

