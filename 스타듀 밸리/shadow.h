#pragma once
#include "gameObject.h"


struct tagShadow
{

	image* img;
	animation* ani;
	RECT rc;
};

class shadow :public gameObject
{
private:
	tagShadow _shadow;

public:

	int _alpha;

	HRESULT init(string objectName, string imagKeyName, tagFloat pos);
	void release();
	void update();
	void render();

	void startAni();
	void stopAni();


	shadow() {}
	~shadow() {}
};

