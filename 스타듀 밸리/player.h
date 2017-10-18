#pragma once
#include "gameObject.h"
#include "item.h"
#include "tileMap.h"
#include "mapToolTile.h"
#include "eProgressBar.h"
#include "tree1.h"
#define SPEED 4
#define CARRY 210

namespace playerState
{
	enum Enum
	{
		STAND,					//���ֱ�
		STAND_RIGHT,
		STAND_LEFT,
		STAND_BACK,
		STAND_TAKE,				//��� ���ֱ�
		STAND_TAKE_RIGHT,
		STAND_TAKE_LEFT,
		STAND_TAKE_BACK,
		RIGHT_RUN,				//������
		LEFT_RUN,				//����
		UP_RUN,					//����
		DOWN_RUN,				//�Ʒ���
		AXE_RIGHT,				//���� ������
		AXE_LEFT,				//���� ����
		AXE_UP,					//���� ����
		AXE_DOWN,				//���� �Ʒ���
		HOE_RIGHT,				//���� ������
		HOE_LEFT,				//���� ����
		HOE_UP,					//���� ���� 
		HOE_DOWN,				//���� �Ʒ���
		PIXHOE_RIGHT,			//��� ������
		PIXHOE_LEFT,			//��� ����
		PIXHOE_UP,				//��� ����
		PIXHOE_DOWN,			//��� �Ʒ���
		SICKLE_RIGHT,			//�� ������
		SICKLE_LEFT,			//�� ����
		SICKLE_UP,				//�� ����
		SICKLE_DOWN,			//�� �Ʒ���
		SWORD_RIGHT,			//�� ������
		SWORD_LEFT,				//�� ����
		SWORD_UP,				//�� ����
		SWORD_DOWN,				//�� �Ʒ���
		WATER_RIGHT,			//���Ѹ��� ������
		WATER_LEFT,				//���Ѹ��� ����
		WATER_UP,				//���Ѹ��� ����
		WATER_DOWN,				//���Ѹ��� �Ʒ���
		TAKE_RIGHT,				//��� ���������� �޸���
		TAKE_LEFT,				//��� �������� �޸���
		TAKE_UP,				//��� ������ �޸���
		TAKE_DOWN				//��� �Ʒ����� �޸���
	};
}


struct tagPlayer
{
	animation* Motion;
	RECT rc;
	int now;
};

struct tagMyItem			//�������� ����ü�� �Ǿ��ֱ� ������ �̹����� ��ǥ�� �����ͼ� �÷��̾� �ʿ��� �׷��ش�.
{
	image* img;
	float x, y;

};

using namespace playerState;

class player : public gameObject
{
private:
	playerState::Enum _state;
	tagPlayer _player;
	tagMyItem _myItem;
	tagItem* _item;
	tagItem tem;
	tileMap* _map;
	eProgressBar* _power;
	mapToolTile* _tile1;
	mapToolTile* _tile2;
	tree1_bottom* _tree;

	tagFloat	_tilePos;


	int _indexX, _indexY;
	RECT _rcCollision;							//�浹üũ�� ���� ��Ʈ

public:
	HRESULT init(string objName, tagFloat pos);
	void release();
	void update();
	void render();

	void stateUpdate(playerState::Enum state);
	void changeState(playerState::Enum state);
	void eating();
	void lbuttonClick(tagMessage msg);
	void changeTargetItem(tagMessage msg);
	RECT rectMakeBottom();

	void tileCollision();
	

	enum playerState::Enum getPlayerState(void) { return _state; }
	void setPlayerState(playerState::Enum state) { _state = state; }

	animation* getPlayerMotion(void) { return _player.Motion; }
	void setPlayerMotion(animation* ani) { _player.Motion = ani; }

	int getIndexX(void) { return _indexX; }
	int getIndexY(void) { return _indexY; }

	player() {};
	~player() {};
};

