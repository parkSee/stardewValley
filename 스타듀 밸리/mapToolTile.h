#pragma once
#include "gameObject.h"
//gameObject가 worldNode 참조하고 있다
#include "mapToolNode.h"

enum  TERRAIN
{
	TR_GROUND, TR_ROAD, TR_WATER
};

class mapToolTile : public gameObject
{
private:
	struct tag
	{
		int			indexX, indexY;
		RECT		rc;

		TERRAIN		terrain;
		int			terrainFrameX, terrainFrameY;
	};

	tag _tag;

	gameObject* _obj;


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
	void setTileFrameX(int frameX) { _tag.terrainFrameX = frameX; }
	void setTileFrameY(int frameY) { _tag.terrainFrameY = frameY; }

	inline tag* getTagAddress() { return &_tag; }

	inline TERRAIN getTerrain() { return _tag.terrain; }
	inline int getTerrainFrameX() { return _tag.terrainFrameX; }
	inline int getTerrainFrameY() { return _tag.terrainFrameY; }
	inline int getIndexX() { return _tag.indexX; }
	inline int getIndexY() { return _tag.indexY; }
	inline RECT getRect() { return _tag.rc; }
	inline gameObject* getObj() { return _obj; }

	inline void setTerrain(TERRAIN terrain) { _tag.terrain = terrain; }
	inline void setTerrainFrameX(int x) { _tag.terrainFrameX = x; }
	inline void setTerrainFrameY(int y) { _tag.terrainFrameY = y; }
	inline void setIndexX(int x) { _tag.indexX = x; }
	inline void setIndexY(int y) { _tag.indexY = y; }
	inline void setRect(RECT rc) { _tag.rc = rc; }
	inline void setObj(gameObject* obj) { _obj = obj; }


	mapToolTile() {}
	virtual ~mapToolTile() {}
};
