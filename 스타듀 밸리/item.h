#pragma once
#include "gameObject.h"

namespace itemType
{
	enum Enum
	{
		NONE,
		TOOL,
		FOOD,
		SEED,
		END
	};
}

class item : public gameObject
{
private:
	itemType::Enum				_itemType;
	RECT						_rc;
	
public:
	bool		_isPlayerHave;

	HRESULT init(string itemName , string imageKey ,itemType::Enum type = itemType::NONE);
	void release();
	void update();
	void render();

	void setPos(tagFloat tagFloat) { _pos = tagFloat; }

	item() {}
	~item() {}
};

