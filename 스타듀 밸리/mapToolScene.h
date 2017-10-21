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
	struct tagMyButton
	{
		RECT rc;
		KIND kind;
		TERRAIN::Enum terrain;
		OBJECT::Enum object;
		string str;
		bool bTrue;

		tagMyButton() :
			rc({ 0,0,0,0 }), kind(KIND_NONE),
			terrain(TERRAIN::NONE), object(OBJECT::NONE), str(""), bTrue(false) {}

		void init()
		{
			rc = { 0,0,0,0 };
			kind = KIND_NONE;
			terrain = TERRAIN::NONE;
			object = OBJECT::NONE;
			str = "";
			bTrue = false;
		}
	};
	//------------------------

	tileMap* _map;

	vector<RECT> _vSpriteRect;		//��������Ʈ ������ ��ư ���� ��Ʈ
	vector<tagMyButton> _vtileSampleSelect;		//Ÿ�ϻ��� ���� ���ù�ư ����ü
	SPRITE::Enum _sprite;			//���� ������ ��������Ʈ �̳�
	image* _spriteImage;			//���� ������ ��������Ʈ�� �̹���
	string _spriteImageKey;			//���� ������ ��������Ʈ�� �̹��� Ű �����
	MODE _mode;						//������ ��������Ʈ���� ���
	tagInt _mapCam, _spriteCam;		//���̶� ��������Ʈ�� �Դٰ��� �� �� ī�޶� ��ǥ ����

	//��ư��
	tagMyButton _moveTrue, _moveFalse;


	int _selectIdX, _selectIdY;		//��������Ʈ���� ������ �ε��� ����

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
	void modeMapUpdate();

	mapToolScene() {}
	~mapToolScene() {}
};
