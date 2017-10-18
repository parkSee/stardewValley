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

	//������Ʈ �Ŵ����� ������Ʈ�� �߰��Ѵ�.
	void addObject(objectType::Enum type, gameObject* obj);

	//�ش� �̸��� ���� ������Ʈ �ϳ��� ã�Ƽ� ��ȯ�Ѵ�. ������ NULL�� ��ȯ.
	gameObject* findObject(objectType::Enum type, string name);

	//�ش� �̸��� ���� ������Ʈ�� ��� ã�Ƽ� vector�� ��� ��ȯ�Ѵ�.
	vector<gameObject*> findObjects(objectType::Enum type, string name);

	//�ش� Ÿ���� ���� ��� ������Ʈ�� ����Ʈ�� ��ȯ�Ѵ�.
	vector<gameObject*>* getObjectList(objectType::Enum type);
	//��ü ��� ������Ʈ�� ���Ϳ� ��Ƽ� ��ȯ���ش�.
	vector<gameObject*> getTotalObject();

	//Ÿ�ϸ� �ټ�
	inline tileMap* getMap() { return _tileMap; }
	inline void setMapAddress(tileMap* address) { _tileMap = address; }

	//Ÿ�� ��
	mapToolTile* getTile(int indexX, int indexY);

	townWorld() {}
	~townWorld() {}
};

