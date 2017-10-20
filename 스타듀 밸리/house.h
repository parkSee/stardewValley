#pragma once
#include "motherObject.h"
#include "player.h"

class house : public motherObject
{
private:
	RECT		_rc;
	player*		_player;
	int			_alpha;
public:
	HRESULT init(string name ,string imageKey,tagFloat pos);
	void release();
	void update();
	void render();

	house() {}
	~house() {}
};

