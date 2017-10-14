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
	vector<tagItem>			_vInventory;

	tagItem*				_targetItem;
	
	invenDirection::Enum	_direction;

	tagMainInventory		_mainInventory;
	tagSubInventory			_subInventory;
public:
	HRESULT init(string name);
	void release();
	void update();
	void render();
	
	//���� ������ ������ ������
	tagItem* getTargetItemType() { return _targetItem; }

	//�κ��丮�� ��� �����������͸� ���Ϳ� ��Ƽ� ��ȯ���ش�
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
	
	//�κ��丮 ���� ������
	invenDirection::Enum getDirection() { return _direction; }
	//�κ��丮 ���� ������ 
	void setDirection(invenDirection::Enum direction) { _direction = direction; }
	
	//============ �ݹ� ��� =============
	//�κ��丮 â ���� �ٲ�� �ݹ� �Լ� 
	void changeState(tagMessage msg);
	//Ÿ�� ������ �ٲ�� �ݹ� �Լ� (���콺 Ŭ���� ���� �޴´�)
	void setTargetItem(tagMessage msg);

	inventory() {}
	~inventory() {}
};

