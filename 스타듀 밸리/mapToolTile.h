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

	//�������� �ø� �̹���
	image*			_image2;			//�̹����� NULL�̸� ���°ɷ� Ȯ��
	string			_imageKey2;
	int				_frameX2, _frameY2;
	bool			_isMovable2;

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
	inline image* getImage2() { return _image2; }
	inline string getImageKey2() { return _imageKey2; }
	inline int getFrameX() { return _frameX; }
	inline int getFrameY() { return _frameY; }
	inline int getFrameX2() { return _frameX2; }
	inline int getFrameY2() { return _frameY2; }

	inline void setIndexX(int x) { _indexX = x; }
	inline void setIndexY(int y) { _indexY = y; }
	inline void setTerrain(TERRAIN::Enum terrain) { _terrain = terrain; }
	inline void setRect(RECT rc) { _rc = rc; }
	inline void setPObj(gameObject* pObj) { _pObj = pObj; }
	inline void setImage(image* image) { _image = image; }			//�̰� �ΰ� ���� ����
	inline void setImageKey(string str) { _imageKey = str; }		//���� changeImage ���
	inline void setImage2(image* image) { _image2 = image; }		//�̰� �ΰ� ���� ����
	inline void setImageKey2(string str) { _imageKey2 = str; }		//���� changeImage2 ���
	inline void setFrameX(int x) { _frameX = x; }
	inline void setFrameY(int y) { _frameY = y; }
	inline void setFrameX2(int x) { _frameX2 = x; }
	inline void setFrameY2(int y) { _frameY2 = y; }

	inline void changeImage(string imageKey)
	{
		_imageKey = imageKey;
		_image = IMAGEMANAGER->findImage(imageKey);
	}
	inline void changeImage2(string imageKey)
	{
		_imageKey2 = imageKey;
		_image2 = IMAGEMANAGER->findImage(imageKey);
	}

	//���̽�Ÿ
	inline bool getIsMovable()
	{
		if (_isMovable)
		{
			if (_isMovable2) return true;
			else false;
		}
		else return false;
	}
	//Ȥ�� �𸣴�
	inline void setIsMovable(bool isMovable) { _isMovable = isMovable; }
	inline void setIsMovable2(bool isMovable2) { _isMovable2 = isMovable2; }


	mapToolTile() {}
	virtual ~mapToolTile() {}
};
