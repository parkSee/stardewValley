#pragma once
#include "gameObject.h"
#include "inventory.h"

struct tagCreateItem
{
	image*		img;
	bool		isCreate;
	int			alpha;
	float		scale;
	RECT		rc;
};

struct tagExitButton
{
	image*		img;
	RECT		rc;
};

class createUI : public gameObject
{
private:

	image*			_window;
	RECT			_windowRc;

	tagCreateItem	_chest;
	tagCreateItem	_fence;

	inventory*		_inventory;

	tagExitButton	_exit;


public:
	bool			_isActiveUI;

	HRESULT init(string name);
	void release();
	void update();
	void render();

	void createChest();
	void createFence();

	createUI() {}
	~createUI() {}
};

