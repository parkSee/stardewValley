#pragma once		//stdafx.h -> townWorld.h -> worldNode.h, gameObject 클래스 전방선언
#include "gameObject.h"
#include "worldNode.h"
#include "mapToolNode.h"


class mapToolTile : public gameObject		//다시 게임오브젝트를 상속해보았다
{
private:
	int				_indexX, _indexY;
	TERRAIN::Enum	_terrain;
	RECT			_rc;
	//게임오브젝트 상속받으면서 tagFloat _pos 사용함

	gameObject*		_pObj;

	image*			_image;
	string			_imageKey;			//저장용
	int				_frameX, _frameY;

	bool			_isMovable;


public:
	HRESULT init(int idX, int idY, TERRAIN::Enum terrain = TERRAIN::NONE);
	void release();
	void update();		//타일은 업데이트 돌리지 말자
	void render();


	inline int getIndexX() { return _indexX; }
	inline int getIndexY() { return _indexY; }
	inline TERRAIN::Enum getTerrain() { return _terrain; }
	inline RECT getRect() { return _rc; }
	inline gameObject* getPObj() { return _pObj; }
	inline image* getImage() { return _image; }
	inline string getImageKey() { return _imageKey; }
	inline int getFrameX() { return _frameX; }
	inline int getFrameY() { return _frameY; }

	inline void setIndexX(int x) { _indexX = x; }
	inline void setIndexY(int y) { _indexY = y; }
	inline void setTerrain(TERRAIN::Enum terrain) { _terrain = terrain; }
	inline void setRect(RECT rc) { _rc = rc; }
	inline void setPObj(gameObject* pObj) { _pObj = pObj; }
	inline void setImage(image* image) { _image = image; }			//이거 두개 쓰지 말고
	inline void setImageKey(string str) { _imageKey = str; }		//밑의 changeImage 써라
	inline void setFrameX(int x) { _frameX = x; }
	inline void setFrameY(int y) { _frameY = y; }

	inline void changeImage(string imageKey)
	{
		_imageKey = imageKey;
		_image = IMAGEMANAGER->findImage(imageKey);
	}

	//에이스타
	inline bool getIsMovable() { return _isMovable; }
	//혹시 모르니
	inline void setIsMovable(bool isMovable) { _isMovable = isMovable; }


	mapToolTile() {}
	~mapToolTile() {}
};
