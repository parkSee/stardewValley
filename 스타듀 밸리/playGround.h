#pragma once
#include "gameNode.h"
#include "loadingScene.h"
#include "townScene.h"

class playGround : public gameNode
{
private:
	

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	
	playGround();
	~playGround();
};

