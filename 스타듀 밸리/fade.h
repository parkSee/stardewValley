#pragma once
#include "gameObject.h"

class fade : public gameObject
{
private:
	int		_alpha;
	bool	_isMax;
	bool	_isActiving;
public:
	HRESULT init(string name);
	void release();
	void update();
	void render();

	void startFadeOut() { _isActiving = true; }

	fade();
	~fade();
};

