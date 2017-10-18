#pragma once
#include "gameObject.h"
#include "darkNight.h"

class weather : public gameObject
{
private:
	darkNight*			_darkNight[TILEX][TILEY];

public:
	HRESULT init(string name);
	void release();
	void update();
	void render();

	darkNight* getDarkKnight() { return _darkNight[TILEX][TILEY]; }

	weather() {}
	virtual ~weather() {}
};

