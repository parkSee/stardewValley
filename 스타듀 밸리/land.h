#pragma once
#include "motherObject.h"

class land  : public motherObject
{
private:
	

public:
	land() {}
	~land() {}

	bool _isWet;

	virtual HRESULT init(tagFloat pos);
	virtual void release();
	virtual void update();
	virtual void render();

	

};



