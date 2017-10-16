#pragma once
#include "gameObject.h"
//gameObject가 worldNode 참조하고 있다
#include "mapToolNode.h"


class mapToolTile : public gameObject
{
private:
	TERRAIN::Enum	_terrain;
	int				_indexX, _indexY;
	RECT			_rc;

	gameObject*		_pObj;

	int				_terrainFrameX, _terrainFrameY;		//렌더에서 terrain 이넘에 따라서 하면 필요 없을듯


public:
	HRESULT init(int idX, int idY);
	void release();
	void update();
	void render();

	//void setImage(string keyName)
	//{
	//	if (IMAGEMANAGER->findImage(keyName))
	//	{
	//		_image = IMAGEMANAGER->findImage(keyName);
	//	}
	//}
	void setTileFrameX(int frameX) { _terrainFrameX = frameX; }
	void setTileFrameY(int frameY) { _terrainFrameY = frameY; }


	inline TERRAIN::Enum getTerrain() { return _terrain; }
	inline int getIndexX() { return _indexX; }
	inline int getIndexY() { return _indexY; }
	inline RECT getRect() { return _rc; }
	inline gameObject* getPObj() { return _pObj; }
	inline int getTerrainFrameX() { return _terrainFrameX; }
	inline int getTerrainFrameY() { return _terrainFrameY; }

	inline void setTerrain(TERRAIN::Enum terrain) { _terrain = terrain; }
	inline void setIndexX(int x) { _indexX = x; }
	inline void setIndexY(int y) { _indexY = y; }
	inline void setRect(RECT rc) { _rc = rc; }
	inline void setPObj(gameObject* obj) { _pObj = obj; }
	inline void setTerrainFrameX(int x) { _terrainFrameX = x; }
	inline void setTerrainFrameY(int y) { _terrainFrameY = y; }


	mapToolTile() {}
	virtual ~mapToolTile() {}
};
