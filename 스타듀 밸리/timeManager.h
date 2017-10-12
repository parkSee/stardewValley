#pragma once
#include "singletonBase.h"
#include "timer.h"

class timeManager : public singletonBase<timeManager>
{
private:
	timer* _timer;

public:
	HRESULT init(void);
	void release(void);
	void update(float lock = 0.0f);
	void render(HDC hdc);

	inline float getElapsedTime(void) const { return _timer->getElapsedTime(); }
	inline float getWorldTime(void) const { return _timer->getWorldTime(); }


	timeManager();
	~timeManager();
};

