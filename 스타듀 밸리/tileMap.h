#pragma once
#include "gameNode.h"
#include "mapToolTile.h"


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

	//¸ÊÅø¿ë
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

	inline mapToolTile* getTile(int idX, int idY) { return _pTile[idX][idY]; }
	inline void setSelectIdX(int x) { _selectIdX = x; }
	inline void setSelectIdY(int y) { _selectIdY = y; }

	tileMap() {}
	~tileMap() {}
};
