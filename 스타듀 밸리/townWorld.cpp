#include "stdafx.h"
#include "townWorld.h"
#include <algorithm>
#include "gameObject.h"
#include "tileMap.h"
#include "mapToolTile.h"

using namespace objectType;

HRESULT townWorld::init()
{
	//�̸� �����ص� Ÿ�Ժ��� ���� �ʱ�ȭ�Ѵ�.
	for (int i = 0; i < objectType::END; ++i)
	{
		arrObject v;
		_totalObject.insert(make_pair((objectType::Enum)i, v));
	}

	return S_OK;
}


void townWorld::release()
{

}


void townWorld::update() 
{
	auto mIter = _totalObject.begin();
	auto mIterEnd = _totalObject.end();
	//���� ���� ��ȯ
	for (; mIter != mIterEnd; ++mIter)
	{
		//�״��� ���͸� ��ȯ�Ѵ�
		for (int i = 0; i < mIter->second.size(); ++i)
		{
			gameObject* object = mIter->second[i];
			if (object->isActiveObject())
			{
				object->update();
			}
			else if (!object->isLive())
			{
				object->release();
				delete object;
				mIter->second.erase(mIter->second.begin() + i);
				--i;
			}
		}
	}
}


void townWorld::render() 
{

	//Ÿ���� ���� �׷��ش�
	arrObject tile = _totalObject[TILE];
	for (int i = 0; i < tile.size(); ++i)
	{
		tile[i]->render();
	}

	//======================�̿��� ��� ������Ʈ(HUMAN , OBJ)���� z�����Ѵ�=========================

	vector<gameObject*> zOrderObject;			//z���� �� ������Ʈ���� ����� ����

	for (int i = 0 ; i < _totalObject[HUMAN].size(); ++i)
	{
		zOrderObject.push_back(_totalObject[HUMAN][i]);
	}

	for (int i = 0; i < _totalObject[OBJ].size(); ++i)
	{
		zOrderObject.push_back(_totalObject[OBJ][i]);
	}

	for (int i = 0; i < _totalObject[ITEM].size(); ++i)
	{
		zOrderObject.push_back(_totalObject[ITEM][i]);
	}
	
	//y���� �������� �������� ������ ���ش�
	sort(zOrderObject.begin(), zOrderObject.end(), [this](auto a, auto b) {
		if (a->_pos.y < b->_pos.y)return true;
		return false;
	});
	
	//���� �� ������� �������ش�.
	for (int i = 0; i < zOrderObject.size(); ++i)
	{
		if (zOrderObject[i]->isActiveObject())
		{
			zOrderObject[i]->render();
		}
	}

	//z������ ���� ���Ŀ� UI�� �׸���
	for (int i = 0; i < _totalObject[WEATHER].size(); ++i)
	{
		_totalObject[WEATHER][i]->render();
	}

	for (int i = 0; i < _totalObject[INTERFACE].size(); ++i)
	{
		_totalObject[INTERFACE][i]->render();
	}

	for (int i = 0; i < _totalObject[MOUSE].size(); ++i)
	{
		_totalObject[MOUSE][i]->render();
	}

}


//������Ʈ �Ŵ����� ������Ʈ�� �߰��Ѵ�.
void townWorld::addObject(objectType::Enum type, gameObject* obj)
{
	_totalObject[type].push_back(obj);
}

//�ش� �̸��� ���� ������Ʈ �ϳ��� ã�Ƽ� ��ȯ�Ѵ�. ������ NULL�� ��ȯ.
gameObject* townWorld::findObject(objectType::Enum type, string name)
{
	arrObject v = _totalObject[type];
	for (int i = 0; i < v.size(); ++i)
	{
		if ( v[i]->_name == name && v[i]->isActiveObject())
		{
			return v[i];
		}
	}
	return NULL;
}

//�ش� �̸��� ���� ������Ʈ�� ��� ã�Ƽ� vector�� ��� ��ȯ�Ѵ�.
vector<gameObject*> townWorld::findObjects(objectType::Enum type, string name)
{
	arrObject v = _totalObject[type];
	arrObject temp;

	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i]->_name == name && v[i]->isActiveObject())
		{
			temp.push_back(v[i]);
		}
	}
	
	return temp;
}

//�ش� Ÿ���� ���� ��� ������Ʈ�� ����Ʈ�� ��ȯ�Ѵ�.
vector<gameObject*>* townWorld::getObjectList(objectType::Enum type)
{
	return &_totalObject[type];
}

//��ü ��� ������Ʈ�� ���Ϳ� ��Ƽ� ��ȯ���ش�.
vector<gameObject*> townWorld::getTotalObject()
{
	vector<gameObject*> objects;
	mIter miter;

	for (miter = _totalObject.begin(); miter != _totalObject.end(); ++miter)
	{
		for (int i = 0; i < miter->second.size(); ++i)
		{
			objects.push_back(miter->second[i]);
		}
	}
	
	return objects;
}

//Ÿ�� ��
mapToolTile* townWorld::getTile(int indexX, int indexY)
{
	return _tileMap->getTile(indexX, indexY);
}
