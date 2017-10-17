//#pragma once
//#include "gameObject.h"
//
//enum  TERRAIN
//{
//	TR_GROUND , TR_ROAD , TR_WATER 
//};
//
//class tile : public gameObject
//{
//private:
//	TERRAIN		_terrain;
//	int			_terrainFrameX;
//	int			_terrainFrameY;
//
//	int			_indexX;
//	int			_indexY;
//
//	image*		_image;
//
//	RECT		_rc;
//
//public:
//	HRESULT init(float x , float y,int idX ,int idY);
//	void release();
//	void update();
//	void render();
//	
//	void setImage(string keyName)
//	{
//		if (IMAGEMANAGER->findImage(keyName))
//		{
//			_image = IMAGEMANAGER->findImage(keyName);
//		}
//	}
//	void setTileFrameX(int frameX) { _terrainFrameX = frameX; }
//	void setTileFrameY(int frameY) { _terrainFrameY = frameY; }
//
//	int getIndexX() { return _indexX; }
//	int getIndexY() { return _indexY; }
//
//	tile() {}
//	virtual ~tile() {}
//};
//
