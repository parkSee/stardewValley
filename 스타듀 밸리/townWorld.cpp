#include "stdafx.h"
#include "townWorld.h"
#include <algorithm>
#include "gameObject.h"
#include "tileMap.h"
#include "mapToolTile.h"

using namespace objectType;

HRESULT townWorld::init()
{
	//미리 정의해둔 타입별로 맵을 초기화한다.
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
	//먼저 맵을 순환
	for (; mIter != mIterEnd; ++mIter)
	{
		//그다음 벡터를 순환한다
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

	//타일을 먼저 그려준다
	arrObject tile = _totalObject[TILE];
	for (int i = 0; i < tile.size(); ++i)
	{
		tile[i]->render();
	}

	//======================이외의 모든 오브젝트(HUMAN , OBJ)들을 z오더한다=========================

	vector<gameObject*> zOrderObject;			//z오더 할 오브젝트들을 담아줄 역할

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
	
	//y축을 기준으로 오름차순 정렬을 해준다
	sort(zOrderObject.begin(), zOrderObject.end(), [this](auto a, auto b) {
		if (a->_pos.y < b->_pos.y)return true;
		return false;
	});
	
	//정렬 된 순서대로 랜더해준다.
	for (int i = 0; i < zOrderObject.size(); ++i)
	{
		if (zOrderObject[i]->isActiveObject())
		{
			zOrderObject[i]->render();
		}
	}

	//z오더를 다해 준후에 UI를 그리자
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


//오브젝트 매니저에 오브젝트를 추가한다.
void townWorld::addObject(objectType::Enum type, gameObject* obj)
{
	_totalObject[type].push_back(obj);
}

//해당 이름을 가진 오브젝트 하나를 찾아서 반환한다. 없으면 NULL을 반환.
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

//해당 이름을 가진 오브젝트를 모두 찾아서 vector에 담아 반환한다.
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

//해당 타입을 가진 모든 오브젝트의 리스트를 반환한다.
vector<gameObject*>* townWorld::getObjectList(objectType::Enum type)
{
	return &_totalObject[type];
}

//전체 모든 오브젝트를 백터에 담아서 반환해준다.
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

//타일 겟
mapToolTile* townWorld::getTile(int indexX, int indexY)
{
	return _tileMap->getTile(indexX, indexY);
}
