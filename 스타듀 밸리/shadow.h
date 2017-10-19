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
	tagShadow	_shadow;


	float		_scale;

public:

	int			_alpha;
	bool		_isChange;

	HRESULT init(string objectName, string imagKeyName, tagFloat pos);
	void release();
	void update();
	void render();

	void startAni();
	void stopAni();

	bool setChange(bool change) { _isChange = change; }
	bool getChange() { return _isChange; }

	shadow() {}
	~shadow() {}
};

