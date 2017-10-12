#pragma once
#include "singletonBase.h"
#include "worldNode.h"
#include <functional>

class gameObject;

typedef std::function<void()> CAMERA_CALLBACK;		//�ݹ��Լ�

struct tagInt							
{
	int x;
	int y;
	
	tagInt() { x = 0; y = 0; }
	tagInt(int X, int Y) { x = X; y = Y; }
};

namespace direction
{
	enum Enum
	{
		MOVE_TO_TARGET ,  CONNECT_TO_TARGET	, NULL_TARGET
	};
}


class cameraManager : public singletonBase<cameraManager>
{
private: 
	tagInt		_mapSize;				//���� ������

	gameObject*		_target;			//ī�޶� �ֽ��� ���
	gameObject*		_reservedTarget;	//���� ���
	float			_reservedTimer;		//���� ��� Ÿ�̸�

	direction::Enum _direction;			//ī�޶� ����
	
	bool			_isShake;			//ī�޶� ��鸲�� ���� �Ұ�
	float			_shakeTimer;		//ī�޶� ��鸲 �ð�
	float			_shakeStrenth;		//ī�޶� ��鸲 ���� 

	RECT			_renderRc;			//��� ��ǥ ����� ��Ʈ

	//ī�޶� �ð� ���� ������ ���� ������  
	tagInt			_start;				//������
	tagInt			_end;				//������ 
	float			_angle;				//����
	int				_range;				//�̵��Ÿ� 
	float			_worldTimeCount;	//���� ī��Ʈ
	float			_time;				//������� �ð� 

	CAMERA_CALLBACK	_cbCamera;			//ī�޶� �ݹ� �Լ� 

	//���̵� �ƿ� ���̵��� 
	bool			_isFadeOut;
	bool			_isChange;
	int				_fadeAlpha;
	image*			_fadeOut;

public:
	tagInt		_pos;					//ī�޶� ��ǥ

	HRESULT init();
	void release();
	void update();
	void render();
	void cameraMove();

	//ī�޶��� Ÿ���� �������ش�. ������ Ÿ���� �ִٸ� ����Ÿ�ٿ� �־� �д�.
	void connectTarget(gameObject* target , float delayTime = 0.0f);
	//ī�޶� ���� ��ǥ�� ���ϴ� �ð��� �����ϰ� �Ѵ�. ���� �� ���� ����� �ִٸ� �ݹ� �Լ��� ����Ѵ�.
	void moveToCamera(int endX, int endY, float time, CAMERA_CALLBACK cb = NULL);
	//���̵� �ƿ� ���̵� ��
	void fadeOut();
	//�� ������ ������ 
	void setMapSize(int width, int height )
	{
		_mapSize.x = width;
		_mapSize.y = height;
	}
	//�� ������ ������
	tagInt getMapSize() { return _mapSize; }
	//���� ��Ʈ ������
	RECT getRenderRc() { return _renderRc; }

	cameraManager()
		:_cbCamera(NULL){}
	~cameraManager() {}
};

