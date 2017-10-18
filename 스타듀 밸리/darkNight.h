#pragma once
#include "gameObject.h"

#define LEVEL1	0
#define	LEVEL2	100
#define	LEVEL3	150
#define	LEVEL4	200
#define	LEVEL5	230
#define	LEVEL6	255

class darkNight : public gameObject
{
private:
	int							_alpha;
	vector<gameObject*>			_lightList;
	RECT						_rc;
	gameObject*					_player;

	int							_indexX;
	int							_indexY;
	
public:
	HRESULT init(string name,string imageKey,tagFloat pos,int indexX ,int indexY);
	void release();
	void update();
	void render();

	void changeAlpha(tagMessage msg);

	darkNight() {}
	virtual ~darkNight(){}
};

