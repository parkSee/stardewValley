#pragma once		//stdafx.h -> townWorld.h -> worldNode.h, gameObject Ŭ���� ���漱��
#include "gameObject.h"
#include "worldNode.h"
#include "mapToolNode.h"


class mapToolTile : public gameObject		//�ٽ� ���ӿ�����Ʈ�� ����غ��Ҵ�
{
private:
	int				_indexX, _indexY;
	TERRAIN::Enum	_terrain;
	RECT			_rc;
	//���ӿ�����Ʈ ��ӹ����鼭 tagFloat _pos �����

	gameObject*		_pObj;

	image*			_image;
	string			_imageKey;			//�����
	int				_frameX, _frameY;

	bool			_isMovable;


public:
	HRESULT init(int idX, int idY, TERRAIN::Enum terrain = TERRAIN::NONE);
	void release();
	void update();		//Ÿ���� ������Ʈ ������ ����
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
	inline void setImage(image* image) { _image = image; }			//�̰� �ΰ� ���� ����
	inline void setImageKey(string str) { _imageKey = str; }		//���� changeImage ���
	inline void setFrameX(int x) { _frameX = x; }
	inline void setFrameY(int y) { _frameY = y; }

	inline void changeImage(string imageKey)
	{
		_imageKey = imageKey;
		_image = IMAGEMANAGER->findImage(imageKey);
	}

	//���̽�Ÿ
	inline bool getIsMovable() { return _isMovable; }
	//Ȥ�� �𸣴�
	inline void setIsMovable(bool isMovable) { _isMovable = isMovable; }


	mapToolTile() {}
	~mapToolTile() {}
};
