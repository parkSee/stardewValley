#pragma once
#include "gameNode.h"		//�̹� ����ȭ �� ������� �׳� �޾�����
#include "worldNode.h"		//�̹� ����ȭ �� ������� �׳� �޾�����
#include "mapToolNode.h"
#include "tileMap.h"
#include "testObject.h"


class mapToolScene : public gameNode
{
private:
	enum MODE
	{
		MODE_MAP,
		MODE_SPRITE
	};
	enum KIND
	{
		KIND_NONE,
		KIND_TERRAIN,
		KIND_OBJECT
	};
	struct tagTileSampleRect
	{
		RECT rc;
		KIND kind;
		TERRAIN::Enum terrain;
		OBJECT::Enum object;
		string str;

		tagTileSampleRect() :
			rc({ 0,0,0,0 }), kind(KIND_NONE),
			terrain(TERRAIN::NONE), object(OBJECT::NONE), str("") {}

		void init()
		{
			rc = { 0,0,0,0 };
			kind = KIND_NONE;
			terrain = TERRAIN::NONE;
			object = OBJECT::NONE;
			str = "";
		}
	};
	//------------------------

	tileMap* _map;

	vector<RECT> _vSpriteRect;		//��������Ʈ ������ ��ư ���� ��Ʈ
	vector<tagTileSampleRect> _vtileSampleSelect;		//Ÿ�ϻ��� ���� ���ù�ư ����ü
	SPRITE::Enum _sprite;			//���� ������ ��������Ʈ �̳�
	image* _spriteImage;			//���� ������ ��������Ʈ�� �̹���
	MODE _mode;						//������ ��������Ʈ���� ���
	tagInt _mapCam, _spriteCam;		//���̶� ��������Ʈ�� �Դٰ��� �� �� ī�޶� ��ǥ ����


	int _selectIdX, _selectIdY;

	//����Ÿ�Ͽ�
	KIND _selectKind;
	TERRAIN::Enum _selectTerrain;
	OBJECT::Enum _selectObject;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void changeSprite(SPRITE::Enum spriteEnum);
	void leftClickInSprite();

	void setTileSampleSelect();
	void tileSampleToMap();

	mapToolScene() {}
	~mapToolScene() {}
};
