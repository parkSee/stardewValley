#pragma once
#include "gameObject.h"

class dropItem : public gameObject
{
private:
	RECT			_rc;

	gameObject*		_targetPlayer;
public:
	HRESULT init(string name, string keyName);
	void release();
	void update();
	void render();

	dropItem() {}
	~dropItem() {}
};

