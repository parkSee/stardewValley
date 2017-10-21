#pragma once
#include "motherObject.h"
class seed : public motherObject
{
private:
	int _growNum;


public:
	seed() {}
	~seed() {}

	bool _isRight;

	virtual HRESULT init(string name,string imageKey,tagFloat pos);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void grow();
	virtual void growAttack();
};

