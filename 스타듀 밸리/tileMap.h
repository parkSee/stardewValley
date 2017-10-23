#pragma once
#include "gameNode.h"
#include "mapToolTile.h"
#include "gameObject.h"


class tileMap : public gameObject		//게임오브젝트 상속받았당 수누야
{
private:
	struct tagTileSave
	{
		int idX, idY;
		TERRAIN::Enum terrain;

		char imageKey[64];
		int frameX, frameY;
		bool isMovable;

		char imageKey2[64];
		int frameX2, frameY2;
		bool isMovable2;

		char imageKey3[64];
		int frameX3, frameY3;
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

	//타일 포인터 이중배열
	mapToolTile* _pTile[TILEX][TILEY];

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void renderTile3();

	void mapSave(string fileName);
	void mapLoad(string fileName);
	void objectSave(string fileName);
	void objectLoad(string fileName);

	void setTileFrameByAround(int indexX, int indexY);

	//에이스타
	int getHeuristic(int idX1, int idY1, int idX2, int idY2, bool eightDirection);
	vector<mapToolTile*> getShortestAStar(int startIdX, int startIdY, int endIdX, int endIdY, bool eightDirection);


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
