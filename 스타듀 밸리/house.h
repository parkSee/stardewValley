#pragma once
#include "motherObject.h"

class house : public motherObject
{
private:
	RECT		_rc;
public:
	HRESULT init(string name ,string imageKey,tagFloat pos);
	void release();
	void update();
	void render();

	house() {}
	~house() {}
};

