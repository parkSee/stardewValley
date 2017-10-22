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

void tileMap::mapSaveNew(string fileName)
{
	HANDLE file;
	DWORD write;

	file = CreateFile(fileName.c_str(), GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	tagTileSaveNew tileSaveNew;

	for (int j = 0; j < TILEY; ++j)
	{
		for (int i = 0; i < TILEX; ++i)
		{
			memset(&tileSaveNew, 0, sizeof(tileSaveNew));

			tileSaveNew.idX = i;
			tileSaveNew.idY = j;
			tileSaveNew.terrain = _pTile[i][j]->getTerrain();

			sprintf(tileSaveNew.imageKey, _pTile[i][j]->getImageKey().c_str());
			tileSaveNew.frameX = _pTile[i][j]->getFrameX();
			tileSaveNew.frameY = _pTile[i][j]->getFrameY();
			tileSaveNew.isMovable = _pTile[i][j]->getIsMovable1();

			sprintf(tileSaveNew.imageKey2, _pTile[i][j]->getImageKey2().c_str());
			tileSaveNew.frameX2 = _pTile[i][j]->getFrameX2();
			tileSaveNew.frameY2 = _pTile[i][j]->getFrameY2();
			tileSaveNew.isMovable2 = _pTile[i][j]->getIsMovable2();

			WriteFile(file, &tileSaveNew, sizeof(tileSaveNew), &write, NULL);
		}
	}

	CloseHandle(file);
}

void tileMap::mapLoadNew(string fileName)
{
	HANDLE file;
	DWORD read;

	file = CreateFile(fileName.c_str(), GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	tagTileSaveNew tileSaveNew;

	while (true)
	{
		memset(&tileSaveNew, 0, sizeof(tileSaveNew));
		ReadFile(file, &tileSaveNew, sizeof(tileSaveNew), &read, NULL);
		if (read != sizeof(tileSaveNew)) break;

		if (0 <= tileSaveNew.idX && tileSaveNew.idX < TILEX &&
			0 <= tileSaveNew.idY && tileSaveNew.idY < TILEY)
		{
			_pTile[tileSaveNew.idX][tileSaveNew.idY]->init(tileSaveNew.idX, tileSaveNew.idY, tileSaveNew.terrain);
			_pTile[tileSaveNew.idX][tileSaveNew.idY]->changeImage(tileSaveNew.imageKey);
			_pTile[tileSaveNew.idX][tileSaveNew.idY]->setFrameX(tileSaveNew.frameX);
			_pTile[tileSaveNew.idX][tileSaveNew.idY]->setFrameY(tileSaveNew.frameY);
			_pTile[tileSaveNew.idX][tileSaveNew.idY]->setIsMovable1(tileSaveNew.isMovable);
			_pTile[tileSaveNew.idX][tileSaveNew.idY]->changeImage2(tileSaveNew.imageKey2);
			_pTile[tileSaveNew.idX][tileSaveNew.idY]->setFrameX2(tileSaveNew.frameX2);
			_pTile[tileSaveNew.idX][tileSaveNew.idY]->setFrameY2(tileSaveNew.frameY2);
			_pTile[tileSaveNew.idX][tileSaveNew.idY]->setIsMovable2(tileSaveNew.isMovable2);
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

	//있던 오브젝트 다 날려버리고
	for (int j = 0; j < objectType::END; ++j)
	{
		auto vObj = *TOWNWORLD->getObjectList((objectType::Enum)j);
		for (int i = 0; i < vObj.size(); ++i)
		{
			vObj[i]->setDestroy();
		}
	}
	//타일이 들고있던 포인터도 다 날려버리고
	for (int j = 0; j < TILEY; ++j)
	{
		for (int i = 0; i < TILEX; ++i)
		{
			_pTile[i][j]->setPObj(NULL);
		}
	}

	//읽어와서 오브젝트 생성해서 타운월드에 넣기
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
		////타일에도 오브젝트 연결해주기
		//_pTile[objSave.idX][objSave.idY]->setPObj(tempobj);
	}

	CloseHandle(file);
}
