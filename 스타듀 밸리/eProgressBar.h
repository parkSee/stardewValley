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

	float					_playerEnergy;			//���� �Ҽ��� �ǰ� �����Ѵ�.
public:
	HRESULT init();
	void release();
	void update();
	void render();

	eProgressBar() {}
	 ~eProgressBar() {}
};

