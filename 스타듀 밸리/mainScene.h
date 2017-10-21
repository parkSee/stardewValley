#pragma once
#include "gameNode.h"
#include "worldNode.h"

struct tagButton
{
	image*		img;
	tagFloat	pos;
	RECT		rc;
};

class mainScene : public  gameNode
{
private:
	image*	_backGround;
	image*	_title;
	image*	_mouse;

	tagButton	_new;
	tagButton	_map;

public:
	HRESULT init();
	void release();
	void update();
	void render();


	mainScene();
	~mainScene();
};

