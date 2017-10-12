#pragma once
#include "gameNode.h"
#include "button.h"
#include "action.h"

static image* actionImage = NULL;
static action* testAction = NULL;

class selectScene : public gameNode
{
private:
	button* _btnSceneChange;
	action* _action;
	image* _actionTest;

	button* _btnAngleUp;
	button* _btnAngleDown;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	static void cbSceneChange(void);

	static void cbAction(void);
	static void cbAngleUp(void);
	static void cbAngleDown(void);

	selectScene();
	~selectScene();
};

