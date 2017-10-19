#pragma once
#include "gameObject.h"

namespace selectUIDirection
{
	enum Enum
	{
		ACTIVE,NONEACTIVE
	};
}

class selectUI : public gameObject
{
private:
	selectUIDirection::Enum		_direction;
	image*						_window;
	RECT						_windowRc;
	RECT						_yes;
	RECT						_no;
	
public:
	HRESULT init(string name);
	void release();
	void update();
	void render();

	void setSelectUI(tagMessage msg);

	selectUI() {}
	~selectUI() {}
};

