#include "stdafx.h"
#include "inventory.h"

using namespace invenDirection;

HRESULT inventory::init(string name)
{
	gameObject::init(name);
	//�⺻ �κ��丮 â ����ü �ʱ�ȭ
	_subInventory.img = IMAGEMANAGER->findImage("subInventory");
	_subInventory.pos = tagFloat(WINSIZEX / 2, WINSIZEY - 80);
	_subInventory.rc = RectMakeCenter(_subInventory.pos.x, _subInventory.pos.y,
		_subInventory.img->getWidth(), _subInventory.img->getHeight());
	//�κ��丮 ���� �ʱ�ȭ
	_direction = SUB_BOTTOM;
	//���� �κ��丮 12ĭ �ƹ��͵� ���� ���·� �ʱ�ȭ ���ش�
	for (int i = 0; i < 12; i++)
	{
		char str[100] = "";
		sprintf(str, "%d", i);

		tagItem	item = tagItem((string)str, tagFloat(_subInventory.rc.left + 49 + 64*i , _subInventory.pos.y));
		_vInventory.push_back(item);
	}
	//������ ä���־� �ش�
	_vInventory[0] = tagItem("axe", tagFloat(_vInventory[0].pos.x, _vInventory[0].pos.y),0, itemType::TOOL);
	_vInventory[1] = tagItem("hoe", tagFloat(_vInventory[1].pos.x, _vInventory[1].pos.y),0, itemType::TOOL);
	_vInventory[2] = tagItem("pixHoe", tagFloat(_vInventory[2].pos.x, _vInventory[2].pos.y),0, itemType::TOOL);
	_vInventory[3] = tagItem("sickle", tagFloat(_vInventory[3].pos.x, _vInventory[3].pos.y),0, itemType::TOOL);
	_vInventory[4] = tagItem("sword", tagFloat(_vInventory[4].pos.x, _vInventory[4].pos.y),0, itemType::TOOL);
	//�÷��̾ ���� ����ִ� ������ (������ �����̹Ƿ� new���ش�)
	_targetItem = new tagItem;
	_targetItem = &_vInventory[0];		//���� ������ ������ �ʱ�ȭ

	//msg.data -> �̰� ����ȯ���� �κ��丮 â ���� ���� 
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState(msg);
	});
	//���콺 Ŭ���� ���� Ÿ�� �������� �ٲ�� �ݹ� �Լ� 
	this->addCallback("setTargetItem", [this](tagMessage msg)
	{
		this->setTargetItem(msg);
	});

	return S_OK;
}

void inventory::release()
{
	gameObject::release();
}

void inventory::update()
{
	gameObject::update();

	
}

void inventory::render()
{
	//���°� ���� �κ��丮 �����϶� ���� �κ��丮 �׷�����. 
	if (_direction == SUB_BOTTOM || _direction == SUB_TOP)
	{
		//���� �κ��丮 ������ �̹��� �׷��ְ� 
		_subInventory.img->scaleRender(getMemDC(), _subInventory.rc.left, _subInventory.rc.top,
			_subInventory.img->getWidth(), _subInventory.img->getHeight());
		//�귯���� NULL_BRUSH�� ��Ʈ�� �������� �ٲ����� 
		HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);
	
		for (int i = 0; i < 12; ++i)
		{	
			HPEN pen = CreatePen(PS_SOLID, 3, RGB(255,0,0));
			//���δ� ��Ʈ �׵θ��� �������� �ٲ��ش�
			HPEN oldPen = (HPEN)SelectObject(getMemDC(), GetStockObject(NULL_PEN));
			//Ÿ�� �����۸� ������ ���� ĥ���ش�.
			if (_targetItem == &_vInventory[i])
			{
				HPEN oldPen = (HPEN)SelectObject(getMemDC(), pen);
			}
			//Ÿ�� �����ۿ� ��Ʈ �׷�����
			Rectangle(getMemDC(),_vInventory[i].rc.left, _vInventory[i].rc.top, 
				_vInventory[i].rc.right, _vInventory[i].rc.bottom);
		
			SelectObject(getMemDC(), oldPen);
			DeleteObject(pen);
			//�κ��丮â�� �ִ� �������� �̹����� �ִٸ� �׷���� 
			if (_vInventory[i].img != NULL)
			{
				_vInventory[i].img->scaleRender(getMemDC(), _vInventory[i].rc.left, _vInventory[i].rc.top,
					_vInventory[i].img->getWidth(), _vInventory[i].img->getHeight());
			}
		}
		SelectObject(getMemDC(), oldBrush);
		DeleteObject(brush);
	}
}

