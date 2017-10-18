#pragma once
#include "gameObject.h"
#include "player.h"

class darkNight : public gameObject
{
private:
	vector<gameObject*>			_lightList;
	RECT						_rc;
	player*					_player;

	int							_playerIndexX;
	int							_playerIndexY;
	
public:
	int							_alpha;
	int							_indexX;
	int							_indexY;

	HRESULT init(string name,string imageKey,tagFloat pos,int indexX ,int indexY);
	void release();
	void update();
	void render();

	void changeAlpha(tagMessage msg);

	darkNight() {}
	virtual ~darkNight(){}
};

