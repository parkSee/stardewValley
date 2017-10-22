#include "stdafx.h"
#include "mapToolScene.h"


HRESULT mapToolScene::init()
{
	_map = new tileMap;
	_map->init();
	_map->mapLoad("mapSave.map");

	CAMERAMANAGER->setMapSize(TILESIZE * TILEX + WINSIZEX, TILESIZE * TILEY + WINSIZEY);

	CAMERAMANAGER->_pos.x = WINSIZEX / 2;
	CAMERAMANAGER->_pos.y = WINSIZEY / 2;

	//초기화

	//_sprite = SPRITE::TILESAMPLE;
	//_spriteImage = NULL;
	changeSprite(SPRITE::TILESAMPLE);
	_mode = MODE_MAP;
	_mapCam.x = _spriteCam.x = WINSIZEX / 2;
	_mapCam.y = _spriteCam.y = WINSIZEY / 2;
	_selectIdX = _selectIdY = 0;

	//스프라이트 개수만큼 렉트 생성 (스프라이트 변경할 버튼)
	for (int i = 0; i < SPRITE::END; ++i)
	{
		RECT rc = RectMake(WINSIZEX - 210, 10 + i * 50, 200, 40);
		_vSpriteRect.push_back(rc);
	}

	//타일샘플 전용 선택버튼 구조체 세팅
	setTileSampleSelect();

	//버튼들
	_moveFalse.init();
	_moveFalse.str = "moveFalse";
	_moveFalse.rc = RectMake(WINSIZEX - 110, 400, 100, 20);
	_moveFalse.bTrue = false;

	_moveTrue.init();
	_moveTrue.str = "moveTrue";
	_moveTrue.rc = RectMake(_moveFalse.rc.left - 110, _moveFalse.rc.top, 100, 20);
	_moveTrue.bTrue = true;

	return S_OK;
}
void mapToolScene::release()
{

}
void mapToolScene::update()
{
	//F1, F2 세이브 로드
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_map->mapSave("tempMapSave.map");
		_map->mapSaveNew("tempMapSaveNew.map");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		_map->mapLoad("tempMapSave.map");

		////로드하고나서 지형 종류에 따라서 프레임 맞춰준다
		//for (int j = 0; j < TILEY; ++j)
		//{
		//	for (int i = 0; i < TILEX; ++i)
		//	{
		//		_map->setTileFrameByAround(i, j);
		//	}
		//}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		_map->objectSave("tempObjectSave.map");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F4))
	{
		_map->objectLoad("tempObjectSave.map");
	}

	//탭 누르면 맵 - 스프라이트 전환
	if (KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		switch (_mode)
		{
		case mapToolScene::MODE_MAP:
			_mapCam = CAMERAMANAGER->_pos;

			_mode = MODE_SPRITE;
			CAMERAMANAGER->_pos = _spriteCam;
			break;
		case mapToolScene::MODE_SPRITE:
			_spriteCam = CAMERAMANAGER->_pos;

			_mode = MODE_MAP;
			CAMERAMANAGER->_pos = _mapCam;
			break;
		}
	}

	//모드에 따라 업데이트
	switch (_mode)
	{
	case mapToolScene::MODE_MAP:
		//_map->update();

		modeMapUpdate();

		TOWNWORLD->update();
		break;
	case mapToolScene::MODE_SPRITE:
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			leftClickInSprite();
		}
		break;
	}

	//카메라 이동
	int spd = 20;
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		CAMERAMANAGER->_pos.x -= spd;
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		CAMERAMANAGER->_pos.x += spd;
	}
	if (KEYMANAGER->isStayKeyDown('W'))
	{
		CAMERAMANAGER->_pos.y -= spd;
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		CAMERAMANAGER->_pos.y += spd;
	}
}
void mapToolScene::render()
{
	//모드에 따라 렌더
	switch (_mode)
	{
	case mapToolScene::MODE_MAP:
		_map->render();

		//마우스 대고있는 칸 표시
		if (0 <= CAMERAMANAGER->getRenderRc().left + _ptMouse.x && CAMERAMANAGER->getRenderRc().left + _ptMouse.x < TILEX * TILESIZE &&
			0 <= CAMERAMANAGER->getRenderRc().top + _ptMouse.y && CAMERAMANAGER->getRenderRc().top + _ptMouse.y < TILEY * TILESIZE)
		{
			HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), GetStockObject(NULL_BRUSH));
			RectangleMake(getMemDC(), -CAMERAMANAGER->getRenderRc().left + (CAMERAMANAGER->getRenderRc().left + _ptMouse.x) / TILESIZE * TILESIZE,
				-CAMERAMANAGER->getRenderRc().top + (CAMERAMANAGER->getRenderRc().top + _ptMouse.y) / TILESIZE * TILESIZE, TILESIZE, TILESIZE);
			DeleteObject(SelectObject(getMemDC(), oldBrush));
		}

		TOWNWORLD->render();
		break;
	case mapToolScene::MODE_SPRITE:
	{
		switch (_sprite)
		{
		case SPRITE::TILESAMPLE:
			_spriteImage->scaleRender(getMemDC(),
				-CAMERAMANAGER->getRenderRc().left,
				-CAMERAMANAGER->getRenderRc().top,
				_spriteImage->getWidth() * SCALE,
				_spriteImage->getHeight() * SCALE);

			//선택하는 렉트 표시하고 이름까지 표시
			for (int i = 0; i < _vtileSampleSelect.size(); ++i)
			{
				RECT rc = _vtileSampleSelect[i].rc;

				HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), GetStockObject(NULL_BRUSH));
				RectangleMake(getMemDC(),
					-CAMERAMANAGER->getRenderRc().left + rc.left,
					-CAMERAMANAGER->getRenderRc().top + rc.top,
					rc.right - rc.left, rc.bottom - rc.top);
				DeleteObject(SelectObject(getMemDC(), oldBrush));

				const char* str = _vtileSampleSelect[i].str.c_str();
				TextOut(getMemDC(), -CAMERAMANAGER->getRenderRc().left + rc.left + 2,
					-CAMERAMANAGER->getRenderRc().top + rc.top + 2, str, strlen(str));
			}
			break;
		default:
			_spriteImage->scaleRender(getMemDC(),
				-CAMERAMANAGER->getRenderRc().left,
				-CAMERAMANAGER->getRenderRc().top,
				_spriteImage->getWidth() * SCALE,
				_spriteImage->getHeight() * SCALE);
			break;
		}		//스프라이트 이넘 스위치문 끝

		//마우스 대고있는 칸 표시
		if (0 <= CAMERAMANAGER->getRenderRc().left + _ptMouse.x && CAMERAMANAGER->getRenderRc().left + _ptMouse.x <= _spriteImage->getWidth() * SCALE &&
			0 <= CAMERAMANAGER->getRenderRc().top + _ptMouse.y && CAMERAMANAGER->getRenderRc().top + _ptMouse.y <= _spriteImage->getHeight() * SCALE)
		{
			HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), GetStockObject(NULL_BRUSH));
			RectangleMake(getMemDC(), -CAMERAMANAGER->getRenderRc().left + (CAMERAMANAGER->getRenderRc().left + _ptMouse.x) / TILESIZE * TILESIZE,
				-CAMERAMANAGER->getRenderRc().top + (CAMERAMANAGER->getRenderRc().top + _ptMouse.y) / TILESIZE * TILESIZE, TILESIZE, TILESIZE);
			DeleteObject(SelectObject(getMemDC(), oldBrush));
		}

		//현재 선택된 타일 표시
		//HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), GetStockObject(NULL_BRUSH));
		EllipseMakeCenter(getMemDC(), -CAMERAMANAGER->getRenderRc().left + _selectIdX * TILESIZE + TILESIZE / 2,
			-CAMERAMANAGER->getRenderRc().top + _selectIdY * TILESIZE + TILESIZE / 2, 10, 10);
		//DeleteObject(SelectObject(getMemDC(), oldBrush));

		//스프라이트 선택 버튼들 표시
		for (int i = 0; i < SPRITE::END; ++i)
		{
			//ui니까 카메라 좌표 안빼준다
			RECT rc = _vSpriteRect[i];
			Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);

			switch (i)
			{
			case SPRITE::OUTDOORS_SPRING:
				TextOut(getMemDC(), rc.left + 2, rc.top + 2, "Outdoors Spring", strlen("Outdoors Spring"));
				break;
			case SPRITE::FARM_BUILDINGS:
				TextOut(getMemDC(), rc.left + 2, rc.top + 2, "Farm Buildings", strlen("Farm Buildings"));
				break;
			case SPRITE::FARMHOUSE:
				TextOut(getMemDC(), rc.left + 2, rc.top + 2, "Farmhouse", strlen("Farmhouse"));
				break;
			case SPRITE::CROPS:
				TextOut(getMemDC(), rc.left + 2, rc.top + 2, "Crops", strlen("Crops"));
				break;
			case SPRITE::TREES:
				TextOut(getMemDC(), rc.left + 2, rc.top + 2, "Trees", strlen("Trees"));
				break;
			case SPRITE::TOWNINTERIOR:
				TextOut(getMemDC(), rc.left + 2, rc.top + 2, "Town Interior", strlen("Town Interior"));
				break;
			case SPRITE::TILESAMPLE:
				TextOut(getMemDC(), rc.left + 2, rc.top + 2, "TileSample", strlen("TileSample"));
				break;
			}
		}

		////기타 버튼들 표시
		//Rectangle(getMemDC(), _moveTrue.rc.left, _moveTrue.rc.top, _moveTrue.rc.right, _moveTrue.rc.bottom);
		//TextOut(getMemDC(), _moveTrue.rc.left + 2, _moveTrue.rc.top + 2, _moveTrue.str.c_str(), strlen(_moveTrue.str.c_str()));
		//Rectangle(getMemDC(), _moveFalse.rc.left, _moveFalse.rc.top, _moveFalse.rc.right, _moveFalse.rc.bottom);
		//TextOut(getMemDC(), _moveFalse.rc.left + 2, _moveFalse.rc.top + 2, _moveFalse.str.c_str(), strlen(_moveFalse.str.c_str()));
	}
	break;
	}		//맵-스프라이트 모드 이넘 스위치문 끝

	//마우스 인덱스 표시
	int x = (CAMERAMANAGER->getRenderRc().left + _ptMouse.x) / TILESIZE;
	int y = (CAMERAMANAGER->getRenderRc().top + _ptMouse.y) / TILESIZE;
	char str[64];
	sprintf_s(str, "(%d, %d)", x, y);
	TextOut(getMemDC(), _ptMouse.x + 10, _ptMouse.y, str, strlen(str));
}


void mapToolScene::changeSprite(SPRITE::Enum spriteEnum)
{
	//이넘 바꾸고
	_sprite = spriteEnum;

	//이미지랑 이미지키 바꿔줌
	switch (spriteEnum)
	{
	case SPRITE::OUTDOORS_SPRING:
		_spriteImage = IMAGEMANAGER->findImage("outdoorsSpring");
		_spriteImageKey = "outdoorsSpring";
		break;
	case SPRITE::FARM_BUILDINGS:
		_spriteImage = IMAGEMANAGER->findImage("farmBuildings");
		_spriteImageKey = "farmBuildings";
		break;
	case SPRITE::FARMHOUSE:
		_spriteImage = IMAGEMANAGER->findImage("farmHouse");
		_spriteImageKey = "farmHouse";
		break;
	case SPRITE::CROPS:
		_spriteImage = IMAGEMANAGER->findImage("crops");
		_spriteImageKey = "crops";
		break;
	case SPRITE::TREES:
		_spriteImage = IMAGEMANAGER->findImage("trees");
		_spriteImageKey = "trees";
		break;
	case SPRITE::TOWNINTERIOR:
		_spriteImage = IMAGEMANAGER->findImage("townInterior");
		_spriteImageKey = "townInterior";
		break;
	case SPRITE::TILESAMPLE:
		_spriteImage = IMAGEMANAGER->findImage("tileSample");
		_spriteImageKey = "tileSample";
		break;
	case SPRITE::END:
		break;
	}
}

void mapToolScene::leftClickInSprite()
{
	//스프라이트 선택 버튼을 누른 경우
	for (int i = 0; i < SPRITE::END; ++i)
	{
		if (PtInRect(&_vSpriteRect[i], _ptMouse))
		{
			changeSprite((SPRITE::Enum)i);

			//스프라이트 바꾸면 좌표 초기화
			CAMERAMANAGER->_pos.x = WINSIZEX / 2;
			CAMERAMANAGER->_pos.y = WINSIZEY / 2;

			return;
		}
	}
	

	//스프라이트 종류에 따라서 선택을 다르게 하는데,
	//타일 샘플의 경우 빼고는 스프라이트를 그대로 쓰니
	//지형 종류 SOMETHING 같은거로 해서
	//이미지값이랑 프레임번호 저장해주면
	//하나하나 찍어서 맵 만들 수 있다.
	//거기에다가 이동 가능 여부를 같이 지정해주면?
	//맵을 제대로 찍을 수 있겠다
	switch (_sprite)
	{
	//case SPRITE::OUTDOORS_SPRING:
	//{
	//	int x = (CAMERAMANAGER->getRenderRc().left + _ptMouse.x) / TILESIZE;
	//	int y = (CAMERAMANAGER->getRenderRc().top + _ptMouse.y) / TILESIZE;
	//
	//	//case tileNumber():
	//	switch (spriteNumber(x, y))
	//	{
	//		//나무1
	//	case spriteNumber(0, 0): case spriteNumber(1, 0): case spriteNumber(2, 0):
	//	case spriteNumber(0, 1): case spriteNumber(1, 1): case spriteNumber(2, 1):
	//	case spriteNumber(0, 2): case spriteNumber(1, 2): case spriteNumber(2, 2):
	//	case spriteNumber(0, 3): case spriteNumber(1, 3): case spriteNumber(2, 3):
	//	case spriteNumber(1, 4): case spriteNumber(1, 5):
	//		_selectIdX = 1; _selectIdY = 5;
	//		break;
	//		//나무2
	//	case spriteNumber(3, 0): case spriteNumber(4, 0): case spriteNumber(5, 0):
	//	case spriteNumber(3, 1): case spriteNumber(4, 1): case spriteNumber(5, 1):
	//	case spriteNumber(3, 2): case spriteNumber(4, 2): case spriteNumber(5, 2):
	//	case spriteNumber(3, 3): case spriteNumber(4, 3): case spriteNumber(5, 3):
	//	case spriteNumber(4, 4): case spriteNumber(4, 5):
	//		_selectIdX = 4; _selectIdY = 5;
	//		break;
	//		//나무3
	//	case spriteNumber(6, 0): case spriteNumber(7, 0): case spriteNumber(8, 0): case spriteNumber(9, 0):
	//	case spriteNumber(6, 1): case spriteNumber(7, 1): case spriteNumber(8, 1): case spriteNumber(9, 1):
	//	case spriteNumber(6, 2): case spriteNumber(7, 2): case spriteNumber(8, 2): case spriteNumber(9, 2):
	//	case spriteNumber(6, 3): case spriteNumber(7, 3): case spriteNumber(8, 3): case spriteNumber(9, 3):
	//	case spriteNumber(7, 4): case spriteNumber(8, 4):
	//	case spriteNumber(7, 5): case spriteNumber(8, 5):
	//	case spriteNumber(7, 6): case spriteNumber(8, 6):
	//		_selectIdX = 7; _selectIdY = 6;
	//		break;
	//		//나무4
	//	case spriteNumber(10, 0): case spriteNumber(11, 0): case spriteNumber(12, 0):
	//	case spriteNumber(10, 1): case spriteNumber(11, 1): case spriteNumber(12, 1):
	//	case spriteNumber(10, 2): case spriteNumber(11, 2): case spriteNumber(12, 2):
	//	case spriteNumber(10, 3): case spriteNumber(11, 3): case spriteNumber(12, 3):
	//	case spriteNumber(11, 4): case spriteNumber(11, 5):
	//		_selectIdX = 11; _selectIdY = 5;
	//		break;
	//		//큰덤불
	//	case spriteNumber(13, 0): case spriteNumber(14, 0): case spriteNumber(15, 0):
	//	case spriteNumber(13, 1): case spriteNumber(14, 1): case spriteNumber(15, 1):
	//	case spriteNumber(13, 2): case spriteNumber(14, 2): case spriteNumber(15, 2):
	//		_selectIdX = 14; _selectIdY = 2;
	//		break;
	//		//울타리 가로 왼쪽 끝
	//	case spriteNumber(8, 14): case spriteNumber(8, 15):
	//		_selectIdX = 8; _selectIdY = 15;
	//		break;
	//		//울타리 가로 중간
	//	case spriteNumber(9, 14): case spriteNumber(9, 15):
	//		_selectIdX = 9; _selectIdY = 15;
	//		break;
	//		//울타리 가로 오른쪽 끝
	//	case spriteNumber(10, 14): case spriteNumber(10, 15):
	//		_selectIdX = 10; _selectIdY = 15;
	//		break;
	//	default:
	//		_selectIdX = x; _selectIdY = y;
	//		break;
	//	}
	//
	//	_map->setSelectIdX(_selectIdX); _map->setSelectIdY(_selectIdY);
	//}
	//break;

	case SPRITE::TILESAMPLE:
		for (int i = 0; i < _vtileSampleSelect.size(); ++i)
		{
			POINT pt;
			pt.x = ABSMOUSEX;
			pt.y = ABSMOUSEY;

			if (PtInRect(&_vtileSampleSelect[i].rc, pt))
			{
				_selectKind = _vtileSampleSelect[i].kind;
				_selectTerrain = _vtileSampleSelect[i].terrain;
				_selectObject = _vtileSampleSelect[i].object;

				return;
			}
		}

		//선택 구조체 안만들어둔 부분 누르면 일반 스프라이트처럼 사용 가능하게
		_selectKind = KIND_NONE;
		_selectIdX = ABSMOUSEX / TILESIZE;
		_selectIdY = ABSMOUSEY / TILESIZE;

		break;
	case SPRITE::END:
		break;
	default:
		//이미지는 이미 스프라이트 선택하면서 이미지값 바뀌어있으므로 프레임만 가져오면 된다
		_selectIdX = ABSMOUSEX / TILESIZE;
		_selectIdY = ABSMOUSEY / TILESIZE;
		break;
	}
}

void mapToolScene::setTileSampleSelect()
{
	tagMyButton tag;

	tag.init();
	tag.rc = RectMake(TILESIZE * 0, TILESIZE * 0, TILESIZE * 3, TILESIZE * 6);
	tag.kind = KIND_OBJECT;
	tag.object = OBJECT::TREE1;
	tag.str = "tree1";
	_vtileSampleSelect.push_back(tag);

	tag.init();
	tag.rc = RectMake(TILESIZE * 3, TILESIZE * 0, TILESIZE * 3, TILESIZE * 6);
	tag.kind = KIND_OBJECT;
	tag.object = OBJECT::TREE2;
	tag.str = "tree2";
	_vtileSampleSelect.push_back(tag);

	tag.init();
	tag.rc = RectMake(TILESIZE * 22, TILESIZE * 0, TILESIZE * 1, TILESIZE * 1);
	tag.kind = KIND_TERRAIN;
	tag.terrain = TERRAIN::GRASS;
	tag.str = "grass";
	_vtileSampleSelect.push_back(tag);

	tag.init();
	tag.rc = RectMake(TILESIZE * 23, TILESIZE * 2, TILESIZE * 2, TILESIZE * 1);
	tag.kind = KIND_TERRAIN;
	tag.terrain = TERRAIN::DIRT;
	tag.str = "dirt";
	_vtileSampleSelect.push_back(tag);

	tag.init();
	tag.rc = RectMake(TILESIZE * 30, TILESIZE * 0, TILESIZE * 4, TILESIZE * 4);
	tag.kind = KIND_TERRAIN;
	tag.terrain = TERRAIN::WATER;
	tag.str = "water";
	_vtileSampleSelect.push_back(tag);

	tag.init();
	tag.rc = RectMake(TILESIZE * 23, TILESIZE * 4, TILESIZE * 3, TILESIZE * 3);
	tag.kind = KIND_OBJECT;
	tag.object = OBJECT::FARMLAND;
	tag.str = "farmland";
	_vtileSampleSelect.push_back(tag);

	tag.init();
	tag.rc = RectMake(TILESIZE * 24, TILESIZE * 0, TILESIZE * 1, TILESIZE * 1);
	tag.kind = KIND_TERRAIN;
	tag.terrain = TERRAIN::UNMOVABLE_DIRT;
	tag.str = "unmovableDirt";
	_vtileSampleSelect.push_back(tag);
}

void mapToolScene::modeMapUpdate()
{
	//마우스 절대좌표의 인덱스 구해놓고 쓰자
	int idx = ABSMOUSEX / TILESIZE;
	int idy = ABSMOUSEY / TILESIZE;

	//좌클릭
	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		if (0 <= idx && idx < TILEX &&
			0 <= idy && idy < TILEY)
		{
			//1 누르고 좌클릭하면 _isMovable true로
			if (KEYMANAGER->isStayKeyDown('1'))
			{
				_map->getTile(idx, idy)->setIsMovable1(true);
				return;
			}
			//2 누르고 좌클릭하면 _isMovable2 true로
			if (KEYMANAGER->isStayKeyDown('2'))
			{
				_map->getTile(idx, idy)->setIsMovable2(true);
				return;
			}

			//쉬프트 좌클릭 하면 이중 올리기
			if (KEYMANAGER->isStayKeyDown(VK_LSHIFT))
			{
				switch (_sprite)
				{
				case SPRITE::TILESAMPLE:
					switch (_selectKind)
					{
					case mapToolScene::KIND_NONE:
						//일반 스프라이트처럼
						_map->getTile(idx, idy)->changeImage2(_spriteImageKey);
						_map->getTile(idx, idy)->setFrameX2(_selectIdX);
						_map->getTile(idx, idy)->setFrameY2(_selectIdY);
						break;
					}
					break;
				case SPRITE::END:
					break;
				default:
					_map->getTile(idx, idy)->changeImage2(_spriteImageKey);
					_map->getTile(idx, idy)->setFrameX2(_selectIdX);
					_map->getTile(idx, idy)->setFrameY2(_selectIdY);
					break;
				}

				return;
			}

			switch (_sprite)
			{
			case SPRITE::TILESAMPLE:
				switch (_selectKind)
				{
				case mapToolScene::KIND_NONE:
					//일반 스프라이트처럼
					_map->getTile(idx, idy)->setTerrain(TERRAIN::SOMETHING);
					_map->getTile(idx, idy)->changeImage(_spriteImageKey);
					//_map->getTile(idx, idy)->setImage(_spriteImage);
					_map->getTile(idx, idy)->setFrameX(_selectIdX);
					_map->getTile(idx, idy)->setFrameY(_selectIdY);
					break;
				case mapToolScene::KIND_TERRAIN:
					_map->getTile(idx, idy)->init(idx, idy, _selectTerrain);

					//주변 9타일 프레임 조정
					for (int j = idy - 1; j <= idy + 1; ++j)
					{
						for (int i = idx - 1; i <= idx + 1; ++i)
						{
							//범위 안벗어나게
							if (i < 0 || i >= TILEX || j < 0 || j >= TILEY) continue;
							_map->setTileFrameByAround(i, j);
						}
					}
					break;
				case mapToolScene::KIND_OBJECT:
					//타일에 오브젝트 올라가있으면 없애버리기
					if (_map->getTile(idx, idy)->getPObj() != NULL)
					{
						_map->getTile(idx, idy)->getPObj()->setDestroy();
						_map->getTile(idx, idy)->setPObj(NULL);
					}

					//타일에 오브젝트 만들어서 올리기
					testObject* tempobj = new testObject;
					tempobj->init("test", "outdoorsSpring", tagFloat(idx * TILESIZE, idy * TILESIZE), pivot::LEFT_TOP);
					tempobj->setIdX(idx);
					tempobj->setIdY(idy);
					tempobj->setFrameX(1);
					tempobj->setFrameY(5);
					tempobj->_object = _selectObject;
					TOWNWORLD->addObject(objectType::OBJ, tempobj);
					_map->getTile(idx, idy)->setPObj(tempobj);
					break;
				}
				break;
			case SPRITE::END:
				break;
			default:
				_map->getTile(idx, idy)->setTerrain(TERRAIN::SOMETHING);
				_map->getTile(idx, idy)->changeImage(_spriteImageKey);
				//_map->getTile(idx, idy)->setImage(_spriteImage);
				_map->getTile(idx, idy)->setFrameX(_selectIdX);
				_map->getTile(idx, idy)->setFrameY(_selectIdY);
				break;
			}
		}

		return;
	}

	//우클릭
	if (KEYMANAGER->isStayKeyDown(VK_RBUTTON))
	{
		if (0 <= idx && idx < TILEX &&
			0 <= idy && idy < TILEY)
		{
			//1 누르고 우클릭하면 _isMovable false로
			if (KEYMANAGER->isStayKeyDown('1'))
			{
				_map->getTile(idx, idy)->setIsMovable1(false);
				return;
			}
			//2 누르고 우클릭하면 _isMovable2 false로
			if (KEYMANAGER->isStayKeyDown('2'))
			{
				_map->getTile(idx, idy)->setIsMovable2(false);
				return;
			}

			//쉬프트 우클릭 하면 이중 정보 지움
			if (KEYMANAGER->isStayKeyDown(VK_LSHIFT))
			{
				_map->getTile(idx, idy)->changeImage2("");
				_map->getTile(idx, idy)->setFrameX2(0);
				_map->getTile(idx, idy)->setFrameY2(0);

				return;
			}

			if (_map->getTile(idx, idy)->getPObj() != NULL)
			{
				_map->getTile(idx, idy)->getPObj()->setDestroy();
				_map->getTile(idx, idy)->setPObj(NULL);
			}
		}

		return;
	}
}
