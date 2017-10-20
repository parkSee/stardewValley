#include "stdafx.h"
#include "tileMap.h"
#include "motherObject.h"


void tileMap::mapSave(string fileName)
{
	HANDLE file;
	DWORD write;

	file = CreateFile(fileName.c_str(), GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	tagTileSave tileSave;

	for (int j = 0; j < TILEY; ++j)
	{
		for (int i = 0; i < TILEX; ++i)
		{
			memset(&tileSave, 0, sizeof(tileSave));

			tileSave.idX = i;
			tileSave.idY = j;
			tileSave.terrain = _pTile[i][j]->getTerrain();

			sprintf(tileSave.imageKey, _pTile[i][j]->getImageKey().c_str());
			tileSave.frameX = _pTile[i][j]->getFrameX();
			tileSave.frameY = _pTile[i][j]->getFrameY();

			WriteFile(file, &tileSave, sizeof(tileSave), &write, NULL);
		}
	}

	CloseHandle(file);
}

void tileMap::mapLoad(string fileName)
{
	HANDLE file;
	DWORD read;

	file = CreateFile(fileName.c_str(), GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	tagTileSave tileSave;

	while (true)
	{
		memset(&tileSave, 0, sizeof(tileSave));
		ReadFile(file, &tileSave, sizeof(tileSave), &read, NULL);
		if (read != sizeof(tileSave)) break;

		if (0 <= tileSave.idX && tileSave.idX < TILEX &&
			0 <= tileSave.idY && tileSave.idY < TILEY)
		{
			_pTile[tileSave.idX][tileSave.idY]->init(tileSave.idX, tileSave.idY, tileSave.terrain);
			_pTile[tileSave.idX][tileSave.idY]->changeImage(tileSave.imageKey);
			_pTile[tileSave.idX][tileSave.idY]->setFrameX(tileSave.frameX);
			_pTile[tileSave.idX][tileSave.idY]->setFrameY(tileSave.frameY);
		}
	}

	CloseHandle(file);
}

//-------------------------------------------------------------

void tileMap::objectSave(string fileName)
{
	HANDLE file;
	DWORD write;

	file = CreateFile(fileName.c_str(), GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	tagObjectSave objSave;

	for (int j = 0; j < objectType::END; ++j)
	{
		auto vObj = *TOWNWORLD->getObjectList((objectType::Enum)j);
		for (int i = 0; i < vObj.size(); ++i)
		{
			auto obj = vObj[i];

			ZeroMemory(&objSave, sizeof(objSave));

			objSave.idX = obj->_pos.x / TILESIZE;
			objSave.idY = obj->_pos.y / TILESIZE;
			objSave.object = ((motherObject*)obj)->_object;
			//---------------
			int idX, idY;
			OBJECT::Enum object;
			objectType::Enum objectType;
			int frameX, frameY;
			//tagFloat pos;
			pivot::Enum pivot;

			string name;
			string imageKey;

			WriteFile(file, &objSave, sizeof(objSave), &write, NULL);
		}
	}

	CloseHandle(file);
}

void tileMap::objectLoad(string fileName)
{
	//HANDLE file;
	//DWORD read;
	//
	//file = CreateFile(fileName.c_str(), GENERIC_READ, 0, NULL,
	//	OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	//
	////있던 오브젝트 다 날려버리고
	//for (int j = 0; j < objectType::END; ++j)
	//{
	//	auto vObj = *TOWNWORLD->getObjectList((objectType::Enum)j);
	//	for (int i = 0; i < vObj.size(); ++i)
	//	{
	//		vObj[i]->setDestroy();
	//	}
	//}
	////타일이 들고있던 포인터도 다 날려버리고
	//for (int j = 0; j < TILEY; ++j)
	//{
	//	for (int i = 0; i < TILEX; ++i)
	//	{
	//		_pTile[i][j]->setPObj(NULL);
	//	}
	//}
	//
	////읽어와서 오브젝트 생성해서 타운월드에 넣기
	//testObject* tempobj = NULL;
	//tagObjectSave tag1;
	//ZeroMemory(&tag1, sizeof(tag1));
	//while (true)
	//{
	//	ReadFile(file, &tag1, sizeof(tag1), &read, NULL);
	//	if (read != sizeof(tag1)) break;
	//
	//	tempobj = new testObject;
	//	tempobj->init(tag1.name, tag1.imageKey, tag1.pos, tag1.pivot);
	//	tempobj->_object = tag1.object;
	//	tempobj->setFrameX(tag1.frameX);
	//	tempobj->setFrameY(tag1.frameY);
	//	tempobj->setIdX(tag1.idX);
	//	tempobj->setIdY(tag1.idY);
	//
	//	TOWNWORLD->addObject(tag1.objectType, tempobj);
	//
	//	//타일에도 오브젝트 연결해주기
	//	_pTile[tag1.idX][tag1.idY]->setPObj(tempobj);
	//
	//	tempobj = NULL;
	//	ZeroMemory(&tag1, sizeof(tag1));
	//}
	//
	//CloseHandle(file);
}
