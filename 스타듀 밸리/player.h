#pragma once
#include "gameObject.h"

namespace playerState
{
	enum Enum
	{
		STAND,					//���ֱ�
		STAND_RIGHT,
		STAND_LEFT,
		STAND_BACK,
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
		SICKLE_RIGHT,			//�� ������
		SICKLE_LEFT,			//�� ����
		SICKLE_UP,				//�� ����
		SICKLE_DOWN,			//�� �Ʒ���
		WATER_RIGHT,			//���Ѹ��� ������
		WATER_LEFT,				//���Ѹ��� ����
		WATER_UP,				//���Ѹ��� ����
		WATER_DOWN,				//���Ѹ��� �Ʒ���
		TAKE_RIGHT,				//��� �ֱ� ������
		TAKE_LEFT,				//��� �ֱ� ����
		TAKE_UP,				//��� �ֱ� ��
		TAKE_DOWN				//��� �ֱ� �Ʒ�

	};
}

struct tagItem
{
	//������ ������ 
	//�̹��� ������
	image* img;
	RECT rc;
	float x, y;

};

struct tagPlayer
{
	animation* Motion;
	
	RECT rc;
};


using namespace playerState;

class player : public gameObject
{
private:
	playerState::Enum _state;
	tagPlayer _player;
	bool _isStop;
	tagItem _item;


public:
	HRESULT init(string objName, tagFloat pos);
	void release();
	void update();
	void render();

	void stateUpdate(playerState::Enum state);
	void changeState(playerState::Enum state);
	void eating();
	void lbuttonClick();
	void changeTargetItem();


	player() {};
	~player() {};
};

