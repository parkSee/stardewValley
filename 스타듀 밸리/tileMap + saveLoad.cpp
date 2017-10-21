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

			sprintf(tileSave.imageKey2, _pTile[i][j]->getImageKey2().c_str());
			tileSave.frameX2 = _pTile[i][j]->getFrameX2();
			tileSave.frameY2 = _pTile[i][j]->getFrameY2();

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
			_pTile[tileSave.idX][tileSave.idY]->changeImage2(tileSave.imageKey2);
			_pTile[tileSave.idX][tileSave.idY]->setFrameX2(tileSave.frameX2);
			_pTile[tileSave.idX][tileSave.idY]->setFrameY2(tileSave.frameY2);
		}
	}

	CloseHandle(file);
}

//void tileMap::mapLoadPast(string fileName)
//{
//	HANDLE file;
//	DWORD read;
//
//	file = CreateFile(fileName.c_str(), GENERIC_READ, 0, NULL,
//		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//
//	tagTileSavePast tileSavePast;
//
//	while (true)
//	{
//		memset(&tileSavePast, 0, sizeof(tileSavePast));
//		ReadFile(file, &tileSavePast, sizeof(tileSavePast), &read, NULL);
//		if (read != sizeof(tileSavePast)) break;
//
//		if (0 <= tileSavePast.idX && tileSavePast.idX < TILEX &&
//			0 <= tileSavePast.idY && tileSavePast.idY < TILEY)
//		{
//			_pTile[tileSavePast.idX][tileSavePast.idY]->init(tileSavePast.idX, tileSavePast.idY, tileSavePast.terrain);
//			_pTile[tileSavePast.idX][tileSavePast.idY]->changeImage(tileSavePast.imageKey);
//			_pTile[tileSavePast.idX][tileSavePast.idY]->setFrameX(tileSavePast.frameX);
//			_pTile[tileSavePast.idX][tileSavePast.idY]->setFrameY(tileSavePast.frameY);
//		}
//	}
//
//	CloseHandle(file);
//}

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
			memset(&objSave, 0, sizeof(objSave));

			auto obj = vObj[i];

			objSave.idX = obj->_pos.x / TILESIZE;
			objSave.idY = obj->_pos.y / TILESIZE;
			objSave.object = obj->_objEnum;

			////---------------
			//int idX, idY;
			//OBJECT::Enum object;
			//objectType::Enum objectType;
			//int frameX, frameY;
			////tagFloat pos;
			//pivot::Enum pivot;
			//
			//string name;
			//string imageKey;

			WriteFile(file, &objSave, sizeof(objSave), &write, NULL);
		}
	}

	CloseHandle(file);
}

void tileMap::objectLoad(string fileName)
{
	HANDLE file;
	DWORD read;

	//�ִ� ������Ʈ �� ����������
	for (int j = 0; j < objectType::END; ++j)
	{
		auto vObj = *TOWNWORLD->getObjectList((objectType::Enum)j);
		for (int i = 0; i < vObj.size(); ++i)
		{
			vObj[i]->setDestroy();
		}
	}
	//Ÿ���� ����ִ� �����͵� �� ����������
	for (int j = 0; j < TILEY; ++j)
	{
		for (int i = 0; i < TILEX; ++i)
		{
			_pTile[i][j]->setPObj(NULL);
		}
	}

	//�о�ͼ� ������Ʈ �����ؼ� Ÿ����忡 �ֱ�
	file = CreateFile(fileName.c_str(), GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	tagObjectSave objSave;

	while (true)
	{
		memset(&objSave, 0, sizeof(objSave));
		ReadFile(file, &objSave, sizeof(objSave), &read, NULL);
		if (read != sizeof(objSave)) break;



		////--------------------------------------------------------
		//gameObject* tempobj = new gameObject;
		//tempobj->init(objSave.name, objSave.imageKey,
		//	tagFloat(objSave.idX * TILESIZE, objSave.idY * TILESIZE), objSave.pivot);
		//tempobj->_object = objSave.object;
		//tempobj->setFrameX(objSave.frameX);
		//tempobj->setFrameY(objSave.frameY);
		//tempobj->setIdX(objSave.idX);
		//tempobj->setIdY(objSave.idY);
		//
		//TOWNWORLD->addObject(objSave.objectType, tempobj);
		//
		////Ÿ�Ͽ��� ������Ʈ �������ֱ�
		//_pTile[objSave.idX][objSave.idY]->setPObj(tempobj);
	}

	CloseHandle(file);
}
