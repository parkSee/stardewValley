#pragma once
#include "gameObject.h"

class fade : public gameObject
{
private:
	int		_alpha;
	bool	_isMax;
public:
	bool	_isActiving;

	HRESULT init(string name);
	void release();
	void update();
	void render();

	void startFadeOut();

	fade();
	~fade();
};

