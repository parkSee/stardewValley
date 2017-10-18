#pragma once
#include "gameNode.h"
#include "mapToolTile.h"
#include "gameObject.h"


class tileMap : public gameNode
{
private:
	enum KIND
	{
		KIND_TERRAIN,
		KIND_OBJECT,
		KIND_OBJECT_ERASER
	};

	struct tagTileSave
	{
		int idX, idY;
		TERRAIN::Enum terrain;
	};
	struct tagObjectSave
	{
		int idX, idY;
		int frameX, frameY;
		objectType::Enum objectType;
		OBJECT::Enum object;
		tagFloat pos;
		pivot::Enum pivot;

		string name;
		string imageKey;
	};
	//------------------------------------------------

	mapToolTile* _pTile[TILEX][TILEY];

	//∏ ≈¯øÎ
	int _selectIdX, _selectIdY;
	KIND _kind;
	RECT _rc1, _rc2, _rc3;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void save();
	void load();

	void setTileFrameByAround(int indexX, int indexY);

	//ø°¿ÃΩ∫≈∏
	int getHeuristic(int idX1, int idY1, int idX2, int idY2, bool eightDirection);
	vector<mapToolTile*> getShortestAStar(int startIdX, int startIdY, int endIdX, int endIdY, bool eightDirection);


	inline void setSelectIdX(int x) { _selectIdX = x; }
	inline void setSelectIdY(int y) { _selectIdY = y; }

	//≈∏¿œ ∞Ÿ
	inline mapToolTile* getTile(int indexX, int indexY) { return _pTile[indexX][indexY]; }

	tileMap() {}
	~tileMap() {}
};
