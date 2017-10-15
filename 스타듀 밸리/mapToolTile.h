#pragma once
#include "gameObject.h"
//gameObject가 worldNode 참조하고 있다
#include "mapToolNode.h"

//enum  TERRAIN
//{
//	TR_GROUND, TR_ROAD, TR_WATER
//};

class mapToolTile : public gameObject
{
private:
	//struct tag
	//{
	//};
	//
	//tag _tag;

	int				_indexX, _indexY;
	RECT			_rc;

	TERRAIN::Enum	_terrain;
	int				_terrainFrameX, _terrainFrameY;

	gameObject*		_obj;


public:
	HRESULT init(int idX, int idY);
	void release();
	void update();
	void render();

	void setImage(string keyName)
	{
		if (IMAGEMANAGER->findImage(keyName))
		{
			_image = IMAGEMANAGER->findImage(keyName);
		}
	}
	void setTileFrameX(int frameX) { _terrainFrameX = frameX; }
	void setTileFrameY(int frameY) { _terrainFrameY = frameY; }

	//inline tag* getTagAddress() { return &_tag; }

	inline TERRAIN::Enum getTerrain() { return _terrain; }
	inline int getTerrainFrameX() { return _terrainFrameX; }
	inline int getTerrainFrameY() { return _terrainFrameY; }
	inline int getIndexX() { return _indexX; }
	inline int getIndexY() { return _indexY; }
	inline RECT getRect() { return _rc; }
	inline gameObject* getObj() { return _obj; }

	inline void setTerrain(TERRAIN::Enum terrain) { _terrain = terrain; }
	inline void setTerrainFrameX(int x) { _terrainFrameX = x; }
	inline void setTerrainFrameY(int y) { _terrainFrameY = y; }
	inline void setIndexX(int x) { _indexX = x; }
	inline void setIndexY(int y) { _indexY = y; }
	inline void setRect(RECT rc) { _rc = rc; }
	inline void setObj(gameObject* obj) { _obj = obj; }


	mapToolTile() {}
	virtual ~mapToolTile() {}
};
