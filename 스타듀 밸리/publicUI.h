#pragma once
#include "gameObject.h"
#include "worldNode.h"

namespace publicUIType
{
	enum Enum
	{
		GET_ITEM_MESSAGE, GUIDE_MESSAGE, END
	};
}

struct tagUI
{
	image*				img;
	string				txt;
	float				count;
	int					index;
	float				liveTime;
};

class publicUI : public gameObject
{
private:
	vector<tagUI>		_vGetItemUI;
	vector<tagUI>		_vGuideUI;

public:
	HRESULT init(string name);
	void release();
	void update();
	void render();

	void addGetItemUI(tagMessage msg);
	void addGuideUI(tagMessage msg);


	publicUI() {}
	~publicUI() {}
};

