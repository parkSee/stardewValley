#include "stdafx.h"
#include "tileMap.h"
#include "testObject.h"


HRESULT tileMap::init()
{
	for (int j = 0; j < TILEY; ++j)
	{
		for (int i = 0; i < TILEX; ++i)
		{
			_pTile[i][j] = new mapToolTile;
			_pTile[i][j]->init(i, j);
		}
	}

	load();


	////맵툴용
	//_selectIdX = _selectIdY = 0;
	//
	//_rc1 = RectMake(500, 500 + 50, 70, 40);
	//_rc2 = RectMake(_rc1.right + 30, _rc1.top, 70, 40);
	//_rc3 = RectMake(_rc2.left, _rc2.bottom + 20, 150, 40);
	//_kind = KIND_TERRAIN;

	return S_OK;
}
void tileMap::release()
{

}
void tileMap::update()
{
	//타일은 업데이트 돌리지 말자 -----


	////업데이트는 전부다 맵툴용이네. 나중에 맵툴씬에다 빼자
	////엥;; 맵툴씬에서도 여기 업데이트 안돌리고 있네;;
	//if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	//{
	//	//if (WINSIZEX - IMAGEMANAGER->findImage("tiles")->getWidth() <= _ptMouse.x && _ptMouse.x <= WINSIZEX &&
	//	//	0 <= _ptMouse.y && _ptMouse.y <= IMAGEMANAGER->findImage("tiles")->getHeight())
	//	//{
	//	//	_selectIdX = (_ptMouse.x - (WINSIZEX - IMAGEMANAGER->findImage("tiles")->getWidth())) / TILESIZE;
	//	//	_selectIdY = _ptMouse.y / TILESIZE;
	//	//}
	//	if (PtInRect(&_rc1, _ptMouse)) _kind = KIND_TERRAIN;
	//	if (PtInRect(&_rc2, _ptMouse)) _kind = KIND_OBJECT;
	//	if (PtInRect(&_rc3, _ptMouse)) _kind = KIND_OBJECT_ERASER;
	//}
	//if (KEYMANAGER->isStayKeyDown(VK_LBUTTON) &&
	//	!(PtInRect(&_rc1, _ptMouse) || PtInRect(&_rc2, _ptMouse) || PtInRect(&_rc3, _ptMouse)))
	//{
	//	if (0 <= (CAMERAMANAGER->getRenderRc().left + _ptMouse.x) && (CAMERAMANAGER->getRenderRc().left + _ptMouse.x) < TILEX * TILESIZE &&
	//		0 <= (CAMERAMANAGER->getRenderRc().top + _ptMouse.y) && (CAMERAMANAGER->getRenderRc().top + _ptMouse.y) < TILEY * TILESIZE)
	//	{
	//		int idx = (CAMERAMANAGER->getRenderRc().left + _ptMouse.x) / TILESIZE;
	//		int idy = (CAMERAMANAGER->getRenderRc().top + _ptMouse.y) / TILESIZE;
	//
	//		switch (_kind)
	//		{
	//		case tileMap::KIND_TERRAIN:
	//			_pTile[idx][idy]->setFrameX(_selectIdX);
	//			_pTile[idx][idy]->setFrameY(_selectIdY);
	//			break;
	//		case tileMap::KIND_OBJECT:
	//		{
	//			if (_pTile[idx][idy]->getPObj() != NULL)
	//			{
	//				_pTile[idx][idy]->getPObj()->setDestroy();
	//				_pTile[idx][idy]->setPObj(NULL);
	//			}
	//			testObject* tempobj = new testObject;
	//			tempobj->init("test", "tileSprite", tagFloat(idx * TILESIZE, idy * TILESIZE), pivot::LEFT_TOP);
	//			tempobj->setIdX(idx);
	//			tempobj->setIdY(idy);
	//			tempobj->setFrameX(_selectIdX);
	//			tempobj->setFrameY(_selectIdY);
	//			switch (spriteNumber(_selectIdX, _selectIdY))
	//			{
	//			case (spriteNumber(1, 5)):
	//				tempobj->_object = OBJECT::TREE1;
	//				break;
	//			case (spriteNumber(4, 5)):
	//				tempobj->_object = OBJECT::TREE2;
	//				break;
	//			case (spriteNumber(11, 5)):
	//				tempobj->_object = OBJECT::TREE3;
	//				break;
	//			default:
	//				break;
	//			}
	//			TOWNWORLD->addObject(objectType::OBJ, tempobj);
	//			_pTile[idx][idy]->setPObj(tempobj);
	//		}
	//		break;
	//		case tileMap::KIND_OBJECT_ERASER:
	//			if (_pTile[idx][idy]->getPObj() != NULL)
	//			{
	//				_pTile[idx][idy]->getPObj()->setDestroy();
	//				_pTile[idx][idy]->setPObj(NULL);
	//			}
	//			break;
	//		}
	//	}
	//}
}
void tileMap::render()
{
	//타일 렌더 - 창에 보이는 만큼만!
	RECT renderRc = CAMERAMANAGER->getRenderRc();
	int startIndexX = renderRc.left / TILESIZE;
	int startIndexY = renderRc.top / TILESIZE;
	int endIndexX = renderRc.right / TILESIZE;
	int endIndexY = renderRc.bottom / TILESIZE;
	
	//타일 범위 벗어나는거 방지
	if (startIndexX < 0) startIndexX = 0;
	if (startIndexY < 0) startIndexY = 0;
	if (endIndexX >= TILEX) endIndexX = TILEX - 1;
	if (endIndexY >= TILEY) endIndexY = TILEY - 1;
	
	for (int j = startIndexY; j <= endIndexY; ++j)
	{
		for (int i = startIndexX; i <= endIndexX; ++i)
		{
			_pTile[i][j]->render();
		}
	}


	////지형, 오브젝트 선택 버튼 렌더
	//Rectangle(getMemDC(), _rc1.left, _rc1.top, _rc1.right, _rc1.bottom);
	//Rectangle(getMemDC(), _rc2.left, _rc2.top, _rc2.right, _rc2.bottom);
	//Rectangle(getMemDC(), _rc3.left, _rc3.top, _rc3.right, _rc3.bottom);
	//TextOut(getMemDC(), _rc1.left + 5, _rc1.top + 5, "지형", 4);
	//TextOut(getMemDC(), _rc2.left + 5, _rc2.top + 5, "오브젝트", 8);
	//TextOut(getMemDC(), _rc3.left + 5, _rc3.top + 5, "오브젝트 지우개", 15);
	////지형, 오브젝트 선택된 버튼 표시
	//switch (_kind)
	//{
	//case tileMap::KIND_TERRAIN:
	//	EllipseMakeCenter(getMemDC(), _rc1.left + (_rc1.right - _rc1.left) / 2, _rc1.top + (_rc1.bottom - _rc1.top) / 2, 10, 10);
	//	break;
	//case tileMap::KIND_OBJECT:
	//	EllipseMakeCenter(getMemDC(), _rc2.left + (_rc2.right - _rc2.left) / 2, _rc2.top + (_rc2.bottom - _rc2.top) / 2, 10, 10);
	//	break;
	//}
}


void tileMap::setTileFrameByAround(int indexX, int indexY)
{
	mapToolTile* tile = _pTile[indexX][indexY];

	//TERRAIN::Enum left, right, top, bottom;
	//left = right = top = bottom = TERRAIN::NONE;
	//
	//left = _pTile[indexX - 1][indexY]->getTerrain();
	//right = _pTile[indexX + 1][indexY]->getTerrain();
	//top = _pTile[indexX][indexY - 1]->getTerrain();
	//bottom = _pTile[indexX][indexY + 1]->getTerrain();

	TERRAIN::Enum terrain[3][3];
	for (int j = 0; j < 3; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			terrain[i][j] = TERRAIN::NONE;

			int x = indexX - 1 + i;
			int y = indexY - 1 + j;
			//타일 범위 벗어나는거 방지
			if (x < 0 || x >= TILEX || y < 0 || y >= TILEY) continue;
			terrain[i][j] = _pTile[x][y]->getTerrain();
		}
	}

	switch (tile->getTerrain())
	{
	case TERRAIN::NONE:
		break;
	case TERRAIN::DIRT:
		break;
	case TERRAIN::GRASS:
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//주변 다 잔디
			tile->setFrameX(0); tile->setFrameY(7); break;
		}
		if (terrain[1][0] == TERRAIN::DIRT &&
			terrain[0][1] == TERRAIN::DIRT && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::DIRT &&
			terrain[1][2] == TERRAIN::DIRT)
		{		//상하좌우 흙
			tile->setFrameX(6); tile->setFrameY(7); break;
		}
		if (terrain[0][0] == TERRAIN::DIRT && terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//왼쪽 위만 흙
			tile->setFrameX(3); tile->setFrameY(10); break;
		}
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::DIRT &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//오른쪽 위만 흙
			tile->setFrameX(0); tile->setFrameY(10); break;
		}
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[0][2] == TERRAIN::DIRT && terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//왼쪽 아래만 흙
			tile->setFrameX(3); tile->setFrameY(8); break;
		}
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::DIRT)
		{		//오른쪽 아래만 흙
			tile->setFrameX(0); tile->setFrameY(8); break;
		}
		if (terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::DIRT && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//왼쪽 흙
			tile->setFrameX(3); tile->setFrameY(9); break;
		}
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::DIRT &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS)
		{		//오른쪽 흙
			tile->setFrameX(0); tile->setFrameY(9); break;
		}
		if (terrain[1][0] == TERRAIN::DIRT &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//위쪽 흙
			tile->setFrameX(1); tile->setFrameY(10); break;
		}
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[1][2] == TERRAIN::DIRT)
		{		//아래쪽 흙
			tile->setFrameX(1); tile->setFrameY(8); break;
		}
		if (terrain[1][0] == TERRAIN::DIRT &&
			terrain[0][1] == TERRAIN::DIRT && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//왼쪽 위 끝 잔디
			tile->setFrameX(3); tile->setFrameY(7); break;
		}
		if (terrain[1][0] == TERRAIN::DIRT &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::DIRT &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS)
		{		//오른쪽 위 끝 잔디
			tile->setFrameX(2); tile->setFrameY(10); break;
		}
		if (terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::DIRT && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[1][2] == TERRAIN::DIRT)
		{		//왼쪽 아래 끝 잔디
			tile->setFrameX(2); tile->setFrameY(7); break;
		}
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::DIRT &&
			terrain[1][2] == TERRAIN::DIRT)
		{		//오른쪽 아래 끝 잔디
			tile->setFrameX(2); tile->setFrameY(8); break;
		}
		//입력된 상황 아니면 하나짜리 잔디로
		tile->setFrameX(6); tile->setFrameY(7); break;
		break;
	case TERRAIN::WATER:
		break;
	}
}

void tileMap::save()
{
	HANDLE file;
	DWORD write;

	file = CreateFile("mapSave.map", GENERIC_WRITE, 0, NULL,
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

			WriteFile(file, &tileSave, sizeof(tileSave), &write, NULL);
		}
	}

	CloseHandle(file);



	//file = CreateFile("objectSave.map", GENERIC_WRITE, 0, NULL,
	//	CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	//
	//for (int j = 0; j < objectType::END; ++j)
	//{
	//	auto vObj = *TOWNWORLD->getObjectList((objectType::Enum)j);
	//	for (int i = 0; i < vObj.size(); ++i)
	//	{
	//		auto obj = (testObject*)vObj[i];
	//
	//		tagObjectSave tag1;
	//		ZeroMemory(&tag1, sizeof(tag1));
	//
	//		tag1.objectType = (objectType::Enum)j;
	//		tag1.object = obj->_object;
	//		tag1.frameX = obj->getFrameX();
	//		tag1.frameY = obj->getFrameY();
	//		tag1.idX = obj->getIdX();
	//		tag1.idY = obj->getIdY();
	//		tag1.imageKey = "tileSprite";
	//		tag1.name = obj->getName();
	//		tag1.pivot = obj->getPivot();
	//		tag1.pos = obj->_pos;
	//
	//		WriteFile(file, &tag1, sizeof(tag1), &write, NULL);
	//	}
	//}
	//
	//CloseHandle(file);
}
void tileMap::load()
{
	HANDLE file;
	DWORD read;

	file = CreateFile("mapSave.map", GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	tagTileSave tileSave;

	for (int j = 0; j < TILEY; ++j)
	{
		for (int i = 0; i < TILEX; ++i)
		{
			memset(&tileSave, 0, sizeof(tileSave));

			ReadFile(file, &tileSave, sizeof(tileSave), &read, NULL);

			_pTile[i][j]->init(i, j, tileSave.terrain);
			//_pTile[i][j]->setTerrain(tileSave.terrain);
		}
	}

	CloseHandle(file);



	//file = CreateFile("objectSave.map", GENERIC_READ, 0, NULL,
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
