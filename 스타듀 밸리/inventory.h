#pragma once
#include "gameObject.h"
#include "item.h"
#include <vector>

struct tagSubInventory
{
	image*			img;
	tagFloat		pos;
	RECT			rc;
};

struct tagMainInventory
{
	
};

namespace invenDirection
{
	enum Enum
	{
		SUB_BOTTOM,
		SUB_TOP,
		MAIN,
		HIDE
	};
}

class inventory : public gameObject
{
private:
	vector<tagItem>			_vInventory;			//아이템정보 담고 있을 인벤토리 벡터 

	tagItem*				_targetItem;			//플레이어가 현재 들고 있는 아이템 (포인터형태)
	
	invenDirection::Enum	_direction;				//인벤토리 창 상태 

	tagMainInventory		_mainInventory;			//메인 인벤토리 창 구조체
	tagSubInventory			_subInventory;			//기본 인벤토리  창 구조체
public:
	HRESULT init(string name);
	void release();
	void update();
	void render();
	
	//현재 아이템 포인터 접근자(플레이어는 이 함수로 자신이 현재 들고 있는 아이템정보를 받아 올 수 있다.)
	//헤더에 #include "item.h"달아주고
	// inventory* inven = (inventory*)TOWNWORLD->findObject(objectType::INTERFACE , "inventory");
	// tagItem* item = inven->getTargetItem();
	tagItem* getTargetItem() { return _targetItem; }

	//인벤토리의 모든 아이템포인터를 벡터에 담아서 반환해준다
	vector<tagItem*> getItems()
	{
		tagItem* item;
		vector<tagItem*> vItem;
		for (int i = 0; i < _vInventory.size(); ++i)
		{
			item = &_vInventory[i];
			vItem.push_back(item);
		}
		return vItem;
	}
	
	//인벤토리 상태 접근자
	invenDirection::Enum getDirection() { return _direction; }
	//인벤토리 상태 설정자 
	void setDirection(invenDirection::Enum direction) { _direction = direction; }
	
	//============ 콜백 등록 =============
	//인벤토리 창 상태 바뀌는 콜백 함수 
	void changeState(tagMessage msg);
	//타겟 아이템 바뀌는 콜백 함수 (마우스 클래스 한테 받는다)
	void setTargetItem(tagMessage msg);

	inventory() {}
	~inventory() {}
};

