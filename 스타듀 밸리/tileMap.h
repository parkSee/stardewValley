#pragma once
#include "gameNode.h"
#include "mapToolTile.h"
#include "gameObject.h"


class tileMap : public gameObject		//게임오브젝트 상속받았당 수누야
{
private:
	//enum KIND
	//{
	//	KIND_TERRAIN,
	//	KIND_OBJECT,
	//	KIND_OBJECT_ERASER
	//};

	struct tagTileSave
	{
		int idX, idY;
		TERRAIN::Enum terrain;

		char imageKey[64];
		int frameX, frameY;
	};
	struct tagObjectSave
	{
		int idX, idY;
		OBJECT::Enum object;
		objectType::Enum objectType;
		int frameX, frameY;
		//tagFloat pos;
		pivot::Enum pivot;

		string name;
		string imageKey;
	};
	//------------------------------------------------

	mapToolTile* _pTile[TILEX][TILEY];

	////맵툴용
	//int _selectIdX, _selectIdY;
	//KIND _kind;
	//RECT _rc1, _rc2, _rc3;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void mapSave();
	void mapLoad();
	void objectSave();
	void objectLoad();

	void setTileFrameByAround(int indexX, int indexY);

	//에이스타
	int getHeuristic(int idX1, int idY1, int idX2, int idY2, bool eightDirection);
	vector<mapToolTile*> getShortestAStar(int startIdX, int startIdY, int endIdX, int endIdY, bool eightDirection);


	//inline void setSelectIdX(int x) { _selectIdX = x; }
	//inline void setSelectIdY(int y) { _selectIdY = y; }

	inline bool isInRange(int indexX, int indexY)
	{
		if (0 <= indexX && indexX < TILEX && 0 <= indexY && indexY < TILEY) return true;
		return false;
	}

	//타일 겟
	inline mapToolTile* getTile(int indexX, int indexY)
	{
		if (0 <= indexX && indexX < TILEX && 0 <= indexY && indexY < TILEY) return _pTile[indexX][indexY];
		return NULL;
	}

	tileMap() {}
	~tileMap() {}
};
