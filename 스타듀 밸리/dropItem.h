#pragma once
#include "gameObject.h"

#define ITEMSPEED 10

class dropItem : public gameObject
{
private:
	RECT			_rc;
	gameObject*		_targetPlayer;

	string			_explain;

	bool			_isBounce;
	float			_jumpPower;
	float			_gravity;
	int				_jumpCount;
	float			_speed;

	tagFloat		_savePos;

public:
	HRESULT init(string name, string explain,tagFloat pos);
	void release();
	void update();
	void render();

	dropItem() {}
	~dropItem() {}
};

