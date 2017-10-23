#pragma once
#include "gameObject.h"

namespace selectUIDirection
{
	enum Enum
	{
		ACTIVE,NONE_ACTIVE
	};
}

struct tagChoice
{
	RECT rc;
	bool choice;
};

class selectUI : public gameObject
{
private:
	selectUIDirection::Enum		_direction;
	image*						_window;
	RECT						_windowRc;
	tagChoice					_yes;
	tagChoice					_no;
	string						_txt;

	CBFUNCTION					_cb;
	
public:
	HRESULT init(string name);
	void release();
	void update();
	void render();

	void setSelectUI(tagMessage msg);
	void sleep(tagMessage msg);

	void setCb(CBFUNCTION cb) { _cb = cb; }

	selectUI() {}
	~selectUI() {}
};

