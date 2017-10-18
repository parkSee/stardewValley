#pragma once
#include "singletonBase.h"
#include "worldNode.h"
#include <vector>
#include <unordered_map>

class gameObject;
class mapToolTile;
class tileMap;

namespace objectType
{
	enum Enum
	{
		HUMAN , OBJ , TILE ,ITEM ,INTERFACE,MOUSE,WEATHER, END
	};
}

class townWorld : public singletonBase<townWorld>
{
public:
	typedef vector<gameObject*> arrObject;
	typedef unordered_map<objectType::Enum, arrObject>				objectContainer;
	typedef unordered_map<objectType::Enum, arrObject>::iterator	mIter;
private:
	objectContainer _totalObject;
	tileMap* _tileMap;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	//오브젝트 매니저에 오브젝트를 추가한다.
	void addObject(objectType::Enum type, gameObject* obj);

	//해당 이름을 가진 오브젝트 하나를 찾아서 반환한다. 없으면 NULL을 반환.
	gameObject* findObject(objectType::Enum type, string name);

	//해당 이름을 가진 오브젝트를 모두 찾아서 vector에 담아 반환한다.
	vector<gameObject*> findObjects(objectType::Enum type, string name);

	//해당 타입을 가진 모든 오브젝트의 리스트를 반환한다.
	vector<gameObject*>* getObjectList(objectType::Enum type);
	//전체 모든 오브젝트를 백터에 담아서 반환해준다.
	vector<gameObject*> getTotalObject();

	//타일맵 겟셋
	inline tileMap* getMap() { return _tileMap; }
	inline void setMapAddress(tileMap* address) { _tileMap = address; }

	//타일 겟
	mapToolTile* getTile(int indexX, int indexY);

	townWorld() {}
	~townWorld() {}
};

