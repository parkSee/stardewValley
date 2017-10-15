#pragma once
#include "motherObject.h"

class grass : public motherObject
{
public:
	grass() {}
	~grass() {}

	virtual HRESULT init(tagFloat pos);
	virtual void release();
	virtual void update();
	virtual void render();

	void grassAttack();
};

