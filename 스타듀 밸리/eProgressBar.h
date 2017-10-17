#pragma once
#include "gameObject.h"
#include "heightProgressBar.h"

struct tagProgress
{
	image*		img;
	RECT		rc;
	tagFloat	pos;
};

class eProgressBar : public gameObject
{
private:
	tagProgress				_progressWindow;
	heightProgressBar*		_eProgressBar;

	float					_playerEnergy;			//증가 할수록 피가 감소한다.
public:
	HRESULT init();
	void release();
	void update();
	void render();

	eProgressBar() {}
	 ~eProgressBar() {}
};

