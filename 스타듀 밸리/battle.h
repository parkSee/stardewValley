#pragma once
#include "ship.h"

class battle : public ship
{
private:
	missilePF* _missile;

public:
	virtual HRESULT init(const char* imageName, int x, int y);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	virtual void keyControl(void);

	virtual void missileFire();
	virtual void missileMove();
	virtual void missileDraw();
	

	battle();
	~battle();
};

