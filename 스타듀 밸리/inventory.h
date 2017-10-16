#pragma once
#include "gameObject.h"
#include "item.h"
#include <vector>

using namespace itemType;

struct tagSubInventory
{
	image*			img;
	tagFloat		pos;
	RECT			rc;
};

struct tagMainInventory
{
	image*			img;
	tagFloat		pos;
	RECT			rc;
};

struct tagExplain
{
	image*			img;
	RECT			rc;
	tagFloat		pos;
	string			itemName;
	string			itemExplain;
	string			itemType;
	bool			isPicking;
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

struct tagLayer
{
	image*	img;
	bool	isDark;
};

class inventory : public gameObject
{
private:
	vector<tagItem>			_vInventory;			//���������� ��� ���� �κ��丮 ���� 

	tagItem*				_targetItem;			//�÷��̾ ���� ��� �ִ� ������ (����������)
	
	invenDirection::Enum	_direction;				//�κ��丮 â ���� 

	tagMainInventory		_mainInventory;			//���� �κ��丮 â ����ü
	tagSubInventory			_subInventory;			//�⺻ �κ��丮  â ����ü
	tagExplain				_explain;				//������ ���� â ����ü

	//�κ��丮 â���� ������ �ű� �� ��� �ϴ� ���� ������
	bool					_isPicking;
	tagItem					_tempItem;
	tagItem				  _pickingItem;

	//������ ���̾� 
	tagLayer				_layer;

public:
	HRESULT init(string name);
	void release();
	void update();
	void render();

	void keyContoroll();
	//���� �ٲ��ִ� �Լ�
	void changeItem();
	
	//���� ������ ������ ������(�÷��̾�� �� �Լ��� �ڽ��� ���� ��� �ִ� ������������ �޾� �� �� �ִ�.)
	//����� #include "item.h"�޾��ְ�
	// inventory* inven = (inventory*)TOWNWORLD->findObject(objectType::INTERFACE , "inventory");
	// tagItem* item = inven->getTargetItem();
	tagItem* getTargetItem() { return _targetItem; }
	//�������� ã�Ƽ� �����������͸� ��ȯ���ش�. ������ NULL�� ��ȯ
	tagItem* findItem(string name)
	{
		for (int i = 0; i < _vInventory.size(); ++i)
		{
			if (_vInventory[i].name == name)return &_vInventory[i];
		}
		return NULL;
	}
	//�κ��丮�� ã�¾������� ������ ������ ��ȯ�Ѵ�.
	bool isFindItem(string name)
	{
		for (int i = 0; i < _vInventory.size(); ++i)
		{
			if (_vInventory[i].name == name)return true;
		}
		return false;
	}
	
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
	//������ �߰� �ݹ��Լ� 
	void addItem(tagMessage msg);
	//������ Ÿ�� ��Ʈ������ ��ȯ �޴� �Լ�
	string getStringItemType(tagItem* item);

	itemType::Enum getItemType(string itemName);

	inventory() {}
	~inventory() {}
};

