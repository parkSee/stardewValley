#pragma once
#include "gameNode.h"

class collisionTestScene : public gameNode
{
private:
	RECT _rect;
	RECT _rectMove;

	MYCIRCLE _cir;
	MYCIRCLE _cirMove;

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);



	collisionTestScene();
	~collisionTestScene();
};

