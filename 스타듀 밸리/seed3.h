#pragma once
#include "motherObject.h"
class seed3 : public motherObject
{
private:
	int _growNum;
	RECT _rc;

public:
	seed3() {}
	~seed3() {}

	bool _isRight;
	string _explain;

	virtual HRESULT init(string name, string imageKey, tagFloat pos, string explain);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void grow();
	virtual void growAttack();
};

